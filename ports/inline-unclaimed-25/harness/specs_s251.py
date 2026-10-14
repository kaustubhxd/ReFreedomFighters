"""specs_s251.py - unclaimed area 25, slice 4: 0x523040 CMoveAlongPath::ChangePath.
Logger at 0x700390 is a per-case fake (slot 0x20, thiscall, 2 args, returns an object whose cdecl slot 0x2c takes 0 popped
args). A null shape returns at once; t == 0 takes the ext_523280 branch."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _change(c):
    ob_vt = c.emu.logging_vtable('LogOb', 0x140, argwords={0x2c: 0})
    ob = _rnd(c, 0x40)
    c.emu.w32(ob, ob_vt)
    lg_vt = c.emu.logging_vtable('Logger', 0x140, impl={0x20: lambda e, a: (ob, None)}, argwords={0x20: 2})
    lg = _rnd(c, 0x40)
    c.emu.w32(lg, lg_vt)
    c.emu.w32(0x700390, lg)
    shape = _rnd(c, 0x40) if c.rng.random() < 0.9 else 0
    t = 1.0
    self_ = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [self_, shape, F(t)]


S(0x523040, 'CMoveAlongPath::ChangePath', 'thiscall', None, ret=None, gen=_change,
  note='batch251; logger assert-style call, field stores, ext 0x523280 when t == 0')
