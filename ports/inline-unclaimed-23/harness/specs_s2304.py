"""specs_s2304.py - unclaimed-23 batch 4 (docs/20-unclaimed-23.md): ZVehicleIf::addMethodDefinitions (0x51aba0), thiscall with
one stack argument (the method list, ret 4). The count at 0x701730 is drawn from 0..60, so the table path and the full path
both run. Stubs, rewritten each case (with a translation flush):
  * this's vtable slot +0x44: records ECX and its argument, ret 4;
  * the hook at 0x7003b0: a bare 'ret' (cdecl, no arguments);
  * 0x519ea0 (original, ss.patch): records ECX and its argument, ret 4.
The table at 0x701738 and the count live in the exe's .data, which the harness compares after each case."""
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
    self_ = _rnd(c, 0x800)
    lst = _rnd(c, 0x40)
    c.emu.wbytes(lst + 0xc, bytes([c.rng.choice([0, 1, 1, 1])]))
    c.emu.w32(0x701730, c.rng.randint(0, 60))
    vt = c.emu.alloc(0x400, 4)
    cself = _cell(c, 2)
    code = b'\x89\x0d' + _le(cself) + b'\x8b\x44\x24\x04\xa3' + _le(cself + 4) + b'\xc2\x04\x00'
    c.emu.w32(vt + 0x44, _stub(c, code))
    c.emu.w32(self_, vt)
    c.emu.w32(0x7003b0, _stub(c, b'\xc3'))
    cext = _cell(c, 2)
    code = b'\x89\x0d' + _le(cext) + b'\x8b\x44\x24\x04\xa3' + _le(cext + 4) + b'\xc2\x04\x00'
    ss.patch(c, 0x519ea0, _stub(c, code))
    _flush(c)
    return [self_, lst]


S(0x51aba0, 'ZVehicleIf::addMethodDefinitions (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 4; count at 0x701730 0..60; vtbl+0x44 stub; hook 0x7003b0 stub; 0x519ea0 original stubbed')
