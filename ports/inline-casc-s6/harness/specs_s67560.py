"""specs_s67560.py - cascade s6 batch 67560 (0x5c21e0, thiscall(mode) ret 4, return value unused). The object has the direct flag +0x111, mode +0x48 (previous written to +0x4c), table base +0xe8,
the entry array +0xe4 (random dwords), the mode-object factory +0x10d (slot 0x25c, 2 args: returns an object with slots 0xbc / 0x128 or 0), +0x50 flag; sys[0x1b5d] is 1 / 0 / other; the table slot 0x114
(6 args) returns a word with garbage high bits; 0x5c2120 and 0x610100 are hooks; the config chain [0x7003b8]+0x2c15 -> byte +0x103f is random."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5c21e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_slots={0x114: pystub(c, 6, this=True, ret=lambda em, k: r.getrandbits(32))})
    _w(c, so + 0x1b5d, r.choice([0, 1, 1, 2]))
    mo = [obj(c, 0x20, {0xbc: pystub(c, 1, this=True), 0x128: pystub(c, 1, this=True)}) for _ in range(3)]
    fac = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: r.choice(mo + [0]))})
    cfg = rnd(c, 0x1100)
    _w(c, cfg + 0x103f, r.choice([0, 1, 5]), 1)
    gl = rnd(c, 0x2d00)
    _w(c, gl + 0x2c15, cfg)
    e.w32(0x7003b8, gl)
    arr = rnd(c, 0x80)
    t = rnd(c, 0x140)
    _w(c, t + 0x10d, fac)
    _w(c, t + 0xe4, arr)
    base = r.choice([0, 1, 2])
    _w(c, t + 0xe8, base)
    old = r.choice([base, base + 1, base + 3])
    _w(c, t + 0x48, old)
    _w(c, t + 0x111, r.choice([0, 0, 0, 1, 7]))
    _w(c, t + 0x50, r.choice([0, 1, 1, 1]))
    hook_rec(c, 0x5c2120, 1, this=True)
    hook_rec(c, 0x610100, 1)
    return [t, r.choice([base, base + 1, base + 2, 7, 3, 0, 5])]


S(0x5c21e0, 'GUESS switch_mode', 'thiscall', None, ret=None, gen=_g5c21e0, note='batch67560')
