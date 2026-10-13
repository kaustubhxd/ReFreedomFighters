"""specs_s1102.py - unclaimed-11 batch 2 (docs/20-unclaimed-11.md): ZMoveOnSpline::CanSee, ZMovementBase::GetActiveAnim,
ZCollisionBase::LoadUniqueSubStripInfo. CanSee calls CCheckVisible::CanSee (0x4a9cb0, original code via ext_4a9cb0), so
its object at +0x13c is a random 0x800-byte buffer; the sight target at +0x140 is -1 about a third of the time (the
early-out branch)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


def _canseen(c):
    # Sight table for CCheckVisible::CanSee: 200 dwords at co+0x54 with stride 8 (the search loop); the seer index
    # (this+0x140) selects a 0x1b8 record, and the found slot's word at +0x6bc decides the result.
    o = _rnd(c, 0x800)
    co = _rnd(c, 0x2000)
    table = [c.rng.getrandbits(32) for _ in range(200)]
    for i, v in enumerate(table):
        c.emu.w32(co + 0x54 + 8 * i, v)
    c.emu.w32(o + 0x13c, co)
    r = c.rng.random()
    c.emu.w32(o + 0x140, 0xffffffff if r < 0.2 else c.rng.randint(0, 3))
    ref = c.rng.choice(table)
    return [o, ref]


def _obj_u32x2(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _obj_5(c):
    return [_rnd(c, 0x800)] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x5122c0, 'ZMoveOnSpline::CanSee (unknown) thiscall', 'thiscall', None, ret='al', gen=_canseen,
  note='unclaimed-11; -1 at +0x140 gives false, else CCheckVisible::CanSee (ext)')
S(0x4884a0, 'ZMovementBase::GetActiveAnim (GUESS) thiscall', 'thiscall', None, ret='st0', gen=_obj_5,
  note='unclaimed-11; fld float at +0xc, ret 0x14')
S(0x4edce0, 'ZCollisionBase::LoadUniqueSubStripInfo (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_obj_u32x2, note='unclaimed-11; (a1 to +0x190, a2>>3 to +0x194, byte 1 to +0x19c)')
