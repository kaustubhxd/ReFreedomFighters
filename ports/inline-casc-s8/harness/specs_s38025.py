"""specs_s38025.py - cascade s8 batch 38025: 0x4cf690. Container with recording slots 0x54 (iterator start, stack pointer marked), 0x74 (next: returns key arrays, bucket key inside the range, the
count of items is below or equal to this[0x14] so the log path and the pool path both run) and 0xc; fields +0x14 count, +0x18 dims (1..3), +0x1c / +0x20 key range, +0xc capacity (random, high bit
set sometimes). The allocator 0x41e290 hands out blocks filled with random bytes; 0x634d10 (memset) and 0x634d22 (memcpy) are real-effect hooks; 0x634273 free is recorded. The new object's
vtable (0x695734) entries 0x4cd300 / 0x4cd540 / 0x4cdd40 (delete, append slot returning a destination, size) are hooked; the logger slot 0x24 is a recorded cdecl stub."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4cf690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([0, 1, 2, 3, 5])
    dims = r.choice([1, 2, 3])
    lo = r.randrange(0, 20)
    nb = r.choice([0, 1, 2, 4, 6]) if cnt == 0 else r.choice([1, 2, 4, 6])
    hi = lo + nb - 1
    m = r.choice([cnt, cnt, max(cnt - 1, 0)]) if cnt else 0
    items = []
    for _ in range(m):
        x = e.alloc(4 * dims + 8, 4)
        e.wbytes(x, r.randbytes(4 * dims + 8))
        e.w32(x + 4 * (dims - 1), lo + r.randrange(nb))
        items.append(x)

    def nxt(em, k):
        return items[k] if k < len(items) else 0

    def h41e290(em, res_):
        sz = em.arg32(0)
        n = min(sz, 0x4000) + 0x20
        p = em.alloc(n, 4)
        em.wbytes(p, r.randbytes(n))
        em.calllog.append(('alloc', sz))
        em.ret(eax=p, argbytes=0)

    def h634d10(em, res_):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', p, v, n))
        em.wbytes(p, bytes([v & 0xff]) * min(n, 0x4000))
        em.ret(eax=p, argbytes=0)

    def h634d22(em, res_):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d, s, n))
        em.wbytes(d, em.rbytes(s, min(n, 0x100)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x41e290, h41e290)
    e.hook(0x634d10, h634d10)
    e.hook(0x634d22, h634d22)
    hook_rec(c, 0x634273, 2, pop=0)
    dstbuf = e.alloc(0x40, 4)
    e.wbytes(dstbuf, r.randbytes(0x40))
    def s540(em, k):
        o = em.reg('ecx')
        em.w32(o + 4, r.getrandbits(32))
        em.w32(o + 8, r.getrandbits(32))
    hook_rec(c, 0x4cd540, 1, this=True, pop=4, ret=dstbuf, side=s540)
    hook_rec(c, 0x4cdd40, 0, this=True, ret=lambda em, k: cnt if r.random() < 0.7 else r.getrandbits(32))
    hook_rec(c, 0x4cd300, 1, this=True, pop=4)
    logger = obj(c, 0x40, {0x24: pystub(c, 2, pop=0)})
    e.w32(0x700390, logger)
    me = obj(c, 0x40, {0x54: pystub(c, 1, this=True, stackmark=(0,)), 0x74: pystub(c, 1, this=True, stackmark=(0,), ret=nxt),
                       0xc: pystub(c, 0, this=True)})
    e.w32(me + 0xc, r.choice([0, 1, 5, 0x80000003, r.getrandbits(32)]))
    e.w32(me + 0x14, cnt)
    e.w32(me + 0x18, dims)
    e.w32(me + 0x1c, lo)
    e.w32(me + 0x20, hi)
    return [me]


S(0x4cf690, 'GUESS rebuild hash container', 'thiscall', None, ret=None, gen=_g4cf690, note='batch38025')
