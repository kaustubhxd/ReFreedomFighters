"""specs_s765.py - gap band batch 765 (docs/20-gap-band-401000.md): 0x405ee0, cdecl (a, idx, c). The record a holds a pointer at +8 to a
record whose +8 is an array A1, and an array A2 at +0x10. 0x410bf0 (cdecl, three args) is a logging stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x410bf0, c.emu.stub_fn('410bf0 logger', lambda e, r: (e.calllog.append(('0x410bf0', (e.arg32(0), e.arg32(1), e.arg32(2)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    a = _rnd(c, 0x20)
    s1 = _rnd(c, 0x20)
    A1 = _rnd(c, 0x40)
    A2 = _rnd(c, 0x40)
    c.emu.w32(s1 + 8, A1)
    c.emu.w32(a + 8, s1)
    c.emu.w32(a + 0x10, A2)
    return [a, c.rng.randint(0, 7), c.rng.getrandbits(32)]


S(0x405ee0, 'CRT helper 0x405ee0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 765: 0x410bf0 stub with two array reads, returns A1[idx] re-read')
