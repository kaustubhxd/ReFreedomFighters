"""specs_s905.py - unclaimed-01 claim 4 (docs/20-unclaimed-01.md): ZMovementGuide::GotControl (0x489340),
ZFFPRIVATESTDOBJ::OverrideViewMatrix (0x5aaae0), ZFFHeroMovementBaseMove::TerminateControl (0x5e7180) and
ZMovementGuide::TerminateControl (0x489d60). Objects are 0x800 random bytes; the movement guide's pointer at +4 points to
its own 0x800-byte record, so the bit tests and clears land in memory the harness compares."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _guide(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 4, _rnd(c, 0x800))
    return [o]


def _guide_arg(c):
    o = _guide(c)
    return o + [c.rng.getrandbits(32)]


def _stdobj(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x18, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]))
    return [o]


def _hero(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x489340, 'ZMovementGuide::GotControl (unknown) thiscall', 'thiscall', None, ret=None, gen=_guide,
  note='unclaimed-01 claim 4; sets 0x400000 in the owner')
S(0x5aaae0, 'ZFFPRIVATESTDOBJ::OverrideViewMatrix (unknown) thiscall', 'thiscall', None, ret='al', gen=_stdobj,
  note='unclaimed-01 claim 4; al = (dword +0x18 != 0)')
S(0x5e7180, 'ZFFHeroMovementBaseMove::TerminateControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_hero,
  note='unclaimed-01 claim 4; clears byte +0x54b, returns true')
S(0x489d60, 'ZMovementGuide::TerminateControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_guide_arg,
  note='unclaimed-01 claim 4; clears +0x371 and owner bit, returns true')
