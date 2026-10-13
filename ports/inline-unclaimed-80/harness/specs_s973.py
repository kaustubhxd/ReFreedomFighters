"""specs_s973.py - unclaimed-80 residue-19 (docs/20-unclaimed-80.md): ten 6-byte wrappers `call 0x634d1c; ret` (src/batch973.cpp). The IAT
thunk 0x634d1c (claimed in docs/20-unclaimed-69.md) is hooked by address with a recording cdecl stub that logs its (zero) arguments and
returns 0. The wrappers take no arguments."""
from pilot import S


def _gen(c):
    def h(em, r):
        c.emu.calllog.append(('634d1c', None, None, ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x634d1c, h)
    return []

S(0x665076, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66b0b4, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66b0ba, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66b47c, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66d3b0, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66d3b6, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66d3bc, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66def0, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66def6, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
S(0x66defc, 'call-and-return wrapper over 0x634d1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='residue-19 six-byte wrapper; callee 0x634d1c hooked (IAT thunk, claimed elsewhere)')
