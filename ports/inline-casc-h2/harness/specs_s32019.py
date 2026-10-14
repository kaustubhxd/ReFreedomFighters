from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_5331c0(c):
    # thiscall, adds offset 0x8b to ecx and calls ext_534090
    hook_rec(c, 0x534090, 1, ret=c.rng.getrandbits(32), this=True)
    o = obj(c, 0x200, {})  # Large object to account for 0x8b offset
    return [o]

def gen_63fc10(c):
    # thiscall, adds offset 0x8270 to ecx and calls ext_65f200
    hook_rec(c, 0x65f200, 1, ret=c.rng.getrandbits(32), this=True)
    o = obj(c, 0x8300, {})  # Large object to account for 0x8270 offset
    return [o]

S(0x5331c0, 'sub_5331c0', 'thiscall', None, ret='eax', gen=gen_5331c0)
S(0x63fc10, 'sub_63fc10', 'thiscall', None, ret='eax', gen=gen_63fc10)
