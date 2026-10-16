"""specs_s912.py - vehicles batch 912: heli wing guns / rocket creation, InitHeliPosDir."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub
import specs_s907 as b907

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def wing(c):
    g = _rnd(c, 0x60)
    for k in range(12):
        c.emu.w32(g + 4 * k, rf(c, -1, 1))
    c.emu.w32(g + 0x50, 0)
    return g


def weapons(c, n):
    ws = []
    for i in range(n):
        w = obj(c, 0x20, {0xbc: _stub(c, 1)})
        c.emu.w32(w + 8, _rnd(c, 0x48))
        ws.append(w)
    return ws


def heli_cw(c, ws):
    off = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(off + 4 * k, rf(c, -5, 5))
    # CreateWeapon: one stub per call is not possible (fixed return), so cycle: a small table via idstub on the
    # tag argument does not work either; the guns share one weapon object, which is what the record checks.
    return obj(c, 0x600, {0x328: _stub(c, 3, ret=ws[0]),
                          0x8c: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))})


def g_cwg(c):
    ws = weapons(c, 1)
    h = heli_cw(c, ws)
    return [h, c.emu.alloc(20, 4), wing(c)]


S(0x51c2e0, 'ZHeli::CreateWingGuns', 'thiscall', gen=g_cwg)


def g_cwr(c):
    ws = weapons(c, 1)
    return [heli_cw(c, ws), wing(c)]


S(0x51c3d0, 'ZHeli::CreateWingRocket', 'thiscall', ret='eax', gen=g_cwr)


def g_ihp(c):
    s = _rnd(c, 0x200)
    tgt = obj(c, 0x40)
    tv = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(tv + 4 * k, rf(c, -500, 500))
    c.emu.w32(c.emu.r32(tgt) + 0x84, _stub(c, 1, skip=(0,), fills=((0, tv, 3),)))
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [tgt] * 4)}))
    c.emu.w32(0x70039c, s)
    h = b907.heli_spd(c, {})
    p = b907.path(c)
    for o in (8, 0xc, 0x10):
        c.emu.w32(p + o, rf(c, -500, 500))
    c.emu.w32(h + 0x5c, p)
    c.emu.w32(h + 0x34a, c.rng.choice([0, 1]))
    tv2 = c.emu.alloc(0x10, 4)
    c.emu.w32(tv2 + 4, _stub(c, 2))
    c.emu.w32(h + 0x34e, tv2)
    return [h]


S(0x51c560, 'ZHeli::InitHeliPosDir', 'thiscall', gen=g_ihp)
