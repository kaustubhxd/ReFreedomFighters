"""specs_s35123.py - 0x5f25d0 (stdcall(s) ret 4). s: random 0x30 bytes with [+0x20] zero in 3/4; the exe byte 0x7143ac zero in 3/4 (set to a random non-zero byte otherwise); engine table slot 0x58 (1 arg recorded) returns e (null in 1/4); [e+0x10] = c (null in a quarter) whose dword
+0x1c is zero in a third, with vtable slot 0 (0 args); logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g5f25d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.wbytes(0x7143ac, bytes([0 if r.random() < 0.75 else r.randint(1, 255)]))
    if r.random() < 0.25:
        cc = 0
    else:
        cc = obj(c, 0x40, {0: pystub(c, 0, this=True)}, nslots=2)
        e.w32(cc + 0x1c, 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1)
    ent = 0 if r.random() < 0.25 else rnd(c, 0x20)
    if ent:
        e.w32(ent + 0x10, cc)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent)})
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    s = rnd(c, 0x30)
    if r.random() < 0.75:
        e.w32(s + 0x20, 0)
    return [s]


S(0x5f25d0, 'GUESS start named resource with error logs', 'stdcall', None, ret=None, gen=_g5f25d0, note='batch35123')
