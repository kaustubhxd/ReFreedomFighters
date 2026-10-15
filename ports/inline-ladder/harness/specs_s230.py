"""specs_s230.py - ladder thread batch 230: ZIKLNKOBJ::SetFacingTarget (blend continuation timing)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from pe_emu import f32
import ladder_kit as K


def _sf(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    e.w8(s + 0x158, 0 if r.random() < 0.85 else r.randint(1, 255))
    if r.random() < 0.5:
        e.w32(s + 0x136, e.r32(s + 0x136) & ~0x200000)
    eng = K.engine(c)
    now = r.randint(0, 1 << 22)
    e.w32(eng + 0x40, now)
    st = f32(now / 1024.0 - r.uniform(0, 3))
    k = r.random()
    e.wf32(s + 0x1a2, st if k < 0.45 else (-st if k < 0.9 else c.fv()))
    e.wf32(s + 0x19e, r.choice([0.0, 0.25, 0.5, 1.0, f32(r.uniform(0, 3)), c.fv()]))
    ref = r.getrandbits(32)
    if r.random() < 0.3:
        e.w32(s + 0x1a6, ref)
    t = r.choice([0.0, 0.25, 0.5, 1.0, f32(r.uniform(0, 3)), c.fv()])
    return [s, ref, F(t)] + [r.getrandbits(32) for _ in range(4)]


S(0x4678f0, 'ZIKLNKOBJ::SetFacingTarget', 'thiscall', None, ret=None, gen=_sf, note='batch230')
