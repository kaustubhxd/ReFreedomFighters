from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    log = lambda tag, n, pop: pystub(c, n, this=True, pop=pop,
        side=lambda emu, k: emu.calllog.append((tag, emu.reg('ecx'), *(emu.arg32(i) for i in range(n)))))
    payload = r.getrandbits(32)
    item = rnd(c, 0x20)
    e.w32(item + 8, payload)
    get_item = log('get-item', 1, 4)
    syslist = obj(c, 0x70, {0x58: get_item})
    sys = rnd(c, 0xa0)
    e.w32(sys + 0x9b, syslist)
    e.w32(0x70039c, sys)
    invoke = log('invoke', 4, 16)
    obj2 = obj(c, 0x2a0, {0x290: invoke})
    finish = log('finish', 2, 8)
    self = obj(c, 0x60, {0x68: finish})
    e.w32(self + 0x59, obj2)
    e.w32(self + 0x4c, r.getrandbits(32))
    e.w32(self + 0x50, r.getrandbits(32))
    e.w32(self + 0x54, r.choice([0, 1, 2]))
    e.w8(self + 0x58, r.choice([0, 0, 1]))
    hook_rec(c, 0x4dcbb0, 1, this=True, pop=4,
             side=lambda emu, k: emu.calllog.append(('helper', emu.reg('ecx'), emu.arg32(0))))
    return [self]


S(0x4b8da0, 'GUESS initialize and dispatch object once', 'thiscall', None,
  ret=None, gen=gen, note='batch62077')
