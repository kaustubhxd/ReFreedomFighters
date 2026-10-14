"""specs_s5701.py - unclaimed-57 (docs/20-unclaimed-57.md), batch 1: ZFFSearchLightAddActors::Load (0x5c5cc0). Thiscall, one
argument (the ZLoadGame), returns al = 1. The load object has a logging vtable whose slots +0x40 and +0x48 (one argument each)
are the unverified callees; the field addresses passed in are logged and compared."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    vt = e.logging_vtable('searchlight_load', 32, argwords={0x40: 1, 0x48: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, vt)
    return [_rnd(c, 0x800), ld]


S(0x5c5cc0, 'ZFFSearchLightAddActors::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-57 batch 1; load->vt[+0x40] and [+0x48] stubbed; returns 1')
