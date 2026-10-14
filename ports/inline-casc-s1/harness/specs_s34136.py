"""specs_s34136.py - 0x513090: unaligned count at +0xda (0..5) and children at +0xde (objects with slot 0x1e0, 1 arg, low byte random); hooked 0x513340 (ret 4; the low byte decides removal: per child random, repeated children possible); engine [0x70039c]+0x9b table with slot 0x4c (1 arg).
0x513c80: this+8 block, +0x1ed unaligned object with slots 0x14 (returns 0..9 incl. negative) and 0x4; hooked 0x43ec00 (6 args) returning an id; table slot 0x60 returns an object (flags +0x40 random) or 0, slot 0x4c returns a value; 0x44b8b0 recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _tbl(c, slots):
    t = obj(c, 0x20, slots, nslots=0x64 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, t)
    c.emu.w32(0x70039c, so)


def _g513090(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 4, 5])
    kids = [obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))}, nslots=0x1e4 // 4) for _ in range(n)]
    hook_rec(c, 0x513340, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))
    _tbl(c, {0x4c: pystub(c, 1, this=True)})
    me = rnd(c, 0x120)
    c.emu.wbytes(me + 0xda, n.to_bytes(4, 'little') + b''.join(k.to_bytes(4, 'little') for k in kids))
    return [me]


def _g513c80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43ec00, 6, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x44b8b0, 1, this=True)
    ob = rnd(c, 0x50)
    e.w32(ob + 0x40, r.getrandbits(32))
    o = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 6, 7, 8, 0xffffffff, 0x80000000])), 0x4: pystub(c, 1, this=True)}, nslots=0x18 // 4)
    _tbl(c, {0x60: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, ob, ob])), 0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    me = rnd(c, 0x200)
    e.w32(me + 8, rnd(c, 0x50))
    e.wbytes(me + 0x1ed, o.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x513090, 'GUESS prune and pick from a child list', 'thiscall', None, ret=None, gen=_g513090, note='batch34136')
S(0x513c80, 'GUESS create an object and announce it', 'thiscall', None, ret='eax', gen=_g513c80, note='batch34136')
