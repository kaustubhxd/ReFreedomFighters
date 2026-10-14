"""specs_s34034.py - cascade tier E, batch 34034.
0x436450: counts 0..2 / 0..3 / 0..16 (the first two pointer ranges are short: the counts sit at +0xc and +0x1c), every element an object with a slot 0xc recorder.
0x443ad0: member [this+0x77] (unaligned) is an object with slots 0x3c, 0x14 (returns 0 in half the cases) and 0 (the deleting dtor, a recorder); a has slots 0x308 / 0x30c returning 0/1;
0x443c80 / 0x443b40 are thiscall recorders.
0x4544d0: byte +0x5a is zero in three quarters; the iterator object at +0x52 is null in a seventh; its slot 0x4c writes random dwords through the stack iterator, slot 0x5c writes it[0] = 1 for the first
n calls (0..3) and returns ids; engine table slot 0x58 returns an object (null in a quarter) whose slot 0x22c is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g436450(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x70)
    st = pystub(c, 0, this=True)
    mk = lambda: obj(c, 0x20, {0xc: st}, nslots=0x20 // 4)
    for i in range(2):
        c.emu.w32(me + 4 + 4 * i, mk())
    for i in range(3):
        c.emu.w32(me + 0x10 + 4 * i, mk())
    for i in range(16):
        c.emu.w32(me + 0x20 + 4 * i, mk())
    c.emu.w32(me + 0xc, r.choice([0, 1, 2, r.randint(0, 2)]))
    c.emu.w32(me + 0x1c, r.choice([0, 1, 3, r.randint(0, 3)]))
    c.emu.w32(me + 0x60, r.choice([0, 1, 5, 16, r.randint(0, 16)]))
    return [me]


def _g443ad0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x443c80, 1, this=True)
    hook_rec(c, 0x443b40, 1, this=True)
    m = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x14: pystub(c, 0, ret=(0 if r.random() < 0.5 else r.getrandbits(32) | 1), this=True),
                      0: pystub(c, 1, this=True)}, nslots=0x40 // 4)
    a = obj(c, 0x20, {0x308: pystub(c, 0, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True),
                      0x30c: pystub(c, 0, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x320 // 4)
    me = rnd(c, 0x90)
    c.emu.wbytes(me + 0x77, m.to_bytes(4, 'little'))
    return [me, a]


def _g4544d0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    m = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                   0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                         nslots=0x60 // 4)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0x22c: pystub(c, 0, this=True)}, nslots=0x240 // 4) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 3)], this=True)})
    me = rnd(c, 0x70)
    c.emu.wbytes(me + 0x52, m.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x5a, bytes([0 if r.random() < 0.75 else r.randrange(1, 256)]))
    return [me]


S(0x436450, 'GUESS slot 0xc over three object arrays', 'thiscall', None, ret=None, gen=_g436450, note='batch34034')
S(0x443ad0, 'GUESS refresh and maybe release member, dispatch on two predicates', 'thiscall', None, ret=None, gen=_g443ad0, note='batch34034')
S(0x4544d0, 'GUESS once-only walk of id list calling slot 0x22c', 'thiscall', None, ret=None, gen=_g4544d0, note='batch34034')
