"""specs_s371.py - gap band batch 371: 0x405670, cdecl(p). When [p+0x30] is nonzero, 0x4055a0 (exe) is called with p and then free
(0x634d52, hooked and logged). 0x4055a0 is hooked and logged too (its body is another function)."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x4055a0, lambda em, r: (em.calllog.append(('pre_release', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x634d52, lambda em, r: (em.calllog.append(('free', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    p = E.zero_obj(c, 0x40)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(p + 0x30, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32) | 1)
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x405670, 'release if owned (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 371; 0x4055a0 and free hooked')
