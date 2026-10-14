"""specs_s38074.py - cascade s8 batch 38074 (zlib deflate_stored). cdecl(s, flush). s: strm +0, pending_buf_size +0xc, w_size +0x24, window +0x30, block_start +0x54 (signed), strstart +0x64, lookahead +0x6c.
strm: next_out +0xc, avail_out +0x10 (0..0x60), total_out +0x14, state +0x1c {pending_buf +8, pending_out +0x10, pending +0x14}. Hooks: 0x62f1e0 fill_window sets lookahead to a random value (0 often), 0x62fe10 logs
(buf, len, last) and sets state->pending to 0..0x20, 0x634d22 memcpy copies the bytes and logs the length."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g62e190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(em, res_):
        s = em.arg32(0)
        v = r.choice([0, 0, 0, 1, 2, 3, 0x40, 0x200, 0x1000])
        if r.random() < 0.4:   # land exactly on the w_size - 0x106 boundary of the second flush test
            bs = struct.unpack('<i', em.rbytes(s + 0x54, 4))[0]
            tgt = bs + em.r32(s + 0x24) - 0x106 + r.choice([-1, 0, 0, 1]) - em.r32(s + 0x64)
            if 1 < tgt < 0x4000:
                v = tgt
        em.calllog.append(('fill', s != 0, em.r32(s + 0x64), v))
        em.w32(s + 0x6c, v)
        em.ret(eax=0, argbytes=0)
    e.hook(0x62f1e0, fill)

    def fl(em, res_):
        s = em.arg32(0)
        em.calllog.append(('flush', em.arg32(1), em.arg32(2), em.arg32(3)))
        st = em.r32(em.r32(s) + 0x1c)
        em.w32(st + 0x14, r.choice([0, 0, 5, 0x10, r.randrange(0, 0x21)]))
        em.ret(eax=0, argbytes=0)
    e.hook(0x62fe10, fl)

    def mc(em, res_):
        d, sp, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', n))
        em.wbytes(d, em.rbytes(sp, n))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)
    outb = rnd(c, 0x200)
    pbuf = rnd(c, 0x800)
    state = rnd(c, 0x30)
    e.w32(state + 8, pbuf)
    e.w32(state + 0x10, pbuf + r.randrange(0, 8))
    e.w32(state + 0x14, r.choice([0, 3, 0x10]))
    strm = rnd(c, 0x30)
    e.w32(strm + 0xc, outb)
    e.w32(strm + 0x10, r.choice([0, 0x10, 0x30, 0x60, r.randrange(0, 0x61)]))
    e.w32(strm + 0x1c, state)
    s = rnd(c, 0x80)
    e.w32(s, strm)
    e.w32(s + 0xc, r.choice([0x20, 0x40, 0x100, 0x10005, 0xfff0, 0x300]))
    e.w32(s + 0x24, r.choice([0x200, 0x300, 0x8000]))
    e.w32(s + 0x30, rnd(c, 0x20))
    e.wbytes(s + 0x54, struct.pack('<i', r.choice([-1, 0, 5, 0x100, 0x180])))
    e.w32(s + 0x64, r.choice([0, 0, 0x10, 0x100, 0x1f0, 0x300]))
    e.w32(s + 0x6c, r.choice([0, 1, 2, 3, 0x30, 0x400]))
    return [s, r.choice([0, 1, 2, 4, 4])]


S(0x62e190, 'GUESS deflate_stored', 'cdecl', None, ret='eax', gen=_g62e190, note='batch38074')
