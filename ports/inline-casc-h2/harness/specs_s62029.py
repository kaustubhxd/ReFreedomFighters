from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    def log(tag):
        return lambda emu, k: emu.calllog.append((tag, emu.arg32(0)))
    src = obj(c, 0x80, {
        0x58: pystub(c, 1, this=True, side=log('a')),
        0x68: pystub(c, 1, this=True, side=log('b')),
        0x70: pystub(c, 1, this=True, side=lambda emu, k: emu.calllog.append(('c', emu.arg32(0))))
    }, nslots=0x70 // 4 + 1)
    me = rnd(c, 0x90)
    e.w32(me + 4, r.getrandbits(32))
    e.w32(me + 0x6a, r.getrandbits(32))
    return [me, src]

S(0x4c4e50, 'GUESS clear state bit and pass embedded outputs to source', 'thiscall', None, ret='al', gen=gen, note='batch62029')
