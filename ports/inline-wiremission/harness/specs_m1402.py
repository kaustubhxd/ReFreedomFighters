"""specs_m1402.py - batch 1402: CPlayerStats / CPlayerProfile leaves."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, logger, hook_stub  # noqa: E402
from specs_m1400 import pool  # noqa: E402
from specs_m1401 import fill_table, stats, mgr_sys  # noqa: E402

NAMES = ['FirstTimeInZone', 'C02B_Flag', 'C02A_Flag', 'FirstTimeInZone', 'C02A_Obj1', 'Recruits']
LEVELS = ['C01A', 'C02A', 'C02RB', 'C03R', 'C05C', 'C08A', 'C09B', 'C1', '', 'C02', 'C0xR']


def st_obj(c):
    st = rnd(c, 0x100)
    stats(c, st)
    return st


def prof(c):
    pr = rnd(c, 0xe40)
    p = pool(c) + [cstr(c, n) for n in NAMES]
    fill_table(c, pr + 0x4b8, p)
    stats(c, pr + 0x35a)
    c.emu.w8(pr + 2, c.rng.choice(b'0123456789A'))
    c.emu.w8(pr + 0x35a + 0x4d, c.rng.choice(b'0123456789A'))
    return pr


def g_st(c):
    return [st_obj(c)]


def g_name(c):
    st = st_obj(c)
    logger(c, nargs=2)
    n = c.rng.choice([0, 1, 10, 61, 62, 63, 64, 70])
    return [st, cstr(c, ''.join(chr(c.rng.randrange(0x21, 0x7f)) for _ in range(n)))]


def g_str(c):
    st = st_obj(c)
    if c.rng.random() < 0.1:
        return [st, 0]
    return [st, cstr(c, c.rng.choice(['C02A', 'C1', '', 'C05B_x', 'AB']))]


def g_ini(c):
    st = st_obj(c)
    sysi = obj(c, 8, {0x5c: stub(c, 2, rets=[c.rng.choice([0, 1, 0x100])], this=True, outs=[(1, cstr(c, '12'))],
                                skip=(1,))})
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(0x6762d8, stub(c, 1, pop=0, ret=c.rng.getrandbits(32)))
    return [st]


def g_globals(c):
    st = st_obj(c)
    gv = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))] if c.rng.random() < 0.7 else ()),
                       0x90: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32), 1)] if c.rng.random() < 0.7 else ()),
                       0x6c: stub(c, 3, this=True)})
    disp = obj(c, 0x10, {0xdc: stub(c, 0, this=True, ret=c.rng.getrandbits(32))})
    sysi, mgr = mgr_sys(c, {0x134: stub(c, 0, this=True, ret=gv)}, {0xbc: stub(c, 0, this=True, ret=disp)})
    return [st]


def g_prof(c):
    return [prof(c)]


def g_prof_out(c):
    return [prof(c), rnd(c, 16)]


def g_inv(c):
    hook_stub(c, 0x5b0360, 0, this=True, ret=c.rng.getrandbits(32))
    return [prof(c)]


def g_savename(c):
    return [prof(c), cstr(c, c.rng.choice(['', 'Slot 1', 'x' * 40]))]


def g_serial(c):
    pr = prof(c)
    g_globals(c)
    return [pr]


def g_setlevel(c):
    pr = prof(c)
    logger(c)
    hook_stub(c, 0x5ae940, 1, this=True)
    lv = c.rng.choice(LEVELS)
    if c.rng.random() < 0.3:   # same zone as last time
        c.emu.w8(pr + 0x35a + 0x4d, ord(lv[2]) if len(lv) > 2 else 0)
    return [pr, cstr(c, lv)]


def g_slot(c):
    self_ = rnd(c, 0x2100 + 4 * 0x400)
    slot = c.rng.randrange(0, 4)
    c.emu.w8(self_ + slot * 0x80 + c.rng.randrange(0, 0x40), 0)
    hook_stub(c, 0x5ae450, 1, this=True)
    return [self_, prof(c), slot]


S(0x5acfa0, 'CPlayerStats::GetLastSubZone', 'thiscall', ret='eax', gen=g_st)
S(0x5acfb0, 'CPlayerStats::GetNoOfPrisonersFollowingHero', 'thiscall', ret='eax', gen=g_st)
S(0x5ad230, 'CPlayerStats::SetPlayerName', 'thiscall', ret=None, gen=g_name)
S(0x5ad2b0, 'CPlayerStats::SetStartPoint', 'thiscall', ret=None, gen=g_str)
S(0x5ad210, 'CPlayerStats::SetLastSubZone', 'thiscall', ret=None, gen=g_str)
S(0x5ad710, 'CPlayerStats::ClearUniqueBits', 'thiscall', ret=None, gen=g_st)
S(0x5ad2e0, 'CPlayerStats::SetVarsFromMainIni', 'thiscall', ret=None, gen=g_ini)
S(0x5acdb0, 'CPlayerStats::GetGlobalControlVals', 'thiscall', ret=None, gen=g_globals)
S(0x5b10f0, 'CSaveMissions::ClearRecent', 'thiscall', ret=None, gen=g_prof)
S(0x5adda0, 'CPlayerProfile::FirstTimeInZone', 'thiscall', ret='al', gen=g_prof)
S(0x5addc0, 'CPlayerProfile::GetAddCharactersId', 'thiscall', ret=None, gen=g_prof_out)
S(0x5ade30, 'CPlayerProfile::GetDeBriefingLocalizetPath', 'thiscall', ret='eax', gen=g_prof)
S(0x5ade90, 'CPlayerProfile::GetFFInventoryFromHero', 'thiscall', ret='eax', gen=g_inv)
S(0x5adea0, 'CPlayerProfile::GetSaveName', 'thiscall', ret='eax', gen=g_prof)
S(0x5ae900, 'CPlayerProfile::SetSaveName', 'thiscall', ret=None, gen=g_savename)
S(0x5ae240, 'CPlayerProfile::InitSaveDeviceSerialNumberAfterLoad', 'thiscall', ret=None, gen=g_serial)
S(0x5ae860, 'CPlayerProfile::SetLevel', 'thiscall', ret=None, gen=g_setlevel)
S(0x56b930, 'SaveSlots::SlotToProfile (map: SetFileName)', 'thiscall', ret=None, gen=g_slot)
