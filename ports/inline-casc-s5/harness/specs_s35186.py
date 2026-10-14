"""specs_s35186.py - 0x5129c0 (thiscall, no args, ret=None). this: object with recorder slots 0x338 (0 args), 0x2e0 (2 args), 0x28 (0 args), 0x324 (1 arg), 0x288 (3 args) and 0x80 (2 args: writes random floats into P (9 dwords) and Q (3 dwords) on the caller's stack; recorded as flags);
count [+0xda] 0..3 with ids at +0xde, unaligned dword [+0x11f], X = [+0x134] (null in 1/3), Y = [+0x138] (null in 1/3), [+0x8] a heap pointer, word [+0x20f]. Engine table slot 0x4c (1 arg) returns random ids. X: slots 0x7c (2 args: P as 9 dwords, Q as 3 dwords recorded) and 0x2c.
0x4db3b0 hooked (returns obj2 with slot 0x288, 3 args), 0x45fb00 hooked (thiscall, 3 args), 0x4de040 replaced by a Python handler (logs R and P, rewrites P). Y: slots 0x7c (2 heap pointer args) and 0x2c, [+0x50] = list of 0..4 nodes ([+0x54] child with slot 0x2c, [+0x60] next)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj, _HOOKED


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5129c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def s80(em, k):
        p, q = em.arg32(0), em.arg32(1)
        for i in range(9):
            em.w32(p + 4 * i, _fb(c.fv(-20, 20)))
        for i in range(3):
            em.w32(q + 4 * i, _fb(c.fv(-20, 20)))
    obj2 = obj(c, 0x20, {0x288: pystub(c, 3, this=True)}, nslots=0xa4)
    this = obj(c, 0x240, {0x338: pystub(c, 0, this=True), 0x2e0: pystub(c, 2, this=True), 0x28: pystub(c, 0, this=True), 0x324: pystub(c, 1, this=True),
                          0x288: pystub(c, 3, this=True), 0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=s80)}, nslots=0xe0)
    cnt = r.choice([0, 1, 2, 3])
    e.w32(this + 0xda, cnt)
    for i in range(3):
        e.w32(this + 0xde + 4 * i, r.getrandbits(32))
    e.wbytes(this + 0x11f, r.getrandbits(32).to_bytes(4, 'little'))
    e.w32(this + 8, rnd(c, 0x10))
    e.wbytes(this + 0x20f, r.getrandbits(16).to_bytes(2, 'little'))
    X = 0 if r.random() < 1 / 3 else obj(c, 0x20, {0x7c: pystub(c, 2, this=True, deref={0: 9, 1: 3}), 0x2c: pystub(c, 0, this=True)}, nslots=0x20)
    e.w32(this + 0x134, X)
    if r.random() < 1 / 3:
        Y = 0
    else:
        Y = obj(c, 0x80, {0x7c: pystub(c, 2, this=True), 0x2c: pystub(c, 0, this=True)}, nslots=0x20)
        nodes = []
        for _ in range(r.choice([0, 1, 2, 3, 4])):
            nd = rnd(c, 0x80)
            e.w32(nd + 0x54, obj(c, 0x20, {0x2c: pystub(c, 0, this=True)}, nslots=0x20))
            nodes.append(nd)
        for i, nd in enumerate(nodes):
            e.w32(nd + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
        e.w32(Y + 0x50, nodes[0] if nodes else 0)
    e.w32(this + 0x138, Y)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    hook_rec(c, 0x4db3b0, 0, this=True, pop=0, ret=obj2)
    hook_rec(c, 0x45fb00, 3, this=True, pop=12)

    def h040(em, res_):
        pp, rr = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('4de040', tuple(em.r32(pp + 4 * i) for i in range(9)), tuple(em.r32(rr + 4 * i) for i in range(3)), em.arg32(0)))
        for i in range(9):
            if r.random() < 0.5:
                em.w32(pp + 4 * i, _fb(c.fv(-2, 2)))
        em.ret(argbytes=4)
    e.hook(0x4de040, h040)
    _HOOKED.add(0x4de040)
    return [this]


S(0x5129c0, 'GUESS refresh scene object ids attachments and children', 'thiscall', None, ret=None, gen=_g5129c0, note='batch35186')
