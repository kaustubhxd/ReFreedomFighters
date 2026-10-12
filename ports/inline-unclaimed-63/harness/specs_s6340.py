"""specs_s6340.py - unclaimed-63 gap-band batch 40: 0x4d3d30 (wrapper; stdcall, three arguments, returns the callee's eax).
The callee 0x4d2700 (stdcall, ret 0x14) is a hook that records its five arguments and returns a random dword. The three arguments are
random dwords; the second one (a2) and the fifth argument (0) are pushed by the wrapper in its own way, so the order matters."""
from pilot import S


def _gen_3d30(c):
    e = c.emu
    e.hook(0x4d2700, lambda em, a: (em.calllog.append(('call.4d2700', None, None, tuple(em.arg32(k) for k in range(5)))),
                                    em.ret(eax=c.rng.getrandbits(32), argbytes=20)))
    e.mu.ctl_flush_tb()
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4d3d30, 'unnamed wrapper 0x4d3d30 stdcall', 'stdcall', None, ret='eax', gen=_gen_3d30,
  note='unclaimed-63 band batch 40')
