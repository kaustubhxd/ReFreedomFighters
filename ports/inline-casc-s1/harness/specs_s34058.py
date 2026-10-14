"""specs_s34058.py - cascade tier E, batch 34058.
0x496690: s slots 0xc (1 arg) and 0x18 (stack id pointer + size; writes 0..3 valid ids then -1); [this+0x14] -> block whose +4 is an array of 4 nodes of 0x70 bytes with random flags; hooked 0x4d9430 / 0x4d9590.
0x4b70f0: byte +0x183 zero in a third; engine table slots 0x138 (object whose slot 0x88 writes tmp half of the time through a stack pointer), 0x58, 0x114 (four args; full 32-bit value used) are recorders; the object
from slot 0x58 (null in a quarter) has slot 0x130 (three args).
0x4c8560: the engine table's list (+0xadc) holds up to 3 nodes (slot 0x50 writes the next node through a stack pointer); each node's +0x54 is null or a record whose [+0xc] block carries random flags at +0x23
(bit 0x400000 in half the cases); hooked 0x4daa20; byte +0x52 random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g496690(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4d9430, 0, this=True, pop=0)
    hook_rec(c, 0x4d9590, 1, pop=0)
    nn = r.choice([0, 1, 2, 3])
    ids = [r.randrange(4) for _ in range(nn)] + [0xffffffff]

    def rd(em, k):
        em.w32(em.arg32(0), ids[min(k, len(ids) - 1)])
    s = obj(c, 0x20, {0xc: pystub(c, 1, this=True), 0x18: pystub(c, 2, this=True, side=rd, stackmark=(0,))}, nslots=0x1c // 4)
    base = rnd(c, 4 * 0x70)
    for i in range(4):
        w = r.getrandbits(32)
        w = (w | 0x4000000) if r.random() < 0.5 else (w & ~0x4000000)
        c.emu.w32(base + 0x70 * i + 0x3c, w & 0xffffffff)
    owner = rnd(c, 0x20)
    c.emu.w32(owner + 4, base)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x14, owner)
    return [me, s]


def _g4b70f0(c):
    clear_hooks(c)
    r = c.rng

    def wtmp(em, k):
        if r.random() < 0.5:
            em.w32(em.arg32(1), r.getrandbits(32))
    t = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=wtmp, stackmark=(1,))}, nslots=0x90 // 4)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x130: pystub(c, 3, this=True)}, nslots=0x134 // 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=t, this=True), 0x58: pystub(c, 1, ret=o, this=True),
                           0x114: pystub(c, 4, ret=lambda em, k: r.getrandbits(32), this=True)})
    me = rnd(c, 0x190)
    c.emu.wbytes(me + 0x183, bytes([0 if r.random() < 1 / 3 else r.randrange(1, 256)]))
    return [me]


def _g4c8560(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4daa20, 1, this=True)
    nn = r.choice([0, 1, 2, 3])
    nodes = []
    for _ in range(nn):
        nd = rnd(c, 0x60)
        if r.random() < 0.2:
            c.emu.w32(nd + 0x54, 0)
        else:
            blk = rnd(c, 0x40)
            w = r.getrandbits(32)
            w = (w | 0x400000) if r.random() < 0.5 else (w & ~0x400000)
            c.emu.wbytes(blk + 0x23, (w & 0xffffffff).to_bytes(4, 'little'))
            rec = rnd(c, 0x20)
            c.emu.w32(rec + 0xc, blk)
            c.emu.w32(nd + 0x54, rec)
        nodes.append(nd)
    seq = nodes + [0]

    def nxt(em, k):
        em.w32(em.arg32(0), seq[k + 1] if k + 1 < len(seq) else 0)
    lst = obj(c, 0x20, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x60 // 4)
    c.emu.w32(lst + 8, nodes[0] if nodes else 0)
    so = sysobj(c, table_size=0xc00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xadc, lst)
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x52, bytes([r.choice([0, 0, 1, r.getrandbits(8)])]))   # the toggled flag must be 0 or 1 often enough to be visible
    return [me]


S(0x496690, 'GUESS release the nodes named by a stream', 'thiscall', None, ret=None, gen=_g496690, note='batch34058')
S(0x4b70f0, 'GUESS one-shot lookup of a table value and a word', 'thiscall', None, ret=None, gen=_g4b70f0, note='batch34058')
S(0x4c8560, 'GUESS toggle flag and apply it to flagged entries', 'thiscall', None, ret=None, gen=_g4c8560, note='batch34058')
