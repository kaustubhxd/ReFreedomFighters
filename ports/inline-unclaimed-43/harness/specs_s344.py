"""specs_s344.py - gap band batch 344: 0x41e110 calls the CRT import tmpfile (no arguments) through the IAT slot 0x6763ec and
stores the returned pointer in the global dword 0x6fd1a4. The import is stubbed: it returns a fresh block from the fake heap
(or NULL in one case out of 8; the draw is made in the stub from a counter reset in gen)."""
from pilot import S

CALLS = [0]


def _hook(c):
    def h(em, rr):
        CALLS[0] += 1
        em.ret(eax=0 if CALLS[0] % 8 == 0 else em.alloc(16, 16), argbytes=0)
    c.emu.stub_import('tmpfile', h)


def _gen(c):
    CALLS[0] = 0
    c.emu.mu.ctl_flush_tb()
    return []


S(0x41e110, 'tmpfile import into global (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 344; tmpfile import stubbed')
