"""specs_m1400.py - batch 1400: CSaveMissions (mission-variable table).
Names come from a small pool of level-prefixed strings (shared pointers and equal copies), so prefix and full-name
matches both happen. Types 0..4, values mostly 0/1."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, logger  # noqa: E402

POOL = ['C01A_Obj1', 'C01A_Obj2', 'C01A', 'C01B_Flag', 'C01AX', 'C02A_Bomb', 'C02A_Obj1', 'C0', 'C01A_Obj1',
        'XXXX_Completed', 'C03C_Sec', '']


def pool(c):
    return [cstr(c, s) for s in POOL]


def table(c, maxcount=0x74, full=False):
    """A random CSaveMissions; returns (obj, string pointers)."""
    s = rnd(c, 0x960)
    p = pool(c)
    n = 0x74 if full else c.rng.choice([0, 1, 2, 5, 12, c.rng.randrange(0, maxcount + 1)])
    c.emu.w32(s + 0x5b8, n)
    for i in range(0x74):
        c.emu.w32(s + 8 + 4 * i, c.rng.choice(p))
        c.emu.w32(s + 0x3c8 + 4 * i, c.rng.choice([0, 0, 1, 1, 2, 0xffffffff, c.rng.getrandbits(32)]))
        c.emu.w32(s + 0x5c0 + 4 * i, c.rng.choice([0, 0, 0, 1, 2, 3, 4, 5]))
    return s, p


def key(c, p):
    return c.rng.choice(p) if c.rng.random() < 0.8 else cstr(c, c.rng.choice(POOL))


def g_ctor(c):
    return [rnd(c, 0x960)]


def g_add(c):
    s, p = table(c)
    if c.rng.random() < 0.2:
        c.emu.w32(s + 0x5b8, c.rng.choice([0x73, 0x74, 0x75, 0x200]))
    logger(c)
    return [s, c.rng.choice([0, 1, 2, 3, 3, 4, c.rng.getrandbits(32)]), c.rng.getrandbits(32), c.rng.getrandbits(32),
            c.rng.getrandbits(32)]


def g_addl(c):
    a = g_add(c)
    return [a[0], a[2], a[4]]


def g_get(c):
    s, p = table(c)
    return [s, key(c, p)]


def g_sub(c):
    s, p = table(c, maxcount=40)
    out = rnd(c, 0x108)
    # at most 16 matches fit: keep the case inside the output, as the original writes past it unchecked
    return [s, out, key(c, p)]


def g_ini(c):
    s, p = table(c)
    rets = [c.rng.choice([0, 1, 0x100, 0xffffff01]) for _ in range(16)]
    sysi = obj(c, 8, {0x5c: stub(c, 2, rets=rets, this=True, outs=[(1, c.rng.choice(p))], skip=(1,))})
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(0x6762d8, stub(c, 1, pop=0, rets=[c.rng.getrandbits(32) for _ in range(16)]))
    return [s]


S(0x5b0990, 'CSaveMissions::CSaveMissions', 'thiscall', ret='eax', gen=g_ctor)
S(0x5b0a60, 'CSaveMissions::AddVar', 'thiscall', ret=None, gen=g_add)
S(0x5b0a20, 'CSaveMissions::AddMission', 'thiscall', ret=None, gen=g_add)
S(0x5b0a00, 'CSaveMissions::AddAdditional', 'thiscall', ret=None, gen=g_addl)
S(0x5b0b70, 'CSaveMissions::GetLevelVar', 'thiscall', ret='eax', gen=g_get)
S(0x5b0bf0, 'CSaveMissions::GetNumPrimaryObjectives', 'thiscall', ret='eax', gen=g_get)
S(0x5b0c50, 'CSaveMissions::GetNumPrimaryObjectivesCompleted', 'thiscall', ret='eax', gen=g_get)
S(0x5b1000, 'CSaveMissions::LevelCompleted', 'thiscall', ret='al', gen=g_get)
S(0x5b1440, 'CSaveMissions::ZoneCompleted', 'thiscall', ret='al', gen=g_get)
S(0x5b0af0, 'CSaveMissions::CompleteSecondaryTargets', 'thiscall', ret=None, gen=g_get)
S(0x5b0f20, 'CSaveMissions::GetSubZoneMissionInfo', 'thiscall', ret=None, gen=g_sub)
S(0x5b12d0, 'CSaveMissions::SetVarsFromMainIni', 'thiscall', ret=None, gen=g_ini)
