"""specs_s368.py - gap band batch 368: 0x401090, cdecl(p). The block has random bytes; calloc (0x634df4) is hooked and returns a
fresh fake-heap block (its argument pair is logged)."""
from pilot import S
import engine_stubs as E


def _hook(c):
    def h(em, rr):
        em.calllog.append(('calloc', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=em.alloc(0x1070, 16), argbytes=0)
    c.emu.hook(0x634df4, h)


def _gen(c):
    p = E.zero_obj(c, 0x40)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x401090, 'zero eight dwords and calloc into +0x1c (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 368; calloc hooked')
