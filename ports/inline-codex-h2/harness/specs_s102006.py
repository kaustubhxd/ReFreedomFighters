from pilot import S
from recruits_util import obj, rnd, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    slot44 = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    slot4c = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    target = obj(c, 0x80, {0x44: slot44, 0x4c: slot4c})
    owner = rnd(c, 0x100)
    return [owner, target]


S(0x4bd240, 'GUESS_forward_parameter_fields_to_object', 'thiscall', None,
  ret=None, gen=gen, note='batch102006')
