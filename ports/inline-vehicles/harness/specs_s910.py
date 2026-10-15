"""specs_s910.py - vehicles batch 910: heli turn mode, roll/tilt, height."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, fconst, idstub, cstub


def gen(c, h, off, out):
    val = c.emu.alloc(4, 4)
    c.emu.w32(val, rf(c, -1, 1))
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 8, _stub(c, 1, fills=((0, val, 1),)))
    c.emu.w32(vt + 0x20, _stub(c, 0, ret=c.rng.choice([0, 1])))
    c.emu.w32(vt + 4, _stub(c, 3))
    c.emu.w32(h + off, vt)


def sysx(c, extra=None):
    s = _rnd(c, 0x200)
    rv = fconst(c, c.rng.uniform(-1, 1))
    tgt = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), fills=((0, c.emu.alloc(12, 4), 0),))})
    tv = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(tv + 4 * k, rf(c))
    c.emu.w32(c.emu.r32(tgt) + 0x84, _stub(c, 1, skip=(0,), fills=((0, tv, 3),)))
    wd = obj(c, 0x40, {0x58: idstub(c, [tgt, tgt, tgt, tgt])})
    c.emu.w32(s + 0x9b, wd)
    dbg = obj(c, 0x10, {0x184: cstub(c, 8)})
    slots = {0x1c4: _stub(c, 2, fld=rv), 0x190: _stub(c, 0, ret=dbg)}
    c.emu.w32(s, c.emu.r32(obj(c, 4, slots)))
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    c.emu.w32(0x7003b0, _stub(c, 0))


def heli(c, slots=None):
    h = obj(c, 0x600, slots)
    for o in list(range(0x216, 0x25e, 4)) + [0x60, 0x64, 0x68, 0x26e, 0x272, 0x342, 0x346, 0x597]:
        c.emu.w32(h + o, rf(c, -2, 2) if c.rng.random() > 0.05 else 0)
    c.emu.w32(h + 0x597, rf(c, 0, 3000))
    c.emu.w32(h + 0x34a, c.rng.choice([0, 0, 1]))
    c.emu.w32(h + 0x469, c.rng.choice([0, 1]))
    return h


def g_tm(c):
    sysx(c)
    return [heli(c)]


S(0x51e560, 'ZHeli::UpdateTurnMode', 'thiscall', gen=g_tm)
S(0x51e470, 'ZHeli::UpdateRollAndTiltMode', 'thiscall', gen=g_tm)


def g_rt(c):
    sysx(c)
    h = heli(c, {0x380: _stub(c, 0)})
    gen(c, h, 0x39f, 0x236)
    gen(c, h, 0x3c8, 0x22e)
    return [h]


S(0x51e340, 'ZHeli::UpdateRollAndTilt', 'thiscall', gen=g_rt)


def g_y(c):
    h = heli(c)
    gen(c, h, 0x29a, 0x26e)
    return [h]


S(0x51e7b0, 'ZHeli::UpdateYPos', 'thiscall', gen=g_y)
