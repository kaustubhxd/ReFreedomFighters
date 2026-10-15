"""specs_s977.py - area 56 band, claim A43 (0x524780).

this is a 0x40-byte object of random bytes. o is a 0x40-byte object whose first dword is a fake vtable; slot 0x50 is a GUESS
recording stub (thiscall, one argument; logs ecx and the argument; returns a random dword, ignored). ret='al' (always 1)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h50(e2, r):
        e2.calllog.append(('V50', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rng.getrandbits(32), argbytes=4)

    vt = e.fake_vtable('vt524780', 0x80, {0x50: h50})
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(o, vt)
    return [this, o]


S(0x524780, 'unnamed 0x524780 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A43; vt slot 0x50 of o is a GUESS recording stub')
