"""specs_s366.py - area 76, batch 366: 0x5e1160 (thiscall, two stack arguments, ret 8, returns this; GUESS, label D).
The base constructor 0x5e0e10 is hooked (it faults on the fixture: SEH frame and its tables); the hook logs its arguments and writes nothing. The object is 0x600 random bytes; the arguments are random."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h5e0e10(em, r):
        em.calllog.append(('base5e0e10', 0x5e0e10, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    e.hook(0x5e0e10, h5e0e10)
    this = e.alloc(0x600, 4)
    e.wbytes(this, rng.randbytes(0x600))
    return [this, rng.getrandbits(32), rng.getrandbits(32)]


S(0x5e1160, 'ctor5e1160 (GUESS)', 'thiscall', None, ret='eax', gen=_gen,
  note='area 76 batch 366; label D; 0x5e0e10 hooked')
