"""specs_s35088.py - 0x5d8470 (thiscall, no args). Engine table block (0x100 bytes) with an embedded object at +0x1c (vtable pointer written there; slots 0x54 (1 arg, out pointer flag-recorded) and 0x74 (1 arg, returns non-zero for 0..4
calls, then 0)); engine word at +0x40 random; this: random 0xc0 bytes, [+0x30] object with slot 0x100 (1 arg), [+0x44] object with slot 0x130 (ECX plus three stack args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g5d8470(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([0, 1, 2, 3, 4])
    q = obj(c, 4, {0x54: pystub(c, 1, nullflag=(0,), this=True), 0x74: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: 1 if k < m else 0)}, nslots=0x20)
    so = sysobj(c, table_size=0x100)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0x1c, e.r32(q))
    me = rnd(c, 0xc0)
    e.w32(me + 0x30, obj(c, 0x20, {0x100: pystub(c, 1, this=True)}, nslots=0x41))
    e.w32(me + 0x44, obj(c, 0x20, {0x130: pystub(c, 3, this=True)}, nslots=0x4d))
    return [me]


S(0x5d8470, 'GUESS drain embedded queue and notify listener', 'thiscall', None, ret=None, gen=_g5d8470, note='batch35088')
