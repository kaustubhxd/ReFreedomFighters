"""specs_u69_01.py - area 69, group 1 (unclaimed-69 thread)."""
from pilot import S
from ckit import rnd


def _o(c, size=0xc00):
    return [rnd(c, size)]


S(0x4d0690, 'unnamed address of +0x217 (GUESS)', 'thiscall', None, ret='eax', gen=lambda c: _o(c, 0x400), note='u69')
S(0x492b10, 'unnamed setter +0xbc3 := 1 (GUESS)', 'thiscall', None, ret=None, gen=lambda c: _o(c), note='u69')
S(0x4951d0, 'unnamed setter +0xbc3 := 0 (GUESS)', 'thiscall', None, ret=None, gen=lambda c: _o(c), note='u69')
S(0x48f7d0, 'unnamed getter +0xbc3 (GUESS)', 'thiscall', None, ret='al', gen=lambda c: _o(c), note='u69')
