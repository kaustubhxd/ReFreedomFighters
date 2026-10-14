"""specs_s38056.py - cascade s8 batch 38056. Record with flag bit 0x10 (90%), flag byte at +0x14, a chain of 0..3 instances (+0x1c next, own object at +8 whose +0x10 -> +8 -> block with word +2 in {0, 1, 2, 5} and byte
+0x30, own +0x14 dword), and a block B with 0..4 entries of {instance or 0, source object with dword +0x30} at B[0x40]. The two pools (slot 8 allocate: fresh objects, null 8%; slot 0xc free, recorded),
this[0x1005d] (slots 0xa8 -> bool, 0xac) and this slots 0x54 (bool) / 0x58 are recording stubs; unaligned fields +0x10059 (mask), +0x1005d, +0x1015d. 0x64d490 / 0x64d5f0 hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g6491b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pf = r.choice([0.0, 0.08, 0.2])

    def pool(n):
        objs = [rnd(c, 0x40) for _ in range(n)]
        return objs

    p1o = pool(6)
    p2o = pool(10)

    def a1(em, k):
        return 0 if r.random() < pf else p1o[k % 6]

    def a2(em, k):
        return 0 if r.random() < pf else p2o[k % 10]
    pool1 = obj(c, 0x40, {8: pystub(c, 0, this=True, ret=a1), 0xc: pystub(c, 1, this=True)})
    pool2 = obj(c, 0x40, {8: pystub(c, 0, this=True, ret=a2), 0xc: pystub(c, 1, this=True)})
    pok = r.choice([0.3, 0.8, 1.0])
    M = obj(c, 0x300, {0xa8: pystub(c, 3, this=True, ret=lambda em, k: 1 if r.random() < pok else 0), 0xac: pystub(c, 1, this=True)})
    e.w32(M + 0x224, pool1)
    sok = r.choice([0.3, 0.8, 1.0])
    me = obj(c, 0x10200, {0x54: pystub(c, 1, this=True, ret=lambda em, k: r.choice([1, 0x101]) if r.random() < sok else 0),
                          0x58: pystub(c, 1, this=True)})
    e.wbytes(me + 0x10059, struct.pack('<I', r.choice([0, 1, 4, 0x80, r.getrandbits(32)])))
    e.wbytes(me + 0x1005d, struct.pack('<I', M))
    e.wbytes(me + 0x1015d, struct.pack('<I', pool2))

    def mkinst():
        n = rnd(c, 0x40)
        e.wbytes(n + 5, bytes([r.choice([0x10, 0x10, 0x00, 0x30])]))
        own = rnd(c, 0x40)
        px = rnd(c, 0x20)
        q = rnd(c, 0x40)
        e.wbytes(q + 2, struct.pack('<H', r.choice([0, 1, 2, 5])))
        e.w32(px + 8, q)
        e.w32(own + 0x10, px)
        e.w32(n + 8, own)
        return n
    chain = [mkinst() for _ in range(r.choice([0, 0, 1, 2, 3]))]
    for a, b in zip(chain, chain[1:]):
        e.w32(a + 0x1c, b)
    if chain:
        e.w32(chain[-1] + 0x1c, 0)
    count = r.choice([0, 1, 2, 3, 4])
    tab = e.alloc(8 * max(count, 1) + 8, 4)
    for i in range(count):
        slot = 0
        if r.random() < 0.45:
            slot = rnd(c, 0x40)
        C = rnd(c, 0x40)
        e.w32(tab + 8 * i, slot)
        e.w32(tab + 8 * i + 4, C)
    B = rnd(c, 0x60)
    e.wbytes(B + 0x3d, bytes([count]))
    e.w32(B + 0x40, tab)
    rec = rnd(c, 0x40)
    e.wbytes(rec + 5, bytes([0x10 if r.random() < 0.9 else 0]))
    e.wbytes(rec + 0x14, bytes([r.choice([0, 1, 2, 4, 0xff, r.getrandbits(8)])]))
    e.w32(rec + 8, B)
    e.w32(rec + 0x1c, chain[0] if chain else 0)
    hook_rec(c, 0x64d490, 1, this=True, pop=4)
    hook_rec(c, 0x64d5f0, 1, this=True, pop=4)
    return [me, rec]


S(0x6491b0, 'GUESS refresh effect instances of a record', 'thiscall', None, ret=None, gen=_g6491b0, note='batch38056')
