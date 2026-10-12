"""specs_s924.py - unclaimed-80 claim 4 (docs/20-unclaimed-80.md): ZFFMortar::Load (0x5dd3f0). The global callback at 0x7003b0
is a no-op thiscall stub (the exe faults on a null callback, so it is always set). 0x5dd4b0 is a logging no-op stub (one
argument, ret 4). The load object is a logging fake: slots +0x68 and +0x40 (one pointer argument) write a per-case byte through
the pointer, which the fields of the object then carry."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    cb = ss.rec(c, 0, ret=0)
    c.emu.w32(0x7003b0, cb)
    ss.patch(c, 0x5dd4b0, ss.rec(c, 1, ret=0))
    v = c.rng.getrandbits(8)

    def wbyte(e, args, v=v):
        e.w8(args[0], v)
        return (0, None)

    load = _rnd(c, 0x40)
    c.emu.w32(load, c.emu.logging_vtable('ZLoadGame2', 0x30, impl={0x40: wbyte, 0x68: wbyte},
                                         argwords={0x40: 1, 0x68: 1}))
    o = _rnd(c, 0x100)
    return [o, load]


S(0x5dd3f0, 'ZFFMortar::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-80 claim 4; callback 0x7003b0 no-op; 0x5dd4b0 stubbed; load slots +0x68 (six) and +0x40 logged')
