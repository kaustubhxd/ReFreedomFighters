"""specs_s6331.py - unclaimed-63 gap-band batch 31: 0x4cf620 (C-set, args P and f, ret 8) and 0x4da3c0 (A+D set, one pointer, ret 4).
Stubs, rewritten each case (with a flush):
  * 0x4cf620: this's vtable slot +0x98 records ECX and its three arguments, returns V (a random dword); slot +0x20 records ECX and
    its argument (ret 4); 0x634d22 (import thunk, ss.patch, cdecl) records its three arguments. this+0x18 is random;
  * 0x4da3c0: src is a random 0x60-byte object; its dwords are random bit patterns (NaN and small values included), so the three
    clamps run both ways."""
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


def _gen_cf62(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, c.rng.getrandbits(32))
    vt = c.emu.alloc(0x200, 4)
    c98, c20 = _cell(c, 4), _cell(c, 2)
    V = c.rng.getrandbits(32)
    # slot +0x98: three stack arguments, ret 12; slot +0x20: one argument, ret 4
    code = (b'\x89\x0d' + _le(c98) + b'\x8b\x44\x24\x04\xa3' + _le(c98 + 4) + b'\x8b\x44\x24\x08\xa3' + _le(c98 + 8) +
            b'\x8b\x44\x24\x0c\xa3' + _le(c98 + 12) + b'\xb8' + _le(V) + b'\xc2\x0c\x00')
    c.emu.w32(vt + 0x98, _stub(c, code))
    code = b'\x89\x0d' + _le(c20) + b'\x8b\x44\x24\x04\xa3' + _le(c20 + 4) + b'\xc2\x04\x00'
    c.emu.w32(vt + 0x20, _stub(c, code))
    c.emu.w32(self_, vt)
    c634 = _cell(c, 3)
    ss.patch(c, 0x634d22, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c634) + b'\x8b\x44\x24\x08\xa3' + _le(c634 + 4) +
                                b'\x8b\x44\x24\x0c\xa3' + _le(c634 + 8) + b'\xc3'))
    _flush(c)
    P = _rnd(c, 0x20)
    c.emu.w32(P, c.rng.getrandbits(32))
    return [self_, P, c.rng.getrandbits(32)]


def _gen_da3c(c):
    self_ = _rnd(c, 0x80)
    src = _rnd(c, 0x80)
    # the clamp compares with the constant at 0x679540; one case in three sets a field equal to it (the strict '>' boundary)
    if c.rng.random() < 1 / 3:
        k = c.emu.rbytes(0x679540, 4)
        c.emu.wbytes(src + 0x40 + 4 * c.rng.randint(0, 2), k)
    return [self_, src]


S(0x4cf620, 'unnamed C-set 0x4cf620 thiscall', 'thiscall', None, ret=None, gen=_gen_cf62, note='unclaimed-63 band batch 31; vtbl+0x98/+0x20 stubs; 0x634d22 stubbed')
S(0x4da3c0, 'unnamed A+D 0x4da3c0 thiscall', 'thiscall', None, ret=None, gen=_gen_da3c, note='unclaimed-63 band batch 31')
