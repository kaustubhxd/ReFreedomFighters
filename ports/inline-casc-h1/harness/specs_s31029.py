"""specs_s31029.py - batch 31029: null checks, multi-dword copy, and comparison (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g533bc0(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    param = c.rng.choice([0, obj(c, 0x100, {0x10: c.rng.getrandbits(32)})])
    return [o, param]

def _g5b04a0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {8: c.rng.getrandbits(32), 0x10: c.rng.getrandbits(32)})
    ptr1 = obj(c, 0x100, {})
    ptr2 = obj(c, 0x100, {})
    return [o, ptr1, ptr2]

def _g516230(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0: c.rng.getrandbits(32), 0x41: c.rng.getrandbits(32), 8: c.rng.getrandbits(32)})
    param = obj(c, 0x100, {})
    return [o, param]

def _g4dc600(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x3c: 0})
    param = obj(c, 0x100, {0: c.rng.getrandbits(32), 4: c.rng.getrandbits(32), 8: c.rng.getrandbits(32)})
    return [o, param]

def _g471a10(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    if c.rng.random() < 0.5:
        param = 0
    else:
        inner = obj(c, 0x100, {0x23: c.rng.choice([0x1007d3, 0x1007d4, c.rng.getrandbits(32)])})
        param = obj(c, 0x100, {0xc: inner})
    return [o, param]

S(0x533bc0, 'null_check_deref', 'thiscall', None, ret='eax', gen=_g533bc0)
S(0x5b04a0, 'copy_2dwords_out', 'thiscall', None, ret=None, gen=_g5b04a0)
S(0x516230, 'copy_3dwords_out', 'thiscall', None, ret=None, gen=_g516230)
S(0x4dc600, 'copy_3dwords_in_flag', 'thiscall', None, ret=None, gen=_g4dc600)
S(0x471a10, 'null_check_cmp', 'thiscall', None, ret='al', gen=_g471a10)
