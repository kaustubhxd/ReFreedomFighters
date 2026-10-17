from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    selector = r.choice([0, 1, 2, 0x7f, 0xfe, 0xff, r.randrange(1, 256)])
    base = rnd(c, 0x100)
    e.wbytes(base, bytes([r.choice([0, 0x7f, 0xff, r.randrange(256)]) for _ in range(0x100)]))
    retbase = r.randrange(0, 256)
    e.w8(base + selector, r.choice([0xff, r.randrange(255)]))
    table = obj(c, 0x20, {0xc8: pystub(c, 1, this=True, ret=base-retbase)})
    mgr = rnd(c, 0x30)
    e.w32(mgr + 0x18, table)
    engine = rnd(c, 0x1ab0)
    e.w32(engine + 0x1aa3, mgr)
    e.w32(0x70039c, engine)
    param = rnd(c, 0x80)
    e.w32(param + 0x6c, r.getrandbits(32))
    me = rnd(c, 0x20)
    e.w32(me + 8, param)
    return [me, selector]

S(0x462f80, 'GUESS look up indexed engine byte', 'thiscall', None, ret='eax', gen=gen, note='batch62027')
