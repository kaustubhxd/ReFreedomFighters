"""specs_s625.py - band 0x421000-0x441000, batch 625 (see src/batch625.cpp).
0x427f40 logs through the logger at [0x700390] (slot 0x20 with file and line, returns a recording stream whose cdecl slot
0x2c gets (stream, fmt)). 0x432250 calls the receiver's slot 0xc with the key: it answers 0 or a block holding a pointer.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

LOG_GLOBAL = 0x700390


def _gen_writeto(c):
    r = c.rng

    def printf_h(e, rr):
        e.calllog.append(('log.printf', 0x2c, 0, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)     # cdecl: the caller pops
    stream = c.emu.fake_object('stream', 0x40, nslots=0x30, slots={0x2c: printf_h})

    def log_h(e, rr):
        e.calllog.append(('log.get', 0x20, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=stream, argbytes=8)
    lg = c.emu.fake_object('logger', 0x40, nslots=0x30, slots={0x20: log_h})
    c.emu.w32(LOG_GLOBAL, lg)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _gen_key(c):
    r = c.rng
    blk = c.emu.alloc(0x20, 16)
    c.emu.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x20)))

    def h(e, rr):
        e.calllog.append(('cfg.c', 0xc, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=blk if r.random() < 0.8 else 0, argbytes=4)
    cfg = c.emu.fake_object('cfg', 0x40, nslots=0x20, slots={0xc: h})
    return [cfg, r.getrandbits(32)]


S(0x427f40, 'ZSysFileGC::WriteTo (logs, ignores its four arguments)', 'stdcall', None, ret=None, gen=_gen_writeto)
S(0x432250, 'CConfiguration::ExtractKeyNameFromNode', 'thiscall', None, ret='eax', gen=_gen_key)
