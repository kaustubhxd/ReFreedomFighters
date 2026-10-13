"""specs_s352.py - gap band batch 352: 0x4079c0, cdecl with one argument; if the argument is nonzero it calls 0x40fa40 with it
(cdecl). 0x40fa40 is hooked and logged (its body is another function)."""
from pilot import S


def _hook(c):
    c.emu.hook(0x40fa40, lambda em, r: (em.calllog.append(('fa40', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    v = 0 if r.random() < 0.3 else (r.getrandbits(31) | 1) << 1
    c.emu.mu.ctl_flush_tb()
    return [v]


S(0x4079c0, 'optional call to 0x40fa40 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 352; 0x40fa40 hooked')
