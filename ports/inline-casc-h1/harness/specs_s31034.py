"""specs_s31034.py - batch 31034: bit manipulation and initialization."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g45e900(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {0x14: c.rng.choice([0, 0x10, 0xffffffff, c.rng.getrandbits(32)])})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [self_obj, param]

def _g524660(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {
        0: c.rng.choice([0, 1, c.rng.getrandbits(32)]),
        4: c.rng.choice([0, 1, c.rng.getrandbits(32)]),
        8: c.rng.choice([0, 1, c.rng.getrandbits(32)]),
        0xc: c.rng.choice([0, 0x46c35000, c.rng.getrandbits(32)]),
        0x10: c.rng.choice([0, 0x44fa0000, c.rng.getrandbits(32)]),
        0x14: c.rng.choice([0, 0x42a00000, c.rng.getrandbits(32)]),
        0x18: c.rng.choice([0, 1, c.rng.getrandbits(32)]),
        0x1c: c.rng.choice([0, 1, c.rng.getrandbits(32)])
    })
    return [self_obj]

def _g533bc0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    param = c.rng.choice([0, 1, 0x12345678, c.rng.getrandbits(32)])
    return [self_obj, param]

S(0x45e900, 'cond_bit_setter', 'thiscall', None, ret=None, gen=_g45e900)
S(0x524660, 'struct_initializer', 'thiscall', None, ret=None, gen=_g524660)
S(0x533bc0, 'null_check_return', 'thiscall', None, ret='eax', gen=_g533bc0)
