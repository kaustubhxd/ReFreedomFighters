"""specs_m1406.py - batch 1406: GetGameOSD, unique-bit counts, GiveRemainingCharisma, StartupRebelBase."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402
from specs_m1401 import lctrl, mgr_sys, stats  # noqa: E402


def g_osd(c):
    return [rnd(c, 0x2c40), c.rng.choice([0, 1, 2, 3])]


def g_count(c):
    st = rnd(c, 0x100)
    stats(c, st)
    return [st, c.rng.choice([0, 1, 2]), c.rng.choice([0, 1, 2, 3, 4])]


def g_lc_count(c):
    lc, p = lctrl(c)
    return [lc, c.rng.choice([0, 1, 2])]


def g_charisma(c):
    lc, p = lctrl(c)
    # mostly levels that can complete, keep at most 16 matching variables in the table
    lv = c.rng.choice(['C02A', 'C03B', 'C01A', 'C00A', 'C05C'])
    c.emu.wbytes(lc + 0x48, (lv + '\0').encode())
    t = lc + 0x50f
    c.emu.w32(t + 0x5b8, min(c.emu.r32(t + 0x5b8), 14))
    c.emu.w32(lc + 0x467, c.rng.choice([0, 1, 3, 5, 31, 33]))   # = stats bit count of type 1 (prisoners)
    gd = rnd(c, 0x2c40)
    c.emu.w32(gd + 0x2c2d, rnd(c, 16) if c.rng.random() < 0.8 else 0)
    c.emu.w32(0x7003b8, gd)
    hook_stub(c, 0x596940, 4, this=True, skip=(1,))
    hook_stub(c, 0x5acfb0, 0, this=True, ret=c.rng.choice([0, 1, 2, 3]))
    return [lc]


def g_rebel(c):
    lc, p = lctrl(c)
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    mgr_sys(c, {0x138: stub(c, 0, this=True, ret=reg),
                0x58: stub(c, 1, this=True, ret=rnd(c, 8) if c.rng.random() < 0.8 else 0)})
    hook_stub(c, 0x485060, 1, this=True)
    return [lc]


S(0x589c20, 'ZFFGameData::GetGameOSD', 'thiscall', ret='eax', gen=g_osd)
S(0x5ad6c0, 'CPlayerStats::UniqueBitCountTrue', 'thiscall', ret='eax', gen=g_count)
S(0x59d1b0, 'ZFFLevelController::UniqueBitCountTrue', 'thiscall', ret='eax', gen=g_lc_count)
S(0x59b710, 'ZFFLevelController::GiveRemainingCharisma', 'thiscall', ret=None, gen=g_charisma)
S(0x59ce00, 'ZFFLevelController::StartupRebelBase', 'thiscall', ret=None, gen=g_rebel)
