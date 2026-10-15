"""specs_s66023.py - cascade s4 batch 66023: 0x42aee0 / 0x42afb0 (copy a range of byte vectors forward / backward)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, stub_memmove


def _build(c, same):
    r = c.rng
    e = c.emu
    stub_memmove(c)

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', n))
        if n:
            em.wbytes(d, bytes(em.rbytes(s_, n)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)
    hook_rec(c, 0x5f2c60, 2, this=True)
    n = r.choice([0, 1, 2, 3, 4])
    cnt = n
    src = e.alloc(12 * max(cnt, 1) + 12, 8)
    dst = src if same else e.alloc(12 * max(cnt, 1) + 12, 8)
    for arr, isdst in ((src, False), (dst, True)):
        if arr == dst and arr == src and isdst:
            continue
        for i in range(cnt):
            buf = e.alloc(0x50, 8)
            e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x50)))
            ln = r.choice([0, 1, 3, 8, 0x10])
            e.w32(arr + 12 * i, buf)
            e.w32(arr + 12 * i + 4, buf + ln)
            e.w32(arr + 12 * i + 8, buf + 0x40)
    return n, cnt, src, dst


def _g42aee0(c):
    clear_hooks(c)
    n, cnt, src, dst = _build(c, c.rng.random() < 0.15)
    if c.rng.random() < 0.1:
        return [src + 12 * cnt, src, dst, 1, 2]
    return [src, src + 12 * cnt, dst, 1, 2]


def _g42afb0(c):
    clear_hooks(c)
    n, cnt, src, dst = _build(c, c.rng.random() < 0.15)
    if c.rng.random() < 0.1:
        return [src + 12 * cnt, src, dst + 12 * cnt, 1, 2]
    return [src, src + 12 * cnt, dst + 12 * cnt, 1, 2]


S(0x42aee0, 'GUESS copy a range of byte vectors forward', 'fastcall', None, ret='eax', gen=_g42aee0, note='batch66023')
S(0x42afb0, 'GUESS copy a range of byte vectors backward', 'fastcall', None, ret='eax', gen=_g42afb0, note='batch66023')
