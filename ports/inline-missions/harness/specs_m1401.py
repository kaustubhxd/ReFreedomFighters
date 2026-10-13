"""specs_m1401.py - batch 1401: SetLevelVar and mission save data, CBuffer dword/char I/O, profile thunks,
unique bits, ZFFLevelController leaves, CEnemyFlag::FlagPole, ZFFFlak::CheckMissionVar."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, logger  # noqa: E402
from specs_m1400 import POOL, pool, key  # noqa: E402

LEVELS = ['C01A', 'C00A', 'C02B', 'C05D', 'C03C', 'C08E', 'C0', 'C01AB', 'C09A', 'C1']


def fill_table(c, s, p, maxcount=0x74):
    n = c.rng.choice([0, 1, 2, 5, 12, c.rng.randrange(0, maxcount + 1)])
    c.emu.w32(s + 0x5b8, n)
    for i in range(0x74):
        c.emu.w32(s + 8 + 4 * i, c.rng.choice(p))
        c.emu.w32(s + 0x3c8 + 4 * i, c.rng.choice([0, 0, 1, 1, 2, 0xffffffff, c.rng.getrandbits(32)]))
        c.emu.w32(s + 0x5c0 + 4 * i, c.rng.choice([0, 0, 0, 1, 2, 3, 4, 5]))
    for k in range(8):
        c.emu.w32(s + 0x598 + 4 * k, c.rng.choice([0xffffffff, 0xffffffff, 3, c.rng.getrandbits(32)]))


def table(c):
    s = rnd(c, 0x960)
    p = pool(c)
    fill_table(c, s, p)
    return s, p


def buf(c, cap=None, fill=True):
    cap = c.rng.choice([0, 1, 3, 4, 5, 8, 100, 124, 127, 128, 200, 300]) if cap is None else cap
    b = c.emu.alloc(16, 4)
    d = rnd(c, cap + 8) if fill else c.emu.alloc(cap + 8, 4)
    pos = c.rng.choice([0, 0, 0, max(cap - 4, 0), max(cap - 1, 0), cap, c.rng.randrange(0, cap + 1)])
    c.emu.w32(b, cap)
    c.emu.w32(b + 4, pos)
    c.emu.w32(b + 8, d)
    c.emu.w8(b + 12, c.rng.choice([0, 0, 0, 1, 0x80]))
    return b


def g_add32(c):
    return [buf(c), c.rng.getrandbits(32)]


def g_get(c):
    return [buf(c), rnd(c, 8)]


def g_set(c):
    s, p = table(c)
    logger(c)
    v = c.rng.choice([0, 1, 2, 0xffffffff, c.rng.getrandbits(32)])
    return [s, key(c, p), v]


def g_put(c):
    s, p = table(c)
    return [s, buf(c, cap=c.rng.choice([0, 4, 50, 124, 127, 128, 129, 200]))]


def g_take(c):
    s, p = table(c)
    logger(c, nargs=2)
    b = buf(c, cap=c.rng.choice([0, 3, 4, 50, 120, 124, 151, 152, 200]))
    d = c.emu.r32(b + 8)
    c.emu.w32(b + 4, c.rng.choice([0, 0, 0, 1]))
    c.emu.w32(d + c.emu.r32(b + 4), c.rng.choice([1, 1, 2, 2, 0, 3, c.rng.getrandbits(32)]))
    return [s, b]


def profile(c):
    pr = rnd(c, 0x4b8 + 0x960)
    p = pool(c)
    fill_table(c, pr + 0x4b8, p)
    return pr, p


def g_prof_get(c):
    pr, p = profile(c)
    return [pr, key(c, p)]


def g_prof_sub(c):
    pr, p = profile(c)
    fill_table(c, pr + 0x4b8, p, maxcount=40)
    return [pr, rnd(c, 0x108), key(c, p)]


def g_prof_set(c):
    pr, p = profile(c)
    logger(c)
    return [pr, key(c, p), c.rng.choice([0, 1, c.rng.getrandbits(32)])]


def stats(c, st):
    """bits[3 types][5 sub-zones] at +0x76, then the per-type bit counts at +0xb2 (written last; a type above 2
    reads counts as bits, which stays bounded)."""
    for i in range(15):
        c.emu.w32(st + 0x76 + 4 * i, c.rng.choice([0xffffffff, 0xffffffff, 0x7fffffff, 0, c.rng.getrandbits(32)]))
    for t in range(8):
        c.emu.w32(st + 0xb2 + 4 * t, c.rng.choice([0, 1, 2, 5, 31, 32, 33, c.rng.randrange(0, 40)]))


def g_st_all(c):
    st = rnd(c, 0x200)
    stats(c, st)
    return [st, c.rng.choice([0, 1, 2, 3]), c.rng.choice([0, 1, 2, 3, 4])]


def g_st_get(c):
    st = rnd(c, 0x200)
    stats(c, st)
    return [st, c.rng.getrandbits(32), c.rng.choice([0, 1, 2]), c.rng.choice([0, 1, 2, 3, 4])]


def g_st_set(c):
    a = g_st_get(c)
    return a[:3] + [c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]), a[3]]


def lctrl(c, size=0x1100):
    lc = rnd(c, size)
    lv = c.rng.choice(LEVELS)
    if c.rng.random() < 0.2:
        lv = 'C0' + chr(c.rng.randrange(0x20, 0x7f)) + chr(c.rng.randrange(0x20, 0x7f))
    c.emu.wbytes(lc + 0x48, (lv + '\0').encode('latin-1'))
    p = pool(c)
    fill_table(c, lc + 0x50f, p)
    stats(c, lc + 0x3b1)
    return lc, p


def g_lc(c):
    return [lctrl(c)[0]]


def g_lc_get(c):
    lc, p = lctrl(c)
    return [lc, key(c, p)]


def g_lc_next(c):
    lc, p = lctrl(c)
    return [lc, cstr(c, c.rng.choice(['', 'C02A', 'FF-C01A_MAIN', 'x' * 30]))]


def g_lc_id(c):
    lc, p = lctrl(c)
    return [lc, c.rng.choice([0, 1, 2, 3, 4])]


def g_lc_state(c):
    lc, p = lctrl(c)
    return [lc, c.rng.choice([0, 1, 1, 2]), c.rng.getrandbits(32) if c.rng.random() < 0.2 else c.rng.randrange(0, 34)]


def g_lc_setstate(c):
    lc, p = lctrl(c)
    logger(c, skip=(2,))   # the name passed on is a stack buffer
    return [lc, c.rng.choice([0, 1, 1, 1, 2]), c.rng.randrange(0, 34), c.rng.choice([0, 1, 1, 0x100])]


def g_charisma(c):
    lc, p = lctrl(c)
    s = c.rng.choice(['C01A', 'C02A', 'C03B', 'C04A', 'C05A', 'C06A', 'C07A', 'C08A', 'C09A', 'C00A', 'C0:A', 'C0/'])
    return [lc, cstr(c, s)]


def g_sewer(c):
    lc, p = lctrl(c)
    if c.rng.random() < 0.15:
        return [lc, 0]
    t = rnd(c, 16)
    nm = c.rng.choice(['Sewer07', 'SewerLid12', 'x', 'AB', 'Lid_9z', None])
    c.emu.w32(t + 4, cstr(c, nm) if nm is not None else 0)
    o = obj(c, 16, {0x20: stub(c, 0, ret=t, this=True)})
    g = obj(c, 16, {0x20: stub(c, 0, ret=o, this=True)})
    return [lc, g]


def mgr_sys(c, mslots, sslots=None):
    mgr = obj(c, 0x40, mslots)
    sysi = obj(c, 0x100, sslots or {0: 0})
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    return sysi, mgr


def g_endscene(c):
    lc, p = lctrl(c)
    c.emu.w8(lc + 0x1042, c.rng.choice([0, 1, 0x80]))
    mgr_sys(c, {0xa8: stub(c, 0, this=True, ret=c.rng.getrandbits(32)), 0xa4: stub(c, 0, this=True),
                0xa0: stub(c, 1, this=True)}, {0xc: stub(c, 4, this=True)})
    return [lc]


def g_flag(c):
    f = rnd(c, 0x120)
    if c.rng.random() < 0.4:
        c.emu.w32(f + 0x115, 0)
    mgr_sys(c, {0x58: stub(c, 1, this=True, ret=c.rng.getrandbits(32))})
    return [f]


def g_flak(c):
    lc = obj(c, 0x40, {0x128: stub(c, 3, this=True, skip=(1,), derefs=[(1, 4)],
                                  outs=[(1, c.rng.choice([0, 0, 1, 0x100, c.rng.getrandbits(32)]))])})
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    mgr_sys(c, {0x138: stub(c, 0, this=True, ret=reg),
                0x58: stub(c, 1, this=True, ret=lc if c.rng.random() < 0.8 else 0),
                0x114: stub(c, 4, this=True, ret=c.rng.getrandbits(32))})
    logger(c, nargs=2)
    return [rnd(c, 0x40), cstr(c, c.rng.choice(['', 'C02A_FlakOff', 'x']))]


S(0x5f01c0, 'CBuffer::Add(unsigned int)', 'thiscall', ret='al', gen=g_add32)
S(0x5f0280, 'CBuffer::Get(unsigned int*)', 'thiscall', ret='al', gen=g_get)
S(0x5f02f0, 'CBuffer::Get(char*)', 'thiscall', ret='al', gen=g_get)
S(0x5b1150, 'CSaveMissions::SetLevelVar', 'thiscall', ret=None, gen=g_set)
S(0x5b1070, 'CSaveMissions::PutDataIntoBuffer', 'thiscall', ret='al', gen=g_put)
S(0x5b1330, 'CSaveMissions::TakeDataOutOfBuffer', 'thiscall', ret='al', gen=g_take)
S(0x5adeb0, 'CPlayerProfile::GetLevelVar', 'thiscall', ret='eax', gen=g_prof_get)
S(0x5adee0, 'CPlayerProfile::GetSubZoneMissionInfo', 'thiscall', ret=None, gen=g_prof_sub)
S(0x5ae930, 'CPlayerProfile::SetLevelVar', 'thiscall', ret=None, gen=g_prof_set)
S(0x5ad640, 'CPlayerStats::UniqueBitAllBitsTrue', 'thiscall', ret='al', gen=g_st_all)
S(0x5ad690, 'CPlayerStats::UniqueBitGetIDState', 'thiscall', ret='al', gen=g_st_get)
S(0x5ad740, 'CPlayerStats::UniqueBitSetIDState', 'thiscall', ret=None, gen=g_st_set)
S(0x59b6d0, 'ZFFLevelController::GetSubZone', 'thiscall', ret='eax', gen=g_lc)
S(0x59b310, 'ZFFLevelController::GetLevelVar', 'thiscall', ret='eax', gen=g_lc_get)
S(0x59cb60, 'ZFFLevelController::SetNextScene', 'thiscall', ret=None, gen=g_lc_next)
S(0x59d130, 'ZFFLevelController::UniqueBitGetID', 'thiscall', ret='eax', gen=g_lc_id)
S(0x59d150, 'ZFFLevelController::UniqueBitGetIDState', 'thiscall', ret='al', gen=g_lc_state)
S(0x59d090, 'ZFFLevelController::UniqueBitAllBitsTrue', 'thiscall', ret='al', gen=g_lc_id)
S(0x59d250, 'ZFFLevelController::UniqueBitSetIDState', 'thiscall', ret=None, gen=g_lc_setstate)
S(0x59ca50, 'ZFFLevelController::SetDefaultCharisma', 'thiscall', ret=None, gen=g_charisma)
S(0x59b350, 'ZFFLevelController::GetSewerId', 'thiscall', ret='eax', gen=g_sewer)
S(0x59be70, 'ZFFLevelController::LevelComplete', 'thiscall', ret='al', gen=g_lc)
S(0x59c420, 'ZFFLevelController::PushEndScene', 'thiscall', ret=None, gen=g_endscene)
S(0x5c1650, 'CEnemyFlag::FlagPole', 'thiscall', ret='eax', gen=g_flag)
S(0x5dc7a0, 'ZFFFlak::CheckMissionVar', 'thiscall', ret='al', gen=g_flak)
