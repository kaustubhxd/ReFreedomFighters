"""specs_s365.py - gap band batch 365: 0x40c400, cdecl with one pointer; when the pointer is nonzero it zeroes 0x18 dwords there and calls
free (0x634d52, hooked and logged). Half the cases pass NULL."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634d52, lambda em, r: (em.calllog.append(('free', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    p = 0 if c.rng.random() < 0.5 else E.zero_obj(c, 4 * 0x18 + 16)
    if p:
        c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(4 * 0x18 + 16)))
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x40c400, 'zero 0x18 dwords and free (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 365; free hooked')
