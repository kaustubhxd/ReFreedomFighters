"""specs_s617.py - band 0x421000-0x441000, batch 617 (see src/batch617.cpp): the logger at [0x700390] is a recording fake
whose slot 0x2c (cdecl: logger, fmt, argument) is logged; the caller pops (no argbytes).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

LOG_GLOBAL = 0x700390


def _gen(c):
    r = c.rng

    def printf_h(e, rr):
        e.calllog.append(('log.printf', 0x2c, 0, (e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=0)
    lg = c.emu.fake_object('logger', 0x40, nslots=0x30, slots={0x2c: printf_h})
    c.emu.w32(LOG_GLOBAL, lg)
    return [r.getrandbits(32)]


S(0x424d50, 'debug log forwarder (fmt 0x677368)', 'cdecl', None, ret=None, gen=_gen)
