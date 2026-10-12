"""specs_s776.py - unclaimed-77 claim 6 (docs/20-unclaimed-77.md): CEntityTracker::~CEntityTracker, thiscall, one argument
(random flags), ret 4, returns this. SEH frame not reproduced. The null-hook branch traps in the original (int3 at 0x5bfd22)
and is excluded: the hook at 0x7003b0 is always set to a counting stub. Stubs (GUESS): 0x41e2c0 (cdecl, one argument, logged),
0x4690b0 (cdecl, two arguments, logged), the render-manager object's slot 0x34 (thiscall, one argument, logged), and the hook."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _recc1(c):
    """Cdecl stub with one stack argument: logs [esp+4] in an 8-entry ring, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _recc2(c):
    """Cdecl stub with two stack arguments (p, n): logs both, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x41e2c0, _recc1(c))
    ss.patch(c, 0x4690b0, _recc2(c))
    obj2 = ss.mkobj(c, {0x34: ss.rec(c, 1)})    # render-manager's +0x9b object: slot 0x34 takes one argument (this)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, obj2)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(0x7003b0, ss.rec(c, 0))            # hook: nonzero (the null case traps in the original and is excluded)
    return [self, c.rng.getrandbits(32)]


S(0x5bfc80, 'CEntityTracker::~CEntityTracker (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-77 claim 6; SEH frame not reproduced; null-hook branch excluded (traps in the original)')
