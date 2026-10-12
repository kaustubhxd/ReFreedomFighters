"""specs_s6328.py - unclaimed-63 gap-band batch 28: 0x4d2df0 (C-set, two stack arguments, ret 8). Stubs, rewritten each case (with a flush):
  * this's vtable slot +0xb0 records ECX and its two arguments and returns R (0 in one case of four; else a random object whose
    +0 dword is a random value and whose +8 is random);
  * R+4 -> F; F's byte at +0x10 is random (its low bit decides the G call);
  * global 0x700390 -> G; G's vtable slot +0x24 records ECX and its three stack arguments (caller cleans, plain ret);
  * 0x634d22 (import thunk, ss.patch): cdecl, records its three arguments, returns."""
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
    vt = c.emu.alloc(0x200, 4)
    cb0 = _cell(c, 4)
    R = 0
    if c.rng.random() < 0.75:
        R = _rnd(c, 0x40)
        c.emu.w32(R, c.rng.getrandbits(32))
        c.emu.w32(R + 8, c.rng.getrandbits(32))
        F = _rnd(c, 0x40)
        flags = c.rng.getrandbits(8)
        c.emu.wbytes(F + 0x10, bytes([flags]))
        c.emu.w32(R + 4, F)
    # slot +0xb0: records ECX and args 1, 2; ret 8
    code = (b'\x89\x0d' + _le(cb0) + b'\x8b\x44\x24\x04\xa3' + _le(cb0 + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cb0 + 8) + b'\xb8' + _le(R) + b'\xc2\x08\x00')
    c.emu.w32(vt + 0xb0, _stub(c, code))
    c.emu.w32(self_, vt)
    # G at 0x700390: slot +0x24 records ECX and its three arguments; caller cleans, so plain ret
    G_ = _rnd(c, 0x40)
    vg = c.emu.alloc(0x200, 4)
    cg = _cell(c, 4)
    code = (b'\x89\x0d' + _le(cg) + b'\x8b\x44\x24\x04\xa3' + _le(cg + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cg + 8) + b'\x8b\x44\x24\x0c\xa3' + _le(cg + 12) + b'\xc3')
    c.emu.w32(vg + 0x24, _stub(c, code))
    c.emu.w32(G_, vg)
    c.emu.w32(0x700390, G_)
    # 0x634d22: cdecl, records its three arguments
    c634 = _cell(c, 3)
    ss.patch(c, 0x634d22, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c634) + b'\x8b\x44\x24\x08\xa3' + _le(c634 + 4) +
                                b'\x8b\x44\x24\x0c\xa3' + _le(c634 + 8) + b'\xc3'))
    _flush(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4d2df0, 'unnamed C-set 0x4d2df0 thiscall', 'thiscall', None, ret='eax', gen=_gen, note='unclaimed-63 band batch 28')
