from pilot import S
from recruits_util import clear_hooks, obj, pystub, rnd

def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    records = [rnd(c, 0x10), rnd(c, 0x10)]
    e.w32(records[0], r.randrange(0x10, 0x100))
    e.w32(records[1], r.randrange(0x10, 0x100))
    idx = [0]
    slot38 = pystub(c, 1, ret=lambda em, k: records[min(k, 1)], this=True, pop=4)
    self = obj(c, 0x80, {
        0x34: pystub(c, 0, ret=2, this=True, pop=0),
        0x38: slot38,
    })
    string = rnd(c, 0x20)
    data = bytes(r.randrange(1, 256) for _ in range(r.randrange(0, 13))) + b'\0'
    e.wbytes(string, data)
    e.w32(self + 0x18, string)
    return [self]

S(0x638610, 'GUESS string_and_item_size_sum', 'thiscall', None, ret='eax', gen=gen, note='batch62141')
