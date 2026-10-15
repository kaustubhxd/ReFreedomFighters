from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g520ad0(c):
    clear_hooks(c)

    def mark(tag):
        return lambda emu, call_no: emu.calllog.append((tag,))

    hook_rec(c, 0x515790, 1, this=True, pop=4, side=mark('begin'))
    hook_rec(c, 0x4e12e0, 2, this=True, pop=8, side=mark('decode'))
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0, side=mark('finish'))
    self = rnd(c, 0x2600)
    reader = rnd(c, 0x40)
    return [self, reader]


S(0x520ad0, 'GUESS initialize and consume reader fields', 'thiscall', None, ret=None, gen=g520ad0, note='batch62012')
