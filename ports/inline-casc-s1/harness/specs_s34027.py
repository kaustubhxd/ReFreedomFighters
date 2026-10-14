"""specs_s34027.py - cascade tier E, batch 34027.
0x5f1610: hooked 0x5fb530 (thiscall ret 0x10, returns an entry or 0) and 0x5f2b90; c is zero in a third; the logger object at 0x700390 is set.
0x458300: s slot 0x1e0 returns 0/1 (random high bytes); both blocks are random so every copied field (and the untouched ones) is visible.
0x45dcd0: this slots 0x20 (0 in a fifth) and 0x1b4 (0/1); a slot 0x294 returns a value; c and d are zero in a third each; e is unused (random)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5f1610(c):
    clear_hooks(c)
    r = c.rng
    e = 0 if r.random() < 0.25 else rnd(c, 0x40)
    hook_rec(c, 0x5fb530, 4, ret=e, this=True)
    hook_rec(c, 0x5f2b90, 0, this=True, pop=0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = rnd(c, 0x20)
    mid = rnd(c, 0x20)
    c.emu.w32(mid + 4, rnd(c, 0x20))
    c.emu.w32(me + 0xc, mid)
    return [me, r.getrandbits(32), r.getrandbits(32), 0 if r.random() < 0.33 else (r.getrandbits(32) | 1)]


def _g458300(c):
    clear_hooks(c)
    r = c.rng
    s = obj(c, 0xe0, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x1f0 // 4)
    for off in range(0x78, 0xc4, 4):
        c.emu.w32(s + off, r.getrandbits(32))
    return [rnd(c, 0xe0), s]


def _g45dcd0(c):
    clear_hooks(c)
    r = c.rng
    a = obj(c, 0x20, {0x294: pystub(c, 4, ret=r.getrandbits(32) | 1, this=True)}, nslots=0x2a0 // 4)
    me = obj(c, 0x40, {0x20: pystub(c, 0, ret=(0 if r.random() < 0.2 else r.getrandbits(32) | 1), this=True),
                       0x1b4: pystub(c, 2, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x1c0 // 4)
    c.emu.w32(me + 4, r.getrandbits(32))
    mid = rnd(c, 0x10)
    c.emu.w32(me + 0xc, mid)
    z = lambda: 0 if r.random() < 0.33 else r.getrandbits(32) | 1
    return [me, a, r.getrandbits(32), z(), z(), r.getrandbits(32)]


S(0x5f1610, 'GUESS create entry and tag it', 'thiscall', None, ret='eax', gen=_g5f1610, note='batch34027')
S(0x458300, 'GUESS copy settings block from matching object', 'thiscall', None, ret=None, gen=_g458300, note='batch34027')
S(0x45dcd0, 'GUESS create child with defaults and attach', 'thiscall', None, ret='eax', gen=_g45dcd0, note='batch34027')
