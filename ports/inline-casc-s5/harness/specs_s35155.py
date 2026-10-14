"""specs_s35155.py - 0x5c8f10 (thiscall, no args, ret=None). Engine table (+0x9b): +0xadc = manager m with slot 0x25c (2 args; returns an object x or 0 in half) and slot 0x294 (4 args; returns an object y); table slots 0x138 (0 args; returns o, whose slot 0x60 takes 2 args) and 0x4c (2 args; returns a random dword);
x and y have slot 0x218 (1 arg). [0x7003b8] = a block of 0x2d00 bytes. this: 0x80 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g5c8f10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    x = 0 if r.random() < 0.5 else obj(c, 0x20, {0x218: pystub(c, 1, this=True)}, nslots=0x90)
    y = obj(c, 0x20, {0x218: pystub(c, 1, this=True)}, nslots=0x90)
    m = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=x), 0x294: pystub(c, 4, this=True, ret=y)}, nslots=0xa8)
    o = obj(c, 0x20, {0x60: pystub(c, 2, this=True)}, nslots=0x20)
    so = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x4c: pystub(c, 2, this=True, ret=r.getrandbits(32))}, table_size=0xae0)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, m)
    e.w32(0x7003b8, rnd(c, 0x2d00))
    return [rnd(c, 0x80)]


S(0x5c8f10, 'GUESS look up or create named resource and register it', 'thiscall', None, ret=None, gen=_g5c8f10, note='batch35155')
