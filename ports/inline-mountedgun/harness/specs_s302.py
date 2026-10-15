"""specs_s302.py - mounted gun batch 302: vaddscalar, placeGun, AimWeaponAt, AimWeaponRef.
A full nest fixture: the object manager's slot 0x58 is a dispatcher keyed on the reference values stored in the nest;
objects that receive matrices/points record the pointed-to dwords per call (rec_stub)."""
from pilot import S, F
from mg_helpers import _rnd, _stub, _obj, flush, b8, dispatch, rec_stub


def _wf(c, a, vals):
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)


def _put(c, vals, pad=8):
    a = c.emu.alloc(4 * (len(vals) + pad), 4)
    for i in range(len(vals) + pad):
        c.emu.wf32(a + 4 * i, vals[i] if i < len(vals) else c.fv())
    return a


def _geom_obj(c, extra=None, size=0x40):
    """An object whose +8 points at a geom with a position at +0x24."""
    geom = _rnd(c, 0x40)
    _wf(c, geom + 0x24, [c.fv(-500, 500) for _ in range(3)])
    o = _obj(c, size, extra) if extra else _rnd(c, size)
    c.emu.w32(o + 8, geom)
    return o


def _nest(c, refs_extra=None):
    r = c.rng
    s = _rnd(c, 0xa0)
    lim = lambda: c.fv(-1.5, 1.5, 0.1)
    _wf(c, s + 0x50, [c.fv(0, 1), lim(), lim(), c.fv(0.1, 3), lim(), lim()])
    off = _put(c, [c.fv(-50, 50) for _ in range(3)])
    g = _obj(c, 0x40, {0x8c: _stub(c, 1, adds=((0, off, 3),), skip=(0,))})
    c.emu.w32(s + 0x44, g)
    refs = {}
    ids = r.sample(range(1, 1 << 30), 6)
    base = _geom_obj(c, {0x80: _stub(c, 2, fills=((0, _put(c, [c.fv(-1, 1) for _ in range(9)]), 9),
                                                   (1, _put(c, [c.fv(-500, 500) for _ in range(3)]), 3)), skip=(0, 1))})
    pivot = _geom_obj(c)
    sink = _obj(c, 0x20, {0x370: rec_stub(c, 2, {0: 9, 1: 3})})
    gun = _obj(c, 0x20, {0x2f4: _stub(c, 0, ret=sink if r.random() < 0.85 else 0), 0x2d4: rec_stub(c, 2, {0: 9, 1: 3})})
    mobj = _obj(c, 0x80, {0x6c: rec_stub(c, 1, {0: 9})})
    refs[ids[0]] = base
    refs[ids[1]] = pivot
    refs[ids[2]] = gun
    refs[ids[3]] = mobj
    c.emu.w32(s + 0x74, ids[0])
    c.emu.w32(s + 0x78, ids[1])
    c.emu.w32(s + 0x70, ids[2])
    c.emu.w32(s + 0x6c, ids[3] if r.random() < 0.7 else 0)
    if refs_extra:
        for k, v in refs_extra(c, ids).items():
            refs[k] = v
    eng = _rnd(c, 0x200)
    mgr = _obj(c, 0x40, {0x58: dispatch(c, refs)})
    c.emu.w32(eng + 0x9b, mgr)
    c.emu.w32(0x70039c, eng)
    return s, eng, ids


def _vadd(c):
    return [c.fbuf(3), c.fbuf(3), F(c.fv(-200, 200))]


def _place(c):
    s, eng, ids = _nest(c)
    flush(c)
    return [s]


def _at(c):
    s, eng, ids = _nest(c)
    flush(c)
    return [s, _put(c, [c.fv(-500, 500) for _ in range(3)])]


def _ref(c):
    r = c.rng
    holder = {}

    def extra(c, ids):
        tpt = _put(c, [c.fv(-500, 500) for _ in range(3)])
        toff = _put(c, [c.fv(-20, 20) for _ in range(3)])
        t = _obj(c, 0x60, {0x84: _stub(c, 1, adds=((0, tpt, 3),), skip=(0,)),
                           0x8c: _stub(c, 1, adds=((0, toff, 3),), skip=(0,)),
                           0x1e0: _stub(c, 1, ret=b8(c, 0.3))})
        x = r.random()
        if x < 0.2:
            c.emu.w32(t + 0x54, 0)
        else:
            p = _rnd(c, 0x10)
            c.emu.w32(p + 4, 0 if x < 0.7 else r.getrandbits(32) | 1)
            c.emu.w32(t + 0x54, p)
        holder['ref'] = ids[4]
        return {ids[4]: t}
    s, eng, ids = _nest(c, extra)
    rv = _put(c, [r.random() if r.random() < 0.9 else c.fv()])
    eng_vt = _obj(c, 0x10, {0x1c0: _stub(c, 2, fld=rv, this=True)})
    c.emu.w32(eng, c.emu.r32(eng_vt))
    k = r.random()
    c.emu.wf32(s + 0x84, 0.0 if k < 0.4 else (c.fv(0, 1) if k < 0.9 else c.fv()))
    c.emu.wf32(eng + 0x48, c.fv(0, 20) if r.random() < 0.8 else c.fv())
    flush(c)
    return [s, holder['ref'] if r.random() < 0.95 else ids[5]]


S(0x451890, 'vaddscalar', 'fastcall', None, gen=_vadd, note='batch302; x87')
S(0x5c8650, 'MGCG placeUser (unnamed)', 'thiscall', None, gen=_place, note='batch302')
S(0x5c82a0, 'CMachinegunControlGroup::AimWeaponAt', 'thiscall', None, ret='al', gen=_at, note='batch302; entry 0x5c82a0 (Ghidra split at 0x5c82b9)')
S(0x5c8470, 'CMachinegunControlGroup::AimWeaponRef', 'thiscall', None, ret='al', gen=_ref, note='batch302')
