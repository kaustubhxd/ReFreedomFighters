"""specs_s31000.py - batch 31000: four simple functions, mostly thiscall."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g420060(c):
    # stdcall, takes 1 u32 arg, returns nothing
    return [c.rng.getrandbits(32)]

def _g44ca70(c):
    # thiscall, writes to [this] and tail-jumps to 0x43de70
    clear_hooks(c)
    hook_rec(c, 0x43de70, 0, this=True)  # Hook the tail-jump target
    return [obj(c, 0x80, {})]

def _g466470(c):
    # thiscall, clears bit 0x200000 at [this+0x136]
    clear_hooks(c)
    o = obj(c, 0x140, {0x136: 0xffffffff})
    return [o]

def _g46eaa0(c):
    # thiscall, returns [this+0x78]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x80, {0x78: val})
    return [o]

S(0x420060, 'return_zero', 'stdcall', None, ret=None, gen=_g420060)
S(0x44ca70, 'store_and_tail_jump', 'thiscall', None, ret=None, gen=_g44ca70)
S(0x466470, 'clear_flag', 'thiscall', None, ret=None, gen=_g466470)
S(0x46eaa0, 'read_field', 'thiscall', None, ret='eax', gen=_g46eaa0)
