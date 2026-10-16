"""specs_s365.py - area 76, batch 365: 0x5f0340 (thiscall, one stack argument, ret 4, returns this; GUESS, label D).
The argument has a fake vtable whose slot 0x14 is thiscall with one word, returns a per-run value, and logs its argument."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def h14(em, r):
        em.calllog.append(('a14', 0x14, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    vt = e.fake_vtable('arg5f0340', 0x20 // 4 * 4, {0x14: h14})
    a = e.alloc(0x40, 4)
    e.w32(a, vt)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    return [this, a]


S(0x5f0340, 'ctor5f0340 (GUESS)', 'thiscall', None, ret='eax', gen=_gen,
  note='area 76 batch 365; label D; vtable slot 0x14 of the argument stubbed')
