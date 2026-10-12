"""specs_s6316.py - unclaimed-63 batch 16 (docs/20-unclaimed-63.md): GUESS FUN_4eaea0 (0x4eaea0), thiscall with two stack arguments
(ret 8); the result is al. The object is 0x200 random bytes with the flag byte at +0xa4 (zero in one case of three). The
argument a1 is a random 0x200-byte object (the helpers work on it); a2 is a random value. Stubs (with a flush):
  * 0x4ea900 (original, ss.patch): records ECX and its two arguments; returns a random byte (in al).
The helpers 0x43e960, 0x441a60, 0x4419f0 and 0x441940 run as original code in both runs."""
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
    self_ = _rnd(c, 0x200)
    c.emu.wbytes(self_ + 0xa4, bytes([0 if c.rng.random() < 1 / 3 else c.rng.getrandbits(8) | 1]))
    a1 = _rnd(c, 0x200)
    a2 = c.rng.getrandbits(32)
    cc = _cell(c, 3)
    R = c.rng.getrandbits(8)
    code = (b'\x89\x0d' + _le(cc) + b'\x8b\x44\x24\x04\xa3' + _le(cc + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cc + 8) + b'\xb0' + bytes([R]) + b'\xc2\x08\x00')
    ss.patch(c, 0x4ea900, _stub(c, code))
    _flush(c)
    return [self_, a1, a2]


S(0x4eaea0, 'GUESS FUN_4eaea0 thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-63 batch 16; 0x4ea900 stubbed; four helpers original')
