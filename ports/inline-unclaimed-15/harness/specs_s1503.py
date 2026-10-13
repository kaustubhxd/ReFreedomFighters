"""specs_s1503.py - unclaimed-15 claim 3 (docs/20-unclaimed-15.md): ZFFHeroMovementOpenGate::GetAnims (0x5e46a0) and
ZInputActions::CheckAction(ZInputActionGroup*, void*) (0x437fa0).

GetAnims: its base helper 0x5e3e90 is STUBBED (unverified, not lifted here): patch() replaces its entry with a counting
no-op stub (serial_stubs.rec, 0 arguments, returns 0). The helper loads vtables from about twenty embedded sub-objects of
the hero at unaligned offsets, and a random hero faults on the first one, so running the helper for real needs the hero
layout (not in this batch). With the helper stubbed, GetAnims' own work is what is compared: two slot +0x58 lookups on the
hero (a logging vtable returning a 0x200-byte sub-object, which is the value stored at +0x553 and +0x557) and the word at
+0x371. Slot +0x54 returns 0.

CheckAction: a 0x200-byte group whose first dword is a type drawn from {3, 0, 1, 2, random}, flag byte at +0xc from
{0, 1, 2}, and member pointer at +8 to a leaf object (type 3, its own flag byte at +0xc; the member check 0x439670 recurses
along +8 while the type is not 3, so the leaf stops it). The member check 0x439670 runs from the exe image, not stubbed. The action update 0x438150 is STUBBED (a
counting no-op returning a per-case value), so only the bool it returns to CheckAction is compared."""
import os
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


def _hero(c):
    sub = _rnd(c, 0x200)
    svt = c.emu.logging_vtable('ZSubObject', 0x140,
                               impl={0x58: lambda e, a: (sub, None), 0x54: lambda e, a: (0, None)},
                               argwords={off: 1 for off in range(0, 0x140, 4)})
    c.emu.w32(sub, svt)
    o = _rnd(c, 0x1000)
    vt = c.emu.logging_vtable('ZFFHeroMovementOpenGate', 0x140,
                              impl={0x58: lambda e, a: (sub, None), 0x54: lambda e, a: (0, None)},
                              argwords={off: 1 for off in range(0, 0x140, 4)})
    c.emu.w32(o, vt)
    ss.patch(c, 0x5e3e90, ss.rec(c, 0, ret=0))   # base helper, stubbed (see the docstring)
    return [o]


def _group(c):
    g = _rnd(c, 0x200)
    c.emu.wbytes(g + 0xc, bytes([c.rng.choice([0, 1, 1, 2])]))
    c.emu.w32(g, c.rng.choice([3, 3, 0, 1, 2, c.rng.getrandbits(32)]))
    # The member check 0x439670 recurses along +8 while the type dword is not 3. The member is a leaf: type 3, its own
    # flag byte at +0xc, and +8 unused. So 0x439670 returns the member's flag without descending further.
    member = _rnd(c, 0x200)
    c.emu.w32(member, 3)
    c.emu.wbytes(member + 0xc, bytes([c.rng.choice([0, 1, 1, 2])]))
    c.emu.w32(g + 8, member)
    # 0x438150 (the action update) is STUBBED: it dereferences the dword at +0xd of the group, and a random group faults
    # there on the success path, so the path's return value was never compared. The stub returns a per-case value.
    ss.patch(c, 0x438150, ss.rec(c, 0, ret=c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])))
    return [g, c.rng.getrandbits(32)]


S(0x5e46a0, 'ZFFHeroMovementOpenGate::GetAnims (unknown) thiscall', 'thiscall', None, ret=None, gen=_hero,
  note='unclaimed-15 claim 3; base helper 0x5e3e90 STUBBED (rec, 0 args); slot +0x58 lookups; word +0x371 = 0x101')
S(0x437fa0, 'ZInputActions::CheckAction(ZInputActionGroup*, void*) (unknown) stdcall', 'stdcall', None, ret='al',
  gen=_group, note='unclaimed-15 claim 3; bool from 0x439670 on member +8; then 0x438150 (original) returns al')
