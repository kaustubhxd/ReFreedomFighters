"""specs_s1520.py - recruits thread batch 1520: BasicShape::GetSplinePos (0x460aa0).
The shape: segment count n at +0x10 (1..6), record array at +0xc (56 bytes per segment, 13 floats of the curve,
values in [-50, 50]). The curve evaluation (0x4604f0) runs as exe code (the port is batch21 of inline-batch45).
t runs over [-0.2, 1.2] so the clamp at n-1 and the negative side are both used."""
from pilot import S, F
from recruits_util import rnd, obj


def _gen(c):
    r = c.rng
    e = c.emu
    n = r.randint(1, 6)
    shape = rnd(c, 0x40)
    e.w32(shape + 0x10, n)
    recs = c.emu.alloc(56 * n + 16, 16)
    for i in range(56 * n // 4):
        c.emu.wf32(recs + 4 * i, r.uniform(-50, 50))
    e.w32(shape + 0xc, recs)
    out = rnd(c, 0x20)
    return [shape, out, F(r.uniform(-0.2, 1.2))]


S(0x460aa0, 'BasicShape::GetSplinePos', 'thiscall', gen=_gen, note='batch1520')


def _read_gen(c):
    from recruits_util import hook_rec, clear_hooks
    clear_hooks(c)
    r = c.rng
    uvals = [r.getrandbits(32) for _ in range(5)]
    fvals = [r.uniform(-10, 300), r.uniform(-10, 300)]
    hook_rec(c, 0x4e5e60, 0, ret=lambda em, k: uvals[min(k, 4)])
    hook_rec(c, 0x4e5e80, 0, st0=lambda em, k: fvals[min(k, 1)])
    return [rnd(c, 0x80), rnd(c, 0x10)]


S(0x4c79f0, 'BasicShape::ReadFields (GUESS, 0x4c79f0)', 'thiscall', ret='al', gen=_read_gen, note='batch1521')
