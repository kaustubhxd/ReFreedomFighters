from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    enabled = r.choice([0, 0, 1])
    first = obj(c, 0x20, {0x354: pystub(c, 0, this=True, ret=r.choice([0, 0, 1]))})
    n1 = obj(c, 0x20, {})
    n2 = obj(c, 0x20, {0x31c: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    calls = [n1, n2]
    def next_node(emu, k):
        return calls[min(k, 1)]
    me = obj(c, 0x80, {
        0x350: pystub(c, 0, this=True, ret=first),
        0x328: pystub(c, 0, this=True, ret=next_node),
    }, nslots=0xd5)
    e.w32(me + 0x60, enabled)
    return [me]

S(0x46edb0, 'GUESS validate and dispatch through nested slots', 'thiscall', None, ret='eax', gen=gen, note='batch62028')
