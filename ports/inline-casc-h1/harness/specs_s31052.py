"""specs_s31052.py - batch 31052: simple byte write and return."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g429b00(c):
    clear_hooks(c)
    self_obj = obj(c, 0x80, {})
    return [self_obj]

S(0x429b00, 'write_byte_return_one', 'thiscall', None, ret='al', gen=_g429b00)
