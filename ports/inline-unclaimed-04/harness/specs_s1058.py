"""specs_s1058.py - unclaimed-04 batch 58 (docs/20-unclaimed-04.md): 0x66b0f6, 0x66b4b1, 0x66d3f0 (cdecl, no arguments, plain ret).
GUESS: simple wrappers calling the same helper as batches 56-57."""
from pilot import S


def _setup(c):
    # Hook the helper by address
    def helper_hook(em, r):
        em.calllog.append(('helper634d1c', 0, 0, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x634d1c, helper_hook)


def _args(c):
    # No arguments needed
    return []


S(0x66b0f6, 'unknown::call_helper_3 (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 58; helper hooked by address (GUESS)')
S(0x66b4b1, 'unknown::call_helper_4 (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 58; helper hooked by address (GUESS)')
S(0x66d3f0, 'unknown::call_helper_5 (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 58; helper hooked by address (GUESS)')
