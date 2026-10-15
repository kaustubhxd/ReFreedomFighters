"""specs_s50013.py - u3 batch 50013 (Haiku slot, run by Sonnet 5.5), tier H. 0x520450: O1 = unaligned [this+0x2707] with slot 0x84, this slots 0x8c / 0x94 / 0x130 (0x130 records the whole 0x79-byte request struct
and the object / word args), 0x4e0870 hooked (float in st0, logs its two vectors), 0x4e2c60 hooked (logs both stack buffers), 0x4de040 hooked (fills 9 floats, logs the input vector), table slot 0x58 returns the
w object whose slot 0x80 fills the stack matrix / vector and whose [w+8] block holds the position floats; the gate [p+0x4c] + 200 > r is hit on both sides."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g520450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    import os
    p = rnd(c, 0x80)
    if os.environ.get('DBGP'): print('p', hex(p))
    k4c = r.uniform(-300, 300)
    e.wbytes(p + 0x4c, _fb(k4c))
    thr = k4c + 200.0

    def rr(em, k):
        return r.choice([thr + r.uniform(1, 100), thr - r.uniform(1, 100), thr, r.uniform(-500, 500)])

    def lg(em, k):
        em.calllog.append(('edx', em.reg('edx')))
        for a in (em.reg('ecx'), em.reg('edx')):
            em.calllog.append(('v', em.r32(a), em.r32(a + 4), em.r32(a + 8)))
    # 4e0870: the vector (stack) is the first, the point in [this+8]+0x30 the second
    hook_rec(c, 0x4e0870, 0, this='mark', st0=lambda em, k: _f32(rr(em, k)), side=lg)

    def lg2(em, k):
        a, b = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('m', tuple(em.r32(a + 4 * i) for i in range(9)), tuple(em.r32(b + 4 * i) for i in range(3))))
    hook_rec(c, 0x4e2c60, 0, this='mark', side=lg2)

    def b40(em, k):
        o = em.reg('ecx')
        v = em.reg('edx')
        em.calllog.append(('vin', em.r32(v), em.r32(v + 4), em.r32(v + 8)))
        for i in range(9):
            em.wbytes(o + 4 * i, _fb(r.uniform(-1, 1)))
    hook_rec(c, 0x4de040, 1, this='mark', pop=4, side=b40)

    def part(em, k):
        v = em.arg32(0)
        for j in range(3):
            if r.random() < 0.5:
                em.wbytes(v + 4 * j, _fb(r.uniform(-50, 50)))

    def fill80(em, k):
        m, t = em.arg32(0), em.arg32(1)
        for i in range(9):
            em.wbytes(m + 4 * i, _fb(r.uniform(-1, 1)))
        for i in range(3):
            em.wbytes(t + 4 * i, _fb(r.uniform(-1, 1)))
    wblk = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        e.wbytes(wblk + off, _fb(r.uniform(-100, 100)))
    w = obj(c, 0x20, {0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=fill80)}, nslots=0x84 // 4)
    e.w32(w + 8, wblk)
    wid = r.getrandbits(32)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=w)})
    o1 = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 3}, side=part)}, nslots=0x88 // 4)
    me = obj(c, 0x2800, {0x8c: pystub(c, 1, this=True, deref={0: 3}, side=part), 0x94: pystub(c, 2, this=True, deref={0: 9, 1: 3}),
                         0x130: pystub(c, 3, this=True, deref={2: -0x79})}, nslots=0x134 // 4)
    e.w32(me + 8, p)
    e.wbytes(me + 0x2707, o1.to_bytes(4, 'little'))
    e.wbytes(me + 0x123, wid.to_bytes(4, 'little'))
    vecs = []
    for _ in range(4):
        v = rnd(c, 0x10)
        for j in range(3):
            e.wbytes(v + 4 * j, _fb(r.uniform(-100, 100)))
        vecs.append(v)
    if os.environ.get('DBGP'): print('me', hex(me), 'o1', hex(o1), 'w', hex(w), 'wblk', hex(wblk), 'so', hex(so))
    return [me] + vecs


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


S(0x520450, 'GUESS build query request struct', 'thiscall', None, ret=None, gen=_g520450, nan_heap=True, note='batch50013')
