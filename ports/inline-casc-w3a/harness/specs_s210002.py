"""specs_s210002.py - Sonnet-w3a: small member-call chains; callees hooked (ECX, args, order, EDX for the fastcall one compared)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _edx(emu, k): emu.calllog.append(('edx', emu.reg('edx')))


def g42acb5(c):
    clear_hooks(c); return [_r(c), _r(c), _r(c), _r(c), _r(c)]


def g560360(c):
    clear_hooks(c); return [_r(c)]


def g575220(c):
    clear_hooks(c)
    hook_rec(c, 0x573db0, 0, ret=_r(c), this=True); hook_rec(c, 0x575230, 0, ret=_r(c), this=True)
    return [rnd(c, 0x80)]


def g573db0(c):
    clear_hooks(c)
    o = rnd(c, 0x200)
    hook_rec(c, 0x5626c0, 0, ret=_r(c), this=True)
    hook_rec(c, 0x573dd0, 0, ret=_r(c), this=True, side=lambda emu, k: emu.calllog.append(('b', emu.rbytes(o + 0x1f0, 1))))
    return [o]


def g511ab0(c):
    clear_hooks(c)
    hook_rec(c, 0x4690b0, 0, ret=_r(c), this=True)
    return [rnd(c, 0x100)]


def g562260(c):
    clear_hooks(c)
    hook_rec(c, 0x563da0, 0, ret=_r(c), this=True)
    return [obj(c, 0x80, {0xf0: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x40)]


def g5a5c80(c):
    clear_hooks(c)
    o = rnd(c, 0x640); m = rnd(c, 0x40); c.emu.w32(o + 0x62c, m)
    hook_rec(c, 0x5ef040, 1, ret=_r(c), this=True)
    return [o, _r(c), _r(c), _r(c)]


def g5a5c60(c):
    clear_hooks(c)
    o = rnd(c, 0x640)
    m = obj(c, 0x40, {8: pystub(c, 0, ret=_r(c), this=True)}, nslots=8)
    c.emu.w32(o + 0x62c, m)
    hook_rec(c, 0x5ef050, 1, ret=_r(c), this=True)
    return [o]


def g601d60(c):
    clear_hooks(c)
    hook_rec(c, 0x603dd0, 0, ret=_r(c), this=True, side=_edx)
    return [_r(c), _r(c)]


def g44edd0(c):
    clear_hooks(c)
    hook_rec(c, 0x43f900, 1, ret=_r(c), this=True); hook_rec(c, 0x4e1b30, 0, ret=_r(c), this=True)
    return [rnd(c, 0x80), rnd(c, 0x80)]


def g5b22e0(c):
    clear_hooks(c)
    hook_rec(c, 0x445800, 1, ret=_r(c), this=True); hook_rec(c, 0x4e1b30, 0, ret=_r(c), this=True)
    return [rnd(c, 0x80), rnd(c, 0x80)]


def g52aae0(c):
    clear_hooks(c)
    hook_rec(c, 0x45d380, 2, ret=_r(c), this=True)
    return [rnd(c, 0x80), _r(c), _r(c)]


def g5ebd80(c):
    o = rnd(c, 0x80)
    a = c.emu.r32(o + 0x36) if c.rng.random() < 0.5 else _r(c)
    return [o, a]


def g44a1f0(c):
    clear_hooks(c)
    hook_rec(c, 0x4690b0, 0, ret=_r(c))
    return []


S(0x42acb5, 'const_6ff950', 'cdecl', None, ret='eax', gen=g42acb5, note='batch210002')
S(0x560360, 'return_false', 'stdcall', None, ret='al', gen=g560360, note='batch210002')
S(0x575220, 'chain_573db0_575230', 'thiscall', None, ret='eax', gen=g575220, note='batch210002')
S(0x573db0, 'chain_5626c0_flag_573dd0', 'thiscall', None, ret='eax', gen=g573db0, note='batch210002')
S(0x511ab0, 'two_member_resets', 'thiscall', None, ret='eax', gen=g511ab0, note='batch210002')
S(0x562260, 'vslot_f0_then_563da0', 'thiscall', None, ret='eax', gen=g562260, note='batch210002')
S(0x5a5c80, 'forward_third_arg_to_member', 'thiscall', None, ret='eax', gen=g5a5c80, note='batch210002')
S(0x5a5c60, 'set_member_1_then_slot8', 'thiscall', None, ret='eax', gen=g5a5c60, note='batch210002')
S(0x601d60, 'fastcall_forward', 'stdcall', None, ret='eax', gen=g601d60, note='batch210002')
S(0x44edd0, 'two_member_calls_a', 'thiscall', None, ret='eax', gen=g44edd0, note='batch210002')
S(0x5b22e0, 'two_member_calls_b', 'thiscall', None, ret='eax', gen=g5b22e0, note='batch210002')
S(0x52aae0, 'call_45d380_return_0', 'thiscall', None, ret='eax', gen=g52aae0, note='batch210002')
S(0x5ebd80, 'set_dword_36_if_changed', 'thiscall', None, ret='eax', gen=g5ebd80, note='batch210002')
S(0x44a1f0, 'thunk_to_noop_4690b0', 'cdecl', None, ret='eax', gen=g44a1f0, note='batch210002')
