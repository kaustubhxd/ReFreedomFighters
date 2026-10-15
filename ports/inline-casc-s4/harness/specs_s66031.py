"""specs_s66031.py - cascade s4 batch 66031: 0x61ffb0 (allocate a tree node in a growing array and link it to its parent)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g61ffb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fail = {'alloc': r.random() < 0.08, 'realloc': r.random() < 0.08}

    def alloc(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(eax=0 if fail['alloc'] else e.alloc(max(n, 28 * 8), 8), argbytes=0)

    def realloc(em, rr):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('realloc', n))
        if fail['realloc']:
            em.ret(eax=0, argbytes=0)
            return
        q = e.alloc(max(n, 28 * 8), 8)
        old = n // 2
        em.wbytes(q, bytes(em.rbytes(p, old)))
        em.ret(eax=q, argbytes=0)
    ctx = e.alloc(0x280, 8)
    e.wbytes(ctx, bytes(r.getrandbits(8) for _ in range(0x280)))
    e.w32(ctx + 0xc, e.stub_fn('alloc', alloc))
    e.w32(ctx + 0x10, e.stub_fn('realloc', realloc))
    e.w32(ctx + 0x260, r.choice([0, 1, 4, 8]))
    cap = r.choice([0, 1, 2, 4])
    cnt = r.choice([0, 1, 2, 3, 4, 5])
    cnt = min(cnt, cap)
    noarr = r.random() < 0.2
    if noarr:
        cnt = cap
    e.w32(ctx + 0x1f0, cap)
    e.w32(ctx + 0x1f4, cnt)
    arrcap = max(cap, cnt, 1)
    if noarr:
        e.w32(ctx + 0x1e8, 0)
    else:
        arr = e.alloc(28 * (arrcap * 2 + 2), 8)
        for i in range(arrcap):
            e.w32(arr + 28 * i + 0x10, r.choice([0, 0, 1, 2]))
            e.w32(arr + 28 * i + 0x14, r.choice([0, 0, 3]))
        e.w32(ctx + 0x1e8, arr)
    depth = r.choice([0, 0, 1, 2])
    e.w32(ctx + 0x1f8, depth)
    if r.random() < 0.15:
        e.w32(ctx + 0x1fc, 0)
    else:
        st = e.alloc(0x40, 8)
        for i in range(8):
            e.w32(st + 4 * i, r.choice([0, 1, 2]))
        e.w32(ctx + 0x1fc, st)
    return [ctx]


S(0x61ffb0, 'GUESS allocate a tree node in a growing array', 'cdecl', None, ret='eax', gen=_g61ffb0, note='batch66031')
