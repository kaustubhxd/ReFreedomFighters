"""specs_s6372.py - unclaimed-63 batch 72: 0x515790 (ZVehicle::CopyDataBlock; thiscall, one stack argument s, ret 4).
Fakes per case (hooks set in gen; the callees are other areas' code): 0x512850 (thiscall, one argument, ret 4) records ECX and the
argument; 0x4e1600 (thiscall, no arguments) returns a random byte (3 in a third of the cases, so the branch runs); 0x4e14a0 (thiscall, two
arguments, ret 8) records ECX and its arguments; 0x4e1b30 (thiscall, plain ret) records ECX. this is random bytes; s is a heap cell."""
from pilot import S


def _gen_5790(c):
    e = c.emu
    this = e.alloc(0x400, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))
    al = 3 if c.rng.random() < 1 / 3 else c.rng.choice([0, 1, 2, 4, 0xff])
    e.hook(0x512850, lambda em, a: (em.calllog.append(('h.512850', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.hook(0x4e1600, lambda em, a: (em.calllog.append(('h.4e1600', None, em.reg('ecx'), ())), em.ret(eax=al, argbytes=0)))
    e.hook(0x4e14a0, lambda em, a: (em.calllog.append(('h.4e14a0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))
    e.hook(0x4e1b30, lambda em, a: (em.calllog.append(('h.4e1b30', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x515790, 'ZVehicle::CopyDataBlock thiscall', 'thiscall', None, ret=None, gen=_gen_5790,
  note='unclaimed-63 batch 72; callees hooked (other areas)')
