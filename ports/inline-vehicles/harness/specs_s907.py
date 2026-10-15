"""specs_s907.py - vehicles batch 907: heli ground probe, SetPosDir, SplineUpdate, path direction helpers."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst, hookrec

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


def query(c, s):
    p = _rnd(c, 0xb00)
    q = obj(c, 0x40, {0x2e0: _stub(c, 6, ret=c.rng.getrandbits(8))})
    c.emu.w32(p + 0xadc, q)
    c.emu.w32(s + 0x9b, p)


def g_fg(c):
    s = _rnd(c, 0x200)
    query(c, s)
    c.emu.w32(0x70039c, s)
    h = _rnd(c, 0x600)
    for off in (0x60, 0x64, 0x68, 0x552):
        c.emu.w32(h + off, rf(c, -1000, 1000))
    return [h]


S(0x51c470, 'ZHeli::FindGround', 'thiscall', ret='al', gen=g_fg)
S(0x51c540, 'ZHeli::GetDistToGround', 'thiscall', ret='st0', gen=g_fg)
S(0x51c550, 'ZHeli::GetVerticalVisionOffset', 'thiscall', ret='st0', gen=lambda c: [_rnd(c, 0x10)])


def heli_spd(c, extra=None):
    off = vec(c, -5, 5)
    slots = {0x36c: _stub(c, 0), 0x88: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
             0x7c: _stub(c, 2, skip=(1,), copy=(1, PT))}
    slots.update(extra or {})
    h = obj(c, 0x600, slots)
    for o in (0x60, 0x64, 0x68, 0x276, 0x27a, 0x27e):
        c.emu.w32(h + o, rf(c))
    return h


S(0x51cf10, 'ZHeli::SetPosDir', 'thiscall', gen=lambda c: [heli_spd(c)])
S(0x4e0830, 'vdist2', 'fastcall', ret='st0', gen=lambda c: [vec(c), vec(c)])


def shape(c):
    """CMoveAlongPath shape: a random BasicShape at +0x1c is too wild for the exe spline code, so use the real
    shape layout only through its slot 0x88; GetSplinePosVelocity runs on a zeroed block (count 0)."""
    off = vec(c, -5, 5)
    sh = obj(c, 0x200, {0x88: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
                        0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))})
    c.emu.wbytes(sh + 4, b'\0' * 0x1fc)
    n = c.rng.randint(1, 4)
    cv = c.emu.alloc(n * 0x38, 4)
    for k in range(n * 0x38 // 4):
        c.emu.w32(cv + 4 * k, rf(c, -500, 500))
    c.emu.w32(sh + 0x1c + 0xc, cv)
    c.emu.w32(sh + 0x1c + 0x10, n)
    return sh


def path(c):
    p = _rnd(c, 0x80)
    c.emu.w32(p + 0x4b, shape(c) if c.rng.random() < 0.7 else 0)
    for o in (0x20, 0x24, 0x53):
        c.emu.w32(p + o, rf(c, -2, 2))
    c.emu.w32(p + 4, rf(c, 0, 1))
    return p


def g_da(c):
    return [path(c), c.emu.alloc(12, 4), rf(c, 0, 1), rf(c, 0, 600)]


S(0x523520, 'CMoveAlongPath dir around t (inferred)', 'thiscall', gen=g_da)
S(0x523330, 'CMoveAlongPath::GetDir', 'thiscall', gen=lambda c: [path(c), c.emu.alloc(12, 4)])


def g_su(c):
    hookrec(c, 0x51db60, 0)   # UpdateDustEmitter (batch 908) stood in
    s = _rnd(c, 0x200)
    node = _rnd(c, 0x90)
    wd = obj(c, 0x40, {0x58: idstub(c, [0, 0, 0, 0]), 0x60: idstub(c, [node, node, 0, node])})
    c.emu.w32(s + 0x9b, wd)
    c.emu.w32(0x70039c, s)
    h = heli_spd(c, {0x390: _stub(c, 0), 0x374: _stub(c, 0), 0x364: _stub(c, 0)})
    p = path(c)
    tv = fconst(c, c.rng.random())
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0xc, _stub(c, 0, fld=tv))
    c.emu.w32(p, vt)
    c.emu.w32(h + 0x5c, p)
    c.emu.w32(h + 0x499, c.rng.choice([0, 1, 2]))
    c.emu.w32(h + 0x4a9, rf(c, -10, 10))
    return [h]


S(0x51d000, 'ZHeli::SplineUpdate', 'thiscall', gen=g_su)
