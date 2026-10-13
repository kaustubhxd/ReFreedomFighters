"""specs_s205.py - ladder thread batch 205: 0x5e5f90 ZFFHeroMovementGuide::Move (mount, climb, dismount state machine)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _mv(c):
    e, r = c.emu, c.rng
    g = K.rnd(c, 0x600)
    st = r.choice([0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 2, 3, 4, 5])
    e.w32(g + 0x579, st)
    hero = K.rnd(c, 0x480)
    e.w32(hero + 0x417, r.getrandbits(3) if r.random() < 0.9 else r.getrandbits(32))
    e.w32(g + 0x36d, hero)
    eng = K.engine(c)
    now = r.getrandbits(31)
    e.w32(eng + 0x40, now)
    e.wf32(eng + 0x48, f32(r.uniform(0.0, 0.1)))
    if st in (0, 1):
        d = r.randint(-50, 400) if r.random() < 0.9 else r.getrandbits(32)
    else:
        d = r.randint(-100, 1200) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.1:
        d = r.choice([0, 655, 656, 737, 738, 245, 246])   # near 16 frames, 18 frames, 0.24 s
    e.w32(g + 0x5dd, (now - d) & 0xffffffff)
    e.wf32(g + 0x18, 0.0 if r.random() < 0.3 else f32(r.uniform(0.0, 0.1)))
    base = [c.fv(-500.0, 500.0) for _ in range(3)]
    for off in (0x554, 0x560, 0x5a1, 0x5d1):
        for i in range(3):
            e.wf32(g + off + 4 * i, f32(base[i] + r.uniform(-50, 50) + (300.0 if off == 0x560 and i == 1 else 0.0)))
    for i in range(3):
        e.wf32(g + 0x56c + 4 * i, c.fv(-1.0, 1.0))
    for off in (0x57d, 0x5ad):
        for i in range(9):
            e.wf32(g + off + 4 * i, c.fv(-1.0, 1.0))
    mat = c.fbuf(9, lambda cc: cc.fv(-1.0, 1.0))
    pos = c.emu.alloc(0x20, 4)
    y0 = e.rf32(g + 0x558) if r.random() < 0.5 else e.rf32(g + 0x564)
    for i, v in enumerate([base[0], f32(y0 + r.uniform(-120, 120)), base[2]]):
        e.wf32(pos + 4 * i, f32(v))
    matOut = K.rnd(c, 0x30)
    posOut = K.rnd(c, 0x10)
    delta = K.rnd(c, 0x10)
    return [g, mat, pos, matOut, posOut, delta]


S(0x5e5f90, 'ZFFHeroMovementGuide::Move', 'thiscall', None, ret=None, gen=_mv,
  note='batch205; ladder state machine 0..6: walk to grab point, mount, climb 5/frame, climb off')
