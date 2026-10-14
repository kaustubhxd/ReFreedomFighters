"""specs_s31033.py - batch 31033: byte swap and conditional setter."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g466600(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {0: c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [self_obj, param]

def _g475910(c):
    clear_hooks(c)
    self_obj = obj(c, 0x400, {0x3bb: 0})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [self_obj, param]

S(0x466600, 'byte_swap', 'thiscall', None, ret='al', gen=_g466600)
S(0x475910, 'cond_byte_setter', 'thiscall', None, ret=None, gen=_g475910)
