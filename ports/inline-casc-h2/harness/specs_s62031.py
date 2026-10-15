from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    value = r.getrandbits(32)
    table = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=value)})
    eng = rnd(c, 0xa0)
    e.w32(eng + 0x9b, table)
    e.w32(0x70039c, eng)
    target = rnd(c, 0x13320) if r.random() < 0.75 else 0
    hook_rec(c, 0x563a50, 0, this=True, pop=0, side=lambda emu,k: emu.calllog.append(('tail', emu.reg('ecx'))))
    me = obj(c, 0x1d0, {0x64: pystub(c, 1, this=True, side=lambda emu,k: emu.calllog.append(('slot64', emu.arg32(0))))}, nslots=0x64//4+1)
    mode = r.choice([0, 1, 2, 2, 5, 5, 7])
    e.w32(me + 0x1c5, mode)
    e.w32(me + 0x94, target)
    e.w32(me + 0x44, r.getrandbits(32))
    if target:
        e.w32(target + 0x1329f, r.getrandbits(32))
    return [me]

S(0x56a030, 'GUESS update mode dependent engine state', 'thiscall', None, ret=None, gen=gen, note='batch62031')
