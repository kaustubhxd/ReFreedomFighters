from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    helper_ret = r.choice([0x100, 0x101, 0x102, 0x7f000000, 0])
    hook_rec(c, 0x600280, 5, this=True, pop=20, ret=helper_ret,
             side=lambda emu, k: emu.calllog.append(('check', emu.reg('ecx'), *(emu.arg32(i) for i in range(5)))))
    inner = obj(c, 0x30, {0x2c: pystub(c, 3, pop=0,
                 side=lambda emu, k: emu.calllog.append(('print', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))})
    logger = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=inner,
                    side=lambda emu, k: emu.calllog.append(('logger', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    e.w32(0x700390, logger)
    assert_ret = r.getrandbits(32) | 1
    e.w32(0x7003b0, pystub(c, 0, ret=assert_ret,
                           side=lambda emu, k: emu.calllog.append(('assert',))))
    return [rnd(c, 0x120), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x6001e0, 'GUESS check state then log and assert on rejection', 'thiscall', None,
  ret='eax', gen=gen, note='batch62072')
