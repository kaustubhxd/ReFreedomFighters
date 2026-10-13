"""specs_s786.py - gap band batch 786 (docs/20-gap-band-401000.md): 0x4017c0, cdecl (a, obj). 0x634df4 and 0x634d58 (cdecl) and 0x4063c0 (cdecl,
no arguments) are fakes returning fixed blocks or values; 0x410b50 is the band batch 766 port's exe code (run for real). a's first dword is
zero in one case in three."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    blk = _rnd(c, 0x100)
    ss.patch(c, 0x634df4, c.emu.stub_fn('634df4 fake', lambda e, r: (e.calllog.append(('0x634df4', (e.arg32(0), e.arg32(1)))), e.ret(eax=blk, argbytes=0))))
    ss.patch(c, 0x634d58, c.emu.stub_fn('634d58 fake', lambda e, r: (e.calllog.append(('0x634d58', (e.arg32(0),))), e.ret(eax=blk + 8, argbytes=0))))
    ss.patch(c, 0x4063c0, c.emu.stub_fn('4063c0 fake', lambda e, r: (e.calllog.append(('0x4063c0',)), e.ret(eax=3, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    a = _rnd(c, 0x20)
    c.emu.w32(a, 0 if c.rng.random() < 1 / 3 else (c.rng.getrandbits(32) | 1))
    obj = _rnd(c, 0x80)
    return [a, obj]


S(0x4017c0, 'CRT helper 0x4017c0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 786: clear the record, optional allocation pair')
