from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    cb = obj(c, 0x20, {0x28: pystub(c, 6, this=True, side=lambda emu,k: emu.calllog.append(('cb', *(emu.arg32(i) for i in range(6)))))}, nslots=0x28//4+1)
    me = rnd(c, 0xb0)
    data = rnd(c, 0x30)
    e.w8(me + 0x35, r.choice([0, 1, 1]))
    e.w32(me + 0x3a, data)
    e.w32(data, r.choice([0, 1, r.getrandbits(32)]))
    e.w32(me + 0x36, r.getrandbits(32))
    e.w8(me + 0x5e, r.getrandbits(8))
    return [me, cb, r.getrandbits(32)]

S(0x5ebda0, 'GUESS dispatch initialized data to callback', 'thiscall', None, ret=None, gen=gen, note='batch62032')
