"""specs_s987.py - area 56 band, claim A53 (0x52cec0): a constructor with one virtual call on the global.

this is a 0x40-byte object of random bytes. a and b are random. The global at 0x70039c points to a fake object g (0x100 random bytes)
whose vtable slot 0x1c8 is a GUESS recording stub (thiscall, two arguments; returns a random dword). ret='eax' (returns this)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h1c8(e2, r):
        e2.calllog.append(('V1c8', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=rng.getrandbits(32), argbytes=8)

    vt = e.fake_vtable('vt52cec0', 0x200, {0x1c8: h1c8})
    g = e.alloc(0x100, 4)
    e.wbytes(g, bytes(rng.getrandbits(8) for _ in range(0x100)))
    e.w32(g, vt)
    e.w32(0x70039c, g)
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    return [this, rng.getrandbits(32), rng.getrandbits(32)]


S(0x52cec0, 'unnamed 0x52cec0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A53; vt slot 0x1c8 of the global object is a GUESS recording stub')
