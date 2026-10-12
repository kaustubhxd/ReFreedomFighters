"""specs_s6335.py - unclaimed-63 gap-band batch 35: 0x4d25f0 (C-set; thiscall, five stack arguments, ret 0x14).
Stubs (each records its arguments into heap cells, so the exe and the port must pass the same values):
  * the object's vtable slot +0xa0 (thiscall, two arguments, ret 8, returns 0) and slot +4 of the object at this+0x4008 (ret 4);
  * 0x4cd9b0 (the pool allocator, thiscall, ret 8): records ECX and its two arguments, returns a random offset Y below 0x800;
  * 0x634d22 (cdecl import thunk, ss.patch): appends its three arguments to a log (it is called twice).
this+0x4004 is a 0x1000-byte heap block, so B + Y + the copied bytes stay inside it. The a2 and a4 lengths are 0 to 0x80 bytes.
The source blocks a1 and a5 are random 0x80-byte heap blocks. Stubs are rewritten each case (with a flush)."""
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
    self_ = c.emu.alloc(0x4100, 4)
    c.emu.wbytes(self_, bytes(0x4100))
    b = c.emu.alloc(0x1000, 4)
    c.emu.w32(self_ + 0x4004, b)
    obj = self_ + 0x4008
    # vtable of this: slot +0xa0 records ECX and two arguments (ret 8)
    cs, cs2 = _cell(c, 3), _cell(c, 3)
    code_a0 = (b'\x89\x0d' + _le(cs) + b'\x8b\x44\x24\x04\xa3' + _le(cs + 4) + b'\x8b\x44\x24\x08\xa3' + _le(cs + 8) +
               b'\x31\xc0\xc2\x08\x00')
    vt = c.emu.alloc(0x100, 4)
    c.emu.w32(vt + 0xa0, _stub(c, code_a0))
    c.emu.w32(self_, vt)
    # object at this+0x4008: vtable slot +4 records ECX and its argument (ret 4)
    code_4 = b'\x89\x0d' + _le(cs2) + b'\x8b\x44\x24\x04\xa3' + _le(cs2 + 4) + b'\x31\xc0\xc2\x04\x00'
    vto = c.emu.alloc(0x40, 4)
    c.emu.w32(vto + 4, _stub(c, code_4))
    c.emu.w32(obj, vto)
    # pool allocator 0x4cd9b0 (thiscall, ret 8): records ECX, size and one; returns Y (a 0x10-aligned offset below 0x800)
    y = 0x10 * c.rng.randrange(0, 0x80)
    ca = _cell(c, 3)
    code_pool = (b'\x89\x0d' + _le(ca) + b'\x8b\x44\x24\x04\xa3' + _le(ca + 4) + b'\x8b\x44\x24\x08\xa3' + _le(ca + 8) +
                 b'\xb8' + _le(y) + b'\xc2\x08\x00')
    ss.patch(c, 0x4cd9b0, _stub(c, code_pool))
    # 0x634d22 (cdecl, caller cleans): records its three arguments
    # the thunk is called twice, so each call appends its three arguments to a log (a cursor cell advances by 12 bytes)
    cm, cur = _cell(c, 6), _cell(c, 1)
    c.emu.w32(cur, cm)
    ss.patch(c, 0x634d22, _stub(c, b'\x8b\x0d' + _le(cur) + b'\x8b\x44\x24\x04\x89\x01\x8b\x44\x24\x08\x89\x41\x04' +
                                b'\x8b\x44\x24\x0c\x89\x41\x08\x83\xc1\x0c\x89\x0d' + _le(cur) + b'\xc3'))
    _flush(c)
    a1 = _rnd(c, 0x80)
    a5 = _rnd(c, 0x80)
    a2 = c.rng.randint(0, 0x80)
    a4 = c.rng.randint(0, 0x80)
    a3 = c.rng.getrandbits(32)
    return [self_, a1, a2, a3, a4, a5]


S(0x4d25f0, 'unnamed C-set 0x4d25f0 thiscall', 'thiscall', None, ret=None, gen=_gen, note='unclaimed-63 band batch 35')
