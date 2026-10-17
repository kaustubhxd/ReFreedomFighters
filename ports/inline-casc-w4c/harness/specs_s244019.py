"""specs_s244019.py - Sonnet-w4c batch 244019: colour-distance routines 0x63a390 / 0x63a460."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _s32(x):
    x &= 0xffffffff
    return x - (1 << 32) if x & 0x80000000 else x


def _common(c):
    r = c.rng
    em = c.emu
    bufvals = [r.randrange(0, 600) - 100 for _ in range(22)]
    c.bufvals = bufvals

    def fill(emu, k):
        emu.wbytes(emu.reg('edx'), b''.join((v & 0xffffffff).to_bytes(4, 'little') for v in bufvals))
    hook_rec(c, 0x6383a0, 2, ret=r.getrandbits(32), pop=8, this=True, deref={0: 3, 1: 3}, side=fill)
    a0 = rnd(c, 0x10)
    a1 = rnd(c, 0x10)
    for p in (a0, a1):
        for j in range(3):
            em.w32(p + 4 * j, r.choice([0, 1, 31, 32, 255, 0x80000000, 0xffffffff, r.getrandbits(32), r.randrange(0, 300)]))
    return a0, a1


def g63a390(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    a0, a1 = _common(c)
    rows = rnd(c, 4 * (4 * 16 + 4))
    for i in range(16 * 4 + 4):
        em.w32(rows + 4 * i, r.randrange(0, 500) if r.random() < 0.9 else r.getrandbits(32))
    sel = rnd(c, 64)
    for i in range(16):
        em.w32(sel + 4 * i, r.randrange(0, 4))
    idx = r.randrange(0, 4)
    sums = []
    t = 0
    for i in range(16):
        d = _s32(em.r32(rows + 4 * (idx + 4 * i)) - c.bufvals[idx + em.r32(sel + 4 * i) * 4])
        t = _s32(t + _s32(d * d))
        sums.append(t)
    limit = r.choice([0, 1000, 100000, 0x7fffffff, 0x80000000, r.randrange(0, 5000000), sums[r.randrange(0, 16)], sums[r.randrange(0, 16)] - 1, sums[r.randrange(0, 16)] + 1])
    return [r.choice([0, 1, 2, 0x100]), idx, a0, a1, rows, sel, limit & 0xffffffff]


def g63a460(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    a0, a1 = _common(c)
    rows = rnd(c, 16 * 16 + 16)
    for i in range(16):
        for j in range(3):
            em.w32(rows + 16 * i + 4 * j, r.randrange(0, 500) if r.random() < 0.9 else r.getrandbits(32))
        em.w32(rows + 16 * i + 12, r.choice([0, 0, 1, r.getrandbits(32)]))
    idx = r.randrange(0, 4)
    sums = []
    t = 0
    for i in range(16):
        v = em.r32(rows + 16 * i + 4 * idx)
        bv = c.bufvals
        if em.r32(rows + 16 * i + 12) == 0:
            d_ = _s32(v - bv[12 + idx])
            term = _s32(d_ * d_)
        else:
            m = 0x7fffffff
            sq = [_s32(_s32(v - bv[k * 4 + idx]) * _s32(v - bv[k * 4 + idx])) for k in range(4)]
            m = min([m] + sq)
            term = m
        t = _s32(t + term)
        sums.append(t)
    limit = r.choice([0, 1000, 100000, 0x7fffffff, 0x80000000, r.randrange(0, 5000000), sums[r.randrange(0, 16)], sums[r.randrange(0, 16)] - 1, sums[r.randrange(0, 16)] + 1])
    return [r.choice([0, 1, 2, 0x100]), idx, a0, a1, rows, limit & 0xffffffff]


S(0x63a390, 'GUESS colour distance against a selected row set', 'fastcall', None, ret='eax', gen=g63a390, note='batch244019')
S(0x63a460, 'GUESS colour distance, min of four candidates', 'fastcall', None, ret='eax', gen=g63a460, note='batch244019')
