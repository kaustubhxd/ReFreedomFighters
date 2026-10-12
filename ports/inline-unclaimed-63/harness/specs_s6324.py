"""specs_s6324.py - unclaimed-63 gap-band batch 24: 0x4d2be0 (C-set, ret 4), 0x4daa00 (A+D set, bool in al, no args) and
0x4cd1e0 (C-set, ret 4). Stubs, rewritten each case (with a flush):
  * 0x4d2be0: this's vtable slot +0xb0 records ECX and its two arguments and returns R (0 in one case of four, else a 16-byte
    object whose +8 dword is random); ret 8;
  * 0x4daa00: this+0x3c flag word is random (bit 0x40000 set in about half the cases); this+0x54 is 0 or an object whose
    vtable slot +0x60 records ECX and returns a random byte (bool, ret);
  * 0x4cd1e0: the helper 0x4cce40 (original, ss.patch, records ECX, plain ret) and 0x634273 (original, cdecl, records its two arguments)."""
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


def _gen_4d2be(c):
    self_ = _rnd(c, 0x40)
    vt = c.emu.alloc(0x400, 4)
    cc = _cell(c, 3)
    R = 0 if c.rng.random() < 0.25 else _rnd(c, 16)
    # records ECX, arg1 (esp+4), arg2 (esp+8); returns R; ret 8
    code = (b'\x89\x0d' + _le(cc) + b'\x8b\x44\x24\x04\xa3' + _le(cc + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cc + 8) + b'\xb8' + _le(R) + b'\xc2\x08\x00')
    c.emu.w32(vt + 0xb0, _stub(c, code))
    c.emu.w32(self_, vt)
    if R:
        c.emu.w32(R + 8, c.rng.getrandbits(32))
    return [self_, c.rng.getrandbits(32)]


def _gen_daa(c):
    self_ = _rnd(c, 0x80)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        flags |= 0x40000
    else:
        flags &= ~0x40000
    c.emu.w32(self_ + 0x3c, flags)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x54, 0)
    else:
        obj = _rnd(c, 0x40)
        vt = c.emu.alloc(0x200, 4)
        c60 = _cell(c)
        v = c.rng.getrandbits(8)
        c.emu.w32(vt + 0x60, _stub(c, b'\x89\x0d' + _le(c60) + b'\xb0' + bytes([v]) + b'\xc3'))
        c.emu.w32(obj, vt)
        c.emu.w32(self_ + 0x54, obj)
    return [self_]


def _gen_cd1e(c):
    self_ = _rnd(c, 0x60)
    c4cc = _cell(c)
    ss.patch(c, 0x4cce40, _stub(c, b'\x89\x0d' + _le(c4cc) + b'\xc3'))
    c634 = _cell(c, 2)
    ss.patch(c, 0x634273, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c634) + b'\x8b\x44\x24\x08\xa3' + _le(c634 + 4) + b'\xc3'))
    _flush(c)
    return [self_, c.rng.getrandbits(32)]


S(0x4d2be0, 'unnamed C-set 0x4d2be0 thiscall', 'thiscall', None, ret='eax', gen=_gen_4d2be, note='unclaimed-63 band batch 24')
S(0x4daa00, 'unnamed A+D 0x4daa00 thiscall bool', 'thiscall', None, ret='al', gen=_gen_daa, note='unclaimed-63 band batch 24')
S(0x4cd1e0, 'unnamed C-set 0x4cd1e0 thiscall', 'thiscall', None, ret='eax', gen=_gen_cd1e, note='unclaimed-63 band batch 24')
