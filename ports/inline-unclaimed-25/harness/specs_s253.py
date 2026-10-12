"""specs_s253.py - unclaimed area 25, slice 4: 0x51b5c0 ZCarIf::collectOpaqueInfo (buf is a logging vtable object)."""
from pilot import S
from anim_common import install_crt_str


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _collect(c):
    install_crt_str(c)
    bvt = c.emu.logging_vtable('OpaqueBuf', 0x140, argwords={0: 1})
    buf = _rnd(c, 0x40)
    c.emu.w32(buf, bvt)
    vt = c.emu.logging_vtable('ZCar', 0x140, impl={0x38: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0x38: 0})
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, vt)
    c.emu.mu.ctl_flush_tb()
    return [self_, buf]


S(0x51b5c0, 'ZCarIf::collectOpaqueInfo', 'thiscall', None, ret=None, gen=_collect,
  note='batch253; ext 0x51f200 (original) then slot 0x38 and buf slot 0')
