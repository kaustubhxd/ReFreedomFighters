from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x120)
    e.w32(self + 0x44, r.getrandbits(32))
    e.w32(self + 0x48, r.getrandbits(32))
    e.w32(self + 0xf4, r.getrandbits(32))
    parser = rnd(c, 0x40)
    cursors = [r.getrandbits(32), r.getrandbits(32)]
    def advance(emu, k):
        emu.w32(emu.arg32(0), cursors[k])
    hook_rec(c, 0x4e6330, 1, this=True, pop=4, side=advance)
    handle = r.getrandbits(32)
    table = obj(c, 0x180, {
        0x138: pystub(c, 0, this=True, ret=0),
        0x4c: pystub(c, 2, this=True, pop=8, ret=handle),
    }, nslots=0x4c // 4 + 1)
    receiver = obj(c, 0x20, {0x60: pystub(c, 2, this=True, pop=8,
        ret=r.getrandbits(32))}, nslots=0x60 // 4 + 1)
    # Slot 0x138 returns the receiver used by the final call.
    e.w32(e.r32(table) + 0x138, pystub(c, 0, this=True, ret=receiver))
    engine = rnd(c, 0x2000)
    e.w32(engine + 0x9b, table)
    e.w32(0x70039c, engine)
    return [self, parser]


S(0x4bb7c0, 'GUESS advance two cursors and submit table handle', 'thiscall', None,
  ret='eax', gen=gen, note='batch62099')
