"""specs_s315.py - mounted gun batch 315: AimControl GetAimPoint and its three phases, ZPmv::Fire, ZPmv::SetTarget.
AimControl::NewTarget (0x5138f0, reached through AimControl::SetTarget) is a Python hook that logs its call."""
from pilot import S
from mg_helpers import _rnd, _stub, _obj, flush, b8


def _put(c, vals, pad=8):
    a = c.emu.alloc(4 * (len(vals) + pad), 4)
    for i in range(len(vals) + pad):
        c.emu.wf32(a + 4 * i, vals[i] if i < len(vals) else c.fv())
    return a


def _aim(c):
    r = c.rng
    eng = _rnd(c, 0x200)
    rv1 = _put(c, [r.random() if r.random() < 0.9 else c.fv()])
    rv2 = _put(c, [r.uniform(-1, 1) if r.random() < 0.9 else c.fv()])
    vt = _obj(c, 0x10, {0x1c0: _stub(c, 2, fld=rv1, this=True), 0x1c4: _stub(c, 2, fld=rv2, this=True)})
    c.emu.w32(eng, c.emu.r32(vt))
    clock = r.randint(0, 1 << 24)
    c.emu.w32(eng + 0x40, clock)
    c.emu.w32(0x70039c, eng)
    if r.random() < 0.5:
        c.emu.wf32(0x6e8e80, c.fv(0, 2))
    s = _rnd(c, 0x40)
    off = _put(c, [c.fv(-50, 50) for _ in range(3)])
    owner = _obj(c, 0x40, {0x84: _stub(c, 1, adds=((0, off, 3),))})
    c.emu.w32(s + 4, owner if r.random() < 0.9 else 0)
    if r.random() < 0.8:
        pt = _put(c, [c.fv(-500, 500) for _ in range(3)])
        t = _obj(c, 0x40, {0x3a8: _stub(c, 0, ret=r.randint(0, 20)), 0x3b4: _stub(c, 0, ret=r.randint(0, 20)),
                           0x3b8: _stub(c, 0, ret=r.randint(0, 20)), 0x398: _stub(c, 2, fills=((1, pt, 3),))})
    else:
        t = 0
    c.emu.w32(s + 8, t)
    for o in (0xc, 0x10, 0x14):
        k = r.random()
        c.emu.wf32(s + o, clock / 1024.0 if k < 0.1 else ((clock + r.randint(-4000, 4000)) / 1024.0 if k < 0.9 else c.fv()))
    out = _put(c, [c.fv() for _ in range(3)])
    flush(c)
    return [s, out]


def _pmv(c):
    r = c.rng

    def nt(e, rr):
        e.calllog.append(('NewTarget', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    c.emu.hook(0x5138f0, nt)
    s = _obj(c, 0x1720, {0x310: _stub(c, 1, ret=b8(c, 0.4))})
    if r.random() < 0.3:
        c.emu.w32(s + 0x1654, 0)
    flush(c)
    ref = r.choice([0, c.emu.r32(s + 0x16e5), r.getrandbits(32)])
    return [s, ref]


S(0x512db0, 'AimControl::GetAimAtTargetPoint', 'thiscall', None, gen=_aim, note='batch315')
S(0x512be0, 'AimControl::GetAimAroundPoint', 'thiscall', None, gen=_aim, note='batch315')
S(0x512ca0, 'AimControl::GetAimAtLastPosPoint', 'thiscall', None, gen=_aim, note='batch315')
S(0x512e10, 'AimControl::GetAimPoint', 'thiscall', None, gen=_aim, note='batch315')
S(0x51f780, 'ZPmv::Fire', 'thiscall', None, gen=_pmv, note='batch315')
S(0x51fa10, 'ZPmv::SetTarget', 'thiscall', None, gen=_pmv, note='batch315; NewTarget hooked')
