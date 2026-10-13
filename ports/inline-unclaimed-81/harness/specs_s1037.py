"""specs_s1037.py - area 81, batch 1037: 26 list-append functions (template: head A, tail B, shared tails 0x7003bc, 0x7003c0). A and B are random:
null, or a list object whose +0x10 and +0x14 are random. Plain ret, no arguments (cdecl with none)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import obj


def _gen(A, B, tag):
    def g(c):
        rnd = c.rng
        ao = obj(c, 0x40) if rnd.random() < 0.7 else 0
        bo = obj(c, 0x40) if rnd.random() < 0.7 else 0
        c.emu.w32(A, ao)
        c.emu.w32(B, bo)
        c.emu.w32(0x7003bc, obj(c, 0x40) if rnd.random() < 0.5 else 0)
        c.emu.w32(0x7003c0, obj(c, 0x40) if rnd.random() < 0.5 else 0)
        return []
    return g

S(0x66f080, 'GUESS list append 0x66f080', 'cdecl', None, ret=None, gen=_gen(0x6e5184, 0x6e5188, '0x66f080'))
S(0x66f1c0, 'GUESS list append 0x66f1c0', 'cdecl', None, ret=None, gen=_gen(0x6e51ec, 0x6e51f0, '0x66f1c0'))
S(0x66f300, 'GUESS list append 0x66f300', 'cdecl', None, ret=None, gen=_gen(0x6e50e8, 0x6e50ec, '0x66f300'))
S(0x66f440, 'GUESS list append 0x66f440', 'cdecl', None, ret=None, gen=_gen(0x6e52f0, 0x6e52f4, '0x66f440'))
S(0x66f580, 'GUESS list append 0x66f580', 'cdecl', None, ret=None, gen=_gen(0x6e539c, 0x6e53a0, '0x66f580'))
S(0x66f6c0, 'GUESS list append 0x66f6c0', 'cdecl', None, ret=None, gen=_gen(0x6e54a4, 0x6e54a8, '0x66f6c0'))
S(0x66f800, 'GUESS list append 0x66f800', 'cdecl', None, ret=None, gen=_gen(0x6e557c, 0x6e5580, '0x66f800'))
S(0x66f940, 'GUESS list append 0x66f940', 'cdecl', None, ret=None, gen=_gen(0x6e5618, 0x6e561c, '0x66f940'))
S(0x66fa80, 'GUESS list append 0x66fa80', 'cdecl', None, ret=None, gen=_gen(0x6e5728, 0x6e572c, '0x66fa80'))
S(0x66fbc0, 'GUESS list append 0x66fbc0', 'cdecl', None, ret=None, gen=_gen(0x6e5804, 0x6e5808, '0x66fbc0'))
S(0x66fd00, 'GUESS list append 0x66fd00', 'cdecl', None, ret=None, gen=_gen(0x6e5878, 0x6e587c, '0x66fd00'))
S(0x66fe40, 'GUESS list append 0x66fe40', 'cdecl', None, ret=None, gen=_gen(0x6e59b4, 0x6e59b8, '0x66fe40'))
S(0x66ff80, 'GUESS list append 0x66ff80', 'cdecl', None, ret=None, gen=_gen(0x6e5c6c, 0x6e5c70, '0x66ff80'))
S(0x674080, 'GUESS list append 0x674080', 'cdecl', None, ret=None, gen=_gen(0x6eeb88, 0x6eeb8c, '0x674080'))
S(0x6741c0, 'GUESS list append 0x6741c0', 'cdecl', None, ret=None, gen=_gen(0x6eec68, 0x6eec6c, '0x6741c0'))
S(0x674300, 'GUESS list append 0x674300', 'cdecl', None, ret=None, gen=_gen(0x6eed48, 0x6eed4c, '0x674300'))
S(0x674440, 'GUESS list append 0x674440', 'cdecl', None, ret=None, gen=_gen(0x6eee28, 0x6eee2c, '0x674440'))
S(0x674580, 'GUESS list append 0x674580', 'cdecl', None, ret=None, gen=_gen(0x6eef08, 0x6eef0c, '0x674580'))
S(0x6746c0, 'GUESS list append 0x6746c0', 'cdecl', None, ret=None, gen=_gen(0x6ef010, 0x6ef014, '0x6746c0'))
S(0x674800, 'GUESS list append 0x674800', 'cdecl', None, ret=None, gen=_gen(0x6ef0f0, 0x6ef0f4, '0x674800'))
S(0x674940, 'GUESS list append 0x674940', 'cdecl', None, ret=None, gen=_gen(0x6ef208, 0x6ef20c, '0x674940'))
S(0x674a80, 'GUESS list append 0x674a80', 'cdecl', None, ret=None, gen=_gen(0x6ef2b0, 0x6ef2b4, '0x674a80'))
S(0x674bc0, 'GUESS list append 0x674bc0', 'cdecl', None, ret=None, gen=_gen(0x6ef39c, 0x6ef3a0, '0x674bc0'))
S(0x674d00, 'GUESS list append 0x674d00', 'cdecl', None, ret=None, gen=_gen(0x6ef47c, 0x6ef480, '0x674d00'))
S(0x674e40, 'GUESS list append 0x674e40', 'cdecl', None, ret=None, gen=_gen(0x6ef55c, 0x6ef560, '0x674e40'))
S(0x674f80, 'GUESS list append 0x674f80', 'cdecl', None, ret=None, gen=_gen(0x6ef638, 0x6ef63c, '0x674f80'))
