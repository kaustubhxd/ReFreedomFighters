"""specs_s50005.py - u3 (Sonnet) batch 50005, tier H. 0x56b030: engine object +0x9b table (slots 0xb4 / 0x138 / 0x58), unaligned +0x1a9f optional object (slot 0x138), unaligned screen ints +0x6f / +0x73
(negative, zero, odd and typical sizes), R slot 0x88 writing a value through its stack pointer argument, S slot 0x70 (vector contents recorded) and 0x288, this[0x44] slot 0x25c returning a record or null,
0x4db500 hooked (rewrites only some of the two floats), unaligned float outputs at this+0x51..0x5d; /GS check keeps eax."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g56b030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    def lv(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))
    Rr = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=lv)}, nslots=0x8c // 4)
    Ss = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3}), 0x288: pystub(c, 3, this=True)}, nslots=0x28c // 4)
    so = sysobj(c, table_slots={0xb4: pystub(c, 1, this=True), 0x138: pystub(c, 0, this=True, ret=Rr),
                                0x58: pystub(c, 1, this=True, ret=Ss)}, table_size=0x20)
    opt = obj(c, 0x20, {0x138: pystub(c, 1, this=True)}, nslots=0x13c // 4) if r.random() < 0.6 else 0
    e.wbytes(so + 0x1a9f, opt.to_bytes(4, 'little'))
    dims = [640, 800, 1024, 1280, 1920, 0x280, 0x1c0, 1, 0, 479, 641, -3, -641, 100000, r.randrange(1, 4000), r.getrandbits(32)]
    w = r.choice(dims)
    h = r.choice(dims[:8] + [480, 600, 768, 1080, 1, 0, 449, 447, -5, r.randrange(1, 3000)])
    e.wbytes(so + 0x6f, (w & 0xffffffff).to_bytes(4, 'little'))
    e.wbytes(so + 0x73, (h & 0xffffffff).to_bytes(4, 'little'))

    def vec(em, k):
        p = em.arg32(0)
        if r.random() < 0.7:
            em.wbytes(p, _fb(r.uniform(-300, 300)))
        if r.random() < 0.7:
            em.wbytes(p + 4, _fb(r.uniform(-300, 300)))
    hook_rec(c, 0x4db500, 1, this=True, pop=4, stackmark=(0,), side=vec)
    inner = rnd(c, 0x20)
    rec = rnd(c, 0x20)
    e.w32(rec + 8, inner)
    q = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=rec if r.random() < 0.75 else 0)}, nslots=0x260 // 4)
    me = rnd(c, 0x100)
    e.w32(me + 0x44, q)
    return [me]


S(0x56b030, 'GUESS recentre overlay for screen size', 'thiscall', None, ret=None, gen=_g56b030, nan_heap=True, note='batch50005')
