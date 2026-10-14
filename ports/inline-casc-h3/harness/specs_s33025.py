"""specs_s33025.py - h3 batch 33025: conditional flag setter."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g45e900(c):
    clear_hooks(c)
    # Create self with field at 0x14
    self = c.emu.alloc(0x200, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    # Randomize field at 0x14
    field_val = c.rng.getrandbits(32)
    c.emu.wbytes(self + 0x14, field_val.to_bytes(4, 'little'))
    # Flag: 0 or 1
    flag = c.rng.choice([0, 1])
    return [self, flag]

S(0x45e900, 'flag_set_clear', 'thiscall', None, ret=None, gen=_g45e900)
