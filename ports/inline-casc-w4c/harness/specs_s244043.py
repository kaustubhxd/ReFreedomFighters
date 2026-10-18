"""specs_s244043.py - hand-written specs for batch 244043."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import pe_emu


def g4f3390(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)

    def sehlog(emu):
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1, emu.r32(a + 4) if a != 0xffffffff else -1))

    def cs(emu, p, n=0x100):
        out = b''
        while p and len(out) < n:
            ch = bytes(emu.rbytes(p + len(out), 1))
            if ch == b'\0':
                break
            out += ch
        return out

    def lg(nm, *idx):
        return lambda emu, k: (emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx)), sehlog(emu))
    W, Hh = r.choice([640, 800, 128, 256, 128]), r.choice([480, 600, 128, 256, 128])
    cur = [r.choice([-5.0, -1.0, 0.0, 1.0, 10.0, 50.0, W / 2.0, W - 1.0, float(W), W + 1.0, W + 5.0, 99.0]),
           r.choice([-5.0, -1.0, 0.0, 1.0, 10.0, 50.0, Hh / 2.0, Hh - 1.0, float(Hh), Hh + 1.0, Hh + 5.0, 99.0])]
    clamp = [min(max(cur[0], 0.0), float(W)), min(max(cur[1], 0.0), float(Hh))]
    nz = {'dx': r.choice([0.0, 0.25, 0.5, 1.0, 0.125])}
    FV = [0.0, 0.25, 0.5, 1.0, 0.1, 2.0, -1.0, 100.0]
    # --- text object (slot 0x184, cdecl 4 args) behind [G] slot 0x190
    TX = obj(c, 0x200, {0x184: pystub(c, 4, ret=r.getrandbits(32), pop=0, side=lg('print', 1, 2, 3))})
    Gv = obj(c, 0x200, {0x190: pystub(c, 0, ret=TX, pop=0, this=True, side=lg('g190'))})
    # --- object returned by H slot 0x58 (id): slot 0x240(&out vec4) and 0x1d8 etc.
    def s240(emu, k):
        emu.calllog.append(('o240', emu.reg('ecx')))
        if r.random() < 0.7:   # a box (x, y, w, h as screen fractions) around the clamped cursor, with exact edge ties
            fx, fy = clamp[0] / W, clamp[1] / Hh
            ex, ey = r.choice([0.0, 0.0, 0.125, 0.5]), r.choice([0.0, 0.0, 0.125, 0.5])
            bx = fx - r.choice([0.0, 0.0, 0.125]); by = fy - r.choice([0.0, 0.0, 0.125])
            emu.wbytes(emu.arg32(0), pk(bx) + pk(by) + pk(bx * 0 + (fx - bx) + ex) + pk((fy - by) + ey))
        else:
            emu.wbytes(emu.arg32(0), b''.join(pk(r.choice(FV)) for _ in range(4)))
    nstr = em.alloc(0x40, 4)
    em.wbytes(nstr, r.choice([b'dir/name', b'plain', b'', b'a/b/c.tex']) + b'\0')

    def s1d8(emu, k):
        emu.calllog.append(('o1d8', emu.reg('ecx'), emu.arg32(1)))
        emu.w32(emu.arg32(0), 0)
        sehlog(emu)
    ob_slots = {0x70: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('o70', bytes(emu.rbytes(emu.arg32(0), 12)))))),
                0x240: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s240),
                0x1d8: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(0,), side=s1d8),
                0x24c: pystub(c, 0, ret=lambda emu, k: st['cam'], pop=0, this=True, side=lg('o24c')),
                0x80: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(0, 1), side=lambda emu, k: (emu.calllog.append(('o80',)), emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(0x40))))),
                0x2cc: pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, stackmark=(0, 1, 2), side=None)}
    st = {'cam': 0}
    Obs = [obj(c, 0x100, ob_slots) for _ in range(2)]
    camvt = {0x94: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(0, 1), side=lg('c94')),
             0x2cc: pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, stackmark=(0, 1, 2), side=lambda emu, k: (emu.calllog.append(('c2cc',)), emu.w32(emu.arg32(0), r.choice([0, 0, 0x5000, 0x5100])), sehlog(emu)))}
    cam = obj(c, 0x100, camvt)
    st['cam'] = cam
    nul = r.random() < 0.2   # first lookup (the cursor object) sometimes null
    cnt58 = [0]

    def r58(emu, k):
        cnt58[0] += 1
        return 0 if (nul and cnt58[0] == 1) else r.choice(Obs)
    hoh = obj(c, 0x40, {0x58: pystub(c, 1, ret=r58, pop=4, this=True, side=lg('h58', 0))})
    G = rnd(c, 0x2000)
    em.w32(G, em.r32(Gv))
    em.w32(G + 0x6f, W)
    em.w32(G + 0x73, Hh)
    em.w32(G + 0x9b, hoh)
    em.w32(0x70039c, G)
    # --- this (esi): [esi+0x1a7] is an embedded list object with slots 0x54 / 0x6c
    state = {'n': 0}

    def s54(emu, k):
        emu.calllog.append(('l54', emu.arg32(0) if emu.arg32(0) < 1 else 'stk'))
        state['i'] = 0
        state['n'] = r.choice([0, 1, 2, 3])

    def s6c(emu, k):
        j = state['i']
        state['i'] += 1
        on = j < state['n']
        emu.w32(emu.arg32(0), 1 if on else 0)
        emu.calllog.append(('l6c', j, on))
    me = rnd(c, 0x400)
    lvt = em.alloc(0x100, 4)
    em.w32(lvt + 0x54, pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s54))
    em.w32(lvt + 0x6c, pystub(c, 1, ret=lambda emu, k: 0x40 + 4 * state['i'], pop=4, this=True, stackmark=(0,), side=s6c))
    em.w32(me + 0x1a7, lvt)
    em.wbytes(me + 0x8f, pk(clamp[0] if r.random() < 0.4 else r.choice(FV))); em.wbytes(me + 0x93, pk(clamp[1] if r.random() < 0.4 else r.choice(FV)))
    em.w32(me + 0x73, r.choice([0, 1, 7]))
    # --- hooks
    hook_rec(c, 0x4db7c0, 1, ret=0, pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('b7c0',)), (emu.wbytes(emu.arg32(0), b''.join(pk(r.choice(FV)) for _ in range(3))) if r.random() < 0.7 else None)))
    hook_rec(c, 0x4e09b0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('e09b0',)))
    hook_rec(c, 0x4e0010, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('e0010', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 8)))), emu.wbytes(emu.reg('edx'), pk(r.choice(FV)))))
    hook_rec(c, 0x4de7a0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('e7a0',)))
    pc = em.alloc(0x40, 4)
    em.wbytes(pc, r.choice([b'dir/name', b'plain']) + b'\0')
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: pc, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('cstr',)), sehlog(emu)))
    hook_rec(c, 0x4cbec0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('dtor',)), sehlog(emu)))

    def strrchr(emu, k):
        b = cs(emu, emu.arg32(0))
        i = b.rfind(bytes([emu.arg32(1) & 0xff]))
        emu.calllog.append(('strrchr', b))
        st['rch'] = 0 if i < 0 else emu.arg32(0) + i
    em.w32(0x676258, pystub(c, 2, ret=lambda emu, k: st['rch'], pop=0, stackmark=(0,), side=strrchr))
    import math

    def floor_h(e, rr):   # CRT floor (x87 convention: double on the stack, result in st0); results here are small integers, exact in single precision
        d = struct.unpack('<d', bytes(e.rbytes(e.reg('esp') + 4, 8)))[0]
        e.calllog.append(('floor', d if d == d else 'nan'))
        v = math.floor(d) if d == d and abs(d) < 1e9 else 0
        e.ret(st0=float(v), argbytes=0)
    em.stub_import('floor', floor_h)
    # --- argument: pointer to a pair of floats (x, y)
    a0 = rnd(c, 0x20)
    em.wbytes(a0, pk(cur[0]) + pk(cur[1]))
    return [me, a0]


S(0x4f3390, 'GUESS mouse pick: clamps the cursor to the screen, prints debug text, walks pickable objects under the cursor', 'thiscall', 1, ret='eax', gen=g4f3390, note='batch244043')
