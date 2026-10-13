"""specs_u18_02.py - area 18, group 2 (unclaimed-18 thread)."""
from pilot import S
from ckit import rnd


def _o(c, size=0x200):
    return [rnd(c, size)]


S(0x428fd0, 'unnamed getter +0x78 (GUESS)', 'thiscall', None, ret='al', gen=lambda c: _o(c), note='u18')
S(0x638cd0, 'unnamed getter +0x32 (GUESS)', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x5c39d0, 'unnamed empty method (GUESS)', 'thiscall', None, ret='eax', gen=lambda c: [rnd(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32)], note='u18')
S(0x604390, 'unnamed getter +0x24 (GUESS)', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x443010, 'unnamed constant 4', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x4c6190, 'unnamed global 0x6e73b8', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x64b150, 'unnamed constant 0x24', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
