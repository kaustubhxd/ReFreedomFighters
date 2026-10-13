"""specs_s351.py - decomp area 64 (docs/20-unclaimed-64.md): exe string compare 0x59be70; exe helper 0x5b1000 stubbed (GUESS)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, addr):
    # The NUL-terminated constant at addr, read from the exe image (at most 0x40 bytes).
    bs = bytes(c.emu.mu.mem_read(addr, 0x40))
    return bs[:bs.index(0) + 1]


def _cmp(c):
    e = c.emu
    # 0x5b1000 (thiscall, one word, ret 4): a stub that counts, records ecx and its word, and returns a per-case eax.
    cnt = e.alloc(4, 4)
    e.wbytes(cnt, bytes(4))
    rv = c.rng.getrandbits(32)
    cell = e.alloc(8, 4)
    e.wbytes(cell, bytes(8))
    ss.patch(c, 0x5b1000, ss.code(c, b'\xff\x05' + ss.P(cnt)
             + b'\x89\x0d' + ss.P(cell)                                  # mov [cell], ecx
             + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell + 4)     # mov edx,[esp+4]; mov [cell+4], edx
             + b'\xb8' + ss.P(rv) + b'\xc2\x04\x00'))

    obj = _rnd(c, 0x600)
    r = c.rng.random()
    if r < 0.35:
        s = _cstr(c, 0x6a7808)
    elif r < 0.7:
        s = _cstr(c, 0x6adcc8)
    else:
        s = bytes(c.rng.randrange(1, 256) for _ in range(c.rng.randrange(1, 20))) + b'\x00'
    e.wbytes(obj + 0x48, s + bytes(0x40 - len(s)) if len(s) < 0x40 else s[:0x40])
    return [obj]


S(0x59be70, 'classify (GUESS)', 'thiscall', None, ret='eax', gen=_cmp,
  note='batch351; no stack words; exe 0x5b1000 stubbed (GUESS); constants 0x6a7808 and 0x6adcc8 read from the image')
