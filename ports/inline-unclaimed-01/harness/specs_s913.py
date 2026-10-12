"""specs_s913.py - unclaimed-01 claim 12 (docs/20-unclaimed-01.md): ZInputActions::CheckActionAnalog (0x438000). The
object's vtable is a logging fake: slot +0x2c returns a per-case value (zero about a third of the time, so the 0.0 path
runs), slot +0xa0 returns a per-case value (its low byte, read as signed, is the numerator). The float result is
compared through st0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _analog(c):
    v1 = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32)
    v2 = c.rng.getrandbits(32)
    o = _rnd(c, 0x40)
    vt = c.emu.logging_vtable('ZInputActions', 0x2a, impl={0x2c: (lambda e, a, v=v1: (v, None)),
                                                            0xa0: (lambda e, a, v=v2: (v, None))},
                              argwords={0x2c: 2, 0xa0: 1})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x438000, 'ZInputActions::CheckActionAnalog (unknown) thiscall', 'thiscall', None, ret='st0', gen=_analog,
  note='unclaimed-01 claim 12; st0 result: 0.0, or signed byte from slot +0xa0 divided by the constant at 0x67af20')
