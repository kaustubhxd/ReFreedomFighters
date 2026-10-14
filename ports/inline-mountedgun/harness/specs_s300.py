"""specs_s300.py - mounted gun batch 300: CMachinegunControlGroup leaf methods."""
from pilot import S, F
from mg_helpers import _rnd, _stub, _obj, engine, flush, b8


def _owner_obj(c):
    """An object for objMgr slot 0x58: null, or IsA stub + a +0x54 pointer (null, +4 == 0, or +4 != 0)."""
    r = c.rng
    if r.random() < 0.15:
        return 0
    o = _obj(c, 0x60, {0x1e0: _stub(c, 1, ret=b8(c, 0.3))})
    x = r.random()
    if x < 0.2:
        c.emu.w32(o + 0x54, 0)
    else:
        p = _rnd(c, 0x10)
        c.emu.w32(p + 4, 0 if x < 0.7 else r.getrandbits(32) | 1)
        c.emu.w32(o + 0x54, p)
    return o


def _lock(c):
    r = c.rng
    sysobj, _ = engine(c)
    c.emu.w32(sysobj + 0x40, r.choice((r.getrandbits(32), r.randint(0, 1 << 20), 0x7fffffff, 0x80000000)))
    self = _rnd(c, 0xa0)
    return [self, r.getrandbits(32), F(c.fv(-100.0, 100.0))]


def _free(c):
    o = _owner_obj(c)
    engine(c, {0x58: _stub(c, 1, ret=o)})
    flush(c)
    return [_rnd(c, 0xa0), c.rng.getrandbits(32)]


def _wsub(c):
    r = c.rng
    sub = r.getrandbits(32)
    w = _obj(c, 0x20, {0x2f4: _stub(c, 0, ret=sub)})
    engine(c, {0x58: _stub(c, 1, ret=w), 0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    flush(c)
    return [_rnd(c, 0xa0)]


S(0x5c9130, 'CMachinegunControlGroup::Reserve', 'thiscall', None, gen=_lock, note='batch300')
S(0x5c94a0, 'MGCG refIsFreeOwner (unnamed)', 'thiscall', None, ret='al', gen=_free, note='batch300')
S(0x5c90b0, 'CMachinegunControlGroup::LockTargetSetup', 'thiscall', None, gen=_free, note='batch300')
S(0x5c94f0, 'MGCG getUserRef (GetOwner)', 'thiscall', None, ret='eax', gen=_wsub, note='batch300')
