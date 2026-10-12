"""specs_s6313.py - unclaimed-63 batch 13 (docs/20-unclaimed-63.md): ZMoveOnSpline::Resurrect (0x513ee0), thiscall with one float
argument (ret 4). Stubs, rewritten each case (with a flush):
  * this+0x134 is an object (or 0 in one case of four); its slot +0x28 records ECX and returns (no arguments);
  * this's slots: +0x2d0 records ECX and its float argument (ret 4), +0x2c records ECX (ret), +0xbc records ECX and its argument (ret 4).
The float argument is drawn from -2 to 2 (and edge values), so both sides of the 0 test and of the 1.0 bound run."""
from pilot import S, F
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
    vt = c.emu.alloc(0x400, 4)
    c2d0, c2c, cbc = _cell(c, 2), _cell(c), _cell(c, 2)
    c.emu.w32(vt + 0x2d0, _stub(c, b'\x89\x0d' + _le(c2d0) + b'\x8b\x44\x24\x04\xa3' + _le(c2d0 + 4) + b'\xc2\x04\x00'))
    c.emu.w32(vt + 0x2c, _stub(c, b'\x89\x0d' + _le(c2c) + b'\xc3'))
    c.emu.w32(vt + 0xbc, _stub(c, b'\x89\x0d' + _le(cbc) + b'\x8b\x44\x24\x04\xa3' + _le(cbc + 4) + b'\xc2\x04\x00'))
    c.emu.w32(self_, vt)
    if c.rng.random() < 0.75:
        o = _rnd(c, 0x40)
        vto = c.emu.alloc(0x100, 4)
        c28 = _cell(c)
        c.emu.w32(vto + 0x28, _stub(c, b'\x89\x0d' + _le(c28) + b'\xc3'))
        c.emu.w32(o, vto)
        c.emu.w32(self_ + 0x134, o)
    else:
        c.emu.w32(self_ + 0x134, 0)
    t = F(c.fv(-2.0, 2.0)) if c.rng.random() < 0.9 else F(c.rng.choice([0.0, 1.0, -0.0, 0.5]))
    return [self_, t]


S(0x513ee0, 'ZMoveOnSpline::Resurrect (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 13; this vtbl +0x2d0/+0x2c/+0xbc stubs; c vtbl +0x28 stub')
