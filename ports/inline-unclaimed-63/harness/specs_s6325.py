"""specs_s6325.py - unclaimed-63 gap-band batch 25: 0x4cd430, 0x4d8580, 0x4d85c0 (C-set, ret 4) and 0x4dc1a0 (A+D+E, no args, recursive
walk). Stubs, rewritten each case (with a flush): 0x4cbec0 (original, plain ret, records ECX in a heap cell) and 0x634273 (original,
cdecl, records its two arguments). For 0x4dc1a0: this+0x54 is 0 or an object X with X+0xc -> Y and Y+0x23 random (bit 0x100000 set in
about half the cases); X+0x50 heads a list of 0 to 2 children (next at +0x60), each child with +0x54 = 0 and random bytes."""
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


def _patch_helpers(c):
    c4c = _cell(c, 4)
    ss.patch(c, 0x4cbec0, _stub(c, b'\x89\x0d' + _le(c4c) + b'\xc3'))
    c63 = _cell(c, 2)
    ss.patch(c, 0x634273, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c63) + b'\x8b\x44\x24\x08\xa3' + _le(c63 + 4) + b'\xc3'))
    _flush(c)


def _gen_obj(c):
    self_ = _rnd(c, 0x200)
    _patch_helpers(c)
    return [self_, c.rng.getrandbits(32)]


def _gen_dc1a(c):
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x3c, c.rng.getrandbits(32))
    _patch_helpers(c)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x54, 0)
    else:
        X = _rnd(c, 0x80)
        Y = _rnd(c, 0x40)
        c.emu.w32(X + 0xc, Y)
        yval = c.rng.getrandbits(32)
        if c.rng.random() < 0.5:
            yval |= 0x100000
        else:
            yval &= ~0x100000
        c.emu.w32(Y + 0x23, yval & 0xffffffff)
        c.emu.w32(self_ + 0x54, X)
        kids = [_rnd(c, 0x80) for _ in range(c.rng.randint(0, 2))]
        for i, k in enumerate(kids):
            c.emu.w32(k + 0x54, 0)
            c.emu.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
        c.emu.w32(X + 0x50, kids[0] if kids else 0)
    return [self_]


S(0x4cd430, 'unnamed C-set 0x4cd430 thiscall', 'thiscall', None, ret='eax', gen=_gen_obj, note='unclaimed-63 band batch 25')
S(0x4d8580, 'unnamed C-set 0x4d8580 thiscall', 'thiscall', None, ret='eax', gen=_gen_obj, note='unclaimed-63 band batch 25')
S(0x4d85c0, 'unnamed C-set 0x4d85c0 thiscall', 'thiscall', None, ret='eax', gen=_gen_obj, note='unclaimed-63 band batch 25')
S(0x4dc1a0, 'unnamed A+D+E 0x4dc1a0 thiscall', 'thiscall', None, ret=None, gen=_gen_dc1a, note='unclaimed-63 band batch 25; recursive child walk')
