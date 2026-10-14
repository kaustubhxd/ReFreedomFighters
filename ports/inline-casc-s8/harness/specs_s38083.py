"""specs_s38083.py - cascade s8 batch 38083 (zlib deflate). stdcall(strm, flush). strm: next_in +0, avail_in +4, next_out +0xc (null 5%), avail_out +0x10, msg +0x18, state +0x1c (null 3%), adler +0x30;
state s: status +4 (0x2a mostly, 0x71, 0x29a), pending +0x14, wrap +0x18, last_flush +0x20, w_bits +0x28, head +0x3c / hash_size +0x44, preset-dict flag +0x64, lookahead +0x6c, level +0x7c (0..9). flush 0..5.
The strategy table in the exe image (0x6c0250, 12 bytes per level) is overwritten with logging stubs that return a random block state 0..4. flush_pending (0x62f340) logs and clears pending / avail_out at random;
putShortMSB / _tr_align / _tr_stored_block are recording hooks; memset 0x634d10 logs and clears. The two error-message globals (0x6f44c8 / 0x6f44d4) get distinct values."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g62ebc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6f44c8, 0x11110000 + r.getrandbits(8))
    e.w32(0x6f44d4, 0x22220000 + r.getrandbits(8))

    def strat(em, res_):
        v = r.choice([0, 1, 1, 2, 3, 3, 4])
        em.calllog.append(('strategy', em.arg32(0) != 0, em.arg32(1), v))
        em.ret(eax=v, argbytes=0)
    stub = e.stub_fn('strategy', strat)
    for lvl in range(10):
        e.w32(0x6c0250 + 12 * lvl, stub)

    def fp(em, res_):
        strm = em.arg32(0)
        s_ = em.r32(strm + 0x1c)
        em.calllog.append(('flush_pending', em.arg32(0) != 0, em.r32(s_ + 0x14), em.r32(strm + 0x10)))
        em.w32(s_ + 0x14, r.choice([0, 0, 3]))
        em.w32(strm + 0x10, r.choice([0, em.r32(strm + 0x10), 5]))
        em.ret(eax=0, argbytes=0)
    e.hook(0x62f340, fp)
    hook_rec(c, 0x62f5a0, 2, pop=0)
    hook_rec(c, 0x62fc30, 1, pop=0)
    hook_rec(c, 0x630070, 4, pop=0)

    def ms(em, res_):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', p, v, n))
        em.wbytes(p, bytes(n))
        em.ret(eax=p, argbytes=0)
    e.hook(0x634d10, ms)
    head = rnd(c, 0x80)
    s = rnd(c, 0x90)
    strm = rnd(c, 0x40)
    e.w32(strm + 0, r.choice([0, rnd(c, 0x10), rnd(c, 0x10)]))
    e.w32(strm + 4, r.choice([0, 0, 5, 7]))
    e.w32(strm + 0xc, 0 if r.random() < 0.05 else rnd(c, 0x20))
    e.w32(strm + 0x10, r.choice([0, 0x10, 0x100]))
    e.w32(strm + 0x1c, 0 if r.random() < 0.03 else s)
    e.w32(strm + 0x30, r.getrandbits(32))
    e.w32(s + 4, r.choice([0x2a, 0x2a, 0x2a, 0x71, 0x71, 0x29a]))
    e.w32(s + 0x14, r.choice([0, 0, 4]))
    e.w32(s + 0x18, r.choice([0, 1, 2]))
    e.w32(s + 0x20, r.choice([-1 & 0xffffffff, 0, 1, 2, 3, 4]))
    e.w32(s + 0x28, r.choice([9, 15, 12]))
    e.w32(s + 0x3c, head)
    e.w32(s + 0x44, r.choice([2, 5, 16]))
    e.w32(s + 0x64, r.choice([0, 0, 1]))
    e.w32(s + 0x6c, r.choice([0, 0, 3]))
    e.w32(s + 0x7c, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
    return [strm if r.random() > 0.03 else 0, r.choice([0, 1, 2, 3, 4, 4, 4, 5])]


S(0x62ebc0, 'GUESS zlib deflate', 'stdcall', None, ret='eax', gen=_g62ebc0, note='batch38083')
