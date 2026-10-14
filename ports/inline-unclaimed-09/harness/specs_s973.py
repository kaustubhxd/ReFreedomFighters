"""specs_s973.py - area 56 band, claim A39 (0x533d60).

this is a 0x40-byte object of random bytes. [this] is a fake object (its first dword a fake vtable with slot 0 a GUESS recording
stub, thiscall, one argument) in about 4 cases in 5, else null. [this+4] and [this+8] are random heap pointers or null. 0x634273 is
hooked (recording, plain ret). ret=None (void)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def hv(e2, r):
        e2.calllog.append(('V0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def hfree(e2, r):
        e2.calllog.append(('Free634273', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=0)

    e.hook(0x634273, hfree)
    vt = e.fake_vtable('vt533d60', 0x40, {0: hv})
    p = 0
    if rng.random() < 0.8:
        p = e.alloc(0x40, 4)
        e.wbytes(p, bytes(rng.getrandbits(8) for _ in range(0x40)))
        e.w32(p, vt)
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(this, p)
    for off in (4, 8):
        q = 0 if rng.random() < 0.3 else e.alloc(0x20, 4)
        e.w32(this + off, q)
    return [this]


S(0x533d60, 'unnamed 0x533d60 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A39; vt slot 0 is a GUESS recording stub; 0x634273 hooked')
