"""specs_c114.py - climb thread batch 114: CheckGroundContact and GetActiveAnimMovement."""
import struct
from pilot import S, F
from ckit import obj, rnd, floats, wfloats

_PH = [0.0, 0.2, 0.25, 0.3, 0.5, 0.7, 0.75, 0.8, 1.0, 0.24, 0.26, 0.74, 0.76, float('nan')]


def _cgc(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    v3 = r.choice([0, 0x7070, 0x7071])
    own = obj(e, 'owner', 0xa00, {0x3f8: (1, lambda e, t, a: ((v3 + a[0]) if v3 else 0, None, (a[0],)))}, rng=r)
    e.w32(own + 0x417, r.choice([2, 0, 0x8000000, r.getrandbits(32)]))
    e.w32(o + 4, own)
    gs = {}

    def g60(e, t, a):
        if a[0] not in gs:
            gs[a[0]] = rnd(c, 0x80) if r.random() < 0.8 else 0
        return (gs[a[0]], None, (a[0],))
    db = obj(e, 'enginedb', 0x10, {0x60: (1, g60)})
    rv = r.random()
    s = obj(e, 'sys', 0x100, {0x1c0: (2, lambda e, t, a: (0, rv, (a[0], a[1])))}, rng=r)
    e.mu.mem_write(s + 0x9b, struct.pack('<I', db))
    e.w32(0x70039c, s)
    a = r.choice(_PH) if r.random() < 0.7 else c.fv(0, 1)
    b = r.choice(_PH) if r.random() < 0.7 else c.fv(0, 1)
    return [o, F(a), F(b)]


S(0x4882d0, 'ZMovementBase::CheckGroundContact', 'thiscall', None, ret=None, gen=_cgc, note='c114')


def _gam(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    if r.random() < 0.3:
        wfloats(e, o + 0x18, [0.0])
    has = r.choice([0, 1, 0x100])
    m = [c.fv(-2, 2) for _ in range(9)]
    v = [c.fv(-50, 50) for _ in range(3)]

    def rm(e, t, a):
        wfloats(e, a[0], m)
        wfloats(e, a[1], v)
        return (has, None, ())
    own = obj(e, 'owner', 0xa00, {0x5e0: (2, rm)}, rng=r)
    e.w32(o + 4, own)
    s = rnd(c, 0x100)
    wfloats(e, s + 0x48, [r.choice([0.0, 0.033, 0.016, c.fv(0, 0.1)])])
    e.w32(0x70039c, s)
    return [o, c.fbuf(9), c.fbuf(3), c.fbuf(9), c.fbuf(3)]


S(0x488a00, 'ZMovementBase::GetActiveAnimMovement', 'thiscall', None, ret='al', gen=_gam,
  note='c114; matrix and vector helpers run as original')
