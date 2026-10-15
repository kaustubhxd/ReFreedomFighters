from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    cb = obj(c, 0x20, {0x114: pystub(c, 3, ret=1, this=True)})
    config = rnd(c, 0x40)
    e.w32(config + 0x18, cb)
    so = sysobj(c)
    e.w32(so + 0x1aa3, config)
    node = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        e.w32(node + off, r.choice([0, 0x39000000, 0x3f800000]))
    e.w32(node + 0x6c, r.getrandbits(32))
    me = rnd(c, 0x20)
    e.w32(me + 8, node)
    return [me]


S(0x44f480, 'GUESS refresh object bounds and radius', 'thiscall', None, ret=None, gen=gen)
