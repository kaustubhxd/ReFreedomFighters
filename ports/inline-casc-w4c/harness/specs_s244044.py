"""specs_s244044.py - hand-written specs for batch 244044."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g5390d0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 0.5, 1.0, -1.0, 2.0, 100.0, 0.25, 4.0, 5.0, 0.0]
    NZ = [0.0, 0.5, 1.0, 2.0, 5.0, 4.0, 3.0, 6.0]

    def lg(nm, *idx):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx))
    # --- the engine object tables
    def s80(emu, k):
        emu.calllog.append(('s80', emu.reg('ecx')))
        emu.wbytes(emu.arg32(0), b''.join(pk(r.choice(FV)) for _ in range(9)))
        emu.wbytes(emu.arg32(1), b''.join(pk(r.choice(FV)) for _ in range(3)))
    Os = [obj(c, 0x80, {0x80: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(0, 1), side=s80)}) for _ in range(3)]
    gt = [0]

    def r58(emu, k):
        return r.choice(Os)
    # entities (slot 0x60 of H): fields as the state machine needs
    tie = r.random() < 0.35   # all entities share one time stamp V, offset 0 and G[0x1c] = V: the `time < stamp` compare ties exactly
    V = r.choice([5, 100, 1000, 2000])
    Es = []
    for _ in range(4):
        e = rnd(c, 0x100)
        em.w32(e + 4, r.choice([0, 1, 2, 5, 10, 0xb, 3]))
        em.w32(e + 8, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12]))
        em.w32(e + 0xc, r.choice([0, 1, 2, 3, 4, 5]))
        em.w32(e + 0x40, r.choice([0, 8, 0x10, 0x40, 0x48, 0x58, r.getrandbits(8)]))
        em.w32(e + 0x6c, V if tie else r.choice([0, 5, 100, 1000, 2000]))
        em.w32(e + 0x7c, r.choice([0, 1, 0x1234]))
        em.w32(e + 0x8c, r.getrandbits(32))
        em.w32(e + 0xd0, 0 if tie else r.choice([0, 7, 0x80000000, 1000]))
        em.wbytes(e + 0xd4, b''.join(pk(r.choice(FV)) for _ in range(3)))
        Es.append(e)

    def r60(emu, k):
        return 0 if r.random() < 0.1 else r.choice(Es)
    H = obj(c, 0x40, {0x58: pystub(c, 1, ret=r58, pop=4, this=True, side=lg('h58', 0)),
                      0x60: pystub(c, 1, ret=r60, pop=4, this=True, side=lg('h60', 0))})
    G = rnd(c, 0x2000)
    em.w32(G + 0x9b, H)
    em.w32(G + 0x1c, V if tie else r.choice([0, 500, 1000, 1500, 3000]))
    em.w32(0x70039c, G)
    # --- this
    st = {'n': 0, 'i': 0}
    tv = {0x40: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lg('t40', 0)),
          0x1dc: pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 1, 1, 0x100]), pop=4, this=True, side=lg('t1dc', 0))}
    me = obj(c, 0x5400, tv)
    for i in range(4):
        em.wbytes(me + 0x15 + 0xd * i, bytes([r.choice([0, 1, 1])]))
        em.w32(me + 0x1e + 0xd * i, r.getrandbits(32))
        em.w32(me + 0x1a + 0xd * i, r.getrandbits(32))
    em.wbytes(me + 0x50a9, bytes([r.choice([0, 1, 1])]))
    em.w32(me + 0x52fe, 0 if r.random() < 0.5 else rnd(c, 0x20))
    # --- iterator container a1 (slots 0x4c begin, 0x5c next(&more)), and two actor objects a0 / a2 (slots 4 and 0x98)
    def s4c(emu, k):
        emu.calllog.append(('i4c',))
        st['i'] = 0
        st['n'] = r.choice([0, 1, 2, 3])

    def s5c(emu, k):
        j = st['i']
        st['i'] += 1
        on = j < st['n']
        emu.w32(emu.arg32(0), 1 if on else 0)
        emu.calllog.append(('i5c', j, on))
    cont = obj(c, 0x80, {0x4c: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s4c),
                         0x5c: pystub(c, 1, ret=lambda emu, k: 0x1000 + st['i'], pop=4, this=True, stackmark=(0,), side=s5c)})

    def actor():
        return obj(c, 0x80, {0x4: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, side=lg('a4', 0)),
                             0x98: pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, side=lg('a98', 0, 1, 2))})
    a0 = actor()
    a2 = actor()
    # --- hooks for the exe helpers (float returns in st0)
    stf = lambda emu, k: r.choice(NZ)
    hook_rec(c, 0x4e0830, 0, ret=0, pop=0, this='mark', st0=stf, side=lambda emu, k: emu.calllog.append(('e830', bytes(emu.rbytes(emu.reg('ecx'), 12)), emu.reg('edx') if False else 0)))
    hook_rec(c, 0x4e0870, 0, ret=0, pop=0, this='mark', st0=stf, side=lambda emu, k: emu.calllog.append(('e870', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12)))))
    hook_rec(c, 0x43e960, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('e960', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12)))), emu.wbytes(emu.reg('edx'), b''.join(pk(r.choice(FV)) for _ in range(3)))))
    hook_rec(c, 0x441a60, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('a60', bytes(emu.rbytes(emu.reg('edx'), 12)))), emu.wbytes(emu.reg('ecx'), b''.join(pk(r.choice(FV)) for _ in range(3)))))
    hook_rec(c, 0x43e920, 1, ret=0, pop=4, this='mark', stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('e920', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12)))), emu.wbytes(emu.reg('ecx'), b''.join(pk(r.choice(FV)) for _ in range(3)))))
    hook_rec(c, 0x4de7a0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('e7a0',)))
    hook_rec(c, 0x53b6d0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('b6d0',)))
    return [me, cont, a0, a2]


S(0x5390d0, 'GUESS entity state machine tick: classifies pickable entities by type and hit test and steps their state', 'thiscall', 3, ret='al', gen=g5390d0, note='batch244044')
