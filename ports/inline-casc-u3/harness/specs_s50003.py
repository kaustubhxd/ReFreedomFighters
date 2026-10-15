"""specs_s50003.py - u3 (Sonnet) batch 50003, tier H. 0x4427c0: this[8] flags (bit 10), slot 0x314 (query object or null), slots 0x8c / 0x90 (rewrite the stack vectors), real 0x4e3180 and
0x43e8e0 (vector add), 0x4e4520 hooked (records its object, both vectors' contents and the callback struct fields, then fills the hit buffer and count), 0x442420 hooked (records ecx, edx
and the five stack args), unaligned pointer this[0x7b] with a word count and per-index objects whose slot 0x2e8 takes seven args; /GS check keeps eax."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fb(r):
    return struct.pack('<f', r.uniform(-100, 100))


def _g4427c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    def vec(em, k):
        p = em.arg32(0)
        for j in range(3):   # the slot rewrites only some components, so the copied inputs stay visible
            f = _fb(r)
            if r.random() < 0.5:
                em.wbytes(p + 4 * j, f)
    q = rnd(c, 0x20)

    def query(em, k):
        st = em.arg32(0)
        em.calllog.append(('st', em.r32(st), em.r32(st + 4), em.r32(st + 0x64), em.r32(st + 0x68)))
        buf = em.r32(st + 0x5c)
        n = r.choice([0, 0, 1, 2, 3, 7, 20])
        for i in range(n):
            em.w32(buf + 4 * i, r.getrandbits(32))
        em.w32(st + 0x64, n)
    hook_rec(c, 0x4e4520, 3, this=True, pop=0xc, nullflag=(0,), deref={1: 3, 2: 3}, side=query)

    def hit(em, k):
        em.calllog.append(('hit', em.reg('edx')))
    hook_rec(c, 0x442420, 5, this=True, pop=0x14, ret=lambda em, k: r.getrandbits(8), side=hit)
    qobj = q if r.random() > 0.15 else 0
    me = obj(c, 0x100, {0x314: pystub(c, 0, this=True, ret=qobj),
                        0x8c: pystub(c, 1, this=True, stackmark=(0,), side=vec),
                        0x90: pystub(c, 1, this=True, stackmark=(0,), side=vec)}, nslots=0x318 // 4)
    fl = rnd(c, 0x60)
    e.w32(fl + 0x3c, (r.getrandbits(32) & ~0x400) | (0x400 if r.random() < 0.15 else 0))
    e.w32(me + 8, fl)
    n = r.choice([0, 1, 2, 3, 5])
    P = rnd(c, 0x404 + 4 * 8 + 16)
    e.wbytes(P + 2, struct.pack('<H', n))
    for i in range(8):
        o = obj(c, 0x20, {0x2e8: pystub(c, 7, this=True, pop=0x1c, ret=lambda em, k: r.getrandbits(8))}, nslots=0x2ec // 4)
        e.w32(P + 0x404 + 4 * i, o)
    e.wbytes(me + 0x7b, (P if r.random() > 0.2 else 0).to_bytes(4, 'little'))
    cv = rnd(c, 0x10)
    dv = rnd(c, 0x10)
    for p in (cv, dv):
        e.wbytes(p, b''.join(_fb(r) for _ in range(3)))
    return [me, r.getrandbits(32), r.getrandbits(32), cv, dv, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4427c0, 'GUESS query box hits and let each react', 'thiscall', None, ret='al', gen=_g4427c0, note='batch50003')
