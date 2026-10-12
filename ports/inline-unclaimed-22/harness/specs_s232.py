"""specs_s232.py - unclaimed area 22, batch232 (src/batch232.cpp): eight leaves. No stubs except the vtable callee of
0x5139d0 (a logged sparse slot with no arguments). 0x5abcd0 is checked on al only (ret 'al'), since the original leaves
the upper bits of eax alone."""
from pilot import S
from helpers22 import _rnd, _multi_vt


def _g_self(c):
    return [_rnd(c, 0x900)]


def _g_5ab050(c):
    self_ = _rnd(c, 0x900)
    if c.rng.random() < 0.4:
        c.emu.w32(self_ + 0x300, 0x10000000)
    return [self_]


def _g_vt10(c):
    self_ = _rnd(c, 0x80)
    obj = _rnd(c, 0x40)
    v = c.rng.getrandbits(32)
    c.emu.w32(obj, _multi_vt(c, {0x10: (lambda em, args, v=v: (v, None), 0)}))
    c.emu.w32(self_ + 0x5c, obj)
    return [self_]


S(0x46eed0, 'getField5c (GUESS)', 'thiscall', None, ret='eax', gen=_g_self, note='batch232; [this+0x5c]')
S(0x5a8350, 'getField300 (GUESS)', 'thiscall', None, ret='eax', gen=_g_self, note='batch232; [this+0x300]')
S(0x483f10, 'getBit417 (GUESS)', 'thiscall', None, ret='eax', gen=_g_self, note='batch232; [this+0x417] & 1')
S(0x5139d0, 'vtTail10 (GUESS)', 'thiscall', None, ret='eax', gen=_g_vt10, note='batch232; tail jump to vtable 0x10 on [this+0x5c]')
S(0x5ab050, 'bumpIfNot (GUESS)', 'thiscall', None, ret=None, gen=_g_5ab050, note='batch232; increment [this+0x8b3] unless [this+0x300] is 0x10000000')
S(0x5abcd0, 'byte8 (GUESS)', 'thiscall', None, ret='al', gen=_g_self, note='batch232; mov al, [this+8]')
S(0x468210, 'floatAt1da (GUESS)', 'thiscall', None, ret='st0', gen=_g_self, note='batch232; fld [this+0x1da]')
S(0x483a10, 'floatAt451 (GUESS)', 'thiscall', None, ret='st0', gen=_g_self, note='batch232; fld [this+0x451]')
