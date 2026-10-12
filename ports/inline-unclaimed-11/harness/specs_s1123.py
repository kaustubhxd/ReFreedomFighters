"""specs_s1123.py - unclaimed-11 batch 24 (gap band): 0x5a4590, thiscall, one int argument (ret 4). Name map (low):
CMPGameController::GetHeroStat(int). Body: if (idx - 1) as unsigned is at most 3, eax = this + 0x99 + 16*idx; else eax = 0.
The argument is drawn from -2..6 (in range 1..4 about 2/3 of the time, plus random values). The object is 0x200 random bytes."""
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    idx = c.rng.randint(-2, 6) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [o, idx & 0xffffffff]


S(0x5a4590, 'CMPGameController::GetHeroStat (low) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 24 (gap band)')
