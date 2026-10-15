from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g4f9970(c):
    clear_hooks(c)
    hook_rec(c, 0x43ea20, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('cleanup', emu.reg('ecx'))))
    hook_rec(c, 0x45c510, 1, pop=0,
             side=lambda emu, k: emu.calllog.append(('release', emu.arg32(0))))
    flags = c.rng.choice([0, 1, 4, 5, 3, 7, c.rng.getrandbits(32)])
    return [rnd(c, 0x60), flags]


S(0x4f9970, 'GUESS select cleanup release path', 'thiscall', None, ret='eax', gen=g4f9970, note='batch62021')
