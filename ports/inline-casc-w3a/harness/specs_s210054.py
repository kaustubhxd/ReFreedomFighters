"""specs_s210054.py - Sonnet-w3a: 0x503450. 0x5003d0 hooked (three distinct cells holding objects/values); object slots 0x34 return tags; manager slot 0x114 returns values with high bits; target slot 0x12c records args."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g503450(c):
    clear_hooks(c)
    e = c.emu
    o2 = obj(c, 0x20, {0x34: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    o1 = obj(c, 0x20, {0x34: pystub(c, 4, ret=_r(c), this=True)}, nslots=0x20)
    cells = {2: rnd(c, 0x10), 1: rnd(c, 0x10), 0: rnd(c, 0x10)}
    e.w32(cells[2], o2); e.w32(cells[1], o1); e.w32(cells[0], _r(c))
    order = []
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: cells[emu.arg32(0)], this=True)
    tgt = obj(c, 0x40, {0x12c: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x60)
    mg = obj(c, 0x40, {0x114: pystub(c, 1, ret=lambda emu, k: _r(c), this=True)}, nslots=0x60)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    p = rnd(c, 0x20); e.w32(p + 4, rnd(c, 0x10))
    s = rnd(c, 0x20); e.w32(s + 0xc, tgt)
    return [s, p]


S(0x503450, 'relay_cells_to_target', 'thiscall', None, ret='eax', gen=g503450, note='batch210054')
