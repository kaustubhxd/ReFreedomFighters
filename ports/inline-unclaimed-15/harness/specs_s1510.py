"""specs_s1510.py - unclaimed-15 claim 10 (docs/20-unclaimed-15.md): CExplodeMolotov::PlaySound (0x584a20).

Stubbed (unverified): the helper 0x43ec00 (serial_stubs.rec with 0 args, returning a per-case value), the sub-object's
slot +0x20 (logged, six stack words) and the render manager's slot +0x60 (logged, one word; returns a 0x200-byte heap
object, or null in 20% of cases). The sound manager's flag at +0x1a9f is 0, 1 or random, so both early returns run. The
self object is 0x200 random bytes with the sub-object at +0x44 (its +8 is random). The second argument is drawn from
{-1, 0, 5, -3, random} so the -1 skip runs."""
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


def _playsound(c):
    o = _rnd(c, 0x400)              # the store at +0x36e must lie inside the object
    sub = _rnd(c, 0x200)
    svt = c.emu.logging_vtable('ZMolotovSub', 0x40,
                               impl={0x20: lambda e, a: (c.rng.getrandbits(32), None)},
                               argwords={0x20: 6})
    c.emu.w32(sub, svt)
    c.emu.w32(sub + 8, c.rng.getrandbits(32))
    c.emu.w32(o + 0x44, sub)
    rm = _rnd(c, 0x1000)
    c.emu.wbytes(rm + 0x1a9e, bytes([c.rng.randrange(1, 256)]))   # nonzero byte below the flag, so a read at +0x1a9e differs
    c.emu.w32(rm + 0x1a9f, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    target = _rnd(c, 0x200) if c.rng.random() < 0.8 else 0
    robj = _rnd(c, 0x200)
    rvt = c.emu.logging_vtable('ZRenderSub', 0x100, impl={0x60: lambda e, a: (target, None)}, argwords={0x60: 1})
    c.emu.w32(robj, rvt)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x43ec00, ss.rec(c, 0, ret=c.rng.getrandbits(32)))
    a1 = c.rng.choice([0, 1, 0x1234, c.rng.getrandbits(32)])
    a2 = c.rng.choice([0xffffffff, 0, 5, 0xfffffffd, c.rng.getrandbits(32)])
    return [o, a1, a2]


S(0x584a20, 'CExplodeMolotov::PlaySound (unknown) thiscall', 'thiscall', None, ret=None, gen=_playsound,
  note='unclaimed-15 claim 10; helper 0x43ec00 stubbed; sub slot +0x20 (6 words) and render slot +0x60 logged')
