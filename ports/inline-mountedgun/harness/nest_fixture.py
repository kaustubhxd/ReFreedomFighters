"""nest_fixture.py - a full CMachinegunControlGroup test fixture for batches 303+ (mounted gun tree).

Builds the nest object (0xa0 bytes of random bytes, then plausible fields), the engine object at 0x70039c with a
vtable (slot 0x1c0 = random float in ST0), a clock (+0x40) and frame step (+0x48), and an object manager (+0x9b) with
slot 0x58 = a dispatcher on reference values, slot 0x4c = object to reference (records its argument), slot 0x114 =
message registration (records its args). Every object that receives data records it per call (rec_stub) or records
its stack args (_stub), so the heap compare checks the calls.

Reference ids: base (+0x74), pivot (+0x78), gun (+0x70), matrix sink (+0x6c, sometimes 0), owner (+0x80, a target
actor or 0), lock target (+0x88, or 0), plus an unknown id that the manager maps to null."""
from mg_helpers import _rnd, _stub, _obj, flush, b8, dispatch, rec_stub


def wf(c, a, vals):
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)


def put(c, vals, pad=8):
    a = c.emu.alloc(4 * (len(vals) + pad), 4)
    for i in range(len(vals) + pad):
        c.emu.wf32(a + 4 * i, vals[i] if i < len(vals) else c.fv())
    return a


def geom_obj(c, extra=None, size=0x40):
    geom = _rnd(c, 0x40)
    wf(c, geom + 0x24, [c.fv(-500, 500) for _ in range(3)])
    o = _obj(c, size, extra) if extra else _rnd(c, size)
    c.emu.w32(o + 8, geom)
    return o


def actor(c, gunner_p=0.7):
    """A possible gun user / target: IsA (slot 0x1e0) true with probability gunner_p, +0x54 owner sub-object,
    slot 0x504 held weapon (or 0) whose slot 0xbc records its arg, slot 0x84 point (adds), slot 0x8c offset (adds),
    slot 0x128 records (message id, a, b). Size 0x940 so +0x91c is inside."""
    r = c.rng
    wpn = _obj(c, 0x20, {0xbc: _stub(c, 1)}) if r.random() < 0.7 else 0
    tpt = put(c, [c.fv(-500, 500) for _ in range(3)])
    toff = put(c, [c.fv(-20, 20) for _ in range(3)])
    a = _obj(c, 0x940, {0x1e0: _stub(c, 1, ret=1 if r.random() < gunner_p else b8(c, 0.9)),
                        0x504: _stub(c, 0, ret=wpn),
                        0x84: _stub(c, 1, adds=((0, tpt, 3),), skip=(0,)),
                        0x8c: _stub(c, 1, adds=((0, toff, 3),), skip=(0,)),
                        0x128: _stub(c, 3), 0x370: rec_stub(c, 2, {0: 9, 1: 3})})
    x = r.random()
    if x < 0.2:
        c.emu.w32(a + 0x54, 0)
    else:
        p = _rnd(c, 0x10)
        c.emu.w32(p + 4, 0 if x < 0.7 else r.getrandbits(32) | 1)
        c.emu.w32(a + 0x54, p)
    return a


def nest(c, cur_user='random', owner_p=0.6, lock_p=0.6):
    """Returns dict with keys self, eng, ids, objects. cur_user: the gun's current user ('random', None or an object)."""
    r = c.rng
    s = _rnd(c, 0xa0)
    lim = lambda: c.fv(-1.5, 1.5, 0.1)
    wf(c, s + 0x50, [c.fv(0, 1), lim(), lim(), c.fv(0.1, 3), lim(), lim()])
    off = put(c, [c.fv(-50, 50) for _ in range(3)])
    g = _obj(c, 0x40, {0x8c: _stub(c, 1, adds=((0, off, 3),), skip=(0,)),
                       0x288: _stub(c, 3), 0x12c: _stub(c, 3)})
    c.emu.w32(s + 0x44, g)
    ids = r.sample(range(1, 1 << 30), 8)
    bpt = put(c, [c.fv(-500, 500) for _ in range(3)])
    base = geom_obj(c, {0x80: _stub(c, 2, fills=((0, put(c, [c.fv(-1, 1) for _ in range(9)]), 9),
                                                  (1, put(c, [c.fv(-500, 500) for _ in range(3)]), 3)), skip=(0, 1)),
                        0x84: _stub(c, 1, adds=((0, bpt, 3),), skip=(0,))})
    pivot = geom_obj(c)
    sink = _obj(c, 0x20, {0x370: rec_stub(c, 2, {0: 9, 1: 3})})
    if cur_user == 'random':
        cu = actor(c) if r.random() < 0.6 else 0
    else:
        cu = cur_user or 0
    gun = _obj(c, 0x20, {0x2f4: _stub(c, 0, ret=cu), 0x2d4: rec_stub(c, 2, {0: 9, 1: 3}),
                         0x2f0: _stub(c, 3), 0x2d0: _stub(c, 2)})
    mobj = _obj(c, 0x80, {0x6c: rec_stub(c, 1, {0: 9})})
    owner = actor(c)
    tgt = actor(c)
    refs = {ids[0]: base, ids[1]: pivot, ids[2]: gun, ids[3]: mobj, ids[4]: owner, ids[5]: tgt}
    c.emu.w32(s + 0x74, ids[0])
    c.emu.w32(s + 0x78, ids[1])
    c.emu.w32(s + 0x70, ids[2])
    c.emu.w32(s + 0x6c, ids[3] if r.random() < 0.7 else 0)
    c.emu.w32(s + 0x80, ids[4] if r.random() < owner_p else 0)
    c.emu.w32(s + 0x88, ids[5] if r.random() < lock_p else 0)
    k = r.random()
    c.emu.wf32(s + 0x84, 0.0 if k < 0.4 else (c.fv(0, 1) if k < 0.9 else c.fv()))
    eng = _rnd(c, 0x200)
    rv = put(c, [r.random() if r.random() < 0.9 else c.fv()])
    eng_vt = _obj(c, 0x10, {0x1c0: _stub(c, 2, fld=rv, this=True)})
    c.emu.w32(eng, c.emu.r32(eng_vt))
    clock = r.randint(0, 1 << 24)
    c.emu.w32(eng + 0x40, clock)
    c.emu.wf32(eng + 0x48, c.fv(0, 20) if r.random() < 0.8 else c.fv())
    # lock expiry around the clock (seconds), so both sides of the test happen
    k = r.random()
    c.emu.wf32(s + 0x8c, clock / 1024.0 if k < 0.15 else ((clock + r.randint(-3000, 3000)) / 1024.0 if k < 0.9 else c.fv()))
    mgr = _obj(c, 0x200, {0x58: dispatch(c, refs), 0x4c: _stub(c, 1, ret=0 if r.random() < 0.25 else r.getrandbits(32)),
                          0x114: _stub(c, 4, ret=r.getrandbits(32))})
    c.emu.w32(eng + 0x9b, mgr)
    c.emu.w32(0x70039c, eng)
    return dict(self=s, eng=eng, ids=ids, base=base, gun=gun, owner=owner, tgt=tgt, cur=cu, mgr=mgr)
