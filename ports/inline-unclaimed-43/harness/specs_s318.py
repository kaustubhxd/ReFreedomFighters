"""specs_s318.py - unclaimed-43 batch 318: scalar deleting destructor (0x5422e0), thiscall, one stack argument (flags), ret 4.
The vtable store at [this] is compared in the heap. The delete (0x634273, __builtin_delete) is hooked and logged; the
exe pushes two words (pointer, 4) and pops them itself (cdecl)."""
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


S(0x5422e0, 'scalar deleting destructor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_hook,
  note='unclaimed-43 batch 318 (leaf); __builtin_delete hooked')
