"""specs_s67541.py - cascade s6 batch 67541 (0x56cc30, thiscall() plain ret, return value unused). sys[0x6c] / this[0x1c6] gate the poll; the input object (sys[0x1907]) slot 0x2c
(2 args) answers from a seeded sequence; the device object at 0x7003a0 slot 0x4c returns the mask; 0x562260 / 0x56d950 are hooks; per-slot flags +0x19c..+0x19f / +0x1a0..+0x1a3 are 0 / 1 / other."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g56cc30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562260, 0, this=True)
    hook_rec(c, 0x56d950, 0, this=True)
    inp = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))})
    so = sysobj(c)
    _w(c, so + 0x1907, inp)
    _w(c, so + 0x6c, r.choice([0, 1, 1, 1]), 1)
    dev = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0xf, 0x5, 0xa, 0x3, 0x8, 0x10, 0x1f]))})
    e.w32(0x7003a0, dev)
    t = rnd(c, 0x200)
    for i in range(8):
        _w(c, t + 0x19c + i, r.choice([0, 1, 1, 2]), 1)
    _w(c, t + 0x1c6, r.choice([0, 1, 1, 7]))
    _w(c, t + 0x1c2, r.choice([0, 0xf, 0x5, 0xa, 0x3, 0x10]))
    return [t]


S(0x56cc30, 'GUESS poll_input_slots', 'thiscall', None, ret=None, gen=_g56cc30, note='batch67541')
