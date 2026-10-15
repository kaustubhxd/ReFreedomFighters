from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x612030, 2, this=True, pop=8, ret=r.getrandbits(32),
             side=lambda emu, k: emu.calllog.append(('finish', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    nested = obj(c, 0x20, {4: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32),
                  side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    self = rnd(c, 0x1400)
    e.w32(self + 0x13e7, nested)
    key = r.choice([0, 0x800, 1, 0x7ff, 0x801, 0xffffffff])
    return [self, key, r.getrandbits(32), r.getrandbits(32)]


S(0x6120f0, 'GUESS look up keyed value and finalize request', 'thiscall', None,
  ret='eax', gen=gen, note='batch62057')
