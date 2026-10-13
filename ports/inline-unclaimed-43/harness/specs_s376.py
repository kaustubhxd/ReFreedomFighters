"""specs_s376.py - gap band batch 376: 0x4102f0, cdecl(p). When p is nonzero it frees the three pointers at +0, +0x10, +0x14 that
are nonzero (free 0x634d52 hooked and logged), then zeroes 0x5a dwords at p. Half of the cases pass NULL; the three pointers are
random nonzero or zero."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634d52, lambda em, r: (em.calllog.append(('free', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    p = 0
    if r.random() < 0.5:
        p = E.zero_obj(c, 0x5a * 4 + 16)
        c.emu.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x5a * 4 + 16)))
        for off in (0, 0x10, 0x14):
            c.emu.w32(p + off, r.getrandbits(32) | 0x10000 if r.random() < 0.7 else 0)
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x4102f0, 'free three and zero (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_hook,
  note='gap band batch 376; free hooked')
