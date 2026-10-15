"""specs_s46005.py - cascade t7 batch 46005: 0x62e730 zlib deflate_slow(s, flush), cdecl. Hooked: 0x62f1e0 fill_window (adds to lookahead on its first calls),
0x62f430 longest_match (returns <= lookahead, sets match_start), 0x62fe10 _tr_flush_block (resets last_lit, sets the pending count), 0x634d22 memcpy.
The deflate state lives in a random-filled block with real window/head/prev/l_buf/d_buf arrays; the length/dist code tables are the exe's own."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def g62e730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    wsize = r.choice([0x200, 0x400, 0x800, 0x2000])
    hbits = r.choice([8, 9, 10])
    hsize = 1 << hbits
    lit = r.choice([3, 4, 6, 16, 64])
    s = rnd(c, 0x16c0)
    win = c.emu.alloc(0x4000, 4)
    e.wbytes(win, r.randbytes(0x4000))
    head = c.emu.alloc(hsize * 2 + 8, 4)
    prev = c.emu.alloc(wsize * 2 + 8, 4)
    lbuf = rnd(c, lit + 8)
    dbuf = rnd(c, lit * 2 + 8)
    strstart = r.randrange(1, min(wsize, 0x1800)) if r.random() < 0.7 else r.randrange(min(wsize, 0x1800) // 2, min(wsize, 0x1800))
    look = r.choice([0, 1, 2, 3, 5, 8, 0x20, 0x60, 0x105, 0x106, 0x107, 0x110])
    ml = min(r.choice([2, 2, 2, 3, 4, 5, 10, 40]), look)
    hb = bytearray()
    for i in range(hsize):
        hb += (0 if r.random() < 0.3 else r.randrange(0, strstart + 1)).to_bytes(2, 'little')
    e.wbytes(head, bytes(hb))
    e.wbytes(prev, r.randbytes(wsize * 2))
    W = lambda off, v: e.w32(s + off, v & 0xffffffff)
    # strm + state
    strm = rnd(c, 0x40)
    st = rnd(c, 0x40)
    e.w32(strm + 0x1c, st)
    e.w32(strm + 0xc, rnd(c, 0x40))
    e.w32(strm + 0x10, r.choice([0, 3, 5, 40, 0x1000]))
    e.w32(st + 8, rnd(c, 0x40))
    e.w32(st + 0x10, rnd(c, 0x40))
    e.w32(st + 0x14, r.choice([0, 4, 20]))
    W(0, strm)
    W(0x24, wsize)
    W(0x2c, wsize - 1)
    W(0x30, win)
    W(0x38, prev)
    W(0x3c, head)
    W(0x40, r.getrandbits(32))
    W(0x4c, hsize - 1)
    W(0x50, (hbits + 2) // 3)
    W(0x54, r.choice([0xffffffff - r.randrange(0, 5), r.randrange(0, strstart + 1), strstart]))
    W(0x58, ml)
    W(0x5c, r.getrandbits(10))
    W(0x60, r.choice([0, 1]))
    W(0x64, strstart)
    W(0x68, r.randrange(0, strstart + 1))
    W(0x6c, look)
    W(0x70, r.getrandbits(8))
    W(0x74, r.getrandbits(8))
    W(0x78, r.choice([0, 4, 16, 32, 258]))
    W(0x80, r.choice([0, 0, 0, 1, 2]))
    W(0x1690, lbuf)
    W(0x1694, lit)
    W(0x1698, r.randrange(0, lit - 1))
    W(0x169c, dbuf)

    addl = [r.choice([0, 0, 4, 0x20, 0x60, r.randrange(0, 0x120)]) for _ in range(4)]

    def sfill(em, k):
        if k < 4:
            sp = em.arg32(0)
            em.w32(sp + 0x6c, (em.r32(sp + 0x6c) + addl[k]) & 0xffffffff)
    hook_rec(c, 0x62f1e0, 1, pop=0, side=sfill)
    mls = [r.choice([0, 2, 3, 3, 3, 4, 5, 6, 20, 258]) for _ in range(40)]
    mst = [r.getrandbits(10) for _ in range(40)]

    def lm_ret(em, k):
        la = em.r32(em.arg32(0) + 0x6c)
        return min(mls[k % 40], la)

    def lm_side(em, k):
        em.w32(em.arg32(0) + 0x68, mst[k % 40] % max(1, em.r32(em.arg32(0) + 0x64) + 1))
    hook_rec(c, 0x62f430, 2, pop=0, ret=lm_ret, side=lm_side)
    pend = [r.choice([0, 0, 3, 8, 20]) for _ in range(20)]

    def sfb(em, k):
        sp = em.arg32(0)
        em.w32(sp + 0x1698, 0)
        stt = em.r32(em.r32(sp) + 0x1c)
        em.w32(stt + 0x14, pend[k % 20])
    hook_rec(c, 0x62fe10, 4, pop=0, side=sfb)
    hook_rec(c, 0x634d22, 3, pop=0)
    return [s, r.choice([0, 0, 1, 2, 4, 4])]


S(0x62e730, 'GUESS deflate_slow', 'cdecl', None, ret='eax', gen=g62e730, note='batch46005')
