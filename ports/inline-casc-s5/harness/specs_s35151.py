"""specs_s35151.py - 0x478b70 (thiscall(o, unused) ret 8, ret='eax'). this: 0x780 random bytes with bytes +0x726, +0x753, +0x26a and dword +0x64c steered (0x726 set in 3/4, 0x64c = 10 in 1/4, 0x753 set in 1/8, 0x26a set in 1/6). o: null in 1/8, else an object with slot 0x1e0 (1 arg, al true in 3/4,
upper bytes garbage when false) and slot 0x350 (returns p, whose slot 0x330 returns k from 0..9 incl. the boundaries 1, 2, 3, 4, 6, 7, and garbage)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g478b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x780)
    e.w8(me + 0x726, r.getrandbits(8) | 1 if r.random() < 0.75 else 0)
    e.w32(me + 0x64c, 10 if r.random() < 0.25 else r.choice([0, 9, 11, r.getrandbits(32)]))
    e.w8(me + 0x753, r.getrandbits(8) | 1 if r.random() < 1 / 8 else 0)
    e.w8(me + 0x26a, r.getrandbits(8) | 1 if r.random() < 1 / 6 else 0)
    k = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xffffffff, 0x100000004, r.getrandbits(32)]) & 0xffffffff
    p = obj(c, 0x20, {0x330: pystub(c, 0, this=True, ret=k)}, nslots=0xd0)
    ok = r.random() < 0.75
    o = 0 if r.random() < 1 / 8 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=(r.getrandbits(32) | 1) if ok else (r.getrandbits(24) << 8)), 0x350: pystub(c, 0, this=True, ret=p)}, nslots=0xe0)
    return [me, o, r.getrandbits(32)]


S(0x478b70, 'GUESS cached value when target in allowed state', 'thiscall', None, ret='eax', gen=_g478b70, note='batch35151')
