from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    ptrs, values = [], []
    for _ in range(3):
        p = rnd(c, 4)
        value = r.getrandbits(32)
        e.w32(p, value)
        ptrs.append(p)
        values.append(value)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4,
             ret=lambda emu, k: ptrs[min(k, 2)],
             side=lambda emu, k: emu.calllog.append(('reader', emu.reg('ecx'), emu.arg32(0))))
    self = rnd(c, 0x310)
    output = rnd(c, 0x2a0)
    e.w32(self + 0x18, output)
    arg = rnd(c, 0x20)
    reader = rnd(c, 0x20)
    e.w32(arg + 4, reader)
    return [self, arg]


S(0x51ea20, 'GUESS copy three reader values into output record', 'thiscall', None,
  ret='eax', gen=gen, note='batch62046')
