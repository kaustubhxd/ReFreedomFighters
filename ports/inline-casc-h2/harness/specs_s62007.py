from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    hook_rec(c, 0x5e93f0, 2, this=True, pop=8)
    returned_ref = {}

    def fill(emu, k):
        emu.w32(emu.arg32(1), returned_ref['ptr'])

    fetch = pystub(c, 2, this=True, pop=8, side=fill, stackmark=(1,))
    returned = obj(c, 0x60, {0x88: fetch})
    returned_ref['ptr'] = returned
    get_obj = pystub(c, 0, this=True, pop=0, ret=returned)
    sysobj(c, table_slots={0x138: get_obj})
    self = obj(c, 0xa00, {})
    c.emu.w8(self + 0x9e7, c.rng.choice([0, 1]))
    return [self, c.rng.getrandbits(32)]

S(0x594540, 'GUESS remove item from engine object', 'thiscall', None, ret=None, gen=gen, note='batch62007')
