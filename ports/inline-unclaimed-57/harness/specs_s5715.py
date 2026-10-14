"""specs_s5715.py - unclaimed-57, batch 15: ZMoveOnSpline::GetCurrentSoundSet (0x512f80). Thiscall, no arguments, returns eax. Leaf.
The engine (global 0x70039c) has the dword at +0x1a9f set to zero in half the cases, so both paths run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gs(c):
    eng = _rnd(c, 0x2000)
    c.emu.w32(eng + 0x1a9f, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    c.emu.w32(0x70039c, eng)
    return [_rnd(c, 0x800)]


S(0x512f80, 'ZMoveOnSpline::GetCurrentSoundSet (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gs,
  note='unclaimed-57 batch 15; leaf; engine +0x1a9f selects zero or this+0x12f')
