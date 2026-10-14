"""specs_s34022.py - cascade tier E, batch 34022.
0x4c8760: engine +0x190f (unaligned) list object, slot 0xb4(i) returns ids while i < n (n 0..4); engine table slot 0x58 returns random objects (the first never null,
later ones null in a quarter of the cases); flag word at +0x48 random.
0x4d2120: hooked 0x4d1cf0 returns an entry or 0 (logger path through the object at 0x700390), 0x41e290 returns a fresh buffer, 0x634d22 / 0x634273 cdecl recorders.
0x4db930: [this+0x54] is null in a fifth; the record at [s+0xc] has the dword at +0x23 with bit 0x100000 set in half the cases; slot 0x50 of s writes the next node
(random, 0 after at most three nodes); 0x4db860 is a thiscall recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4c8760(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 1, 2, 3, 4])
    objs = [rnd(c, 0x60)] + [0 if r.random() < 0.25 else rnd(c, 0x60) for _ in range(5)]
    lst = obj(c, 0x20, {0xb4: pystub(c, 1, ret=lambda em, k: (k + 1) * 0x11 if k < n else 0, this=True)}, nslots=0x40)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 5)], this=True)})
    c.emu.wbytes(so + 0x190f, lst.to_bytes(4, 'little'))
    return []


def _g4d2120(c):
    clear_hooks(c)
    r = c.rng
    e = 0 if r.random() < 0.25 else rnd(c, 0x20)
    hook_rec(c, 0x4d1cf0, 1, ret=e, this=True)
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x40), pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    return [rnd(c, 0x20), r.getrandbits(32), rnd(c, 0x40), r.choice([0, 1, 8, 0x20, r.randint(0, 0x30)])]


def _g4db930(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4db860, 1, this=True)

    def nxt(em, k):
        em.w32(em.arg32(0), 0 if k >= 3 or r.random() < 0.25 else (r.getrandbits(32) | 0x10000000))
    if r.random() < 0.2:
        s = 0
    else:
        rec = rnd(c, 0x40)
        w = r.getrandbits(32)
        w = (w | 0x100000) if r.random() < 0.5 else (w & ~0x100000)
        c.emu.wbytes(rec + 0x23, w.to_bytes(4, 'little'))
        s = obj(c, 0x40, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x20)
        c.emu.w32(s + 0xc, rec)
        c.emu.w32(s + 8, 0 if r.random() < 0.2 else (r.getrandbits(32) | 0x10000000))
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x54, s)
    return [me, r.getrandbits(32)]


S(0x4c8760, 'GUESS set/clear flag 0x10 on listed objects', 'cdecl', None, ret=None, gen=_g4c8760, note='batch34022')
S(0x4d2120, 'GUESS replace entry buffer', 'thiscall', None, ret=None, gen=_g4d2120, note='batch34022')
S(0x4db930, 'GUESS visit node list', 'thiscall', None, ret=None, gen=_g4db930, note='batch34022')
