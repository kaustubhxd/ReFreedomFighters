"""specs_s34047.py - cascade tier E, batch 34047.
0x4f2240 (stdcall, ECX unused): o is null in a seventh; o slot 0x1e0 returns 0/1; node chain of 0..3 nodes at [o+8] (next written through slot 0x50's stack pointer argument); hooked 0x4db9a0 returns 0/1;
each node's child at +0x54 has byte +0x21 equal to 8 in half the cases and slot 0x250 as a recorder.
0x529d00: s slots 0x6c (heap pointers), 0x40 (stack pointer: writes a random id) and 0x50 (heap pointers) are recorders; engine table slot 0x58 returns random values; hooked 0x529d70.
0x546040: the record count at +0x28 is -1..4; the unaligned pointer at +0xf leads to a block of 4 * 0x34 random bytes; s slot 0x6c records the pointer arguments as offsets (heap pointers, recorded as is)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4f2240(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4db9a0, 1, ret=lambda em, k: r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)
    nn = r.choice([0, 1, 2, 3])
    nodes = []
    for _ in range(nn):
        nd = rnd(c, 0x60)
        ch = obj(c, 0x40, {0x250: pystub(c, 1, this=True)}, nslots=0x260 // 4)
        c.emu.wbytes(ch + 0x21, bytes([8 if r.random() < 0.5 else r.randrange(0, 256)]))
        c.emu.w32(nd + 0x54, ch)
        nodes.append(nd)
    seq = nodes + [0]

    def nxt(em, k):
        em.w32(em.arg32(0), seq[k + 1] if k + 1 < len(seq) else 0)
    o = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True),
                                                  0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x1f0 // 4)
    if o:
        c.emu.w32(o + 8, seq[0])
    return [r.getrandbits(32), o]


def _g529d00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x529d70, 1, this=True)

    def wid(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    s = obj(c, 0x20, {0x6c: pystub(c, 1, this=True), 0x40: pystub(c, 1, this=True, side=wid, stackmark=(0,)),
                      0x50: pystub(c, 1, this=True)}, nslots=0x70 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    return [rnd(c, 0x60), s]


def _g546040(c):
    clear_hooks(c)
    r = c.rng
    s = obj(c, 0x20, {0x6c: pystub(c, 1, this=True)}, nslots=0x70 // 4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x28, r.choice([-1, 0, 1, 2, 4, r.randint(0, 4)]) & 0xffffffff)
    c.emu.wbytes(me + 0xf, rnd(c, 4 * 0x34).to_bytes(4, 'little'))
    return [me, s]


S(0x4f2240, 'GUESS notify matching children of a node list', 'stdcall', None, ret=None, gen=_g4f2240, note='batch34047')
S(0x529d00, 'GUESS read a record from a stream', 'thiscall', None, ret='al', gen=_g529d00, note='batch34047')
S(0x546040, 'GUESS write an array of 0x34-byte records to a stream', 'thiscall', None, ret='al', gen=_g546040, note='batch34047')
