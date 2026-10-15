from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def gen(c):
    clear_hooks(c)
    hook_rec(c, 0x5aedb0, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('base', emu.reg('ecx'))))
    hook_rec(c, 0x65e090, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('member', emu.reg('ecx'))))
    hook_rec(c, 0x5af2a0, 2, this=True, pop=8,
             side=lambda emu, k: emu.calllog.append(('set', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    self = rnd(c, 0x80)
    c.emu.w32(self + 0x14, c.rng.getrandbits(32))
    return [self]


S(0x5afc10, 'GUESS initialize fields from configuration keys', 'thiscall', None,
  ret='eax', gen=gen, note='batch62055')
