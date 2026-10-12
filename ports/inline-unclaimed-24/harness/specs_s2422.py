"""specs_s2422.py - decomp area 24, batch 2422: ZSoundAmbient::GetValues(DBREAD&) (0x4a4260) and its forwarder
(0x4a3e70). GetValues reads two REFTABs (0x4e6330, recorder) and two floats (0x4e5e80, recorder, st0). The floats are
drawn from 0.0, -0.0, NaN and random values, so the equal-to-zero and NaN branches run. The object at +0x44 has a
name-lookup slot 0x104 (one stack argument, recorder returning a random dword), called four times."""
import math
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x200)
    db = rnd(c, 0x40)
    tab = obj(c, 0x40, {0x104: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    e.w32(self_ + 0x44, tab)
    vals = [0.0, -0.0, math.nan]

    def fv(emu, k):
        x = r.random()
        if x < 0.2:
            return F(r.choice(vals))
        return F(r.uniform(-2.0, 2.0))
    hook_rec(c, 0x4e6330, 1, this=True)
    hook_rec(c, 0x4e5e80, 0, this=True, st0=fv)
    return [self_, db]


S(0x4a4260, 'ZSoundAmbient::GetValues', 'thiscall', None, ret='al', gen=_gen, note='batch2422')
S(0x4a3e70, 'ZSoundAmbient::CopyEventDataBlock', 'thiscall', None, ret='al', gen=_gen, note='batch2422')
