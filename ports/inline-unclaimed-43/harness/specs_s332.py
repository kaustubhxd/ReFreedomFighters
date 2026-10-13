"""specs_s332.py - area 71 batch 332: scalar deleting destructor (0x4e5020), thiscall, one stack argument (flags), ret 4.
Stores vtable 0x697360 at [this]; if flags bit 0 is set, __builtin_delete(this, 4) (hooked and logged)."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('builtin_delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    flags = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, flags]


S(0x4e5020, 'scalar deleting destructor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_hook,
  note='area 71 batch 332 (leaf, residue 10); __builtin_delete hooked')
