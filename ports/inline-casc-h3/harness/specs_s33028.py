"""specs_s33028.py - h3 batch 33028: conditional add and field initialization."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g537770(c):
    clear_hooks(c)
    # Create self with field at 0x5302
    self = c.emu.alloc(0x6000, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x6000)))
    # Field value: 0 or nonzero
    if c.rng.choice([True, False]):
        val = 0
    else:
        val = 1 + c.rng.getrandbits(31)
    c.emu.wbytes(self + 0x5302, val.to_bytes(4, 'little'))
    # Argument: 0 or nonzero
    if c.rng.choice([True, False]):
        arg = 0
    else:
        arg = 1 + c.rng.getrandbits(31)
    return [self, arg]

def _g5df5f0(c):
    clear_hooks(c)
    # Create self with random data
    self = c.emu.alloc(0x200, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    # Three arguments
    arg1 = c.rng.getrandbits(32)
    arg2 = c.rng.getrandbits(32)
    arg3 = c.rng.getrandbits(32)
    return [self, arg1, arg2, arg3]

S(0x537770, 'conditional_field_add_arg', 'thiscall', None, ret='eax', gen=_g537770)
S(0x5df5f0, 'field_init_three_args', 'thiscall', None, ret=None, gen=_g5df5f0)
