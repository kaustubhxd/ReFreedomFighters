from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x563110, 2, this=True, pop=8, side=lambda emu,k: emu.calllog.append(('begin', emu.arg32(0), emu.arg32(1))))
    hook_rec(c, 0x56fe40, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('finish1',)))
    hook_rec(c, 0x56fb10, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('finish2',)))
    child = obj(c, 0x20, {0xbc: pystub(c, 1, this=True, pop=4, side=lambda emu,k: emu.calllog.append(('child', emu.arg32(0))))})
    manager = obj(c, 0x20, {0x284: pystub(c, 1, this=True, pop=4, side=lambda emu,k: emu.calllog.append(('manager', emu.arg32(0))))}, nslots=0x284//4+1)
    me = rnd(c, 0x700)
    e.w32(me + 0x44, child)
    e.w32(me + 0x5ce, manager)
    e.w16(me + 0x196, r.getrandbits(16))
    a = r.getrandbits(32)
    b = r.choice([0, 1, 0x100, 0x101, 0x80000000])
    return [me, a, b]

S(0x56fab0, 'GUESS start and finalize mode transition', 'thiscall', None, ret='al', gen=gen, note='batch62039')
