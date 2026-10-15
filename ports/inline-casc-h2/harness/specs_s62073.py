from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    code = r.choice([0, 1, 7, 8, 31, 32, 0x100, 0x1234, 0x7fff, 0xffff,
                     0x10000, 0x12340000, 0xffffffff, r.getrandbits(32)])
    arg = r.getrandbits(32)
    record = rnd(c, 0x178)
    e.w32(record + 0x170, pystub(c, 2, pop=0, ret=code,
                                 side=lambda emu, k: emu.calllog.append(('callback', emu.arg32(0), emu.arg32(1)))))
    e.w32(record + 0x174, r.getrandbits(32))
    return [record, arg]


S(0x62c790, 'GUESS decode compact table membership code', 'cdecl', None,
  ret='eax', gen=gen, note='batch62073')
