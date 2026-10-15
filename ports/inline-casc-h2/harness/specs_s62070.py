from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    first = pystub(c, 2, this=True, pop=8,
                   side=lambda emu, k: emu.calllog.append(('first', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    result = r.choice([0, 0, 1, r.getrandbits(32)])
    second = pystub(c, 4, this=True, pop=16, ret=result,
                    side=lambda emu, k: emu.calllog.append(('second', emu.reg('ecx'), *(emu.arg32(i) for i in range(4)))))
    collection = obj(c, 0x40, {0x34: first, 0x30: second})
    helper_ret = r.getrandbits(32)
    hook_rec(c, 0x54f2b0, 0, ret=helper_ret,
             side=lambda emu, k: emu.calllog.append(('tail', emu.reg('ecx'), emu.reg('edx'))))
    self = rnd(c, 0x63f4)
    e.w32(self + 0x63ec, collection)
    e.w32(self + 0x75, r.choice([0, 1, 2, 3, 4, 0xffffffff, r.getrandbits(32)]))
    e.w8(self + 0x7b, r.choice([0, 1, 0x7f]))
    return [self]


S(0x54c320, 'GUESS set state flags and dispatch collection result', 'thiscall', None,
  ret='eax', gen=gen, note='batch62070')
