"""specs_s224.py - small leaves, slice 0/1 (batch224). Pure memory: no stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x600)]


def _obj_idx(c):
    return [_rnd(c, 0x600), c.rng.randrange(0, 0x40)]


def _obj_ab(c):
    return [_rnd(c, 0x600), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _obj_p(c):
    return [_rnd(c, 0x600), _rnd(c, 12)]


S(0x468200, 'getDword1d2 (GUESS)', 'thiscall', None, ret='eax', gen=_obj, note='batch224; dword at +0x1d2')
S(0x52a1c0, 'setConstFloats (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch224; three constant floats')
S(0x483b40, 'getIndexed (GUESS)', 'thiscall', None, ret='eax', gen=_obj_idx, note='batch224; dword at +idx*4+0x45d')
S(0x469100, 'maskOr (GUESS)', 'thiscall', None, ret='eax', gen=_obj_ab, note='batch224; [+4] = (b & [+4]) | a')
S(0x485080, 'copy3 (GUESS)', 'thiscall', None, ret=None, gen=_obj_p, note='batch224; copies three dwords from arg')
