"""specs_s35153.py - 0x43fba0 (thiscall(a, b, c, d, e) ret 0x14, ret='eax'). Engine table (0x70039c +0x9b): slot 0x10 (0 args, al true in half, garbage upper bytes when false), slot 0x158 (1 arg; returns a pointer to a random dword), and [+8] = sub object with slot 0x1c (3 args; returns a record with a random dword at +0x54, null in 1/4).
this: slot 0x294 (4 args, returns a random dword) and slot 0x28c (3 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g43fba0(c):
    clear_hooks(c)
    r = c.rng
    ok = r.random() < 0.5
    okv = (r.getrandbits(32) | 1) if ok else (r.getrandbits(24) << 8)
    rec = 0 if r.random() < 0.25 else rnd(c, 0x60)
    sub = obj(c, 0x20, {0x1c: pystub(c, 3, this=True, ret=rec)}, nslots=0x10)
    pd = rnd(c, 0x10)
    so = sysobj(c, table_slots={0x10: pystub(c, 0, this=True, ret=okv), 0x158: pystub(c, 1, this=True, ret=pd)}, table_size=0x170)
    tab = c.emu.r32(so + 0x9b)
    c.emu.w32(tab + 8, sub)
    me = obj(c, 0x20, {0x294: pystub(c, 4, this=True, ret=r.getrandbits(32)), 0x28c: pystub(c, 3, this=True)}, nslots=0xa5)
    return [me] + [r.getrandbits(32) for _ in range(5)]


S(0x43fba0, 'GUESS dispatch by engine mode through table or sub-table', 'thiscall', None, ret='eax', gen=_g43fba0, note='batch35153')
