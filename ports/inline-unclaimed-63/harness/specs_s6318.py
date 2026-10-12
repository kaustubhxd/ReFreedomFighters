"""specs_s6318.py - unclaimed-63 batch 18 (docs/20-unclaimed-63.md): 0x51aa60 (GUESS thunk), thiscall with no arguments (ret).
The base constructor 0x519430 is stubbed (ss.patch, records ECX, plain ret, per flush). The object is 0x40 random bytes; the vptr
written at its first dword is compared in the heap."""
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


def _gen(c):
    self_ = _rnd(c, 0x40)
    cc = _cell(c)
    ss.patch(c, 0x519430, ss.code(c, b'\x89\x0d' + _le(cc) + b'\xc3'))
    _flush(c)
    return [self_]


S(0x51aa60, 'GUESS FUN_51aa60 thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 18; 0x519430 stubbed (base constructor)')
