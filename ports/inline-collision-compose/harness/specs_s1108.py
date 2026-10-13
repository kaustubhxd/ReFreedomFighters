"""specs_s1108.py - collision thread batch 1108: GetLocalPoint / GetLocalVect / GetLocalPointVect, GetBoundTreeType,
0x4e3170, SRecurseInfoCompiled ctor."""
from pilot import S, F
from specs_s1100 import _chain, _vec


def _lp(c):
    return [_chain(c), _vec(c, 3, -50.0, 50.0)]


def _lpv(c):
    return [_chain(c), _vec(c, 3, -50.0, 50.0), _vec(c, 3, -2.0, 2.0)]


def _bt(c):
    e, r = c.emu, c.rng
    g = e.alloc(0x60, 4)
    if r.random() < 0.7:
        vt = e.logging_vtable('bound', 0x3c // 4, impl={0x38: lambda em, a: (c.vars['t'], None)})
        c.vars['t'] = r.getrandbits(32)
        o = e.alloc(0x10, 4)
        e.w32(o, vt)
        e.w32(g + 0x54, o)
    return [g]


def _cw(c):
    a = c.bytes_(8)
    return [c.emu.alloc(8, 4), a]


S(0x4db1f0, 'ZBaseGeom::GetLocalPoint', 'thiscall', None, gen=_lp, note='batch1108')
S(0x4db270, 'ZBaseGeom::GetLocalVect', 'thiscall', None, gen=_lp, note='batch1108')
S(0x4db220, 'ZBaseGeom::GetLocalPointVect', 'thiscall', None, gen=_lpv, note='batch1108')
S(0x4daf80, 'ZBaseGeom::GetBoundTreeType', 'thiscall', None, ret='eax', gen=_bt, note='batch1108')
S(0x4e3170, 'copy one word (unnamed)', 'thiscall', None, ret='eax', gen=_cw, note='batch1108')
S(0x4e3180, 'SRecurseInfoCompiled::SRecurseInfoCompiled', 'thiscall', None, ret='eax',
  gen=lambda c: [c.bytes_(8)], note='batch1108')
