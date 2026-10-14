"""specs_s38052.py - cascade s8 batch 38052. A std::string {begin, end, capacity end} with 0..8 characters and a NUL at the end, insert position anywhere in [begin, end] (including both ends), the inserted
range 0..8 bytes (empty 8%); capacity chosen so that the in-place tail >= n, the in-place tail < n and the reallocating cases all occur. The memmove import (0x676278) and memcpy (0x634d22) are logged
hooks with real overlap-safe copies, the allocator 0x6014a0 hands out zeroed blocks, 0x54f870 (free) is logged; the final string buffers are in the heap compare."""
import struct
from pilot import S
from recruits_util import clear_hooks


def _g430d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    size = r.randrange(0, 9)
    n = 0 if r.random() < 0.08 else r.randrange(1, 9)
    mode = r.choice(['room', 'tight', 'full'])
    if mode == 'room':
        free = n + 1 + r.randrange(0, 4)
    elif mode == 'tight':
        free = r.randrange(0, n + 1) if n else r.randrange(0, 3)
    else:
        free = n + 1
    cap = size + free
    buf = e.alloc(cap + 32, 4)
    e.wbytes(buf, bytes(r.choice(b'abcdefgh') for _ in range(cap + 32)))
    e.wbytes(buf + size, b'\0')
    src = e.alloc(n + 16, 4)
    e.wbytes(src, bytes(r.choice(b'WXYZ') for _ in range(n + 16)))
    me = e.alloc(16, 4)
    e.wbytes(me, struct.pack('<III', buf, buf + size, buf + cap) + bytes(4))
    pos = buf + r.randrange(0, size + 1)

    def memmove(em, res_):
        d, s2, k = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memmove', d, s2, k))
        if 0 < k < 0x1000:
            em.wbytes(d, em.rbytes(s2, k))
        em.ret(eax=d, argbytes=0)

    def memcpy(em, res_):
        d, s2, k = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d, s2, k))
        if 0 < k < 0x1000:
            em.wbytes(d, em.rbytes(s2, k))
        em.ret(eax=d, argbytes=0)

    def alloc(em, res_):
        k = em.arg32(0)
        em.calllog.append(('alloc', em.reg('ecx'), k))
        p = em.alloc(k + 0x20, 4)
        em.wbytes(p, bytes(k + 0x20))
        em.ret(eax=p, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.w32(0x676278, e.stub_fn('memmove', memmove))
    e.hook(0x634d22, memcpy)
    e.hook(0x6014a0, alloc)
    e.hook(0x54f870, free)
    return [me, pos, src, src + n]


S(0x430d10, 'GUESS std::string insert range', 'thiscall', None, ret=None, gen=_g430d10, note='batch38052')
