"""specs_s799.py - gap band batch 799 (docs/20-gap-band-401000.md): 0x4104c0, cdecl (p, n). The memmove 0x634d28 is a logging stub; the realloc
0x634dee and the allocator 0x634d58 are fakes returning fixed blocks. p[0] is NULL in one case in three."""
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
    ss.patch(c, 0x634d28, c.emu.stub_fn('634d28 logger', lambda e, r: (e.calllog.append(('0x634d28', (e.arg32(0), e.arg32(1), e.arg32(2)))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x634dee, c.emu.stub_fn('634dee fake', lambda e, r: (e.calllog.append(('0x634dee', (e.arg32(0), e.arg32(1)))), e.ret(eax=blk, argbytes=0))))
    ss.patch(c, 0x634d58, c.emu.stub_fn('634d58 fake', lambda e, r: (e.calllog.append(('0x634d58', (e.arg32(0),))), e.ret(eax=blk + 0x10, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x20)
    buf = _rnd(c, 0x200)
    c.emu.w32(p, buf if c.rng.random() < 2 / 3 else 0)
    c.emu.w32(p + 4, c.rng.randint(0, 0x200))
    c.emu.w32(p + 8, c.rng.randint(0, 0x100))
    c.emu.w32(p + 0xc, c.rng.choice([0, c.rng.randint(0, 0x40)]))
    return [p, c.rng.randint(0, 0x200)]


S(0x4104c0, 'CRT helper 0x4104c0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 799: compact the pending bytes, grow the buffer if needed')
