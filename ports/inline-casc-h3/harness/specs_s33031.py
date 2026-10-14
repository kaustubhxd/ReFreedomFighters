"""specs_s33031.py - h3 batch 33031: field copies and conditional logic."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g5d4210(c):
    clear_hooks(c)
    # Create self and arg with field data
    self = c.emu.alloc(0x100, 4)
    arg = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.wbytes(arg, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [self, arg]

def _g537790(c):
    clear_hooks(c)
    # Create self with field at 0x5302
    self = c.emu.alloc(0x6000, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x6000)))
    # Field: 0 or nonzero
    if c.rng.choice([True, False, False]):
        field_val = 0
        arg = 0
    else:
        field_val = 1 + c.rng.getrandbits(31)
        c.emu.wbytes(self + 0x5302, field_val.to_bytes(4, 'little'))
        # Arg pointer with optional data
        if c.rng.choice([True, False]):
            arg = 0
        else:
            arg = c.emu.alloc(0x100, 4)
            c.emu.wbytes(arg, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
            # Value at arg[0]: test 1, 2, and other values
            val_cases = [1, 2, 3, 0, 5]
            val = c.rng.choice(val_cases)
            c.emu.wbytes(arg, val.to_bytes(4, 'little'))
            # Value at arg[2] (offset 0x8): for val 1 or 2, return this
            if val in [1, 2]:
                result = c.rng.getrandbits(32)
                c.emu.wbytes(arg + 8, result.to_bytes(4, 'little'))
    return [self, arg]

S(0x5d4210, 'field_copy_multi', 'thiscall', None, ret=None, gen=_g5d4210)
S(0x537790, 'field_check_conditional', 'thiscall', None, ret='eax', gen=_g537790)
