"""specs_s210001.py - Sonnet-w3a: tail-jump thunks; target hooked (call count, ECX, args, order compared, random return)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def g43de70(c):
    clear_hooks(c)
    hook_rec(c, 0x45c3e0, 0, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o]

S(0x43de70, 'thunk_vt_45c3e0', 'thiscall', None, ret='eax', gen=g43de70, note='batch210001')

def g445330(c):
    clear_hooks(c)
    hook_rec(c, 0x45c3e0, 0, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o]

S(0x445330, 'thunk_vt_45c3e0', 'thiscall', None, ret='eax', gen=g445330, note='batch210001')

def g4ccee0(c):
    clear_hooks(c)
    hook_rec(c, 0x4cce40, 0, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o]

S(0x4ccee0, 'thunk_vt_4cce40', 'thiscall', None, ret='eax', gen=g4ccee0, note='batch210001')

def g519430(c):
    clear_hooks(c)
    hook_rec(c, 0x500a10, 0, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o]

S(0x519430, 'thunk_vt_500a10', 'thiscall', None, ret='eax', gen=g519430, note='batch210001')

def g4765d0(c):
    clear_hooks(c)
    hook_rec(c, 0x45c680, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o, c.rng.getrandbits(32)]

S(0x4765d0, 'thunk_pass_45c680', 'thiscall', None, ret='eax', gen=g4765d0, note='batch210001')

def g4e12e0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e11e0, 2, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x4e12e0, 'thunk_pass_4e11e0', 'thiscall', None, ret='eax', gen=g4e12e0, note='batch210001')

def g45f020(c):
    clear_hooks(c)
    hook_rec(c, 0x4db5a0, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    c.emu.w32(o + 8, rnd(c, 0x40))
    return [o, c.rng.getrandbits(32)]

S(0x45f020, 'thunk_inner_4db5a0', 'thiscall', None, ret='eax', gen=g45f020, note='batch210001')

def g45f070(c):
    clear_hooks(c)
    hook_rec(c, 0x4db860, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    c.emu.w32(o + 8, rnd(c, 0x40))
    return [o, c.rng.getrandbits(32)]

S(0x45f070, 'thunk_inner_4db860', 'thiscall', None, ret='eax', gen=g45f070, note='batch210001')

def g45fc70(c):
    clear_hooks(c)
    hook_rec(c, 0x4dca60, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    c.emu.w32(o + 8, rnd(c, 0x40))
    return [o, c.rng.getrandbits(32)]

S(0x45fc70, 'thunk_inner_4dca60', 'thiscall', None, ret='eax', gen=g45fc70, note='batch210001')

def g45fde0(c):
    clear_hooks(c)
    hook_rec(c, 0x4dd910, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    c.emu.w32(o + 8, rnd(c, 0x40))
    return [o, c.rng.getrandbits(32)]

S(0x45fde0, 'thunk_inner_4dd910', 'thiscall', None, ret='eax', gen=g45fde0, note='batch210001')

def g59cb50(c):
    clear_hooks(c)
    hook_rec(c, 0x5ae930, 2, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x59cb50, 'thunk_add_5ae930', 'thiscall', None, ret='eax', gen=g59cb50, note='batch210001')

def g504880(c):
    clear_hooks(c)
    o = obj(c, 0x80, {0x4c: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)}, nslots=0x17)
    return [o, c.rng.getrandbits(32)]

S(0x504880, 'vslot_thunk_4c', 'thiscall', None, ret='eax', gen=g504880, note='batch210001')

def g49c610(c):
    clear_hooks(c)
    o = obj(c, 0x80, {0x14: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)}, nslots=0x9)
    return [o, c.rng.getrandbits(32)]

S(0x49c610, 'vslot_thunk_14', 'thiscall', None, ret='eax', gen=g49c610, note='batch210001')

def g4d1630(c):
    clear_hooks(c)
    o = obj(c, 0x80, {0x8: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)}, nslots=0x6)
    return [o, c.rng.getrandbits(32)]

S(0x4d1630, 'vslot_thunk_8', 'thiscall', None, ret='eax', gen=g4d1630, note='batch210001')

def g4d1e30(c):
    clear_hooks(c)
    o = obj(c, 0x80, {0x3c: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)}, nslots=0x13)
    return [o, c.rng.getrandbits(32)]

S(0x4d1e30, 'vslot_thunk_3c', 'thiscall', None, ret='eax', gen=g4d1e30, note='batch210001')

def g49b330(c):
    clear_hooks(c)
    hook_rec(c, 0x49a300, 1, ret=c.rng.getrandbits(32), this=True)
    o = rnd(c, 0x80)
    pass
    return [o, c.rng.getrandbits(32)]

S(0x49b330, 'thunk_inc_49a300', 'thiscall', None, ret='eax', gen=g49b330, note='batch210001')
