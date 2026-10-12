"""specs_s6306.py - unclaimed-63 batch 6 (docs/20-unclaimed-63.md): CRagdoll2::~CRagdoll2 (0x640f20), thiscall with one argument
(the flags byte, ret 4); the result is eax (this, or this-4 on the array path). Stubs, rewritten each case (with a flush):
  * 0x63418c (original, ss.patch): stdcall stub recording its four arguments, ret 16;
  * 0x634273 (original, ss.patch): cdecl stub recording its two arguments, ret;
  * this+0x17f is an object (or 0) whose slot +4 records its argument (1), thiscall, ret 4;
  * the element count at this-4 is 0..3 (a dword just before the object). The object is 0x810 bytes so this+0x17f is inside."""
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
    base = _rnd(c, 0x810)
    this = base + 8
    c.emu.w32(this - 4, c.rng.randint(0, 3))
    flags = c.rng.randint(0, 7) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        o = _rnd(c, 0x40)
        vt_o = c.emu.alloc(0x100, 4)
        co = _cell(c)
        c.emu.w32(vt_o + 4, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(co) + b'\xc2\x04\x00'))
        c.emu.w32(o, vt_o)
        c.emu.w32(this + 0x17f, o)
    else:
        c.emu.w32(this + 0x17f, 0)
    # 0x63418c: stdcall, records its four arguments, ret 16
    c4 = _cell(c, 4)
    code = b''
    for i in range(4):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + _le(c4 + 4 * i)
    code += b'\xc2\x10\x00'
    ss.patch(c, 0x63418c, _stub(c, code))
    # 0x634273: cdecl, records its two arguments
    c2 = _cell(c, 2)
    code = b'\x8b\x44\x24\x04\xa3' + _le(c2) + b'\x8b\x44\x24\x08\xa3' + _le(c2 + 4) + b'\xc3'
    ss.patch(c, 0x634273, _stub(c, code))
    _flush(c)
    return [this, flags]


S(0x640f20, 'CRagdoll2::~CRagdoll2 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-63 batch 6; 0x63418c and 0x634273 stubbed; SEH frame not reproduced')
