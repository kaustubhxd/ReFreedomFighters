"""specs_s33106.py - h3 (Sonnet) batch 33106: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4d1220(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 7, 8, 9, 15, 16, 17, 24, 33])
    arr = rnd(c, 8 * max(n, 1) + 8)
    me = rnd(c, 0x20)
    c.emu.w32(me, arr)
    c.emu.w32(me + 8, n)
    return [me]


def _g467850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stubs = {off: pystub(c, 1, this=True) for off in (0x60, 0x70, 0x68, 0x4c, 0x3c)}
    o = obj(c, 0x80, stubs)
    s3bc = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    q = obj(c, 0x3c8, {0x3bc: s3bc})
    me = rnd(c, 0x60)
    e.w32(me + 0x3d, r.choice([0, 0, 1, _w(c)]))
    return [me, o, q]


S(0x4d1220, 'GUESS sum of second dwords of 8-byte entries', 'thiscall', None, ret='eax', gen=_g4d1220, note='batch33106')
S(0x467850, 'GUESS write record fields to stream with optional query', 'thiscall', None, ret='al', gen=_g467850, note='batch33106')
