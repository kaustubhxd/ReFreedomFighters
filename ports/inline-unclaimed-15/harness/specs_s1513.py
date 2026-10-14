"""specs_s1513.py - unclaimed-15 claim 13 (docs/20-unclaimed-15.md): ZFFHeroIf::CenterPrint (0x55f5e0).

Stubbed (unverified, not lifted): 0x5003d0 (3 args), 0x506040 (0 args), 0x589c20 (2 args) and 0x59a580 (0 args). Each is a
thiscall code stub that records its `this` (ecx) and its stack arguments in heap cells, returns a per-case value in eax
and cleans its own arguments (ret 4n). The hero's vtable slot +0x1e0 is logged and returns 0 or 1 per case. The hero is
0x1000 random bytes with its vtable at +0; the hero's dword at +0x684 is random. The argument object's +4 holds a pointer
to a 0x40-byte object. The global at 0x7003b8 points to a 0x40-byte object."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thiscall_log(c, nargs, ret):
    """thiscall stub: stores ecx and its nargs stack arguments in heap cells, returns ret in eax, ret 4*nargs."""
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)                              # mov [cells], ecx
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])              # mov eax, [esp + 4 + 4i]
        code += b'\xa3' + ss.P(cells + 4 + 4 * i)                 # mov [cells + 4 + 4i], eax
    code += b'\xb8' + ss.P(ret)                                   # mov eax, ret
    code += b'\xc2' + struct.pack('<H', 4 * nargs)                # ret 4n
    return ss.code(c, code)


def _center(c):
    o = _rnd(c, 0x200)
    hero = _rnd(c, 0x1000)
    answer = c.rng.choice([0, 1])
    hvt = c.emu.logging_vtable('ZFFHero', 0x80, impl={0x1e0: lambda e, a: (answer, None)}, argwords={0x1e0: 1})
    c.emu.w32(hero, hvt)
    c.emu.w32(o + 0x18, hero)
    a1 = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(a1 + 4, q)
    g = _rnd(c, 0x40)
    c.emu.w32(0x7003b8, g)
    ss.patch(c, 0x5003d0, _thiscall_log(c, 3, c.rng.getrandbits(32)))
    ss.patch(c, 0x506040, _thiscall_log(c, 0, c.rng.getrandbits(32)))
    ss.patch(c, 0x589c20, _thiscall_log(c, 2, c.rng.getrandbits(32)))
    ss.patch(c, 0x59a580, _thiscall_log(c, 0, c.rng.getrandbits(32)))
    return [o, a1]


S(0x55f5e0, 'ZFFHeroIf::CenterPrint (unknown) thiscall', 'thiscall', None, ret=None, gen=_center,
  note='unclaimed-15 claim 13; callees 0x5003d0, 0x506040, 0x589c20, 0x59a580 stubbed (log ecx and args)')
