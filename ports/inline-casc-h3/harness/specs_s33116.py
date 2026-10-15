"""specs_s33116.py - h3 (Sonnet) batch 33116: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4a4f10(c):
    clear_hooks(c)
    stubs = {off: pystub(c, 1, this=True) for off in (0x40, 0x60, 0x54, 0x4c)}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0x70), s]


def _g4b7890(c):
    clear_hooks(c)
    stubs = {off: pystub(c, 1, this=True) for off in (0x44, 0x54, 0x4c, 0x3c)}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0x90), s]


def _g642050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 3, 7, 8, 9, 15, 16, 17, 23, 0xffffffff, 0x80000000, 5])
    nn = n if n < 0x1000 else 1
    arr = rnd(c, 4 * 32 + 8)
    for i in range(32):
        q = r.random()
        if q < 0.4:
            e.w32(arr + 4 * i, 0)
        elif q < 0.55:
            e.w32(arr + 4 * i, r.choice([0x10000, 0x80000000, 0xffff0000]))
    me = rnd(c, 0x40)
    e.w32(me + 0x21, n)
    e.w32(me + 0x2d, arr)
    return [me]


S(0x4a4f10, 'GUESS write record fields to stream (a)', 'thiscall', None, ret='al', gen=_g4a4f10, note='batch33116')
S(0x4b7890, 'GUESS write record fields to stream (b)', 'thiscall', None, ret='al', gen=_g4b7890, note='batch33116')
S(0x642050, 'GUESS count non-zero dwords', 'thiscall', None, ret='eax', gen=_g642050, note='batch33116')
