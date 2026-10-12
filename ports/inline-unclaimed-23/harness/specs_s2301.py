"""specs_s2301.py - unclaimed-23 batch 1 (docs/20-unclaimed-23.md): ZItem::Place (0x46ff20), thiscall, two stack arguments
(ret 8). Stubs (patched per gen, with translation flush):
  * this's vtable slot +0x2dc: returns X, or 0 in one case of four ('mov eax, X; ret' / 'xor eax,eax; ret');
  * this's vtable slot +0x74: records its two stack arguments in heap cells, ret 8;
  * X+8 points at a random 0x800-byte object Y, which the helper 0x4db2c0 works on (the helper is original code).
The helpers 0x4dfd10, 0x4de420, 0x4de480, 0x4419f0, 0x43e960 and 0x4db2c0 run as original code in both runs."""
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


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _flush(c):
    """Drop Unicorn's translations for the heap and the exe image (as in the other batches)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x800)
    vt = c.emu.alloc(0x400, 4)
    Y = _rnd(c, 0x800)
    X = _rnd(c, 0x800)
    c.emu.w32(X + 8, Y)
    if c.rng.random() < 0.25:
        ret_code = b'\x31\xc0\xc3'                                  # xor eax, eax; ret  (X null)
    else:
        ret_code = b'\xb8' + _le(X) + b'\xc3'                         # mov eax, X; ret
    c.emu.w32(vt + 0x2dc, _stub(c, ret_code))
    # The two arguments are the caller's locals (stack addresses differ between the exe and the port), so the stub copies
    # the first three dwords each argument points to into six heap cells, not the addresses:
    # mov edx,[esp+4]; 3 x (mov eax,[edx+4i]; mov [cell+4i],eax); mov edx,[esp+8]; 3 x (same into cell+12+4i); ret 8.
    cells = _cell(c, 6)
    code = b'\x8b\x54\x24\x04'
    for i in range(3):
        code += (b'\x8b\x42' + bytes([4 * i]) if i else b'\x8b\x02') + b'\xa3' + _le(cells + 4 * i)
    code += b'\x8b\x54\x24\x08'
    for i in range(3):
        code += (b'\x8b\x42' + bytes([4 * i]) if i else b'\x8b\x02') + b'\xa3' + _le(cells + 12 + 4 * i)
    code += b'\xc2\x08\x00'
    c.emu.w32(vt + 0x74, _stub(c, code))
    c.emu.w32(self_, vt)
    return [self_, _rnd(c, 0x100), _rnd(c, 12)]


S(0x46ff20, 'ZItem::Place (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 1; stubs: vtbl+0x2dc (returns X or 0), vtbl+0x74 (records args); helpers original')
