"""specs_s791.py - gap band batch 791 (docs/20-gap-band-401000.md): 0x401900, cdecl (p). The helpers 0x410b90 and 0x401890 are logging stubs
(cdecl, one argument), the frees are logging stubs. p+0x40 points at a block whose first dword is zero or not, p+0x68 at a block whose +0xc is
zero or a pointer."""
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
    for addr, name in ((0x410b90, '410b90'), (0x401890, '401890'), (0x634d52, '634d52')):
        ss.patch(c, addr, c.emu.stub_fn(name + ' logger', (lambda nm: lambda e, r: (e.calllog.append((nm, (e.arg32(0),))), e.ret(eax=0, argbytes=0)))(name)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x80)
    a40 = _rnd(c, 0x20)
    c.emu.w32(a40, c.rng.choice([0, 1]))
    c.emu.w32(p + 0x40, a40)
    c.emu.w32(p + 0x44, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    b68 = _rnd(c, 0x20)
    c.emu.w32(b68 + 0xc, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(p + 0x68, b68 if c.rng.random() < 0.8 else 0)
    return [p]


S(0x401900, 'CRT helper 0x401900 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 791: release optional members, zero 0x1c dwords')
