"""specs_s31013.py - batch 31013: thiscall setters and indirect jump."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj, sysobj

def _g471670(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g478620(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xff, c.rng.randint(0, 255)])
    return [o, val]

def _g4b00d0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g4d49b0(c):
    clear_hooks(c)
    o = obj(c, 0x100, {0x10db: 0x400})
    return [o]

S(0x471670, 'set_dword_d5', 'thiscall', None, ret=None, gen=_g471670)
S(0x478620, 'set_byte_690', 'thiscall', None, ret=None, gen=_g478620)
S(0x4b00d0, 'set_dword_48', 'thiscall', None, ret=None, gen=_g4b00d0)
S(0x4d49b0, 'load_add_offset_jmp_4', 'thiscall', None, ret=None, gen=_g4d49b0)
