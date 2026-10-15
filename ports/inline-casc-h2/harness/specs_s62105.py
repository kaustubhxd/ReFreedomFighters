from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    flags = r.choice([0, 1, 0x100000, 0x100001, 0xffffffff])
    state = rnd(c, 0x40)
    e.w32(state + 0x23, flags)
    self = rnd(c, 0x20)
    e.w32(self + 0xc, state)
    tokens = [r.getrandbits(32), r.getrandbits(32)]
    table = sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, pop=4,
        ret=lambda emu, k: tokens[min(k, 1)])})
    results = [r.choice([0, 0, 1, 0x12345678]), r.getrandbits(32)]
    object = obj(c, 0x40, {
        0x28: pystub(c, 1, this=True, pop=4, ret=results[0]),
        4: pystub(c, 1, this=True, pop=4, ret=results[1]),
    }, nslots=0x28 // 4 + 1)
    mask = r.choice([1, 0x100000, 0x100001, 0xffffffff])
    return [self, object, mask]


S(0x45eeb0, 'GUESS test resource flags and dispatch one or two slots', 'thiscall', None,
  ret='eax', gen=gen, note='batch62105')
