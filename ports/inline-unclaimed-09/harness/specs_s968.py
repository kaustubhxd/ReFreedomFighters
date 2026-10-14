"""specs_s968.py - area 56 band, claim A33 (0x534d00).

this is a 0x40-byte object of random bytes; flags is random (the low bit set in about half the cases). 0x534be0 and 0x634273 are
hooked (recording, plain ret). ret='eax' (returns this)."""
from pilot import S


def _gen(c):
    def h(e2, r):
        e2.calllog.append(('H534be0', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def hfree(e2, r):
        e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=0)

    c.emu.hook(0x534be0, h)
    c.emu.hook(0x634273, hfree)
    a = c.emu.alloc(0x40, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [a, c.rng.getrandbits(32)]


S(0x534d00, 'unnamed 0x534d00 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A33; 0x534be0 and 0x634273 hooked (GUESS stubs)')
