"""specs_s34037.py - cascade tier E, batch 34037.
0x4a9330: the old value at the unaligned +0xbb equals n in a fifth, is zero in a fifth; engine table slot 0x58 returns an object (null in a quarter) whose slot 0xbc is a recorder; 0x4a90b0 is a thiscall recorder.
0x4b8ab0: member [this+0x4c] null in a seventh; its slot 0x4c writes random dwords through the stack iterator, slot 0x5c writes it[0] = 1 for the first n calls (0..3) and returns ids; [this+0x44] slot 0x12c records
(id, word +0x4a, a).
0x4caed0: the low word of k equals the word at +0x90, the word at +0x92, both or neither; member [this+0x8c] null in a third; this slots 0x64 and 0x68 recorders; the unused second argument is random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4a9330(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4a90b0, 1, this=True)
    mk = lambda: 0 if r.random() < 0.25 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    objs = [mk() for _ in range(3)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 2)], this=True)})
    me = rnd(c, 0xd0)
    old = 0 if r.random() < 0.2 else (r.getrandbits(32) | 1)
    c.emu.wbytes(me + 0xbb, old.to_bytes(4, 'little'))
    n = old if r.random() < 0.2 else (0 if r.random() < 0.2 else (r.getrandbits(32) | 1))
    return [me, n]


def _g4b8ab0(c):
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
    sink = obj(c, 0x20, {0x12c: pystub(c, 3, this=True)}, nslots=0x130 // 4)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x4c, m)
    c.emu.w32(me + 0x44, sink)
    return [me, r.getrandbits(32)]


def _g4caed0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x98, {0x64: pystub(c, 1, this=True), 0x68: pystub(c, 2, this=True)}, nslots=0x70 // 4)
    w90, w92 = r.getrandbits(16), r.getrandbits(16)
    if r.random() < 0.15:
        w92 = w90
    c.emu.wbytes(me + 0x90, w90.to_bytes(2, 'little') + w92.to_bytes(2, 'little'))
    k = r.choice([w90, w92, w90, w92, r.getrandbits(16)])
    k |= r.getrandbits(16) << 16
    p = 0 if r.random() < 0.33 else rnd(c, 0x30)
    c.emu.w32(me + 0x8c, p)
    return [me, k, r.getrandbits(32)]


S(0x4a9330, 'GUESS swap tracked object', 'thiscall', None, ret=None, gen=_g4a9330, note='batch34037')
S(0x4b8ab0, 'GUESS send every id of a list to a sink', 'thiscall', None, ret=None, gen=_g4b8ab0, note='batch34037')
S(0x4caed0, 'GUESS copy or clear pair on matching id', 'thiscall', None, ret='eax', gen=_g4caed0, note='batch34037')
