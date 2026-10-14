"""specs_s38038.py - cascade s8 batch 38038 (zlib deflateInit2_). Parameters are drawn mostly valid (level -1..9, method 8, windowBits +-8..15, memLevel 1..9, strategy 0..2) with each one
occasionally invalid; version string first byte equals the exe's ZLIB_VERSION[0] (read through the pointer at 0x6f4478) 85% of the time; stream_size 0x38 90%; strm null 4%. The stream's zalloc
(strm+0x20) is either null (then the default 0x631810 is hooked) or a custom cdecl Python allocator; the allocator zero-fills what it hands out and fails (returns 0) at a random call index about
20% of the time. 0x62ee40 (deflateEnd) / 0x62f140 (deflateReset) are hooks (the latter returns a random value); the message pointer at 0x6f44d0 is a data word."""
import random
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g62ef10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    failat = r.choice([None, None, None, None, 0, 1, 2, 3, 4, 5])
    cnt = [0]

    def alloc(em, res_):
        op, items, size = em.arg32(0), em.arg32(1), em.arg32(2)
        k = cnt[0]
        cnt[0] += 1
        em.calllog.append(('zalloc', op, items, size))
        n = min((items * size) & 0xffffffff, 0x20000)
        if failat is not None and k == failat:
            p = 0
        else:
            p = em.alloc(n + 0x20, 4)
            em.wbytes(p, r.randbytes(n + 0x20))
        em.ret(eax=p, argbytes=0)
    stub = e.stub_fn('zalloc', alloc)
    e.hook(0x631810, alloc)
    hook_rec(c, 0x62ee40, 1, pop=4)
    hook_rec(c, 0x62f140, 1, pop=4, ret=lambda em, k: r.choice([0, 0, 0xfffffffe, r.getrandbits(32)]))
    e.w32(0x6f44d0, r.getrandbits(32))
    strm = rnd(c, 0x40)
    e.w32(strm + 0x20, stub if r.random() < 0.5 else 0)
    e.w32(strm + 0x24, r.choice([0, stub]))
    e.w32(strm + 0x28, r.getrandbits(32))
    e.w32(strm + 0x18, r.getrandbits(32))
    ver_first = e.rbytes(e.r32(0x6f4478), 1)
    vb = ver_first if r.random() < 0.85 else bytes([r.randrange(1, 255)])
    ver = e.alloc(8, 1)
    e.wbytes(ver, vb + b'.2.3\0')
    if r.random() < 0.04:
        strm_arg = 0
    else:
        strm_arg = strm
    level = r.choice([-1, 0, 1, 6, 9, 9, 10, -5, 4])
    method = 8 if r.random() < 0.93 else r.choice([0, 7, 9])
    wb = r.choice([15, 15, 9, 8, 12, -15, -9, -8, 16, 7, -7, 0, -16])
    ml = r.choice([8, 9, 1, 5, 0, 10])
    strat = r.choice([0, 1, 2, 3])
    ssize = 0x38 if r.random() < 0.9 else 0x37
    return [strm_arg, level & 0xffffffff, method, wb & 0xffffffff, ml, strat, ver if r.random() > 0.03 else 0, ssize]


S(0x62ef10, 'GUESS zlib deflateInit2_', 'stdcall', None, ret='eax', gen=_g62ef10, note='batch38038')
