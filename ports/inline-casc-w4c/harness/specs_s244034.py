"""specs_s244034.py - hand-written specs for batch 244034."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g4ec040(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 0.0, 1.0, -1.0, 0.5, -0.5, 2.0]
    if r.random() < 0.4:
        FV = [0.0, 1.0, -1.0, 0.5, -0.5, 2.0, 3.0, r.uniform(-3, 3), 1e-4]

    def v3():
        return b''.join(pk(r.choice(FV)) for _ in range(3))

    def lg(nm, n=0):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(n)))
    count = r.choice([0, 1, 2, 3, 4])
    # objects in a1 (slot 0x8c fills a vec3 at its arg)
    def s8c(emu, k):
        emu.calllog.append(('s8c', emu.reg('ecx'), bytes(emu.rbytes(emu.arg32(0) + 4, 8))))   # the vec copied from a7 sits right behind the output vec
        emu.wbytes(emu.arg32(0), v3())
    O = [obj(c, 0x80, {0x8c: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s8c)}) for _ in range(count)]
    a1 = rnd(c, 0x40)
    for i, o in enumerate(O):
        em.w32(a1 + 4 * i, o)
    # entity list a4: pointers P_k, terminated by 0; a2[i] = start index
    nP = r.choice([1, 2, 3])
    state = {'items': [], 'idx': 0}
    Hobjs = []
    for _ in range(3):
        Hobjs.append(obj(c, 0x40, {0x20: pystub(c, 0, ret=lambda emu, k: (r.choice(O) if O else 0), pop=0, this=True, side=lg('h20'))}))
    H = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, k: r.choice(Hobjs), pop=4, this=True, side=lg('h58', 1))})
    G = rnd(c, 0x200)
    em.w32(G + 0x9b, H)
    em.w32(0x70039c, G)

    def s4c(emu, k):
        emu.calllog.append(('e4c',))
        state['idx'] = 0
        state['n'] = r.choice([0, 1, 2, 3])

    def s5c(emu, k):
        buf = emu.arg32(0)
        j = state['idx']
        state['idx'] += 1
        on = j < state['n']
        emu.w32(buf, 1 if on else 0)
        state['ret'] = r.getrandbits(32) if on else 0
        emu.calllog.append(('e5c', j, on))
    E1s = [obj(c, 0x80, {0x4c: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s4c),
                         0x5c: pystub(c, 1, ret=lambda emu, k: state['ret'], pop=4, this=True, stackmark=(0,), side=s5c)}) for _ in range(2)]
    D = rnd(c, 0x80)
    flagr = lambda emu, k: r.choice([0, 1, 0x100, 0x1ff])
    Ps = []
    for _ in range(nP):
        q = obj(c, 0x100, {0x234: pystub(c, 0, ret=flagr, pop=0, this=True, side=lg('q234')),
                           0x230: pystub(c, 0, ret=lambda emu, k: 0 if r.random() < 0.2 else r.choice(E1s), pop=0, this=True, side=lg('q230')),
                           0x244: pystub(c, 0, ret=D, pop=0, this=True, side=lg('q244'))})
        p = rnd(c, 0x80)
        em.w32(p + 0x54, q)
        em.wbytes(p + 0x24, v3() + v3())
        em.wbytes(p + 0x4c, pk(r.choice([0.0, 1.0, 0.5, 2.0])))
        Ps.append(p)
    a4 = rnd(c, 0x40)
    for i, p in enumerate(Ps):
        em.w32(a4 + 4 * i, p)
    em.w32(a4 + 4 * nP, 0)
    a2 = rnd(c, 0x40)   # unused
    a6 = rnd(c, 0x40)   # index array (ebp+0x20): a6[i] = start index into the entity list a4
    for i in range(count):
        em.w32(a6 + 4 * i, r.randrange(0, nP))
    a0 = rnd(c, 0x40)
    a5 = 0 if r.random() < 0.5 else rnd(c, 0x40)
    if a5:
        em.wbytes(a5, bytes(0x40))
    a7 = rnd(c, 0x20)
    em.wbytes(a7, v3())
    # helper hooks writing a vec3 at ecx
    for ad, nst in ((0x43e920, 1), (0x446ee0, 1)):
        hook_rec(c, ad, nst, ret=r.getrandbits(32), pop=4 * nst, this='mark', stackmark=(0,), side=lambda emu, k, ad=ad: (emu.calllog.append((hex(ad), emu.reg('edx') if 0x20000000 <= emu.reg('edx') < 0x30000000 else 0)), emu.wbytes(emu.reg('ecx'), v3())))
    hook_rec(c, 0x441a60, 0, ret=r.getrandbits(32), pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('a60',)), emu.wbytes(emu.reg('ecx'), v3())))
    hook_rec(c, 0x4e0d00, 1, ret=r.getrandbits(32), pop=4, this='mark', side=lambda emu, k: (emu.calllog.append(('d00', emu.arg32(0))), emu.wbytes(emu.reg('ecx'), v3())))
    return [a0, a1, a2, count, a4, a5, a6, a7]


S(0x4ec040, 'GUESS ray vs entity list: sorts the hit entities of a ray to the front of the result arrays', 'stdcall', 8, ret=None, gen=g4ec040, note='batch244034')
