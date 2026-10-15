from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    item = obj(c, 0x20, {0x2c: pystub(c, 0, this=True, side=lambda emu,k: emu.calllog.append(('dispatch',)))})
    sub = rnd(c, 0x50)
    e.w32(item + 8, sub)
    e.w32(sub + 0x3c, r.choice([0, 1<<10, 1<<11, 3<<10, r.getrandbits(16)<<10]))
    element = r.getrandbits(32)
    table = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=item, side=lambda emu,k: emu.calllog.append(('lookup', emu.arg32(0))))})
    eng = rnd(c, 0xa0)
    e.w32(eng + 0x9b, table)
    e.w32(0x70039c, eng)
    count = r.randrange(1, 8)
    arr = rnd(c, count*4+4)
    vals = [r.getrandbits(32) for _ in range(count)]
    vals[0] = element
    e.wbytes(arr, b''.join(v.to_bytes(4,'little') for v in vals))
    me = rnd(c, 0xb0)
    e.w32(me + 0x98, arr)
    e.w32(me + 0x9c, count)
    e.w32(me + 0xa0, r.randrange(count))
    return [me]

S(0x46ed50, 'GUESS rotate item index and dispatch by state bit', 'thiscall', None, ret='eax', gen=gen, note='batch62035')
