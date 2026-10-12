"""specs_s1025.py - unclaimed-04 batch 26 (docs/20-unclaimed-04.md): 0x41dd70 (no arguments, plain ret).
The counter at 0x6fcd7c is decremented; when it reaches zero the function calls GetCurrentProcess (IAT 0x6760ac, stdcall)
and then the cdecl function pointer at 0x6fcd54 with the handle. The spec sets the counter per case and points the pointer
at a recording stub. Both the import and the stub are Python (GUESS on their roles)."""
from pilot import S


def _setup(c):
    handle = c.rng.getrandbits(32)

    def gcp(em, r):
        em.calllog.append(('GetCurrentProcess', 0, 0, ()))
        em.ret(eax=handle, argbytes=0)

    def fp(em, r):
        em.calllog.append(('fnptr', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)  # the call site has no add esp: the target pops its one argument

    c.emu.stub_import('GetCurrentProcess', gcp)
    c.emu.w32(0x6fcd54, c.emu.stub_fn('fnptr', fp))


def _args(c):
    c.emu.w32(0x6fcd7c, c.rng.choice([0, 1, 1, 2, -1 & 0xffffffff]))
    return []


S(0x41dd70, 'unknown::counter_gated_call (unknown) cdecl', 'cdecl', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 26; GetCurrentProcess import and the fn pointer at 0x6fcd54 are stubs (GUESS)')
