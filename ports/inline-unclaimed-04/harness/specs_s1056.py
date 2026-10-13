"""specs_s1056.py - unclaimed-04 batch 56 (docs/20-unclaimed-04.md): 0x6650b4 (cdecl, no arguments, plain ret).
GUESS: simple wrapper calling a helper."""
from pilot import S


def _setup(c):
    # Hook the helper by address
    def helper_hook(em, r):
        em.calllog.append(('helper634d1c', 0, 0, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x634d1c, helper_hook)


def _args(c):
    # No arguments needed for a cdecl function with no parameters
    return []


S(0x6650b4, 'unknown::call_helper (unknown) cdecl', 'cdecl', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 56; helper hooked by address (GUESS)')
