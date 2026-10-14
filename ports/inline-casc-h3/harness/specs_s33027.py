"""specs_s33027.py - h3 batch 33027: comparison and field checks."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g471aa0(c):
    clear_hooks(c)
    # arg is a pointer to object, or null
    if c.rng.choice([True, False, False]):  # 2/3 probability: valid pointer, 1/3 null
        arg = 0
    else:
        arg = c.emu.alloc(0x100, 4)
        c.emu.wbytes(arg, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
        # [arg+0xc] points to another valid object
        obj = c.emu.alloc(0x100, 4)
        c.emu.wbytes(arg + 0xc, obj.to_bytes(4, 'little'))
        c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
        # Field at obj+0x23: test both matching and non-matching cases
        if c.rng.choice([True, True, False]):  # 2/3 matching, 1/3 not
            val = 0x1007d4
        else:
            val = 0x1007d5
        c.emu.wbytes(obj + 0x23, val.to_bytes(4, 'little'))
    return [arg]

def _g5889c0(c):
    clear_hooks(c)
    # Create self with random data
    self = c.emu.alloc(0x200, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    # Argument
    arg = c.rng.getrandbits(32)
    return [self, arg]

def _g640c90(c):
    clear_hooks(c)
    # Create arg pointer with data
    arg = c.emu.alloc(0x100, 4)
    c.emu.wbytes(arg, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    # Word at arg+0x5a: test zero and nonzero cases
    if c.rng.choice([True, False]):
        w = 0  # 50% zero
    else:
        w = 1 + c.rng.getrandbits(15)  # 50% nonzero
    c.emu.wbytes(arg + 0x5a, w.to_bytes(2, 'little'))
    # Dword at arg+0x3c: test with and without 0x2000 bit
    if c.rng.choice([True, False]):
        d = c.rng.getrandbits(32) & ~0x2000  # 50% no 0x2000 bit
    else:
        d = c.rng.getrandbits(32) | 0x2000   # 50% with 0x2000 bit
    c.emu.wbytes(arg + 0x3c, d.to_bytes(4, 'little'))
    return [arg]

S(0x471aa0, 'deref_compare_const', 'stdcall', None, ret='al', gen=_g471aa0)
S(0x5889c0, 'field_init_return_self', 'thiscall', None, ret='eax', gen=_g5889c0)
S(0x640c90, 'field_check_nonzero_no_bit', 'stdcall', None, ret='al', gen=_g640c90)
