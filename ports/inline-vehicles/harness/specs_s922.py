"""specs_s922.py - vehicles batch 922: tank dust/exhaust emitters and CUnderCarriageTank::FrameUpdate (its
sub-steps stood in with vh.hookrec)."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec, fconst
import specs_s921 as b921


def rmx(c, s):
    q = _rnd(c, 0x50)
    wd = obj(c, 0x40, {0x58: idstub(c, [0, 0, 0, 0]), 0x160: idstub(c, [q, 0, q, q])})
    c.emu.w32(s + 0x9b, wd)
    eng = _rnd(c, 0x20)
    c.emu.w32(eng + 0x1c, obj(c, 8, {0x74: _stub(c, 1, ret=r32(c))}))
    c.emu.w32(eng + 0x18, obj(c, 8, {0xf8: _stub(c, 1, ret=c.rng.choice([0, _rnd(c, 8)]))}))
    c.emu.w32(s + 0x1aa3, eng)
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c0: _stub(c, 2, fld=fconst(c, c.rng.random() * 0.2))})))


def g_gd(c):
    s = b921.sysw(c)
    rmx(c, s)
    d = _rnd(c, 0xe0)
    c.emu.w32(d + 0xad, c.rng.choice([0, 1]))
    return [d]


S(0x516250, 'CDamper ground dust (inferred)', 'thiscall', ret='eax', gen=g_gd)


def g_wsd(c):
    hookrec(c, 0x516b60, 3)
    return [_rnd(c, 0x140), _rnd(c, 0x50)]


S(0x52a070, 'CWheel set dust (inferred)', 'thiscall', gen=g_wsd)


def g_wd(c):
    s = b921.sysw(c)
    rmx(c, s)
    hookrec(c, 0x516b60, 3)
    o = b921.ucx(c)
    c.emu.w32(o + 0x785 + 0xad, c.rng.choice([0, 1]))
    return [o]


S(0x5292c0, 'CUnderCarriageTank wheel dust (inferred)', 'thiscall', gen=g_wd)


def g_ex(c):
    hookrec(c, 0x5168b0, 0)
    o = b921.ucx(c)
    c.emu.w32(o + 0x68, rf(c, 0, 300))
    c.emu.w32(o + 0x22c0, c.rng.randint(0, 3))
    return [o]


S(0x5295d0, 'CUnderCarriageTank exhaust (inferred)', 'thiscall', gen=g_ex)


def g_fu(c):
    s = b921.sysw(c)
    for a in (0x527bd0, 0x529660, 0x5279f0, 0x529130, 0x529450, 0x529020, 0x528b60, 0x528ae0, 0x5292c0, 0x5295d0):
        hookrec(c, a, 0)
    o = b921.ucx(c)
    c.emu.w8(o + 0x84, c.rng.choice([0, 1, 1]))
    c.emu.w8(o + 0x21cd, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x85, (c.emu.r32(s + 0x40) + c.rng.randint(-5, 5)) & 0xffffffff)
    grp = obj(c, 0x40, {0x7c: _stub(c, 2), 0x80: _stub(c, 2, skip=(0, 1))})
    c.emu.w32(o + 0x89, grp)
    vs = []
    for _ in range(2):
        v = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(v + 4 * k, rf(c, -1, 1))
        vs.append(v)
    return [o, c.emu.alloc(36, 4), c.emu.alloc(12, 4), vs[0], vs[1], rf(c, 0, 100), rf(c, -50, 50), rf(c, -1, 1)]


S(0x527d10, 'CUnderCarriageTank::FrameUpdate', 'thiscall', gen=g_fu)
