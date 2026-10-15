from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def gen(c):
    clear_hooks(c)
    hook_rec(c, 0x43ea20, 0, this=True, pop=0, side=lambda emu, k: emu.calllog.append(('init', emu.reg('ecx'))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda emu, k: emu.calllog.append(('release', emu.arg32(0))))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda emu, k: emu.calllog.append(('tag', emu.arg32(0), emu.arg32(1))))
    return [rnd(c, 0x100), c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]

S(0x4f59a0, 'GUESS initialize and select release path', 'thiscall', None, ret='eax', gen=gen, note='batch62030')
