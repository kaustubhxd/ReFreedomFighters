"""specs_s38049.py - cascade s8 batch 38049. S: current chunk A (the running offset +0xc is a pointer just past the data written so far: cursor + 0..0x30) (+0), free chunk B (+4, null 25%), cursor (+0x10: 0, A + 8 or inside A's data), end (+8), running offset (+0xc, zero 10%), callbacks (+0x14 ->
{alloc, realloc} Python stubs that fail 10% of the time). The reader (src slot 0x3c, custom cdecl stub) reports got != want for the first 0..3 calls and logs its (src, want, offset word, end). 0x634d22
(memcpy) is a real-effect hook, 0x6206e0 a hook returning a random bool. Every allocator call is logged; the heap compare covers the chunk contents."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g620180(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = e.alloc(0x800, 4)
    e.wbytes(A, r.randbytes(0x800))
    asz = r.choice([0x40, 0x100, 0x200])
    e.w32(A, 0)
    e.w32(A + 4, asz)
    B = 0
    if r.random() < 0.75:
        B = e.alloc(0x800, 4)
        e.wbytes(B, r.randbytes(0x800))
        C = 0
        if r.random() < 0.4:
            C = e.alloc(0x800, 4)
            e.wbytes(C, r.randbytes(0x800))
            e.w32(C, 0)
            e.w32(C + 4, r.choice([0x10, 0x40, 0x100, 0x200]))
        e.w32(B, C)
        e.w32(B + 4, r.choice([0x10, 0x40, 0x100, 0x200]))
    k = r.random()
    if k < 0.15:
        cur = 0
    elif k < 0.45:
        cur = A + 8
    else:
        cur = A + 8 + r.randrange(0, 0x30)
    n = r.choice([0, 4, 0x20, 0x80, 0x200, -4, -0x10]) if (cur and B) else r.choice([0, 4, 0x20, 0x80, 0x200])
    end = (cur if cur else A + 8) + n
    me = e.alloc(0x40, 4)
    e.wbytes(me, r.randbytes(0x40))
    e.w32(me, A)
    e.w32(me + 4, B)
    e.w32(me + 8, end)
    e.w32(me + 0xc, 0 if (cur == 0 or r.random() < 0.1) else cur + r.choice([0, 0, 4, 0x10, 0x30]))
    e.w32(me + 0x10, cur)
    pf = r.choice([0.0, 0.1])
    cnt = [0]

    def alloc(em, res_):
        sz = em.arg32(0)
        em.calllog.append(('alloc', sz))
        if r.random() < pf:
            p = 0
        else:
            p = em.alloc(min(sz, 0x4000) + 0x20, 4)
            em.wbytes(p, r.randbytes(min(sz, 0x4000) + 0x20))
        em.ret(eax=p, argbytes=0)

    def realloc(em, res_):
        p0, sz = em.arg32(0), em.arg32(1)
        em.calllog.append(('realloc', p0, sz))
        if r.random() < pf:
            p = 0
        else:
            p = em.alloc(min(sz, 0x4000) + 0x20, 4)
            em.wbytes(p, em.rbytes(p0, min(sz, 0x800)) + r.randbytes(min(sz, 0x4000) + 0x20 - min(sz, 0x800)))
        em.ret(eax=p, argbytes=0)
    cbs = e.alloc(8, 4)
    e.w32(cbs, e.stub_fn('alloc', alloc))
    e.w32(cbs + 4, e.stub_fn('realloc', realloc))
    e.w32(me + 0x14, cbs)
    miss = r.choice([0, 1, 1, 2, 3])
    want = r.randrange(1, 0x100)

    def rd(em, res_):
        k2 = cnt[0]
        cnt[0] += 1
        got_p, w, off_p, endv = em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)
        em.calllog.append(('rd', em.arg32(0), w, em.r32(off_p), endv))
        em.w32(got_p, w if k2 >= miss else w + 1)
        em.ret(eax=0, argbytes=0)
    src = rnd(c, 0x50)
    e.w32(src + 0x3c, e.stub_fn('rd', rd))
    hook_rec(c, 0x6206e0, 1, pop=0, ret=lambda em, kk: r.choice([0, 1, 1]))

    def memcpy(em, res_):
        d, s2, nn = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d, s2, nn))
        em.wbytes(d, em.rbytes(s2, min(nn, 0x400)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, memcpy)
    return [me, src, r.getrandbits(32), want]


S(0x620180, 'GUESS refill chunked output buffer', 'cdecl', None, ret='eax', gen=_g620180, note='batch38049')
