"""specs_s967.py - area 56 band, claims A31-A32 (0x533d20, 0x534d30).

A31: this is a 0x1100-byte object of random bytes; 0x534190 is hooked (recording, plain ret). A32: this is a 0x40-byte object of
random bytes, flags is random (the low bit set in about half the cases); 0x4e66a0 and 0x634273 are hooked (recording, plain ret).
ret='eax' (both return this)."""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_a31(c):
    def h(e2, r):
        e2.calllog.append(('H534190', e2.reg('ecx')))
        e2.ret(argbytes=0)
    c.emu.hook(0x534190, h)
    return [_rnd(c, 0x1100)]


def _gen_a32(c):
    def h66(e2, r):
        e2.calllog.append(('H4e66a0', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def hfree(e2, r):
        e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=0)

    c.emu.hook(0x4e66a0, h66)
    c.emu.hook(0x634273, hfree)
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


S(0x533d20, 'unnamed 0x533d20 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_a31,
  note='unclaimed-56 A31; 0x534190 hooked (GUESS stub)')
S(0x534d30, 'unnamed 0x534d30 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_a32,
  note='unclaimed-56 A32; 0x4e66a0 and 0x634273 hooked (GUESS stubs)')
