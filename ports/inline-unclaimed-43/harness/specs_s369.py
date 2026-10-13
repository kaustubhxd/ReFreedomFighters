"""specs_s369.py - gap band batch 369: 0x410b90, cdecl(p). free (0x634d52) is hooked and logged; the block has random bytes so the
five zeroed dwords and the untouched tail show in the heap compare."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634d52, lambda em, r: (em.calllog.append(('free', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    p = E.zero_obj(c, 0x40)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(p + 8, c.rng.getrandbits(32) | 0x10000)
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x410b90, 'free +8 and zero five dwords (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 369; free hooked')
