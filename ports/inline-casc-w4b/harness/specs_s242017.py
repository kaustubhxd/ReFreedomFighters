"""specs_s242017.py - hand spec for 0x457960 (Sonnet-w4b)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _u2f(u):
    return struct.unpack('<f', struct.pack('<I', u))[0]


def g457960(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fv = lambda: _f2u(r.choice([0.0, 0.0, 0.5, 1.0, 2.0, -1.0, -2.0, 3.0, 0.25, -0.5, 7.0]))
    K1 = _u2f(em.r32(0x680a84))
    cnt = r.choice([0, 1, 2, 3, 5, 8, 8, 2, 4])

    def s451fc0(emu, k):
        a, b = emu.arg32(0), emu.arg32(2)
        emu.calllog.append(('h451fc0', emu.reg('ecx'), emu.arg32(1), emu.arg32(3), emu.arg32(4)))
        for j in range(72): emu.w32(a + 4 * j, fv())
        pick = r.random()
        emu.w32(b, emu.r32(0x6785d0) if pick < 0.4 else (_f2u(r.choice([0.0, 1.0, -3.5])) if pick < 0.8 else r.getrandbits(32)))
    hook_rec(c, 0x451fc0, 5, ret=cnt, this=True, nullflag=(0, 2), side=s451fc0)

    def mk(addr, nstack, wr=0, rd_e=0, rd_d=0, derefs=None, zp=0.0):
        def side(emu, k):
            e, d = emu.reg('ecx'), emu.reg('edx')
            emu.calllog.append(('h%x' % addr,) + tuple(emu.r32(e + 4 * j) for j in range(rd_e)) + tuple(emu.r32(d + 4 * j) for j in range(rd_d)))
            z = r.random() < zp
            for j in range(wr): emu.w32(e + 4 * j, 0 if z else fv())
        hook_rec(c, addr, nstack, ret=R, deref=derefs, side=side)
    mk(0x43e920, 1, wr=3, rd_d=3, derefs={0: 3})
    mk(0x446ee0, 1, wr=3, rd_d=3, derefs={0: 3}, zp=0.3)
    mk(0x441940, 0, wr=3, rd_e=3, rd_d=3, zp=0.3)

    def fl2(emu, k):
        t = r.random()
        if t < 0.25: return float(K1) * float(K1)          # exact tie with the K1 threshold after the sqrt
        return r.choice([0.0, 0.01, 0.25, 1.0, 4.0, 400.0, -1.0, 2.0, K1 * K1 * 4, 100.0, 9.0])
    hook_rec(c, 0x4e2220, 3, ret=R, st0=fl2, nullflag=(0, 1, 2), side=lambda emu, k: emu.calllog.append(
        ('e2220', emu.reg('ecx'), emu.r32(emu.reg('edx')), emu.r32(emu.reg('edx') + 4), emu.r32(emu.reg('edx') + 8)) +
        tuple(emu.r32(emu.arg32(i) + 4 * j) for i in (0, 1, 2) for j in range(3))))
    THIS = rnd(c, 0x40)
    A0 = rnd(c, 0x40)
    vec = em.alloc(0x10, 4)
    for j in range(3): em.w32(vec + 4 * j, fv())
    return [THIS, A0, vec]


S(0x457960, 'GUESS contact clearance query', 'thiscall', None, ret='st0', gen=g457960, note='batch242017')
