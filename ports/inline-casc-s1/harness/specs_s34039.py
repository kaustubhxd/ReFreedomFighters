"""specs_s34039.py - cascade tier E, batch 34039.
0x4f8d80: this slot 0x294 (four stack args) returns an object o with slots 0x154, 0x158, 0xbc and 0x23c recorders and a +8 member; hooked 0x4dc630 (thiscall, two args); the logger object at 0x700390 (slot 0x20
returns an object whose slot 0x30 is a caller-popped recorder); the returned value is o.
0x507240: hooked 0x5003d0 returns an entry whose first dword is an id; engine table slot 0x58 returns an object (null in a quarter) whose slot 0x1e0 returns 0/1; [[this+0x18]+8] is a node whose flag
dword +0x3c has bit 0x40000000 in half the cases; hooked 0x4dafb0 / 0x4dc9c0; the sink object at the unaligned engine table +0x5d31 has slot 0 as a recorder.
0x509aa0: [[this+0xc]+0x18] null in a seventh, otherwise an iterator list object (slots 0x4c, 0x5c with a stack iterator, 0..3 ids); engine table slot 0x58 returns an object (null in a quarter) with slot 0xbc."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4f8d80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc630, 2, this=True)
    o = obj(c, 0x20, {0x154: pystub(c, 0, this=True), 0x158: pystub(c, 0, this=True), 0xbc: pystub(c, 1, this=True),
                      0x23c: pystub(c, 2, this=True)}, nslots=0x240 // 4)
    c.emu.w32(o + 8, rnd(c, 0x20))
    lg2 = obj(c, 0x20, {0x30: pystub(c, 2, this=True, pop=0)}, nslots=0x34 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = obj(c, 0x200, {0x294: pystub(c, 4, ret=o, this=True)}, nslots=0x2a0 // 4)
    return [me, r.getrandbits(32)]


def _g507240(c):
    clear_hooks(c)
    r = c.rng
    ent = rnd(c, 0x10)
    c.emu.w32(ent, r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=ent, this=True)
    hook_rec(c, 0x4dafb0, 0, ret=rnd(c, 0x60), this=True, pop=0)
    hook_rec(c, 0x4dc9c0, 1, this=True)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x1f0 // 4)
    sink = obj(c, 0x20, {0: pystub(c, 1, this=True)}, nslots=4)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)}, table_size=0x5e00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.wbytes(tbl + 0x5d31, sink.to_bytes(4, 'little'))
    node = rnd(c, 0x60)
    w = r.getrandbits(32)
    w = (w | 0x40000000) if r.random() < 0.5 else (w & ~0x40000000)
    c.emu.w32(node + 0x3c, w)
    owner = rnd(c, 0x20)
    c.emu.w32(owner + 8, node)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, owner)
    a = rnd(c, 0x20)
    c.emu.w32(a + 4, rnd(c, 0x10))
    return [me, a]


def _g509aa0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    l = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                   0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                         nslots=0x60 // 4)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 3)], this=True)})
    owner = rnd(c, 0x30)
    c.emu.w32(owner + 0x18, l)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, owner)
    return [me, r.getrandbits(32)]


S(0x4f8d80, 'GUESS create and prime object, log it', 'thiscall', None, ret='eax', gen=_g4f8d80, note='batch34039')
S(0x507240, 'GUESS resolve entry and hand to owner chain', 'thiscall', None, ret=None, gen=_g507240, note='batch34039')
S(0x509aa0, 'GUESS hide every object of a list', 'thiscall', None, ret=None, gen=_g509aa0, note='batch34039')
