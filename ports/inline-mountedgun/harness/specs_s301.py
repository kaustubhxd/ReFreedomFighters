"""specs_s301.py - mounted gun batch 301: ClampAndNormAimDir, canAimAtPoint, CanAimWeaponRef."""
import struct
from pilot import S, F
from mg_helpers import _rnd, _stub, _obj, engine, flush, b8


def _wf(c, a, vals):
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)


def _mg(c, size=0xa0):
    """A nest object with plausible limits at +0x50..+0x64 (edge values sometimes)."""
    r = c.rng
    s = _rnd(c, size)
    lim = lambda: c.fv(-1.5, 1.5, 0.1)
    _wf(c, s + 0x50, [c.fv(0, 1), lim(), lim(), c.fv(0.1, 3), lim(), lim()])
    return s


def _vec(c, n=3):
    r = c.rng
    k = r.random()
    if k < 0.08:
        vals = [0.0, 0.0, 0.0]
    elif k < 0.16:
        vals = [0.0, c.fv(), 0.0]
    elif k < 0.22:
        vals = [c.fv(), 0.0, 0.0]
    else:
        vals = [c.fv() for _ in range(3)]
    return c.fbuf(3, None) if False else _put(c, vals)


def _put(c, vals):
    a = c.emu.alloc(4 * 11, 4)
    for i in range(11):
        c.emu.wf32(a + 4 * i, vals[i] if i < len(vals) else c.fv())
    return a


def _clamp(c):
    return [_mg(c), _vec(c), b8(c, 0.5)]


def _geoms(c, s):
    """Gun geom at +0x44 (slot 0x8c adds a random offset to the point), base object ref at +0x74."""
    off = _put(c, [c.fv(-50, 50) for _ in range(3)])
    g = _obj(c, 0x40, {0x8c: _stub(c, 1, adds=((0, off, 3),), skip=(0,))})
    c.emu.w32(s + 0x44, g)
    geom = _rnd(c, 0x40)
    _wf(c, geom + 0x24, [c.fv(-50, 50) for _ in range(3)])
    base = _rnd(c, 0x20)
    c.emu.w32(base + 8, geom)
    return base


def _point(c):
    s = _mg(c)
    base = _geoms(c, s)
    engine(c, {0x58: _stub(c, 1, ret=base)})
    flush(c)
    return [s, _put(c, [c.fv(-50, 50) for _ in range(3)])]


def _ref(c):
    r = c.rng
    s = _mg(c)
    base = _geoms(c, s)
    pt = _put(c, [c.fv(-50, 50) for _ in range(3)])
    tgt = _obj(c, 0x40, {0x84: _stub(c, 1, fills=((0, pt, 3),), skip=(0,))})
    # slot 0x58 is called twice (target ref, then base ref): a stub that returns tgt first, then base
    seq = c.emu.alloc(16, 4)
    c.emu.w32(seq, 0)
    code = (b'\xa1' + struct.pack('<I', seq) + b'\xff\x05' + struct.pack('<I', seq) + b'\x85\xc0'
            + b'\xb8' + struct.pack('<I', tgt) + b'\x74\x05' + b'\xb8' + struct.pack('<I', base) + b'\xc2\x04\x00')
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    engine(c, {0x58: st})
    pr = _obj(c, 8, {0x2c: _stub(c, 2, pop=0, this=True)})
    lg = _obj(c, 8, {0x20: _stub(c, 2, ret=pr, this=True)})
    c.emu.w32(0x700390, lg)
    flush(c)
    refp = c.emu.alloc(16, 4)
    c.emu.w32(refp, 0 if r.random() < 0.15 else r.getrandbits(32) | 1)
    return [s, refp]


S(0x5c88c0, 'CMachinegunControlGroup::ClampAndNormAimDir', 'thiscall', None, ret='al', gen=_clamp, note='batch301; x87 normalise')
S(0x5c8750, 'MGCG canAimAtPoint (CanAimWeaponAt?)', 'thiscall', None, ret='al', gen=_point, note='batch301')
S(0x5c87f0, 'CMachinegunControlGroup::CanAimWeaponRef', 'thiscall', None, ret='al', gen=_ref, note='batch301')
