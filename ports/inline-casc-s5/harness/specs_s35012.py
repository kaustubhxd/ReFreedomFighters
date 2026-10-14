"""specs_s35012.py - 0x420810. Session object (0x2700 random bytes, vtable slots 0x1d0 / 0x20 / 0x4c (1 arg each) and 0x3c (0 args) recorded); unaligned [+0x9b] (null in 1/4) is an object with slot 0x128,
unaligned [+0x223d] an object with slot 0x10; globals 0x7003a4 / 0x7003a8 null in 1/3 each, otherwise objects with slot 0x10; the logger at 0x700390 (slot 0x20 -> object with slot 0x2c, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g420810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x2700, {0x1d0: pystub(c, 1, this=True), 0x3c: pystub(c, 0, this=True), 0x20: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True)}, nslots=0x1d4 // 4 + 1)
    o1 = 0 if r.random() < 0.25 else obj(c, 0x10, {0x128: pystub(c, 0, this=True)}, nslots=0x4c)
    e.wbytes(me + 0x9b, o1.to_bytes(4, 'little'))
    o2 = obj(c, 0x10, {0x10: pystub(c, 0, this=True)}, nslots=8)
    e.wbytes(me + 0x223d, o2.to_bytes(4, 'little'))
    for g in (0x7003a4, 0x7003a8):
        e.w32(g, 0 if r.random() < 1 / 3 else obj(c, 0x10, {0x10: pystub(c, 0, this=True)}, nslots=8))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [me]


S(0x420810, 'GUESS shut down session objects', 'thiscall', None, ret=None, gen=_g420810, note='batch35012')
