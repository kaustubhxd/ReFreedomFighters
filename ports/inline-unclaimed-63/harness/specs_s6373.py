"""specs_s6373.py - unclaimed-63 batch 73: 0x517630 (ZCar::CopyDataBlock; thiscall, one stack argument s, ret 4).
The base copy 0x515790 runs as the original code (verified in batch 72), so its callees are hooked here as in that batch: 0x512850
(thiscall, one argument), 0x4e1600 (thiscall, no arguments, returns a byte: 3 in a third of the cases), 0x4e14a0 (thiscall, two arguments),
and 0x4e1b30 (thiscall, plain ret). The car's own callees 0x4e11e0 and 0x4e12f0 (thiscall, two arguments, ret 8) and 0x4e1b30 are hooks
that record ECX and their arguments. this is random bytes; s is a heap cell."""
from pilot import S


def _gen_7630(c):
    e = c.emu
    this = e.alloc(0x1800, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x1800)))
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))
    al = 3 if c.rng.random() < 1 / 3 else c.rng.choice([0, 1, 2, 4, 0xff])
    e.hook(0x512850, lambda em, a: (em.calllog.append(('h.512850', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.hook(0x4e1600, lambda em, a: (em.calllog.append(('h.4e1600', None, em.reg('ecx'), ())), em.ret(eax=al, argbytes=0)))
    e.hook(0x4e14a0, lambda em, a: (em.calllog.append(('h.4e14a0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))
    e.hook(0x4e11e0, lambda em, a: (em.calllog.append(('h.4e11e0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))
    e.hook(0x4e12f0, lambda em, a: (em.calllog.append(('h.4e12f0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))
    e.hook(0x4e1b30, lambda em, a: (em.calllog.append(('h.4e1b30', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x517630, 'ZCar::CopyDataBlock thiscall', 'thiscall', None, ret=None, gen=_gen_7630,
  note='unclaimed-63 batch 73; base copy 0x515790 runs as original; callees hooked')
