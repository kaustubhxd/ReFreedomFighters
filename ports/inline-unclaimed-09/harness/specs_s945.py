"""specs_s945.py - area 56 residue 15, claim A4: ZItemAmmo::CopyDataBlock(DBLK*) (0x46cdf0).

Object: 0x100 random bytes (the fields used are at +0x60 and +0x8e). Block d: 0x40 random bytes. The callees are GUESS
recording stubs (unverified): 0x43f900 (thiscall, one argument), 0x4e12e0 and 0x4e11e0 (thiscall, two arguments), 0x4e1b30
(thiscall, no arguments); each logs its object and its arguments and returns with the matching ret."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    def h43f9(e2, r):
        e2.calllog.append(('E43f900', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h12e0(e2, r):
        e2.calllog.append(('E4e12e0', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    def h1b30(e2, r):
        e2.calllog.append(('E4e1b30', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def h11e0(e2, r):
        e2.calllog.append(('E4e11e0', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    c.emu.hook(0x43f900, h43f9)
    c.emu.hook(0x4e12e0, h12e0)
    c.emu.hook(0x4e1b30, h1b30)
    c.emu.hook(0x4e11e0, h11e0)
    return [_rnd(c, 0x100), _rnd(c, 0x40)]


S(0x46cdf0, 'ZItemAmmo::CopyDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A4; helper calls are GUESS recording stubs (unverified)')
