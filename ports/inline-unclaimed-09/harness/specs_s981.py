"""specs_s981.py - area 56 band, claim A47 (0x524460).

this is a 0x40-byte object of random floats (random bytes). o is a 0x40-byte object whose first dword is a fake vtable; slot 0x4c is
a GUESS recording stub (thiscall, one argument; logs ecx and the argument bits; returns a random dword, ignored). ret='al' (always 1)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h4c(e2, r):
        e2.calllog.append(('V4c', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    vt = e.fake_vtable('vt524460', 0x80, {0x4c: h4c})
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(o, vt)
    return [this, o]


S(0x524460, 'unnamed 0x524460 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A47; vt slot 0x4c of o is a GUESS recording stub')
