from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    slots = {
        0x44: pystub(c, 1, ret=r.getrandbits(32), this=True, pop=4),
        0x54: pystub(c, 1, ret=r.getrandbits(32), this=True, pop=4),
        0x60: pystub(c, 1, ret=r.getrandbits(32), this=True, pop=4),
    }
    context = obj(c, 0x20, slots, nslots=0x61 // 4 + 1)
    self = rnd(c, 0x80)
    flags = r.getrandbits(32)
    e.w32(self + 4, flags)
    e.w32(self + 0x48, r.getrandbits(32))
    e.w32(self + 0x50, r.getrandbits(32))
    e.wbytes(self + 0x6c, bytes([r.getrandbits(8)]))
    return [self, context]


S(0x4b0ef0, 'GUESS clear context flag and invoke three callbacks', 'thiscall', None,
  ret='al', gen=gen, note='batch62043')
