"""specs_s2903.py - unclaimed-29 batch 3 (docs/20-unclaimed-29.md, claim 3, slice 8): ZWindControl::Load. Only virtual calls:
the load object's slots +0x70 and +0x50 (the latter returns a fake object Q), and Q's slot +0x50. All are logging stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    q = _rnd(c, 0x40)
    vt_q = c.emu.logging_vtable('wind-q', 0x54, argwords={0x50: 1})
    c.emu.w32(q, vt_q)
    vt_load = c.emu.logging_vtable('zloadgame-w', 0x74, impl={0x50: lambda e, a: (q, None)},
                                   argwords={0x50: 1, 0x70: 1})
    load = _rnd(c, 0x40)
    c.emu.w32(load, vt_load)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x48, c.rng.getrandbits(32))
    return [self_, load]


S(0x4c3680, 'ZWindControl::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-29 batch 3 (slice 8); clears +4 bit 0x40; load slot +0x70 (+0x48); chained slot +0x50 calls on +0x4c, +0x54')
