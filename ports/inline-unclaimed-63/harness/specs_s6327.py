"""specs_s6327.py - unclaimed-63 gap-band batch 27: 0x4cf230 (C-set, one stack argument P, ret 4). Stubs, rewritten each case (with a flush):
  * global 0x700390 -> G; G's vtable slot +0x20 records its two arguments and returns X;
  * X's vtable slot +0x2c records ECX and its two arguments (caller cleans, so plain ret);
  * the signed dword this+0xc is negative in half the cases; this+0x18 and this+0x1c are random;
  * P points to a dword that is 0 or to a random object Q (Q+4 random)."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


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
    neg = c.rng.random() < 0.5
    c.emu.w32(self_ + 0xc, (c.rng.getrandbits(31) | 0x80000000) if neg else (c.rng.getrandbits(31)))
    c.emu.w32(self_ + 0x18, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x1c, c.rng.getrandbits(32))
    # G at 0x700390: slot +0x20 records its two arguments and returns X
    G_ = _rnd(c, 0x40)
    vt_g = c.emu.alloc(0x200, 4)
    cg = _cell(c, 2)
    X = _rnd(c, 0x40)
    code = (b'\x8b\x44\x24\x04\xa3' + _le(cg) + b'\x8b\x44\x24\x08\xa3' + _le(cg + 4) +
            b'\xb8' + _le(X) + b'\xc2\x08\x00')
    c.emu.w32(vt_g + 0x20, _stub(c, code))
    c.emu.w32(G_, vt_g)
    c.emu.w32(0x700390, G_)
    # X's vtable: slot +0x2c records ECX and its two arguments; caller cleans, so 'ret'
    vt_x = c.emu.alloc(0x200, 4)
    cx = _cell(c, 4)
    code = (b'\x89\x0d' + _le(cx) + b'\x8b\x44\x24\x04\xa3' + _le(cx + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cx + 8) + b'\xc3')
    c.emu.w32(vt_x + 0x2c, _stub(c, code))
    c.emu.w32(X, vt_x)
    # P: 0 or an object Q with a random +4
    P = _cell(c)
    if c.rng.random() < 0.5:
        Q = _rnd(c, 0x40)
        c.emu.w32(Q + 4, c.rng.getrandbits(32))
        c.emu.w32(P, Q)
    _flush(c)
    return [self_, P]


S(0x4cf230, 'unnamed C-set 0x4cf230 thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-63 band batch 27; 0x700390 object and X vtable stubs; asm caller-cleaned call')
