"""specs_s3022.py - unclaimed-30 claim 2 (residue 10): ZItemAmmo::Load (0x46f5a0). The base load (0x46f520) is patched with a logged stub
returning a per-case flag; the load object's slot 0x48 (one argument) is logged. Returns al. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _ammo(c):
    e = c.emu
    r = c.rng
    flag = r.choice([0, 1])
    ss.patch(c, 0x46f520, ss.rec(c, 1, ret=flag))
    self_ = rnd(c, 0x100)
    load = rnd(c, 0x40)
    e.w32(load, vtable(c, 'zload_ammo', 0x40, argwords={0x48: 1}))
    return [self_, load]


S(0x46f5a0, 'ZItemAmmo::Load', 'thiscall', None, ret='al', gen=_ammo, n=300)
