"""specs_s67572.py - cascade s6 batch 67572 (0x590140, thiscall(id) ret 4, return value unused). The table slot 0x58 answers the new target (first lookup) and the default target (second): from {old, other, 0}
and {new, other}; this slot 0x504 returns the old target (an object with slots 0x2d0 (2) / 0x2e8 -> helper slot 0x308 (bool-ish, 1 or other)); this slots 0x3ec (1) / 0x3d8 (1) / 0x45c (2); table slot 0x4c."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g590140(c):
    clear_hooks(c)
    r = c.rng
    helper = obj(c, 0x20, {0x308: pystub(c, 0, this=True, ret=lambda em, k: r.choice([1, 1, 0, 2]))})
    old = obj(c, 0x20, {0x2d0: pystub(c, 2, this=True), 0x2e8: pystub(c, 0, this=True, ret=helper)})
    other = rnd(c, 0x20)
    oldv = r.choice([old, old, 0])
    new = r.choice([oldv, other, other, 0])
    dflt = r.choice([new, other, other, old])
    seq = [new, dflt]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 1)]),
                           0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    t = obj(c, 0x860, {0x504: pystub(c, 0, this=True, ret=oldv), 0x3ec: pystub(c, 1, this=True, ret=lambda em, k: 0x500 + k),
                       0x3d8: pystub(c, 1, this=True), 0x45c: pystub(c, 2, this=True)})
    _w(c, t + 0x842, r.getrandbits(32))
    return [t, r.getrandbits(32)]


S(0x590140, 'GUESS switch_target', 'thiscall', None, ret=None, gen=_g590140, note='batch67572')
