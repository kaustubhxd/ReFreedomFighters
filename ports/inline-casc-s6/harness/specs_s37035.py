"""specs_s37035.py - cascade s6 batch 37035: 0x54e1f0. this has packed (unaligned) fields: +0x2e idx (0..1), +0x1e[]/+0x26[] marker/flag arrays, +0x47 block size, +0x5b last size,
+0x4f data base (spec buffer), +0x63 cursor, +0x37 count, +0x32/+0x57 bytes; vtable slot 8 (1 arg); 0x634d22 hooked as a real copy; logger at 0x700390."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g54e1f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        n = {0x6a3f04: 2, 0x6a3f38: 4}.get(em.arg32(1), 2)
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(n))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x400:
            em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    buf = rnd(c, 0x400, 1)
    dst = rnd(c, 0x400, 1)
    unit = r.choice([0x20, 0x40, 0x50])
    lastsz = r.choice([0x10, unit, 0x30])
    me = obj(c, 0x80, {0x8: pystub(c, 1, this=True)})
    idx = r.choice([0, 1])
    _w(c, me + 0x2e, idx)
    _w(c, me + 0x32, r.choice([0, 0, 0, 1]), 1)
    _w(c, me + 0x37, r.choice([1, 2, 3]))
    _w(c, me + 0x47, unit)
    _w(c, me + 0x4f, buf)
    _w(c, me + 0x57, r.choice([0, 1]), 1)
    _w(c, me + 0x5b, lastsz)
    fl = r.choice([0, 1])
    for i in range(2):
        _w(c, me + 0x1e + 4 * i, 0 if r.random() < 0.15 else 0x1234 + i)
        _w(c, me + 0x26 + 4 * i, fl ^ (i & 0) if True else 0)
    size = lastsz if (fl & 1) else unit
    cur = r.randint(0, size)
    _w(c, me + 0x63, cur)
    rem = size - cur
    want = r.choice([rem - 1, rem, rem, rem + 1, 0, 5, rem + 0x20, 1])
    out_r = rnd(c, 8)
    out_p = rnd(c, 8) if r.random() < 0.7 else 0
    return [me, dst if r.random() < 0.8 else 0, want & 0xffffffff, out_r, out_p]


S(0x54e1f0, 'GUESS read from block queue', 'thiscall', None, ret='eax', gen=_g54e1f0, note='batch37035')
