"""specs_s6310.py - unclaimed-63 batch 10 (docs/20-unclaimed-63.md): ResourceCollection::GetResource (0x49df60), thiscall with two
stack arguments (ret 8). Stubs, rewritten each case (with a flush):
  * 0x49e140 (original, ss.patch): records ECX and its two arguments; returns R (0 in one case of three, otherwise a random object);
  * 0x49e260 (original, ss.patch): thiscall with one stack argument (the name): records ECX and it, ret 4;
  * global 0x700390 -> G; G's slot +0x20 records its two arguments and returns L (the logger object);
  * L's vptr -> a table whose slot +0x30 records ECX and its three stack arguments (caller cleans: 'ret');
  * this+4 is 0 in one case of four (the return is 0 then), otherwise a random value.
The out pointer is a random 0x40-byte buffer; the name is a random pointer value."""
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
    e = 0 if c.rng.random() < 0.25 else c.rng.getrandbits(32) | 8
    c.emu.w32(self_ + 4, e)
    name = _rnd(c, 0x40)
    out = _rnd(c, 0x40)
    # 0x49e140: records ECX and its two arguments; returns R
    c140 = _cell(c, 3)
    R = 0 if c.rng.random() < 1 / 3 else _rnd(c, 0x40)
    code = (b'\x89\x0d' + _le(c140) + b'\x8b\x44\x24\x04\xa3' + _le(c140 + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(c140 + 8) + b'\xb8' + _le(R) + b'\xc2\x08\x00')
    ss.patch(c, 0x49e140, _stub(c, code))
    # 0x49e260: thiscall with one stack argument (the name): records ECX and the argument, ret 4
    c260 = _cell(c, 2)
    ss.patch(c, 0x49e260, _stub(c, b'\x89\x0d' + _le(c260) + b'\x8b\x44\x24\x04\xa3' + _le(c260 + 4) + b'\xc2\x04\x00'))
    _flush(c)
    # G at 0x700390: slot +0x20 records its two arguments and returns L
    G_ = _rnd(c, 0x40)
    vt_g = c.emu.alloc(0x200, 4)
    cg = _cell(c, 2)
    L = _rnd(c, 0x40)
    code = (b'\x8b\x44\x24\x04\xa3' + _le(cg) + b'\x8b\x44\x24\x08\xa3' + _le(cg + 4) +
            b'\xb8' + _le(L) + b'\xc2\x08\x00')
    c.emu.w32(vt_g + 0x20, _stub(c, code))
    c.emu.w32(G_, vt_g)
    c.emu.w32(0x700390, G_)
    # L's vtable: slot +0x30 records ECX and its three arguments; caller cleans, so 'ret'
    vt_l = c.emu.alloc(0x200, 4)
    cl = _cell(c, 4)
    code = (b'\x89\x0d' + _le(cl) + b'\x8b\x44\x24\x04\xa3' + _le(cl + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cl + 8) + b'\x8b\x44\x24\x0c\xa3' + _le(cl + 12) + b'\xc3')
    c.emu.w32(vt_l + 0x30, _stub(c, code))
    c.emu.w32(L, vt_l)
    _flush(c)
    return [self_, name, out]


S(0x49df60, 'ResourceCollection::GetResource (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-63 batch 10; 0x49e140 and 0x49e260 stubbed; G vtbl+0x20 and logger vtbl+0x30 stubs; asm call for the logger')
