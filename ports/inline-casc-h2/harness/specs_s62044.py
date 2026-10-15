from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4cbec0, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('member-dtor', emu.reg('ecx'))))
    hook_rec(c, 0x42bae0, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('main-cleanup', emu.reg('ecx'))))
    hook_rec(c, 0x634273, 2, pop=0,
             side=lambda emu, k: emu.calllog.append(('release', emu.arg32(0), emu.arg32(1))))
    return [rnd(c, 0x1e20), r.choice([0, 1, 2, 3, 0x100])]


S(0x42a7b0, 'GUESS destroy embedded members and release object', 'thiscall', None,
  ret='eax', gen=gen, note='batch62044')
