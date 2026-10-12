"""specs_s614.py - unclaimed-06 claims 14 and 15 (docs/20-unclaimed-06.md): ZFFHeroMovementRaiseFlag and ZBOUND destructors.
Thiscall, one argument (random flags), ret 4, return this. The object is 0x1000 random bytes. Every callee is replaced by a
counting stub (GUESS) that logs its arguments: thiscall callees log ecx, cdecl callees log their two stack arguments
(pops nothing). The destructor code (vtable store, call order, flag tests) is what is verified."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
import struct


def _rececx(c):
    """Thiscall stub with no stack arguments that logs ecx (the this pointer) in an 8-entry ring, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x89\x08'                      # mov [eax], ecx
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


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


def _recc(c):
    """Cdecl stub with two stack arguments (p, n): logs both in a 16-dword-per-call ring, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub_all(c):
    for a in (0x480fd0, 0x4878d0, 0x43de70):
        ss.patch(c, a, _rececx(c))          # thiscall: logs ecx
    ss.patch(c, 0x45c510, _recc1(c))        # cdecl, one argument: logs it, pops nothing
    for a in (0x4690b0, 0x634273):
        ss.patch(c, a, _recc(c))            # cdecl, two arguments: logs both, pops nothing


def _gen(c):
    self = _rnd(c, 0x1000)
    _stub_all(c)
    return [self, c.rng.getrandbits(32)]


S(0x5e1690, 'ZFFHeroMovementRaiseFlag::~ZFFHeroMovementRaiseFlag (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-06 claim 14; vtable store, 5 member/base dtor stubs (GUESS), delete 0x634273 stubbed')
S(0x44e710, 'ZBOUND::~ZBOUND (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-06 claim 15; vtable store, base dtor 0x43de70 stubbed (GUESS), delete helpers stubbed')
