from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x518850, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('first', emu.reg('ecx'))))
    hook_rec(c, 0x512e10, 1, this=True, pop=4, side=lambda emu,k: emu.calllog.append(('format', emu.arg32(0))))
    hook_rec(c, 0x51fbe0, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('update', emu.reg('ecx'))))
    item = rnd(c, 0x40)
    tab = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=item, side=lambda emu,k: emu.calllog.append(('lookup', emu.arg32(0))))})
    resource = obj(c, 0x20, {0x184: pystub(c, 5, pop=0, this=True, side=lambda emu,k: emu.calllog.append(('resource', *(emu.arg32(i) for i in range(5)))))})
    eng_v = obj(c, 0xc0, {0x190: pystub(c, 0, this=True, ret=resource)}, nslots=0x190//4+1)
    e.w32(eng_v + 0x9b, tab)
    e.w32(0x70039c, eng_v)
    me = rnd(c, 0x1700)
    for off in (0x1654, 0x16d5): e.w32(me + off, r.getrandbits(32))
    e.w32(me + 0x16e9, 0)  # make 0x512e10 take its plain ret path
    return [me]

S(0x51fa60, 'GUESS refresh entry and submit resource update', 'thiscall', None, ret=None, gen=gen, note='batch62038')
