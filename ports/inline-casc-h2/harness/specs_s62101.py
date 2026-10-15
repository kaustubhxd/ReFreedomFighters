from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = obj(c, 0x80, {0x2f0: pystub(c, 2, this=True, pop=8)}, nslots=0x2f0 // 4 + 1)
    e.w32(self + 0x6c, r.choice([0, 1, 2]))
    item = rnd(c, 0x80)
    nested = rnd(c, 0x40)
    status = rnd(c, 0x40)
    e.w32(item + 0x54, nested)
    e.w32(nested + 0xc, status)
    e.w32(status + 0x23, 0)
    e.w16(item + 0x5e, 1)
    base = rnd(c, 0x70)
    terminal_nested = rnd(c, 0x40)
    terminal_status = rnd(c, 0x40)
    e.w32(base + 0x54, terminal_nested)
    e.w32(terminal_nested + 0xc, terminal_status)
    e.w32(terminal_status + 0x23, 0x100000)
    e.w32(self + 0x54, item if r.random() < 0.8 else 0)
    hook_rec(c, 0x4db520, 0, this=True, pop=0, ret=base)
    return [self, r.getrandbits(32)]


S(0x4faa00, 'GUESS traverse eligible resource items and dispatch slot 0x2f0', 'thiscall', None,
  ret=None, gen=gen, note='batch62101')
