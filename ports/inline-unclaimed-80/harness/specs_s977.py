"""specs_s977.py - unclaimed-80 residue-19 batch 55 (docs/20-unclaimed-80.md), see src/batch977.cpp. Both callees are GUESS (no claim), hooked by address
with recording thiscall stubs: 0x575800 (no arguments, returns al per case) and 0x574250 (one argument, returns a per-case eax). The flag byte at
self+0x216 is set half the time; the argument is 1 half the time (else random)."""
from pilot import S


def _gen(c):
    r800 = 1 if c.rng.random() < 0.6 else 0
    r250 = c.rng.getrandbits(32)

    def h800(em, r):
        c.emu.calllog.append(('575800', None, em.reg('ecx'), ()))
        em.ret(eax=r800, argbytes=0)

    def h250(em, r):
        c.emu.calllog.append(('574250', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=r250, argbytes=4)

    c.emu.hook(0x575800, h800)
    c.emu.hook(0x574250, h250)
    self_o = c.emu.alloc(0x240, 4)
    c.emu.wbytes(self_o, bytes(0x240))
    c.emu.wbytes(self_o + 0x216, bytes([c.rng.randint(0, 1)]))
    a = 1 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [self_o, a]


S(0x575930, 'flag then GUESS helper or forward (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 residue-19; GUESS helpers 0x575800 and 0x574250 hooked by address; one stack argument, ret 4')
