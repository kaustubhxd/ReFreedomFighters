"""specs_s244037.py - hand-written specs for batch 244037."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g60f340(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda v: struct.pack('<f', v)

    def lg(nm, n):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(n)))
    ints = lambda emu, k: r.choice([0, 1, 16, 480, 640, 0x7fffffff])

    def s25c(emu, k):
        sp = emu.arg32(1)
        verts = b''.join(bytes(emu.rbytes(sp + 0x24 * v + o, 4)) for v in range(4) for o in (0, 4, 8, 0x18))
        idx = bytes(emu.rbytes(emu.arg32(3), 8))
        emu.calllog.append(('s25c', emu.arg32(0), emu.arg32(2), emu.arg32(4), verts, idx))
    me = obj(c, 0x200, {0x24: pystub(c, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff]), pop=0, this=True, side=lg('t24', 0)),
                        0x140: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t140', 0)),
                        0xd8: pystub(c, 0, ret=ints, pop=0, this=True, side=lg('td8', 0)),
                        0xdc: pystub(c, 0, ret=ints, pop=0, this=True, side=lg('tdc', 0)),
                        0x134: pystub(c, 4, ret=r.getrandbits(32), pop=16, this=True, side=lambda emu, k: emu.calllog.append(('t134', emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3)))),
                        0x28c: pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, side=lg('t28c', 3)),
                        0x14c: pystub(c, 7, ret=r.getrandbits(32), pop=28, this=True, side=lg('t14c', 7)),
                        0x25c: pystub(c, 5, ret=r.getrandbits(32), pop=20, this=True, stackmark=(1, 3), side=s25c),
                        0x28: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t28', 0)),
                        0x50: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t50', 0))})
    # render-state cache globals and the device wrapper
    Dev = obj(c, 0x40, {0xc8: pystub(c, 3, ret=r.getrandbits(32), pop=12, side=lambda emu, k: emu.calllog.append(('dev', emu.arg32(0), emu.arg32(1), emu.arg32(2))))})
    em.w32(0x724a00, Dev)
    em.w32(0x724a08, r.choice([0, 1, 2, 3]))
    for addr, want in ((0x724928, 5), (0x72492c, 6), (0x724934, 1), (0x72493c, 0), (0x724968, 8), (0x724930, 0), (0x724948, 0), (0x724940, 0)):
        em.w32(addr, want if r.random() < 0.5 else r.choice([0, 1, 2, 5, 6, 8, 99]))
    G = rnd(c, 0x1000)
    for off in (0x9a7, 0x9ab, 0x9af, 0x9b3):
        em.wbytes(G + off, pk(r.choice([0.0, 1.0, 2.0, 0.5, 100.0, -3.0, r.uniform(-9, 9)])))
    em.w32(0x70039c, G)
    thr = struct.unpack('<d', bytes(em.rbytes(0x6a3148, 8)))[0]
    a0 = r.choice([-1.0, 0.0, 0.25, 0.5, 1.0, 1.5, 2.0, 0.9999, 1e-3])
    x2 = f32(min(1.0, a0)) if a0 > 0 else 0.0
    if a0 == 0.0:
        x2 = 0.0
    delta = r.choice([0.0, thr / 2, thr, thr * 2, 1.0, -thr / 2, -thr, 0.3])
    em.wbytes(0x724b44, pk(f32(x2 + delta)))
    hook_rec(c, 0x610070, 1, ret=r.getrandbits(32), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('h070', emu.arg32(0))))
    for ad in (0x60ff30, 0x60feb0):
        hook_rec(c, ad, 2, ret=r.getrandbits(32), pop=8, this=True, side=lambda emu, k, ad=ad: emu.calllog.append((hex(ad), emu.reg('edx'), emu.arg32(0), emu.arg32(1))))
    for addr in (0x6efcd0, 0x6efcd4, 0x6efcd8, 0x6efcdc):   # channel shift counts (exe .data): vary them or `>>` / `<<` mutants are indistinguishable
        em.w32(addr, r.choice([0, 8, 16, 24, 5, 31]))
    color1 = r.getrandbits(32)
    color2 = r.getrandbits(32)
    return [me, F(a0), color1, color2]


S(0x60f340, 'GUESS fullscreen fade quad: sets render state and draws a coloured quad', 'thiscall', 3, ret=None, gen=g60f340, note='batch244037')
