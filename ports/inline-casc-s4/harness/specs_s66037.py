"""specs_s66037.py - cascade s4 batch 66037: 0x496530 (visit the flagged elements of an element array)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g496530(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 3, 7, 8, 9, 16, 20])
    extra = r.choice([0, 0, 5, 0x6f])
    arr = e.alloc(0x70 * max(n, 1) + 0x400, 8)
    for i in range(n):
        e.w32(arr + 0x70 * i + 0x3c, r.choice([0, 0, 0x4000000, 0x8000000, 0xc000000, 0x10000000]))
    holder = e.alloc(0x20, 8)
    e.w32(holder + 4, arr)
    e.w32(holder + 0xc, 0x70 * n + extra)
    t = e.alloc(0x30, 8)
    e.w32(t + 0x14, holder)
    clearmask = bytes(r.choice([0xff, 0xff, 0xf0, 0x0f, 0x00]) for _ in range(4))

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(em.arg32(0), 8), 8), argbytes=0)

    def ms(em, rr):
        d, v, nn = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', v, nn))
        if nn:
            em.wbytes(d, bytes([v & 0xff]) * nn)
        em.ret(eax=d, argbytes=0)

    def sb(em, rr):                       # 0x496380 (this, bits) ret 4: clears bits
        bits = em.arg32(0)
        em.calllog.append(('s496380', em.reg('ecx'), bytes(em.rbytes(bits, 4))))
        for i in range(4):
            em.wbytes(bits + i, bytes([em.rbytes(bits + i, 1)[0] & clearmask[i]]))
        em.ret(eax=0, argbytes=4)
    e.hook(0x41e290, alloc)
    e.hook(0x634d10, ms)
    e.hook(0x496380, sb)
    hook_rec(c, 0x4d9430, 0, this=True)
    hook_rec(c, 0x4d9590, 1, pop=0)
    return [t]


S(0x496530, 'GUESS visit the flagged elements of an element array', 'thiscall', None, ret=None, gen=_g496530, note='batch66037')
