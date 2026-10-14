"""specs_s37025.py - cascade s6 batch 37025: 0x410560 (page reader, cdecl(ctx, out)). 0x410340 hooked (records the 4-dword page descriptor and stores either the page's
original checksum word or a different one at page+0x16); 0x634d3a (memchr thunk) hooked to return a position inside the buffer or null."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g410560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    sig = e.r32(0x6f282c)
    buf = rnd(c, 0x140, 1)
    pos = r.choice([0, 0, 3, 8])
    size = r.choice([0x10, 0x1a, 0x1b, 0x1c, 0x20, 0x30, 0x40, 0x60, 0x100]) + pos
    page = buf + pos
    if r.random() < 0.8:
        e.w32(page, sig)
    nseg = r.choice([0, 1, 2, 3, 5, 9, 0x20, r.getrandbits(8)])
    e.wbytes(page + 0x1a, bytes([nseg]))
    for i in range(min(nseg, 0x40)):
        e.wbytes(page + 0x1b + i, bytes([r.choice([0, 1, 2, 5, 0x10])]))
    v0 = r.getrandbits(32)
    e.w32(page + 0x16, v0)
    good = r.random() < 0.6

    def crc(em, k):
        p0 = em.r32(em.arg32(0))
        em.w32(p0 + 0x16, v0 if good else r.getrandbits(32))
    hook_rec(c, 0x410340, 1, pop=0, deref={0: 4}, side=crc)
    hook_rec(c, 0x634d3a, 3, pop=0, ret=lambda em, k: 0 if r.random() < 0.3 else (page + 1 + r.randrange(0, max(1, size - pos - 1))))
    ctx = rnd(c, 0x20)
    e.w32(ctx, buf)
    e.w32(ctx + 8, size)
    e.w32(ctx + 0xc, pos)
    if r.random() < 0.3:
        e.w32(ctx + 0x14, r.choice([0x1b, 0x1c, 0x20, 0x5]))
        e.w32(ctx + 0x18, r.choice([0, 3, 0x10, 0x30]))
    else:
        e.w32(ctx + 0x14, 0)
        e.w32(ctx + 0x18, r.choice([0, 0, 7]))
    out = rnd(c, 0x10) if r.random() < 0.7 else 0
    return [ctx, out]


S(0x410560, 'GUESS Ogg-style page reader', 'cdecl', None, ret='eax', gen=_g410560, note='batch37025')
