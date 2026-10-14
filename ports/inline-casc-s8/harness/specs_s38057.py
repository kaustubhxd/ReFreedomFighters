"""specs_s38057.py - cascade s8 batch 38057. The destination texture (this) reports a size (slots 0x1c / 0x20: 0..40, so the level count loop and the odd sizes run) and records its setters (0x74 / 0x78 / 0x5c / 0x70 /
0x6c, every call logged in order); the source image (slot 0x1c / 0x20 sizes, slot 0x34 mip count 0..6 matching the level count about half of the time, slot 0x10 = custom 7-arg reader that fills the buffer
with random bytes). genMips is zero 35% of the time. The allocator 0x41e290 hands out zero-filled blocks (size logged), 0x634273 is logged."""
from pilot import S
from recruits_util import obj, clear_hooks, hook_rec, pystub


def _g637a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(name, n):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(i) for i in range(n)))
            em.ret(eax=0, argbytes=4 * n)
        return e.stub_fn(name, h)
    w = r.choice([0, 1, 2, 3, 5, 8, 13, 16, 31, 40])
    hh = r.choice([0, 1, 2, 3, 5, 8, 13, 16, 31, 40])
    this = obj(c, 0x40, {0x1c: pystub(c, 0, this=True, ret=w), 0x20: pystub(c, 0, this=True, ret=hh),
                         0x74: lg('s74', 1), 0x78: lg('s78', 1), 0x5c: lg('s5c', 1), 0x70: lg('s70', 4), 0x6c: lg('s6c', 4)})
    gen = r.choice([0, 0, 1, 1, 1, 0x101])
    # expected level count for the mip-matching case
    lv = 1
    if gen & 0xff:
        a, b = w >> 1, hh
        while True:
            b >>= 1
            if a:
                lv += 1
                a >>= 1
                continue
            if not b:
                break
            lv += 1
    mips = lv if r.random() < 0.5 else r.choice([0, 1, 2, 3, 6])

    def rd(em, res_):
        buf, k = em.arg32(0), em.arg32(6)
        em.calllog.append(('s10', em.reg('ecx'), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5), k))
        n = min(em.arg32(3) * em.arg32(4) * 4, 0x4000)
        if n:
            em.wbytes(buf, bytes(r.getrandbits(8) for _ in range(n)))
        em.ret(eax=0, argbytes=28)
    src = obj(c, 0x40, {0x1c: pystub(c, 0, this=True, ret=r.choice([w, 7, 16])), 0x20: pystub(c, 0, this=True, ret=r.choice([hh, 9, 4])),
                        0x34: pystub(c, 0, this=True, ret=mips), 0x10: e.stub_fn('s10', rd)})

    def alloc(em, res_):
        sz = em.arg32(0)
        em.calllog.append(('alloc', sz))
        p = em.alloc(min(sz, 0x8000) + 0x20, 4)
        em.wbytes(p, bytes(min(sz, 0x8000) + 0x20))
        em.ret(eax=p, argbytes=0)
    e.hook(0x41e290, alloc)
    hook_rec(c, 0x634273, 2, pop=0)
    return [this, src, gen]


S(0x637a30, 'GUESS upload image to texture', 'thiscall', None, ret=None, gen=_g637a30, note='batch38057')
