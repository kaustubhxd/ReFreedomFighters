"""specs_s317.py - gap band, batch 317: 0x61ce20, a cdecl state machine (A, B, P, C, Dv).
Object A (this) and object B hold function pointers and values. The stubs below are cdecl (the caller pops), registered as
fake-vtable slots (their addresses are stored in B+8, B+0x3c, A+0x3c, A+0x4c). Pointers passed to stubs are logged as the value
they point to (stack addresses differ between the two frames). Counters live in the closures, which gen creates for each run, so each
run starts from zero. The helper 0x620cb0 is hooked (cdecl, four arguments, recorded)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    STK_LO, STK_HI = 0x0fe00000, 0x0ff00000

    # the per-run outcome lists (drawn once per gen; the counters below index them)
    r_list = [rng.choice([0x30, rng.randrange(0, 0x2d), rng.randrange(0, 0x2d), rng.randrange(0x2d, 0x40), 0xffffffff, 0xfffffffe])
              for _ in range(8)]   # 0xffffffff and 0xfffffffe reach the case 0 and case 1 targets (k = r + 4 = 3 and 2)
    s_list = [rng.choice([None, rng.getrandbits(32)]) for _ in range(8)]        # None: keep the S argument
    v_list = [rng.choice([None, rng.getrandbits(32)]) for _ in range(8)]        # None: write the S argument (ends the loop)
    l_list = [rng.getrandbits(32) for _ in range(8)]
    cnt = {'step': 0, 'b': 0}

    def rd32(em, addr):
        return struct.unpack('<I', bytes(em.mu.mem_read(addr, 4)))[0]

    def step(em, r):
        # B+8: state step (B, v, C, &S): returns the chosen index, and writes S from the list. After six calls it returns the default index.
        a = [em.arg32(k) for k in range(4)]
        i = cnt['step']
        cnt['step'] += 1
        ret = r_list[i] if i < 6 else 0x30
        if s_list[i % 8] is not None:
            em.w32(a[3], s_list[i % 8])
        em.calllog.append(('step', 0, None, (a[0], a[1], a[2], ('S', rd32(em, a[3])))))
        em.ret(eax=ret, argbytes=0)

    def loopB(em, r):
        # B+0x3c (B, &v, S, &L12, A+0x30): writes L12 and v; from the fifth call on v = S, so the loop ends
        a = [em.arg32(k) for k in range(5)]
        i = cnt['b']
        cnt['b'] += 1
        em.w32(a[3], l_list[i % 8])
        if i < 4 and v_list[i] is not None:
            em.w32(a[1], v_list[i])
        else:
            em.w32(a[1], a[2])
        em.calllog.append(('loopB', 0, None, (a[0], ('v', rd32(em, a[1])), a[2], ('L12', rd32(em, a[3])), a[4])))
        em.ret(eax=0, argbytes=0)

    def callC(em, r):
        a = [em.arg32(k) for k in range(3)]
        # the byte pointer of case 4 is a stack address: log its byte; the other arguments are values
        vals = []
        for x in a:
            if STK_LO <= x < STK_HI:
                vals.append(('byte', em.mu.mem_read(x, 1)[0]))
            else:
                vals.append(x)
        em.calllog.append(('callC', 0, None, tuple(vals)))
        em.ret(eax=0, argbytes=0)

    def callD(em, r):
        em.calllog.append(('callD', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    def hook620(em, r):
        em.calllog.append(('h620cb0', 0, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=0)

    e.hook(0x620cb0, hook620)

    def fake(name, nslots, handlers):
        return e.fake_vtable(name, nslots, handlers)

    def fn_addr(vt, off):
        return struct.unpack('<I', bytes(e.rbytes(vt + off, 4)))[0]

    stepvt = fake('cmd_step', 0x30, {0: step})
    loopvt = fake('cmd_loop', 0x30, {0: loopB})
    cvt = fake('cmd_c', 0x30, {0: callC})
    dvt = fake('cmd_d', 0x30, {0: callD})

    # object B: +8 step, +0x3c loopB, +0x48 flag byte
    B = _rnd(c, 0x60)
    e.w32(B + 8, fn_addr(stepvt, 0))
    e.w32(B + 0x3c, fn_addr(loopvt, 0))
    e.wbytes(B + 0x48, bytes([rng.choice([0, 0, 1])]))

    # object A: +4 value, +0x2c, +0x30 values, +0x3c (callC) or 0, +0x4c (callD) or 0, +0x50 value, +0x8c = B or other, +0x124 block
    A = _rnd(c, 0x200)
    e.w32(A + 4, rng.getrandbits(32))
    e.w32(A + 0x2c, rng.getrandbits(32))
    e.w32(A + 0x30, rng.getrandbits(32))
    e.w32(A + 0x3c, fn_addr(cvt, 0) if rng.random() < 0.85 else 0)
    e.w32(A + 0x4c, fn_addr(dvt, 0) if rng.random() < 0.6 else 0)
    e.w32(A + 0x50, rng.choice([0, 0, 1, rng.getrandbits(32)]))
    e.w32(A + 0x8c, B if rng.random() < 0.7 else rng.getrandbits(32))
    blk = _rnd(c, 0x20)
    e.w32(A + 0x124, blk)

    P = _rnd(c, 4)
    e.w32(P, rng.getrandbits(32))
    Dv = _rnd(c, 4) if rng.random() < 0.5 else 0
    C = rng.getrandbits(32)
    return [A, B, P, C, Dv]


S(0x61ce20, 'state61ce20 (GUESS)', 'cdecl', None, ret='eax', gen=_gen,
  note='batch317; cdecl plain ret; helper 0x620cb0 hooked')
