"""specs_s505.py - weapons batch 505: SetAimTarget (full), RemoveAimTarget, FireWeaponAtPos.
ZTARGET methods run as exe code; the hero/hands and weapon calls are recording stubs."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, sysobj, fedge, vec
from specs_s504 import _tgt, _ticks


def _weapon(c):
    r = c.rng
    tm = obj(c, 0x40, {0x344: stub(c, 0, fldv=r.choice((300.0, 0.0, 1e-40, float('nan'), r.uniform(0, 2000))))})
    return obj(c, 0x100, {0x350: stub(c, 0, ret=tm), 0x32c: stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]))})


def _hands(c, extra):
    r = c.rng
    w = 0 if r.random() < 0.2 else _weapon(c)
    p2 = vec(c, 3, -50, 50)
    slots = {0x50c: stub(c, 0, ret=w), 0x84: stub(c, 1, skip=(0,), adds=((0, p2, 3),))}
    slots.update(extra)
    o = obj(c, 0x900, slots)
    _tgt(c, o, 0x26a)
    c.emu.wf32(o + 0x26a + 0x35, r.choice((0.0, -1.0, 2.0, fedge(c))))
    c.emu.wf32(o + 0x26a + 0x31, r.choice((0.0, 0.5, fedge(c))))
    c.emu.w8(o + 0x3e8, 0 if r.random() < 0.85 else 1)
    c.emu.w32(o + 0x6c, rnd(c, 0x300))
    return o


def _setaim(c):
    r = c.rng
    sysobj(c, {})
    _ticks(c)
    g = obj(c, 0x40, {0x84: stub(c, 1, adds=((0, vec(c, 3, -5, 5), 3),))})
    rm = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    c.emu.w32(c.emu.r32(rm) + 0x58, stub(c, 1, ret=g if r.random() < 0.7 else 0))
    o = _hands(c, {})
    geom = 0 if r.random() < 0.3 else r.getrandbits(32)
    if geom and r.random() < 0.4:
        c.emu.w32(o + 0x26a + 0x39, geom)
    return [o, geom, vec(c, 3, -100, 100), F(r.choice((0.0, 0.2, fedge(c)))),
            r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _remaim(c):
    r = c.rng
    sysobj(c, {})
    _ticks(c)
    o = _hands(c, {0x3b0: stub(c, 0, ret=r.getrandbits(32)), 0x320: stub(c, 1, ret=r.getrandbits(32)),
                   0x4a8: stub(c, 0)})
    return [o, F(r.choice((0.0, -0.0, 0.3, fedge(c)))), r.getrandbits(32), r.getrandbits(32),
            r.getrandbits(32), r.getrandbits(32)]


def _fire(c):
    r = c.rng
    sysobj(c, {})
    _ticks(c)
    w = 0 if r.random() < 0.15 else rnd(c, 0x100)
    o = _hands(c, {0x8c: stub(c, 1), 0x4b0: stub(c, 6)})
    c.emu.w32(c.emu.r32(o) + 0x50c, stub(c, 0, ret=w))
    cam = rnd(c, 0xc00)
    c.emu.w8(cam + 0xb45, 0 if r.random() < 0.5 else r.randint(1, 255))
    c.emu.w32(o + 0x85a, cam)
    c.emu.w8(o + 0x7f0, 0 if r.random() < 0.5 else 1)
    c.emu.w32(o + 0x26a + 0x3d, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [o, vec(c, 3, -100, 100)]


S(0x4754e0, 'ZLNKWHANDS::SetAimTarget(geom, pos, time, cb)', 'thiscall', None, ret=None, gen=_setaim)
S(0x475140, 'ZLNKWHANDS::RemoveAimTarget', 'thiscall', None, ret=None, gen=_remaim)
S(0x591710, 'ZFFHERO::FireWeaponAtPos', 'thiscall', None, ret=None, gen=_fire)
