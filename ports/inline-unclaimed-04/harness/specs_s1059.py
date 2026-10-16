"""specs_s1059.py - unclaimed-04 batch 59 (docs/20-unclaimed-04.md): five cdecl wrappers calling helper 0x634d1c."""
from pilot import S


def _setup(c):
    def helper_hook(em, r):
        em.calllog.append(('helper634d1c', 0, 0, ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x634d1c, helper_hook)


def _args(c):
    return []


S(0x66b4bd, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 59; helper hooked')
S(0x66d3f6, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 59; helper hooked')
S(0x66d3fc, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 59; helper hooked')
S(0x66d674, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 59; helper hooked')
S(0x66d67a, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 59; helper hooked')
