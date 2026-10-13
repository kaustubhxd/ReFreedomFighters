"""specs_s703.py - soldier AI batch 703: CCheckVisible OnSetVisRange/Fov/Offset/LightMultiplier.
Values cover both clamp edges, NaN, infinities and denormals."""
import math
from pilot import S, f32
from specs_s701 import _world, _cv, _ref


def _val(c):
    r = c.rng.random()
    if r < 0.3:
        return f32(c.rng.choice([0.0, -0.0, 10.0, 9.999999, 10000.0, 10000.001, 360.0, 360.00003, -1.0, math.nan,
                                 math.inf, -math.inf, 1e-40, 180.0, 90.0, 120.0]))
    if r < 0.6:
        return f32(c.rng.uniform(-50, 400))
    return f32(c.rng.uniform(-20000, 20000))


def _ev(c, nvals):
    _world(c)
    cv = _cv(c)
    ref = _ref(c)
    if c.rng.random() < 0.8:
        c.emu.w32(cv + 0x694 + 0x1b8 * c.rng.randrange(200), ref)
    ev = c.emu.alloc(16, 4)
    c.emu.w32(ev, ref)
    for k in range(nvals):
        c.emu.wf32(ev + 4 + 4 * k, _val(c))
    return [cv, ev]


S(0x4ab760, 'CCheckVisible::OnSetVisRange', 'thiscall', None, ret='eax', gen=lambda c: _ev(c, 1), note='b703 [high]')
S(0x4ab430, 'CCheckVisible::OnSetVisFov', 'thiscall', None, ret='eax', gen=lambda c: _ev(c, 1),
  note='b703 [high]; CRT cos at 0x634d70 runs as exe code')
S(0x4ab650, 'CCheckVisible::OnSetVisOffset', 'thiscall', None, ret='eax', gen=lambda c: _ev(c, 3), note='b703 [high]')
S(0x4ab560, 'CCheckVisible::OnSetVisLightMultiplier', 'thiscall', None, ret='eax', gen=lambda c: _ev(c, 1),
  note='b703 [high]')
