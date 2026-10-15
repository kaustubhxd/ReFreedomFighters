from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x610100, 1, pop=4,
             side=lambda emu, k: emu.calllog.append(('base', emu.arg32(0))))
    hook_rec(c, 0x4e12f0, 2, this=True, pop=8,
             side=lambda emu, k: emu.calllog.append(('read-word', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    hook_rec(c, 0x4e12e0, 2, this=True, pop=8,
             side=lambda emu, k: emu.calllog.append(('read-dword', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0, ret=r.getrandbits(32),
             side=lambda emu, k: emu.calllog.append(('finish', emu.reg('ecx'))))
    self, reader = rnd(c, 0x70), rnd(c, 0x40)
    rvalue = r.getrandbits(32)
    c.emu.w32(self + 0x1c, rvalue)
    return [self, reader]


S(0x45ba60, 'GUESS serialize three fields and finish reader', 'thiscall', None,
  ret='eax', gen=gen, note='batch62049')
