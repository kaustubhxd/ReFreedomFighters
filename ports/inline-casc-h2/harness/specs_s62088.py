from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    n = r.randrange(0, 6)
    entries = rnd(c, max(8, n * 8))
    for i in range(n):
        e.w32(entries + i * 8, r.randrange(1, 0xffffffff))
        e.w32(entries + i * 8 + 4, r.getrandbits(32))
    def dispatch_side(emu, k):
        emu.calllog.append(('dispatch', emu.reg('ecx'), emu.reg('edx'), *(emu.arg32(i) for i in range(6))))
    vt_obj = obj(c, 0x140, {0x11c: pystub(c, 6, pop=24, ret=r.getrandbits(32), side=dispatch_side)})
    sys = rnd(c, 0x20)
    e.w32(sys, e.r32(vt_obj))
    e.w32(0x724a00, sys)
    array = rnd(c, 0x10)
    e.w32(array, n)
    e.w32(array + 8, entries)
    self = rnd(c, 0x20)
    return [self, array]


S(0x61a660, 'GUESS dispatch indexed key/value records', 'fastcall', None,
  ret=None, gen=gen, note='batch62088')
