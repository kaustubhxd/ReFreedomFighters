from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    error_message = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)})
    engine = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=error_message)})
    e.w32(0x700390, engine)
    logger = obj(c, 0x30, {0x2c: pystub(c, 3, this=True, pop=12)})
    e.w32(0x70038c, logger if r.randrange(2) else 0)
    state = rnd(c, 0x70)
    index = r.choice([0, 1, 19, 255, 509, 510, 700])
    e.w32(state + 0x59, index)
    array = rnd(c, 0x500)
    for i in range(512):
        e.w16(array + 2 * i, r.randrange(128))
    e.w32(state + 0x55, array)
    base = rnd(c, 0x2100)
    e.w32(state + 0x51, base)
    return [state]

S(0x4960e0, 'GUESS allocate_next_buffer_entry_or_report', 'thiscall', None, ret='eax', gen=gen, note='batch62135')
