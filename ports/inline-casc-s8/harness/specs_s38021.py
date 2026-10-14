"""specs_s38021.py - cascade s8 batch 38021: 0x637be0. Width / height 0..16 (mostly 1..9, so odd sizes and the 1-wide / 1-high degenerate paths run), a random RGBA buffer with slack,
level small and this+0x10 equal to level + 1 about 15% of the time. The allocator 0x41e290 hands out a zero-filled block (its requested size is logged), 0x634273 is a recording hook;
slots 0x70 and 0x6c are recording stubs (the 0x6c stub records the produced image through the heap compare of the allocated block)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g637be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sizes = [0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 16]
    w, h = r.choice(sizes), r.choice(sizes)
    pix = e.alloc((w + 2) * (h + 2) * 4 + 64, 4)
    e.wbytes(pix, r.randbytes((w + 2) * (h + 2) * 4 + 64))

    def h41e290(em, res_):
        sz = em.arg32(0)
        p = em.alloc(min(sz, 0x8000) + 0x20, 4)
        em.wbytes(p, bytes(min(sz, 0x8000) + 0x20))
        em.calllog.append(('alloc', sz))
        em.ret(eax=p, argbytes=0)
    e.hook(0x41e290, h41e290)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x40, {0x70: pystub(c, 4, this=True), 0x6c: pystub(c, 4, this=True, deref={3: 4})})
    level = r.randrange(0, 5)
    e.w32(me + 0x10, (level + 1) if r.random() < 0.15 else r.randrange(0, 8))
    return [me, level, w, h, pix]


S(0x637be0, 'GUESS build next mip level', 'thiscall', None, ret=None, gen=_g637be0, note='batch38021')
