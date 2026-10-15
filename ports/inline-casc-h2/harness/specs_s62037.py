from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    me = rnd(c, 0x12150)
    count = r.choice([0, 0, 1, 2, 5])
    e.w32(me + 0x1c4, count)
    for i in range(5):
        e.w32(me + 0x34 + i*4, r.getrandbits(32))
    if count:
        return [me]
    left = r.getrandbits(32)
    right = rnd(c, 0x40)
    i, j = r.randrange(3), r.randrange(3)
    e.w32(me + 0x12130, i)
    e.w32(me + 0xd628, j)
    e.w32(me + 0x11530 + i*4, left)
    e.w32(me + 0xc628 + j*4, right)
    cb = obj(c, 0x20, {0: pystub(c, 1, this=True, side=lambda emu,k: emu.calllog.append(('cb', emu.arg32(0))))})
    e.w32(me + 0x1ea, e.r32(cb))
    return [me]

S(0x4d0630, 'GUESS pop cached entry or refill ring slot', 'thiscall', None, ret='eax', gen=gen, note='batch62037')
