"""specs_s793.py - gap band batch 793 (docs/20-gap-band-401000.md): 0x401890, cdecl (p). The list at +0x54 has 0 to 3 nodes (payload, next); the
frees 0x634d52 are logging stubs, the realloc 0x634dee is a fake returning a fixed block. The record's +0x50 is 0 or positive."""
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
    blk = _rnd(c, 0x200)
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x634dee, c.emu.stub_fn('634dee fake', lambda e, r: (e.calllog.append(('0x634dee', (e.arg32(0), e.arg32(1)))), e.ret(eax=blk, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x80)
    nodes = [_rnd(c, 0x10) for _ in range(c.rng.randint(0, 3))]
    nxt = 0
    for nd in reversed(nodes):
        c.emu.w32(nd, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
        c.emu.w32(nd + 4, nxt)
        nxt = nd
    c.emu.w32(p + 0x54, nxt)
    c.emu.w32(p + 0x50, c.rng.choice([0, c.rng.randint(1, 0x40)]))
    c.emu.w32(p + 0x4c, c.rng.randint(0, 0x40))
    c.emu.w32(p + 0x44, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    return [p]


S(0x401890, 'CRT helper 0x401890 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 793: release the node list, optional realloc of one buffer')
