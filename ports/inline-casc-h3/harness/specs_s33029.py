"""specs_s33029.py - h3 batch 33029: field test and array compare."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g537e40(c):
    clear_hooks(c)
    # Create self with field at 0x5302
    self = c.emu.alloc(0x6000, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x6000)))
    # Field: pointer to buffer or null
    if c.rng.choice([True, False]):
        arg = 0  # Test null case
        field = 0
    else:
        arg = c.rng.randint(0, 0x100)
        field = c.emu.alloc(0x200, 4)
        c.emu.wbytes(field, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
        # Write value at [field+arg]: test both 1 and non-1 cases
        if c.rng.choice([True, False]):
            val = 1
        else:
            val = c.rng.getrandbits(32)
            if val == 1: val = 2
        c.emu.wbytes(field + arg, val.to_bytes(4, 'little'))
    c.emu.wbytes(self + 0x5302, field.to_bytes(4, 'little'))
    return [self, arg]

def _g658d00(c):
    clear_hooks(c)
    # Create self with byte at 0x3f and dword at 0x48
    self = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    # Byte: 0 or nonzero (1-255)
    if c.rng.choice([True, False]):
        b = 0
    else:
        b = c.rng.randint(1, 255)
    c.emu.wbytes(self + 0x3f, bytes([b]))
    # Dword at 0x48
    base = c.rng.getrandbits(32)
    c.emu.wbytes(self + 0x48, base.to_bytes(4, 'little'))
    return [self]

S(0x537e40, 'field_array_compare_one', 'thiscall', None, ret='al', gen=_g537e40)
S(0x658d00, 'byte_conditional_calc', 'thiscall', None, ret='eax', gen=_g658d00)
