"""specs_s33019.py - h3 batch 33019: field readers and tail-jumps."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _me(c, n=0x80):
    return rnd(c, n)

def _g58eb40(c):
    clear_hooks(c)
    hook_rec(c, 0x5cdb70, 0, this=True)
    # Create object with pointer at offset 0x85a
    o = _me(c, 0x100)
    target = c.emu.alloc(0x40, 4)
    c.emu.wbytes(target, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 0x85a, target)
    return [o]

def _g5f18d0(c):
    clear_hooks(c)
    hook_rec(c, 0x5fb920, 0, this=True)
    # Create chain: o[0xc] -> intermediate, intermediate[4] -> final
    o = _me(c, 0x100)
    intermediate = c.emu.alloc(0x40, 4)
    final = c.emu.alloc(0x40, 4)
    c.emu.wbytes(intermediate, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.wbytes(final, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 0xc, intermediate)
    c.emu.w32(intermediate + 4, final)
    return [o]

def _g410100(c):
    clear_hooks(c)
    # Create an object to dereference, with byte at +4
    target = c.emu.alloc(0x40, 4)
    c.emu.wbytes(target, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.wbytes(target + 4, bytes([c.rng.getrandbits(8)]))
    return [target]

def _g446d70(c):
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    return [_me(c), val]

S(0x58eb40, 'read_offset_85a_jump', 'thiscall', None, ret=None, gen=_g58eb40)
S(0x5f18d0, 'double_deref_jump', 'thiscall', None, ret=None, gen=_g5f18d0)
S(0x410100, 'deref_arg_read_byte_4', 'cdecl', None, ret='al', gen=_g410100)
S(0x446d70, 'set_field_192', 'stdcall', None, ret=None, gen=_g446d70)
