"""specs_s6317.py - unclaimed-63 batch 17 (docs/20-unclaimed-63.md): 0x51b1e0 and 0x559ee0 (both GUESS names, thiscall, one
argument P, ret 4). Stubs, patched per gen (with a flush). The callees 0x5003d0, 0x5002f0 and 0x59d130 are original code, stubbed
here, each with the stack discipline read from the exe (ret 4, one stack word):
  * 0x5003d0: records ECX and its argument, returns F (a random buffer);
  * 0x5002f0: records ECX and its argument (the leftover r pushed before the 0);
  * 0x59d130: records ECX and its argument, returns R.
  * 0x51b1e0: this+0x1c -> O; O's vtable slot +0x374 records ECX and returns R2 (no arguments).
  * 0x559ee0: this+0x1c -> X; X+0x54 -> Y; Y+8 = t, drawn from {2, 3, other}; 0x7003b8 -> A; A+0x2c15 -> B; P+8 is random."""
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


def _patch_callees(c):
    """0x5003d0 (returns F), 0x5002f0 and 0x59d130 (returns R), each one stack word and ret 4."""
    c_a, c_b, c_c = _cell(c, 2), _cell(c, 2), _cell(c, 2)
    F = _rnd(c, 0x20)
    R = c.rng.getrandbits(32)
    ss.patch(c, 0x5003d0, _stub(c, b'\x89\x0d' + _le(c_a) + b'\x8b\x44\x24\x04\xa3' + _le(c_a + 4) +
                                b'\xb8' + _le(F) + b'\xc2\x04\x00'))
    ss.patch(c, 0x5002f0, _stub(c, b'\x89\x0d' + _le(c_b) + b'\x8b\x44\x24\x04\xa3' + _le(c_b + 4) + b'\xc2\x04\x00'))
    ss.patch(c, 0x59d130, _stub(c, b'\x89\x0d' + _le(c_c) + b'\x8b\x44\x24\x04\xa3' + _le(c_c + 4) +
                                b'\xb8' + _le(R) + b'\xc2\x04\x00'))
    _flush(c)


def _gen_51b1(c):
    self_ = _rnd(c, 0x40)
    O = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x1c, O)
    vt = c.emu.alloc(0x800, 4)
    c374 = _cell(c)
    R2 = c.rng.getrandbits(32)
    c.emu.w32(vt + 0x374, _stub(c, b'\x89\x0d' + _le(c374) + b'\xb8' + _le(R2) + b'\xc3'))
    c.emu.w32(O, vt)
    P = _rnd(c, 0x20)
    c.emu.w32(P + 8, c.rng.getrandbits(32))
    _patch_callees(c)
    return [self_, P]


def _gen_559e(c):
    self_ = _rnd(c, 0x40)
    O = _rnd(c, 0x80)
    Y = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, O)
    c.emu.w32(O + 0x54, Y)
    c.emu.w32(Y + 8, c.rng.choice([2, 3, c.rng.getrandbits(8)]))
    A = _rnd(c, 0x3000)
    B = _rnd(c, 0x40)
    c.emu.w32(A + 0x2c15, B)
    c.emu.w32(0x7003b8, A)
    P = _rnd(c, 0x20)
    c.emu.w32(P + 8, c.rng.getrandbits(32))
    _patch_callees(c)
    return [self_, P]


S(0x51b1e0, 'GUESS FUN_51b1e0 thiscall', 'thiscall', None, ret=None, gen=_gen_51b1, note='unclaimed-63 batch 17')
S(0x559ee0, 'GUESS FUN_559ee0 thiscall', 'thiscall', None, ret=None, gen=_gen_559e, note='unclaimed-63 batch 17')
