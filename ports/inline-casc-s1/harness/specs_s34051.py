"""specs_s34051.py - cascade tier E, batch 34051.
0x566850: [[this+0x180]+0x18] is the iterator object (null in a seventh; slots 0x4c, 0x5c with a stack iterator, 0..3 ids); [this+0x44] slot 0x12c records (id, word +0x186, id).
0x56ad00: six ids at +0x180; engine table slot 0x58 returns an object (null in a quarter) with slot 0xbc (1 arg); k is 0..8.
0x56c780: five unaligned member pointers (+0xcb6, +0xcc6, +0xcba, +0xcca, +0xcce), each null in a fifth, with slot 0xbc recorders; f random with the low byte zero in a third."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g566850(c):
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
    owner = rnd(c, 0x30)
    c.emu.w32(owner + 0x18, l)
    sink = obj(c, 0x20, {0x12c: pystub(c, 3, this=True)}, nslots=0x130 // 4)
    me = rnd(c, 0x190)
    c.emu.w32(me + 0x180, owner)
    c.emu.w32(me + 0x44, sink)
    return [me]


def _g56ad00(c):
    clear_hooks(c)
    r = c.rng
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4) for _ in range(8)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 7)], this=True)})
    me = rnd(c, 0x1a0)
    return [me, r.choice([0, 1, 2, 5, 6, 7, 8, r.randint(0, 8)])]


def _g56c780(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xce8)
    for off in (0xcb6, 0xcc6, 0xcba, 0xcca, 0xcce):
        o = 0 if r.random() < 0.2 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
        c.emu.wbytes(me + off, o.to_bytes(4, 'little'))
    f = r.getrandbits(32)
    if r.random() < 1 / 3:
        f &= ~0xff
    return [me, f]


S(0x566850, 'GUESS feed every id of a list to a sink', 'thiscall', None, ret=None, gen=_g566850, note='batch34051')
S(0x56ad00, 'GUESS hide six objects then show one', 'thiscall', None, ret=None, gen=_g56ad00, note='batch34051')
S(0x56c780, 'GUESS broadcast a flag to five members', 'thiscall', None, ret=None, gen=_g56c780, note='batch34051')
