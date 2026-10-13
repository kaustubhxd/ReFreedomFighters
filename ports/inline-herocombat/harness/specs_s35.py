"""specs_s35.py - inline session batch 35 (Haiku, night): vnorm 0x44c840 (returns float in ST0), vcross 0x446ee0,
ZMovementBase::DeltaTime 0x488460 (returns float in ST0; reads the global object pointer at 0x70039c)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec3(c, zero_frac=0.2):
    r = c.rng
    v = c.emu.alloc(0x20, 4)
    if r.random() < zero_frac:
        vals = [0.0, 0.0, 0.0]
    else:
        vals = [c.fv(), c.fv(), c.fv()]
        if r.random() < 0.15:
            vals[r.randint(0, 2)] = 0.0
    for i, x in enumerate(vals):
        c.emu.wf32(v + 4 * i, x)
    return v


def _vn(c):
    return [_vec3(c)]


S(0x44c840, 'vnorm', 'thiscall', None, ret='st0', gen=_vn,
  note='batch35; normalise three floats in place, return the length in ST0; zero vector gives 0 and no writes')


def _vx(c):
    return [_rnd(c, 0x20), _vec3(c, 0.05), _vec3(c, 0.05)]


S(0x446ee0, 'vcross', 'fastcall', None, ret=None, gen=_vx, note='batch35; cross product of two vectors, one stack arg')


def _dt(c):
    r = c.rng
    pool = c.emu.alloc(0x80, 4)
    c.emu.wbytes(pool, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    c.emu.wf32(pool + 0x48, c.fv())
    c.emu.w32(0x70039c, pool)
    obj = _rnd(c, 0x40)
    c.emu.wf32(obj + 0x18, 0.0 if r.random() < 0.3 else c.fv())
    return [obj]


S(0x488460, 'ZMovementBase::DeltaTime', 'thiscall', None, ret='st0', gen=_dt,
  note='batch35; zero field returns the float at +0x48 of the object at the global 0x70039c')
