from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    self = obj(c, 0x120, {})
    embedded = obj(c, 0x20, {})
    owner = obj(c, 4, {})
    c.emu.w32(self + 0x44, owner)
    c.emu.w32(0x7002ac, c.rng.getrandbits(16))
    initial = c.rng.choice([0, 0, 0, rnd(c, 4)])
    c.emu.w32(self + 0x102, initial)
    c.emu.w8(self + 0x5e, c.rng.getrandbits(8))
    made = c.rng.choice([0, 0, embedded])

    def write_out(emu, k):
        emu.w32(emu.arg32(1), made)

    slot = pystub(c, 3, this=True, pop=12, side=write_out)
    vt = c.emu.alloc(0x12c, 4)
    c.emu.w32(owner, vt)
    c.emu.w32(vt + 0x128, slot)
    return [self]

S(0x4a0d00, 'GUESS lazy owner-backed record', 'thiscall', None, ret=None, gen=gen, note='batch62005')
