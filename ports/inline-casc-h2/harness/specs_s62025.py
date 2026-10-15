from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g5e1450(c):
    clear_hooks(c)

    def mark(tag):
        return lambda emu, k: emu.calllog.append((tag, emu.reg('ecx')))

    hook_rec(c, 0x480fd0, 0, this=True, pop=0, side=mark('embedded'))
    hook_rec(c, 0x4878d0, 0, this=True, pop=0, side=mark('nested'))
    hook_rec(c, 0x634273, 2, pop=0, side=lambda emu, k: emu.calllog.append(('callback', emu.arg32(0), emu.arg32(1))))
    flags = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])
    return [rnd(c, 0x600), flags]


S(0x5e1450, 'GUESS initialize embedded members and callback', 'thiscall', None, ret='eax', gen=g5e1450, note='batch62025')
