"""specs_s6308.py - unclaimed-63 batch 8 (docs/20-unclaimed-63.md): unnamed function 0x508220 (GUESS), thiscall with one stack
argument (a pointer P, ret 4). Stubs, rewritten each case (with a flush):
  * 0x5003d0 (original, ss.patch): records ECX and its argument, returns F (a random float buffer);
  * this+0x18 -> obj; obj's vtable slot +0x604 records its float argument (as a dword) and returns;
  * P+4 is a random pointer value (the argument to 0x5003d0 is that value).
The multiplier at 0x67cd40 is the exe's own float constant (read, not written)."""
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
    obj = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, obj)
    p = _rnd(c, 0x20)
    c.emu.w32(p + 4, c.rng.getrandbits(32))
    cf = _cell(c, 2)
    F = _rnd(c, 0x20)
    ss.patch(c, 0x5003d0, _stub(c, b'\x89\x0d' + _le(cf) + b'\x8b\x44\x24\x04\xa3' + _le(cf + 4) +
                                b'\xb8' + _le(F) + b'\xc2\x04\x00'))
    vt = c.emu.alloc(0x800, 4)
    cv = _cell(c)
    c.emu.w32(vt + 0x604, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(cv) + b'\xc2\x04\x00'))
    c.emu.w32(obj, vt)
    _flush(c)
    return [self_, p]


S(0x508220, 'GUESS unnamed 0x508220 thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 8; 0x5003d0 stubbed; obj vtbl+0x604 stub records the float')
