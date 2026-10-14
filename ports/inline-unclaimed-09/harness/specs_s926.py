"""specs_s926.py - unclaimed-09 batch 18 (docs/20-unclaimed-09.md, claim 19): 0x460800, the RecSub wrapper.

Inputs follow area 42's ranges so the subdivision stays short: the four points are uniform in [-1, 1]; x is uniform in
[-0.41, 0.77], so s = (1 - x)^2 is in [0.05, 2]. The wrapper's out cursor always points at a zeroed buffer (the exe copies
into it unconditionally). p and q are the two ints: p in [1, 7] (the depth limit), q random. The this pointer (ecx) is a
zeroed 0x100-byte object; the callee 0x460650 and its leaf 0x460870 run as original code (no stubs)."""
from pilot import S
import struct


def _pt(c):
    cell = c.emu.alloc(12, 4)
    for i in range(3):
        c.emu.wbytes(cell + 4 * i, struct.pack('<f', c.rng.uniform(-1.0, 1.0)))
    return cell


def _gen(c):
    obj = c.emu.alloc(0x100, 16)
    c.emu.wbytes(obj, bytes(0x100))
    out = c.emu.alloc(0x40, 16)
    c.emu.wbytes(out, bytes(0x40))
    x = c.rng.uniform(-0.41, 0.77)
    return [obj, out, _pt(c), _pt(c), _pt(c), _pt(c), _f(x), c.rng.randrange(1, 8), c.rng.getrandbits(32)]


def _f(v):
    from pe_emu import F
    return F(v)


S(0x460800, 'ParametricCurve::RecSub wrapper (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-09 b18; wrapper around 0x460650 (area 42, original code runs); GUESS name')
