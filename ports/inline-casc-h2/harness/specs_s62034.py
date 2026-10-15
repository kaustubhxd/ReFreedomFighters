from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    me = rnd(c, 0x80)
    node = rnd(c, 0x40) if r.random() < 0.8 else 0
    e.w32(me + 0x50, node)
    child = obj(c, 0x20, {0: pystub(c, 1, this=True, side=lambda emu,k: emu.calllog.append(('child', emu.arg32(0))))}) if r.random() < 0.6 else 0
    e.w32(me + 0x44, child)
    hook_rec(c, 0x4d9430, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('walk', emu.reg('ecx'))))
    def remove(emu, k):
        emu.calllog.append(('remove', emu.arg32(0)))
        emu.w32(me + 0x50, 0)
    hook_rec(c, 0x4d9590, 1, pop=0, side=remove)
    hook_rec(c, 0x45c3e0, 0, this=True, pop=0, ret=r.getrandbits(32), side=lambda emu,k: emu.calllog.append(('base', emu.reg('ecx'))))
    return [me]

S(0x43ea20, 'GUESS drain linked cleanup list and release child', 'thiscall', None, ret='eax', gen=gen, note='batch62034')
