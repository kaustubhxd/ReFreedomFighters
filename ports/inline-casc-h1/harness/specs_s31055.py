"""specs_s31055.py - batch 31055: indexed byte read and bit extraction."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g4619c0(c):
    clear_hooks(c)
    param = c.rng.choice([0, 1, 2, 5])
    # Create base array with values at calculated offsets
    offset = param * 3 * 8 + 4
    base_fields = {offset: c.rng.choice([0, 1, 2, 3, 0xff])}
    base_array = obj(c, offset + 10, base_fields)

    self_obj = obj(c, 0x30, {0x1c: base_array})
    return [self_obj, param]

S(0x4619c0, 'indexed_byte_bit', 'thiscall', None, ret='al', gen=_g4619c0)
