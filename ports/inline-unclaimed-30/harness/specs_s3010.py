"""specs_s3010.py - unclaimed-30 batch 10 (docs/20-unclaimed-30.md, claim 1): CSpriteBorder2D::Load (0x5ed9d0). The base Load
(0x5ed0b0) is patched with a logged stub (it is not part of this claim); the load object's slots 0x40 / 0x48 / 0x50 write a value
through their pointer argument (pfspec.vtable impl), and their calls are logged with their arguments. Returns with ret 4."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _load(c):
    e = c.emu
    r = c.rng
    base_stub = ss.rec(c, 1, ret=0)
    ss.patch(c, 0x5ed0b0, base_stub)
    vals = [r.getrandbits(32) for _ in range(8)]

    def wr_out(em, a):
        em.w32(a[0], vals[len(em.calllog) % 8])
        return 0
    obj = rnd(c, 0x100)
    load = rnd(c, 0x40)
    e.w32(load, vtable(c, 'zload', 0x80, impl={0x40: wr_out, 0x48: wr_out, 0x50: wr_out},
                       argwords={0x40: 1, 0x48: 1, 0x50: 1}))
    return [obj, load]


S(0x5ed9d0, 'CSpriteBorder2D::Load', 'thiscall', None, gen=_load, n=300)
