from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g460c40(c):
    clear_hooks(c)
    hook_rec(c, 0x43de70, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('begin', emu.reg('ecx'))))
    hook_rec(c, 0x45c510, 1, pop=0,
             side=lambda emu, k: emu.calllog.append(('release', emu.arg32(0))))
    flags = c.rng.choice([0, 1, 4, 5, 3, 7, c.rng.getrandbits(32)])
    return [rnd(c, 0x40), flags]


S(0x460c40, 'GUESS select object teardown path', 'thiscall', None, ret='eax', gen=g460c40, note='batch62018')
