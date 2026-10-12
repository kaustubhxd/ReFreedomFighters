"""specs_s6311.py - unclaimed-63 batch 11 (docs/20-unclaimed-63.md): ZGEOM::CreateExData (0x45d960), thiscall, no arguments.
Stub (original, ss.patch, cdecl): 0x41e290 records its argument and returns P, a random 0x20-byte buffer, or 0 in one case of
four (the PC then leaves [this+0x10] unchanged). this+0x10 is 0 in three cases of four, otherwise a random value (early return)."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen(c):
    self_ = _rnd(c, 0x40)
    if c.rng.random() < 0.75:
        c.emu.w32(self_ + 0x10, 0)
    else:
        c.emu.w32(self_ + 0x10, c.rng.getrandbits(32) | 1)
    ca = _cell(c)
    P = 0 if c.rng.random() < 0.25 else _rnd(c, 0x20)
    code = b'\x8b\x44\x24\x04\xa3' + _le(ca) + b'\xb8' + _le(P) + b'\xc3'
    ss.patch(c, 0x41e290, _stub(c, code))
    _flush(c)
    return [self_]


S(0x45d960, 'ZGEOM::CreateExData (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 11; 0x41e290 stubbed (cdecl allocation)')
