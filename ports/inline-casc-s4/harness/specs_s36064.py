"""specs_s36064.py - cascade s4 batch 36064: 0x62fb30 (CRC-32 update), 0x6015c0 (find a named entry's value), 0x442c30 (read three flags from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g62fb30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 3, 7, 8, 9, 15, 16, 17, 33])
    buf = e.alloc(48, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(48)))
    return [r.choice([0, 0xffffffff, r.getrandbits(32)]), 0 if r.random() < 0.1 else buf + r.choice([0, 0, 1, 3]), n]


def _g6015c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    found = r.choice([-1, -1, 0, 1, 2, 4])
    cn = [0]

    def sc(em, res):
        k = cn[0]
        cn[0] += 1
        em.calllog.append(('cmp', em.arg32(0), em.arg32(1)))
        em.ret(eax=(0 if k == found else r.choice([-1, 1, 0x100])), argbytes=0)
    e.stub_import('_stricmp', sc)
    arr = e.alloc(4 * max(n, 1), 4)
    for i in range(n):
        rec = rnd(c, 0x20)
        e.w32(rec, r.choice([2, 2, 2, 0, 1, 3]))
        e.w32(rec + 0xc, rnd(c, 8))
        val = rnd(c, 8)
        e.w32(rec + 4, val)
        p1 = e.alloc(8, 4)
        e.w32(p1, rec)
        e.w32(arr + 4 * i, p1)
    d = rnd(c, 0x20)
    e.w32(d + 4, arr)
    e.w32(d + 0xc, n)
    return [d, rnd(c, 8)]


def _g442c30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43f900, 1, this=True)
    kinds = [r.choice([3, 3, 3, 2, 0, 1, 0x103]) for _ in range(5)]
    hook_rec(c, 0x4e1600, 0, this=True, ret=lambda em, k, _k=kinds: _k[min(k, 4)])
    vals = [r.choice([0, 1, 5, 0x100]) for _ in range(4)]
    cnt = [0]

    def side(em, k):
        em.w32(em.arg32(0), vals[min(cnt[0], 3)])
        cnt[0] += 1
    hook_rec(c, 0x4e11e0, 2, this=True, stackmark=(0,), side=side)
    hook_rec(c, 0x4e1b30, 0, this=True)
    d = obj(c, 0x30, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])), 0x304: pystub(c, 1, this=True),
                      0x300: pystub(c, 1, this=True), 0x2c4: pystub(c, 1, this=True)})
    return [d, rnd(c, 0x20)]


S(0x62fb30, 'GUESS CRC-32 update', 'stdcall', None, ret='eax', gen=_g62fb30, note='batch36064')
S(0x6015c0, "GUESS find a named entry's value", 'thiscall', None, ret='eax', gen=_g6015c0, note='batch36064')
S(0x442c30, 'GUESS read three flags from a stream', 'thiscall', None, ret=None, gen=_g442c30, note='batch36064')
