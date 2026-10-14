"""specs_u69_23.py - area 69, group 23 (slice 8): dword getters."""
from pilot import S
from ckit import rnd


def _obj(n):
    return lambda c: [rnd(c, n)]


S(0x420e80, 'dwordAt420e80 (thiscall, no args)', 'thiscall', None, ret='eax', gen=_obj(0x1b60), note='u69 group 23; no callees')
S(0x5ed9c0, 'dwordAt5ed9c0 (thiscall, no args)', 'thiscall', None, ret='eax', gen=_obj(0x100), note='u69 group 23; no callees')
S(0x5f3140, 'remaining5f3140 (SerialInfo_t::remaining, thiscall)', 'thiscall', None, ret='eax', gen=_obj(0x20), note='u69 group 23; no callees')
