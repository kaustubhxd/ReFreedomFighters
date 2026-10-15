from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    alloc = pystub(c, 4, this=True, pop=16,
                   side=lambda emu, k: emu.calllog.append(('allocate', emu.reg('ecx'), *(emu.arg32(i) for i in range(4)))))
    flush = pystub(c, 0, side=lambda emu, k: emu.calllog.append(('flush',)))
    e.w32(0x6761d4, alloc)
    e.w32(0x6762ac, flush)
    hook_rec(c, 0x634273, 2, pop=0,
             side=lambda emu, k: emu.calllog.append(('free', emu.arg32(0), emu.arg32(1))))
    self = rnd(c, 0x30)
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 8, r.getrandbits(32))
    e.w32(self + 0x24, r.choice([0, 0, r.getrandbits(32)]))
    return [self, r.choice([0, 1, 2, 3, 0xffffffff])]


S(0x424e70, 'GUESS release communication object', 'thiscall', None,
  ret='eax', gen=gen, note='batch62075')
