"""specs_s350.py - residue-15, batch 350: 0x468570 (ret 8, fastcall shape: ECX = this, EDX input, two stack args; GUESS).

Object graph per case: T (this) -> A (arg2, its +8 AB, +0x6c/+0x70 O objects); T+0x44 F and the 0x8c result are SO objects;
the SO's 0x2c4/0x1b8 return EO objects (edi); EO's 0x100 returns W; the engine (0x70039c) has the DAT object at +0x9b.
Helpers 0x4db2f0/0x4dc630/0x4da340/0x4db2c0 are exe code hooked by address (logged; 0x4db2c0 writes the out-pointers).
Arity of each vtable slot is fixed per case: DAT 0x4c is 2 args in float mode (T+0x5b != 0) and 1 arg otherwise (the two
call sites never share a case); SO 0x1b8 is 1 arg when T+0x53 == 1 and 5 args otherwise. T+0x53 is 0..3 (other values fault).
Out-pointer arguments are logged by their pointee (the stack address differs between the two frames)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a


def _f32(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _mkvt(e, name, nslots, table):
    """table: {byte_off: (nargs, fn(em, args) -> eax, ptr_arg_indexes)}. Pops 4*nargs; ptr args are logged by pointee."""
    slots = {}
    for i in range(nslots):
        off = 4 * i
        n, fn, ptrs = table.get(off, (0, None, ()))

        def h(em, r, off=off, n=n, fn=fn, ptrs=ptrs):
            args = [em.arg32(k) for k in range(n)]
            logged = []
            for k, a in enumerate(args):
                if k in ptrs:
                    logged.append(('p', struct.unpack('<I', bytes(em.mu.mem_read(a, 4)))[0]))
                else:
                    logged.append(a)
            em.calllog.append((name, off, em.reg('ecx'), tuple(logged)))
            res = fn(em, args) if fn else 0
            em.ret(eax=res, argbytes=4 * n)
        slots[off] = h
    return e.fake_vtable(name, nslots, slots)


def _gen(c):
    e = c.emu
    rng = c.rng
    # ---- helpers (exe code, hooked)
    db2f0_ret = rng.getrandbits(32)
    x34, x10 = rng.getrandbits(32), rng.getrandbits(32)

    def h_db2f0(em, r):
        em.calllog.append(('db2f0', 0x4db2f0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=db2f0_ret, argbytes=4)

    def h_dc630(em, r):
        em.calllog.append(('dc630', 0x4dc630, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h_da340(em, r):
        em.calllog.append(('da340', 0x4da340, em.reg('ecx'), tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=16)

    def h_db2c0(em, r):
        p34, p10 = em.arg32(0), em.arg32(1)
        em.w32(p34, x34)
        em.w32(p10, x10)
        em.calllog.append(('db2c0', 0x4db2c0, em.reg('ecx'), (x34, x10)))
        em.ret(eax=0, argbytes=8)

    e.hook(0x4db2f0, h_db2f0)
    e.hook(0x4dc630, h_dc630)
    e.hook(0x4da340, h_da340)
    e.hook(0x4db2c0, h_db2c0)

    # ---- case parameters
    float_mode = rng.random() < 0.35
    t53 = rng.choice([0, 0, 1, 1, 2, 3])
    ar4c = 2 if float_mode else 1          # DAT 0x4c arity for the whole case
    n1b8 = 1 if t53 == 1 else 5            # SO 0x1b8 arity for the whole case

    # ---- records and plain objects
    def rec():
        r = _rnd(c, 0x40)
        e.w32(r + 0x23, rng.getrandbits(32))   # tested with 0x100000 (SO) and 0x400000 (obj54) by the exe
        return r

    rec_s = rec()
    rec_ob = rec()
    ab = _rnd(c, 0x40)                     # A+8
    e.w32(ab + 0x3c, (rng.getrandbits(32) | 0x1000) if rng.random() < 0.7 else (rng.getrandbits(32) & ~0x1000))
    ab2 = _rnd(c, 0x40)                    # F+8
    o6c = _rnd(c, 0x40)
    o70 = _rnd(c, 0x40)
    wpool = [_rnd(c, 0x40) for _ in range(3)]

    # ---- DAT (engine +0x9b)
    r4c = rng.getrandbits(32)

    def fn4c(em, args):
        return r4c
    dat = _rnd(c, 0x1000)
    dat_vt = _mkvt(e, 'cmd_dat', 0x80, {0x4c: (ar4c, fn4c, ())})
    e.w32(dat, dat_vt)
    e.w32(dat + 0xadc, rng.getrandbits(32))

    # ---- engine (0x70039c)
    r1c8 = rng.getrandbits(32)
    eng = _rnd(c, 0x1000)
    eng_vt = _mkvt(e, 'cmd_eng', 0x180, {
        0x1c8: (2, lambda em, a: r1c8, ()),
        0x178: (3, None, ()),
        0x17c: (3, None, ()),
    })
    e.w32(eng, eng_vt)
    e.w32(eng + 0x40, rng.getrandbits(32))
    e.w32(eng + 0x9b, dat)
    for off in (0x9c3, 0x9c7):
        v = 0.0 if rng.random() < 0.12 else rng.choice([1.0, 0.5, -2.0, 1.5])
        e.w32(eng + off, _f32(v))
    e.w32(0x70039c, eng)

    # ---- EO objects (edi candidates): EO+8 is a chain head; chains maps each EO to its Cobj list
    chains = {}
    def fn_w(em, args):
        # deterministic per EO (no rng at run time: the exe and the port run the same handlers in their own order)
        k = em.reg('ecx') % 5
        return wpool[k] if k < len(wpool) else 0

    def fn_iter(em, args):
        p = args[0]
        cur = struct.unpack('<I', bytes(em.mu.mem_read(p, 4)))[0]
        lst = chains.get(em.reg('ecx'), [])
        nxt = 0
        if cur in lst and lst.index(cur) + 1 < len(lst):
            nxt = lst[lst.index(cur) + 1]
        em.w32(p, nxt)
        return 0

    eo_vt = _mkvt(e, 'cmd_eo', 0x240, {
        0x210: (1, None, ()),
        0x2c: (0, None, ()),
        0x100: (1, fn_w, ()),
        0xfc: (1, None, ()),
        0x74: (2, None, (0, 1)),
        0x7c: (2, None, (0, 1)),
        0x50: (1, fn_iter, (0,)),
    })
    ob_vt = _mkvt(e, 'cmd_ob', 0x180, {0x154: (0, None, ()), 0x158: (0, None, ()), 0x128: (3, None, ())})
    w_vt = _mkvt(e, 'cmd_w', 0x80, {0x54: (1, None, ())})
    o_vt = _mkvt(e, 'cmd_o', 0x40, {4: (1, None, ())})

    obs = []
    for _ in range(2):
        ob = _rnd(c, 0x40)
        e.w32(ob, ob_vt)
        e.w32(ob + 0xc, rec_ob)
        obs.append(ob)
    eos = []
    for _ in range(4):
        eo = _rnd(c, 0x40)
        e.w32(eo, eo_vt)
        cobjs = []
        for _ in range(rng.choice([0, 1, 2])):
            co = _rnd(c, 0x80)                 # +0x3c and +0x54 are used
            e.w32(co + 0x3c, (rng.getrandbits(32) | 0x800000) if rng.random() < 0.3 else (rng.getrandbits(32) & ~0x800000))
            e.w32(co + 0x54, rng.choice(obs + [0]))
            cobjs.append(co)
        chains[eo] = cobjs
        e.w32(eo + 8, cobjs[0] if cobjs else 0)
        eos.append(eo)
    for w in wpool:
        e.w32(w, w_vt)
    e.w32(o6c, o_vt)
    e.w32(o70, o_vt)

    def pick_eo(em, args):
        return eos[(args[0] + 3 * (args[1] if len(args) > 1 else 0)) % len(eos)]

    # ---- SO objects: T+0x44 (F) and the 0x8c result
    al_val = rng.choice([0, 1])
    so_vt = _mkvt(e, 'cmd_so', 0x200, {
        0x1e0: (1, lambda em, a: al_val, ()),
        0x2c4: (2, pick_eo, ()),
        0x1b8: (n1b8, pick_eo, ()),
    })
    so_a = _rnd(c, 0x40)
    e.w32(so_a, so_vt)
    e.w32(so_a + 4, rng.choice([0, 0x677b5a]))
    e.w32(so_a + 8, ab2)
    e.w32(so_a + 0xc, rec_s)
    f_obj = _rnd(c, 0x40)
    e.w32(f_obj, so_vt)
    e.w32(f_obj + 4, rng.choice([0, 0x677b5a]))
    e.w32(f_obj + 8, ab2)
    e.w32(f_obj + 0xc, rec_s)

    # ---- A (arg2): 0x20 is only reached when T+0x53 == 1
    r20 = rng.getrandbits(32)

    def fn_y(em, args):
        k = (args[0] + em.reg('ecx')) % 5
        return eos[k] if k < len(eos) else 0

    a_vt = _mkvt(e, 'cmd_a', 0x300, {
        0x2f4: (0, None, ()),
        0x30c: (1, fn_y, ()),
        0x2d8: (1, None, ()),
        0x98: (2, None, (0, 1)),
        0x20: (4, lambda em, a: r20, ()),
        0x314: (1, None, ()),
    })
    aobj = _rnd(c, 0x80)                   # fields at +0x6c and +0x70
    e.w32(aobj, a_vt)
    e.w32(aobj + 8, ab)
    e.w32(aobj + 0x6c, o6c)
    e.w32(aobj + 0x70, o70)

    # ---- T (this)
    r8c = so_a if rng.random() < 0.8 else 0
    t_vt = _mkvt(e, 'cmd_t', 0x100, {
        0x8c: (1, lambda em, a: r8c, ()),
        0x94: (1, None, ()),
    })
    this = _rnd(c, 0x200)
    e.w32(this, t_vt)
    e.wbytes(this + 0xe5, bytes([rng.choice([0, 1])]))
    e.w32(this + 0x53, t53)
    e.wbytes(this + 0x48, rng.getrandbits(16).to_bytes(2, 'little'))
    e.w32(this + 0x44, f_obj)
    if float_mode:
        x = rng.uniform(0.5, 40.0) * rng.choice([1, -1])
        e.wbytes(this + 0x5b, struct.pack('<f', x))
        e.wbytes(this + 0x52, bytes([0]))
        e.wbytes(this + 0x60, bytes([0]))
        e.wbytes(this + 0x5f, bytes([0]))
    else:
        e.wbytes(this + 0x5b, struct.pack('<f', 0.0))
        e.wbytes(this + 0x52, bytes([rng.choice([0, 1])]))
        e.wbytes(this + 0x60, bytes([rng.choice([0, 1])]))
        e.wbytes(this + 0x5f, bytes([rng.choice([0, 1])]))

    edx_in = rng.getrandbits(32)
    a1 = rng.getrandbits(32)
    return [this, edx_in, a1, aobj]


S(0x468570, 'pe_468570 (GUESS)', 'fastcall', None, ret=None, gen=_gen,
  note='batch350; ret 8; EDX is an input; helpers 0x4db2f0/0x4dc630/0x4da340/0x4db2c0 hooked')
