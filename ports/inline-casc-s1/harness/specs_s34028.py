"""specs_s34028.py - cascade tier E, batch 34028.
0x4bafe0: the list object a+0x18 has slots 0x4c (writes random dwords through the stack iterator) and 0x5c (writes it[0] = 1 for the first n calls (n 0..3), then 0, returns an id); engine
table slot 0x58 and this slot 0x94 are recorders; a+0x18 is null in a seventh of the cases.
0x4c86d0: the engine table's list (+0xadc) holds up to 4 nodes (slot 0x50 writes the next node through its stack pointer); each node has [node+0x54] null or a record whose [..+0xc] block carries the
dword 0x200012 at +0x23 in half the cases; 0x4daa20 is a thiscall recorder; byte +0x53 random.
0x4d1b00: [this+0x18] heads a chain of 1..4 nodes (+8 next, +0xc / +0x10 values); n from -1 to 6 (more than the chain length gives the logger path through the object at 0x700390); sink slot 0x1c recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4bafe0(c):
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
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x18, l)
    me = obj(c, 0x40, {0x94: pystub(c, 1, this=True)}, nslots=0xa0 // 4)
    return [me, a]


def _g4c86d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4daa20, 1, this=True)
    nn = r.choice([0, 1, 2, 3, 4])
    nodes = []
    for _ in range(nn):
        nd = rnd(c, 0x60)
        if r.random() < 0.2:
            c.emu.w32(nd + 0x54, 0)
        else:
            blk = rnd(c, 0x40)
            c.emu.wbytes(blk + 0x23, (0x200012 if r.random() < 0.5 else r.getrandbits(32)).to_bytes(4, 'little'))
            rec = rnd(c, 0x20)
            c.emu.w32(rec + 0xc, blk)
            c.emu.w32(nd + 0x54, rec)
        nodes.append(nd)
    seq = nodes + [0]
    st = {'i': 0}

    def nxt(em, k):
        em.w32(em.arg32(0), seq[k + 1] if k + 1 < len(seq) else 0)
    lst = obj(c, 0x20, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x60 // 4)
    c.emu.w32(lst + 8, nodes[0] if nodes else 0)
    so = sysobj(c, table_size=0xc00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xadc, lst)
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x53, bytes([r.choice([0, 0, 1, r.getrandbits(8)])]))   # the toggled flag must be 0 or 1 often enough to be visible
    return [me]


def _g4d1b00(c):
    clear_hooks(c)
    r = c.rng
    nn = r.choice([1, 2, 3, 4])
    nodes = [rnd(c, 0x20) for _ in range(nn)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 8, nodes[i + 1] if i + 1 < nn else 0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, nodes[0])
    sink = obj(c, 0x20, {0x1c: pystub(c, 2, this=True)}, nslots=0x30)
    return [me, sink, r.randint(-1, 6) & 0xffffffff]


S(0x4bafe0, 'GUESS feed every id of a list to this', 'thiscall', None, ret=None, gen=_g4bafe0, note='batch34028')
S(0x4c86d0, 'GUESS toggle flag and apply to matching entries', 'thiscall', None, ret=None, gen=_g4c86d0, note='batch34028')
S(0x4d1b00, 'GUESS replay linked list into sink from n-th node', 'thiscall', None, ret=None, gen=_g4d1b00, note='batch34028')
