"""specs_u18_16.py - core-todo residue 17 (unclaimed-18 thread): ZActor::OnCameraEnter (0x479750)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _fvec(c):
    return [c.fv(-50, 50) for _ in range(3)]


def _oce(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x800)
    e.w32(self_ + 0x65c, r.choice([0, 1, r.getrandbits(32)]))
    t = obj(e, 'camera', 0x40, {0x34: (0, lambda e, t_, a: (r.choice([0, 1]), None, ())),
                                0x38: (0, lambda e, t_, a: (r.choice([0, 1]), None, ()))}, nslots=0x3c // 4)
    e.w32(self_ + 0x6c, t)

    def f57c(e, th, a):
        for base in (a[0], a[1]):
            vals = _fvec(c)
            for i, v in enumerate(vals):
                e.wf32(base + 4 * i, v)
        return (0, None, ())

    def f620(e, th, a):
        vals = _fvec(c)
        for i, v in enumerate(vals):
            e.wf32(a[0] + 4 * i, v)
        return (0, None, (a[1], a[2]))

    def f578(e, th, a):
        return (0, None, (e.r32(a[1] + 4),))

    e_vt = rvt(e, 'actor', {0x32c: (1, lambda e, th, a: (0, None, (a[0],))), 0x57c: (2, f57c),
                            0x620: (3, f620), 0x578: (2, f578)}, nslots=0x630 // 4)
    e.w32(self_, e_vt)
    return [self_]


S(0x479750, 'ZActor::OnCameraEnter', 'thiscall', None, ret=None, gen=_oce, note='u18 core residue 17')
