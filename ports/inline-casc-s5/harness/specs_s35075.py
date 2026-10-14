"""specs_s35075.py - 0x4a8020 (thiscall(s) ret 4, ret='al'). this = random 0x90 bytes; s: object with slots 0x54 and 0x60 (1 arg each, recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4a8020(c):
    clear_hooks(c)
    s = obj(c, 0x20, {0x54: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True)}, nslots=0x19)
    return [rnd(c, 0x90), s]


S(0x4a8020, 'GUESS write record fields to stream', 'thiscall', None, ret='al', gen=_g4a8020, note='batch35075')
