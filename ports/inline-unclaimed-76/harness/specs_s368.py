"""specs_s368.py - area 76, batch 368: three constructors (thiscall, two stack arguments, ret 8, return this; GUESS, label D):
0x5e11c0, 0x5e1200, 0x5e10a0. The base constructor 0x5e0e10 is hooked by address (logs its arguments, pops 8; it faults on the
fixture). The object is 0x600 random bytes, the arguments are random."""
from pilot import S


def _gen_factory():
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
    return _gen


S(0x5e11c0, 'ctor5e11c0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_factory(),
  note='area 76 batch 368; label D; 0x5e0e10 hooked')
S(0x5e1200, 'ctor5e1200 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_factory(),
  note='area 76 batch 368; label D; 0x5e0e10 hooked')
S(0x5e10a0, 'ctor5e10a0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_factory(),
  note='area 76 batch 368; label D; 0x5e0e10 hooked')
