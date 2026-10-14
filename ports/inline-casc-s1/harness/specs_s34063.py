"""specs_s34063.py - cascade tier E, batch 34063.
0x63d270: this slots 0x60 (0 args) and 0x7c (three stack args, returns a node: a block whose unaligned dword at +0x10055 is a slot index 0..31); the 32-dword table at +0x6c has its first zero at a random
position or none; the registry at +0xf0 with count [this+0xec] 0..0x20 (0x20 takes the assert-hook path); byte [this+5] random; hooked 0x64c8d0.
0x64d560: the big block behind this (zero filled; fields at the unaligned +0x10059, +0x1005d, +0x10071, +0x10161); p's chain [p+8] -> [+0x10] -> [+0] (zero or not) -> [+8] -> entry whose word at +6 chooses the
slot; the table slot is set in half the cases; the objects at [this+0x10161] and [[this+0x1005d]+0x234] have slot 0xc as recorders; [p+0xc] is null in a third.
0x434d90: [this+4] is null in a seventh, else an object with slots 0x4c and 0x64 (stack iterator; yields 0..3 elements, each a pointer to an object with slot 0x54); this slot 0x130 returns 0 or a value."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g63d270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    hook_rec(c, 0x64c8d0, 0, this=True, pop=0)
    node = e.alloc(0x10060, 4)
    e.wbytes(node + 0x10055, r.randrange(32).to_bytes(4, 'little'))
    me = obj(c, 0x180, {0x60: pystub(c, 0, this=True), 0x7c: pystub(c, 3, ret=node, this=True)}, nslots=0x80 // 4)
    first_zero = r.choice([0, 1, 5, 31, -1])
    for i in range(32):
        e.w32(me + 0x6c + 4 * i, 0 if i == first_zero else (r.getrandbits(32) | 1))
    e.wbytes(me + 5, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    e.w32(me + 0xec, r.choice([0, 1, 5, 0x1f, 0x20, r.randint(0, 0x20)]))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g64d560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = e.alloc(0x10300, 4)
    slot = r.randrange(0x1000)
    table = e.alloc(0x4000, 4)
    x = 0 if r.random() < 0.5 else obj(c, 0x20, {}, nslots=2)
    e.w32(table + 4 * slot, x)
    if slot != 0 and r.random() < 0.7:
        e.w32(table, obj(c, 0x20, {}, nslots=2))   # slot 0 is what a (wrongly) unguarded read of a null chain would pick
    o1 = obj(c, 0x20, {0xc: pystub(c, 1, this=True)}, nslots=0x10 // 4)
    o2 = obj(c, 0x20, {0xc: pystub(c, 1, this=True)}, nslots=0x10 // 4)
    g = rnd(c, 0x240)
    e.w32(g + 0x234, o2)
    e.wbytes(me + 0x10059, r.getrandbits(32).to_bytes(4, 'little'))
    e.wbytes(me + 0x1005d, g.to_bytes(4, 'little'))
    e.wbytes(me + 0x10071, table.to_bytes(4, 'little'))
    e.wbytes(me + 0x10161, o1.to_bytes(4, 'little'))
    ent = rnd(c, 0x10)
    e.wbytes(ent + 6, (slot | (r.getrandbits(4) << 12)).to_bytes(2, 'little'))
    ablk = rnd(c, 0x10)
    e.w32(ablk, 0 if r.random() < 0.7 else r.getrandbits(32) | 1)
    e.w32(ablk + 8, ent)
    edx = rnd(c, 0x20)
    a_null = r.random() < 0.2
    e.w32(edx + 0x10, 0 if a_null else ablk)
    if a_null:
        try:
            e.w32(0, 0)   # make a (wrongly) unguarded read through a null pointer look like a zero count
        except Exception:
            pass
    p = rnd(c, 0x20)
    e.w32(p + 8, edx)
    e.w32(p + 0xc, 0 if r.random() < 1 / 3 else rnd(c, 0x10))
    return [me, p]


def _g434d90(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])
    elems = []
    for _ in range(n):
        o = obj(c, 0x20, {0x54: pystub(c, 1, this=True)}, nslots=0x58 // 4)
        cell = rnd(c, 0x10)
        c.emu.w32(cell, o)
        elems.append(cell)

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))
    m = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                   0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: elems[k] if k < n else 0)},
                                         nslots=0x68 // 4)
    me = obj(c, 0x20, {0x130: pystub(c, 1, this=True, ret=lambda em, k: 0 if r.random() < 0.4 else r.getrandbits(32) | 1)}, nslots=0x134 // 4)
    c.emu.w32(me + 4, m)
    return [me, r.getrandbits(32)]


S(0x63d270, 'GUESS create a slot node and register it twice', 'thiscall', None, ret='eax', gen=_g63d270, note='batch34063')
S(0x64d560, 'GUESS release a mapped entry and a side object', 'thiscall', None, ret=None, gen=_g64d560, note='batch34063')
S(0x434d90, 'GUESS apply a lookup to every element of a list', 'thiscall', None, ret=None, gen=_g434d90, note='batch34063')
