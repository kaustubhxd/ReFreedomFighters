"""specs_s66049.py - cascade s4 batch 66049: 0x530940 (/GS-protected: walk a glyph table backwards through stack cursor calls)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g530940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    ax = r.choice([0, 1, 3, 8, 0x10, 0x30010, 0x101, 0x1f0, 0x2005])
    idxs = [r.choice([0, 1, 2, 3]) for _ in range(8)]
    cnt = {'k': 0}

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def h1810(em, rr):                    # 0x531810 (ecx = &s, a) ret 4
        s = em.reg('ecx')
        em.calllog.append(('h1810', em.arg32(0), dw(em, s, 3)))
        em.ret(eax=ax, argbytes=4)

    def h1740(em, rr):                    # 0x531740 (ecx = &s, a, k) ret 8; sets s.idx
        k = cnt['k']
        cnt['k'] += 1
        s = em.reg('ecx')
        em.calllog.append(('h1740', em.arg32(0), em.arg32(1), dw(em, s, 3)))
        em.wbytes(s + 0x16, idxs[min(k, 7)].to_bytes(2, 'little'))
        em.ret(eax=0, argbytes=8)
    e.hook(0x531810, h1810)
    e.hook(0x531740, h1740)
    t = e.alloc(0x100, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x100)))
    tab5a = e.alloc(0x40, 8)       # idx * 12 -> word w
    tab54 = e.alloc(0x80, 8)       # idx * 0x16 -> word w
    for i in range(4):
        e.wbytes(tab5a + 12 * i, r.choice([0, 1, 2, 3]).to_bytes(2, 'little'))
        e.wbytes(tab54 + 0x16 * i, r.choice([0, 1, 2, 3]).to_bytes(2, 'little'))
    tab78 = e.alloc(0x40, 8)
    for i in range(4):
        e.wbytes(tab78 + 10 * i + 4, r.choice([0, 3, 7, 0x20]).to_bytes(2, 'little'))
    buf = e.alloc(0x400, 8)
    e.wbytes(buf, bytes(r.randrange(0, 0x30) for _ in range(0x400)))
    e.w32(t + 0x38, r.choice([0, 1, 2, 3, 5, 9]))
    e.w32(t + 0x5a, tab5a)
    e.w32(t + 0x54, tab54)
    e.w32(t + 0x78, tab78)
    e.w32(t + 0x82, buf)
    return [t, r.getrandbits(32), r.choice([0, 1, 2, 3, 4, 0xfffffffe])]


S(0x530940, 'GUESS /GS walk a glyph table backwards through cursor calls', 'thiscall', None, ret='eax', gen=_g530940, note='batch66049')
