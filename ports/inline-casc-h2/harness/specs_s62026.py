from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    item = obj(c, 0x20, {
        0xc: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100, 0xff])),
        0x18: pystub(c, 2, this=True, side=lambda emu, k: emu.calllog.append(('forward', emu.arg32(0), emu.arg32(1))))
    }, nslots=7)
    engine = sysobj(c, slots={0x1b0: pystub(c, 0, this=True, ret=r.choice([0, item]))})
    e.w32(0x70039c, engine)
    me = rnd(c, 0x100)
    e.w8(me + 0x80, r.choice([0, 0, 1]))
    return [me, r.getrandbits(32), r.getrandbits(32)]

S(0x6549e0, 'GUESS forward arguments to enabled engine item', 'thiscall', None, ret=None, gen=gen, note='batch62026')
