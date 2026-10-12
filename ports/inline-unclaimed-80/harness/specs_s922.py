"""specs_s922.py - unclaimed-80 claim 2 (docs/20-unclaimed-80.md): CCheckInside::TimeUpdate (0x4afc30). The stubs: 0x4af6d0
returns the object (a per-case pointer, 0 about 25% of the time, so the early return runs), 0x4af500 and 0x4af5b0 are logging
no-ops with one argument each (both ret 4). The object's vtable is a logging fake whose slot +0x1e0 (one argument) returns a
per-case value; its low byte selects 0x4af5b0 (nonzero) or 0x4af500 (zero)."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _timeupdate(c):
    x = _rnd(c, 0x40)
    v = c.rng.choice([0, 0x101, c.rng.getrandbits(32)])
    x_vt = c.emu.logging_vtable('ZCheckTarget', 0x80, impl={0x1e0: (lambda e, a, v=v: (v, None))}, argwords={0x1e0: 1})
    c.emu.w32(x, x_vt)
    obj_ret = x if c.rng.random() < 0.75 else 0
    ss.patch(c, 0x4af6d0, ss.rec(c, 0, ret=obj_ret))
    ss.patch(c, 0x4af500, ss.rec(c, 1, ret=0))
    ss.patch(c, 0x4af5b0, ss.rec(c, 1, ret=0))
    return [_rnd(c, 0x800)]


S(0x4afc30, 'CCheckInside::TimeUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_timeupdate,
  note='unclaimed-80 claim 2; 0x4af6d0 returns the object, 0x4af500 and 0x4af5b0 stubbed; slot +0x1e0 logged')
