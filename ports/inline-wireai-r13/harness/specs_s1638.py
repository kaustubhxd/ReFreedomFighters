"""specs_s1638.py - residue 13 batch 1638: CActionController::RemoveEvaluator. The evaluator objects are 0x844-byte
records whose first dword is the id; the delete (0x634273) is a recorder. The parallel words (+0x48 + 4k) are written
first, then the evaluator pointers and the count, so the count is not overwritten."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x634273, 2, this=False, pop=False)
    self_ = rnd(c, 0x200)
    for k in range(1, 12):
        c.emu.w32(self_ + 0x48 + 4 * k, r.getrandbits(8))   # parallel words (read when a middle entry is removed)
    n = r.randint(0, 6)
    for i in range(n):
        o = rnd(c, 0x844)
        c.emu.w32(o, r.choice([1, 2, 3, 4, 5]))
        c.emu.w32(self_ + 0x5c + 4 * i, o)
    c.emu.w32(self_ + 0x48, n)
    return [self_, r.choice([1, 2, 3, 4, 5, 6])]


S(0x4a1850, 'CActionController::RemoveEvaluator', 'thiscall', None, ret=None, gen=_gen, note='batch1638')
