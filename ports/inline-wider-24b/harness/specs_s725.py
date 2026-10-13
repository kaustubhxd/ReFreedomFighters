"""specs_s725.py - soldier AI batch 725: ZFFActorIf::GetCoverStandPos. The world: the engine global record at 0x7003b8 (heap
object) with the cover list at +0x2c1d; the list's inline spot list at +0x5f holds 1..4 records of 0x48 bytes (pos at +0x10,
facing at +0x28, type bits at +0x34). The actor (this+0x1c) has +0x54 -> a record whose +4 is the stance flag. The argument
block gives an input accessor (spot index, flag A, flag B) and an output accessor of six items with random values. Accessors
and setters (0x5003d0, 0x500360), the vector helpers and createmat run as exe code. The index is drawn from -1, -5 and the
valid record range, so both the cover path and the default path run."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world


def _list(c, e, items, count):
    """accessor object: +0 -> inner (items at +0, count at +8); items are 8 bytes (value, type byte)."""
    inner = _rnd(c, 0x20)
    arr = _rnd(c, 8 * max(count, 2))
    for i in range(max(count, 2)):
        e.wbytes(arr + 8 * i, struct.pack('<II', items[i] if i < len(items) else c.rng.getrandbits(32), 0))
    e.w32(inner, arr)
    e.w32(inner + 8, count)
    acc = _rnd(c, 0x20)
    e.w32(acc, inner)
    e.w32(acc + 4, 0)
    e.w32(acc + 8, count)
    return acc


def _cgs(c):
    e = c.emu
    _log_world(c)
    gl = _rnd(c, 0x2c40)
    e.w32(0x7003b8, gl)
    cl = _rnd(c, 0x100)
    e.w32(gl + 0x2c1d, cl)
    n = c.rng.randint(1, 4)
    recs = _rnd(c, 0x48 * n)
    e.w32(cl + 0x5f, recs)
    for i in range(n):
        r = recs + 0x48 * i
        for off in (0x10, 0x14, 0x18, 0x28, 0x2c, 0x30):
            e.wbytes(r + off, struct.pack('<f', c.rng.uniform(-400.0, 400.0)))
        e.w32(r + 0x34, c.rng.choice([1, 2, 4]) | c.rng.choice([0, 8, 0x10]))

    actor = _rnd(c, 0x80)
    st = _rnd(c, 0x20)
    e.w32(st + 4, c.rng.choice([0, 1]))
    e.w32(actor + 0x54, st)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, actor)

    idx = c.rng.choice([-1, -5] + list(range(n)))
    fa = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    fb = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    args = _rnd(c, 0x20)
    e.w32(args + 4, _list(c, e, [idx & 0xffffffff, fa, fb], 3))
    e.w32(args + 8, _list(c, e, [c.rng.getrandbits(32) for _ in range(6)], 6))
    return [self_, args]


S(0x5595f0, 'ZFFActorIf::GetCoverStandPos', 'thiscall', None, ret=None, gen=_cgs,
  note='b725 [medium]; accessor, setter and vector helpers run as exe code; cover and default paths both exercised')
