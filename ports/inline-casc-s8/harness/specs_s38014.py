"""specs_s38014.py - cascade s8 batch 38014: 0x405240. CRT malloc / calloc / free (0x634d58 / 0x634df4 / 0x634d52) are logging Python hooks handing out zeroed heap blocks (with slack
so random codes cannot run off the block); 0x4050f0 returns a spec array of random codes (or 0, 6%), 0x405090 returns a small count-dependent value (sometimes below 5 after -4
so the clamp runs). Config: n symbols (1..12, sometimes 0 or negative), lengths 0..6."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g405240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 2, 3, 4, 5, 6, 8, 12, 12, 0, 0xffffffff])
    nn = n if n < 0x80000000 else 0
    lens = e.alloc(4 * max(nn, 1) + 8, 4)
    codes = e.alloc(4 * max(nn, 1) + 8, 4)
    maxlen = r.choice([2, 3, 6])
    e.wbytes(lens, b''.join(struct.pack('<I', r.choice([0, 1, 2, 3, 4, 5, 6][:maxlen + 1]) if r.random() < 0.9 else r.randrange(1, 4)) for _ in range(max(nn, 1) + 2)))
    e.wbytes(codes, b''.join(struct.pack('<I', r.getrandbits(32)) for _ in range(max(nn, 1) + 2)))
    L = rnd(c, 0x10)
    e.w32(L + 4, nn)
    e.w32(L + 8, lens)
    cfg = rnd(c, 0x10)
    e.w32(cfg + 4, n)
    e.w32(cfg + 8, L)
    nocodes = r.random() < 0.06
    kk = r.choice([3, 4, 6, 8, 9, 10])
    zero = lambda p, k: e.wbytes(p, bytes(k))

    def h_malloc(em, res_):
        sz = em.arg32(0)
        p = em.alloc(min(sz, 0x20000) + 0x400, 4)
        zero(p, min(sz, 0x20000) + 0x400)
        em.calllog.append(('malloc', sz))
        em.ret(eax=p, argbytes=0)

    def h_calloc(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sz = min((a * b) & 0xffffffff, 0x20000)
        p = em.alloc(sz + 0x400, 4)
        zero(p, sz + 0x400)
        em.calllog.append(('calloc', a, b))
        em.ret(eax=p, argbytes=0)

    def h_free(em, res_):
        em.calllog.append(('free', em.arg32(0)))
        em.ret(eax=0, argbytes=0)

    def h_codes(em, res_):
        em.calllog.append(('codes', em.arg32(0), em.arg32(1)))
        em.ret(eax=0 if nocodes else codes, argbytes=0)

    def h_log(em, res_):
        em.calllog.append(('log2', em.arg32(0)))
        em.ret(eax=kk, argbytes=0)
    e.hook(0x634d58, h_malloc)
    e.hook(0x634df4, h_calloc)
    e.hook(0x634d52, h_free)
    e.hook(0x4050f0, h_codes)
    e.hook(0x405090, h_log)
    return [cfg]


S(0x405240, 'GUESS build decode tree and lookup table', 'cdecl', None, ret='eax', gen=_g405240, note='batch38014')
