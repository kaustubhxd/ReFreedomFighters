"""specs_s6321.py - unclaimed-63 batch 21 (docs/20-unclaimed-63.md): 0x5ec7e0 (GUESS vector-of-pointers dtor, vptr 0x6b8114), thiscall,
no arguments (ret). The pointer array at [this+0xcb] has 0 to 5 entries (end at [this+0xcf]); [this+0xd3] is the array's
end-of-capacity, 0 to 6 entries past the begin. Stubs (original callees, rewritten each case with a flush):
  * 0x634273 (cdecl): records its two arguments (the pointer and 0x10) and returns;
  * 0x54f870 (thiscall, two stack arguments, ret 8): records ECX and its two arguments;
  * 0x5ebbd0 (thiscall, no arguments): records ECX.
The SEH frame of the PC is not reproduced; no exception is raised on these paths."""
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
    self_ = _rnd(c, 0x200)
    k = c.rng.randint(0, 5)
    arr = _rnd(c, 4 * 8)
    begin = arr
    end = begin + 4 * k
    cap = begin + 4 * c.rng.randint(0, 6)
    c.emu.w32(self_ + 0xcb, begin)
    c.emu.w32(self_ + 0xcf, end)
    c.emu.w32(self_ + 0xd3, cap)
    c634 = _cell(c, 2)
    c.emu.wbytes(c634, bytes(8))
    ss.patch(c, 0x634273, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c634) + b'\x8b\x44\x24\x08\xa3' + _le(c634 + 4) + b'\xc3'))
    c54 = _cell(c, 3)
    ss.patch(c, 0x54f870, _stub(c, b'\x89\x0d' + _le(c54) + b'\x8b\x44\x24\x04\xa3' + _le(c54 + 4) +
                                b'\x8b\x44\x24\x08\xa3' + _le(c54 + 8) + b'\xc2\x08\x00'))
    c5eb = _cell(c)
    ss.patch(c, 0x5ebbd0, _stub(c, b'\x89\x0d' + _le(c5eb) + b'\xc3'))
    _flush(c)
    return [self_]


S(0x5ec7e0, 'GUESS vector-of-pointers dtor (vptr 0x6b8114) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 21; SEH frame not reproduced; 0x634273, 0x54f870, 0x5ebbd0 stubbed')
