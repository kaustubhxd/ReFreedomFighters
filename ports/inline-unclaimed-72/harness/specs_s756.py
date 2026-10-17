"""specs_s756.py - area 72 gap rows, batch 756: pure stores. The argument objects are random blocks; the store targets are
checked through the heap compare. 0x4d4940's first argument is 0x10 in about a third of the cases."""
from pilot import S
from specs_s701 import _rnd


def _g_1(c):
    return [_rnd(c, 0x300), c.rng.getrandbits(32)]


def _g_0(c):
    return [_rnd(c, 0x4200)]


def _g_2(c):
    return [_rnd(c, 0x300), _rnd(c, 0x40), _rnd(c, 0x40)]


def _g_2c(c):
    return [_rnd(c, 0x300), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g_4d4940(c):
    a = 0x10 if c.rng.random() < 0.33 else c.rng.getrandbits(32)
    return [_rnd(c, 0x300), a, c.rng.getrandbits(32)]


S(0x54ba20, 'f_54ba20', 'thiscall', None, ret=None, gen=_g_1, note='b756 area 72 gap row')
S(0x549350, 'f_549350', 'thiscall', None, ret=None, gen=_g_0, note='b756 area 72 gap row')
S(0x4cfd90, 'f_4cfd90', 'thiscall', None, ret=None, gen=_g_2, note='b756 area 72 gap row')
S(0x4c3280, 'f_4c3280', 'thiscall', None, ret=None, gen=_g_2c, note='b756 area 72 gap row')
S(0x4d4940, 'f_4d4940', 'thiscall', None, ret=None, gen=_g_4d4940, note='b756 area 72 gap row')
