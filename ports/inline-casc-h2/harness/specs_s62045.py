from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    arg = rnd(c, 0x20)
    in_range = bool(r.getrandbits(1))
    if in_range:
        e.wbytes(arg + 0x10, b'\x00\x00')
        e.w32(0x700e70, 1)
        target = pystub(c, 1, ret=r.getrandbits(32), pop=4)
        e.w32(0x700e78, target)
    else:
        e.wbytes(arg + 0x10, b'\x01\x00')
        e.w32(0x700e70, 1)
        msg = obj(c, 0x40, {0x2c: pystub(c, 3, this=True, pop=0)})
        logger = obj(c, 0x40, {0x20: pystub(c, 2, ret=msg, this=True, pop=8)})
        e.w32(0x700390, logger)
        e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32)))
    return [arg]


S(0x504560, 'GUESS dispatch indexed callback or log invalid index', 'cdecl', None,
  ret='eax', gen=gen, note='batch62045')
