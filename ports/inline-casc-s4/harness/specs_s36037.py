"""specs_s36037.py - cascade s4 batch 36037: 0x427250 (file-time via GetFileTime), 0x4d7170 (packed date/time less-than), 0x502a00 (typed value to text send), 0x5c4c00 (read counts and build entries), 0x5db910 (copy a list and header fields)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab


def _g427250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def gft(em, res):
        em.calllog.append(('GetFileTime', em.arg32(0), em.arg32(3)))
        em.ret(eax=r.choice([0, 1, 0x100, 5]), argbytes=16)
    e.stub_import('GetFileTime', gft)
    o = obj(c, 0x20, {0x18: pystub(c, 2, this=True, ret=r.choice([0, 1, 0x100, 1]))})
    s = obj(c, 0x20, {0x130: pystub(c, 1, this=True, ret=r.getrandbits(32)),
                      0x70: pystub(c, 1, this=True, ret=o if r.random() < 0.7 else 0),
                      8: pystub(c, 1, this=True, ret=0 if r.random() < 0.2 else r.getrandbits(32) | 1),
                      0x1c: pystub(c, 1, this=True)})
    return [s, r.getrandbits(32), r.getrandbits(32), r.choice([0, 0, 1, 0x100, 0x10000, r.getrandbits(32)])]


def _g4d7170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = rnd(c, 0x10)
    a = rnd(c, 0x10)
    # equal prefixes of the packed fields so every comparison level is reached
    f8 = r.getrandbits(16)
    g8 = f8
    lvl = r.randint(0, 8)
    def tweak(v, lo, hi, w):
        mask = ((1 << (hi - lo)) - 1) << lo
        nv = (v & ~mask) | ((r.getrandbits(hi - lo)) << lo)
        return nv & 0xffff
    if lvl == 0:
        g8 = tweak(f8, 9, 16, 0)
    elif lvl == 1:
        g8 = tweak(f8, 5, 9, 0)
    elif lvl == 2:
        g8 = tweak(f8, 0, 5, 0)
    f6 = r.getrandbits(16)
    g6 = f6
    if lvl == 3:
        g6 = tweak(f6, 11, 16, 0)
    elif lvl == 4:
        g6 = tweak(f6, 5, 11, 0)
    elif lvl == 5:
        g6 = tweak(f6, 0, 5, 0)
    if lvl == 7:
        g8 = f8 ^ (1 << r.randint(0, 15))
    if lvl == 8:
        g6 = f6 ^ (1 << r.randint(0, 15))
    if lvl >= 3 and lvl != 7:
        g8 = f8
    e.wbytes(t + 8, f8.to_bytes(2, 'little'))
    e.wbytes(a + 8, g8.to_bytes(2, 'little'))
    e.wbytes(t + 6, f6.to_bytes(2, 'little'))
    e.wbytes(a + 6, g6.to_bytes(2, 'little'))
    return [t, a]


def _g502a00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 5, 0xff])
    rec1 = rnd(c, 0x10)
    e.wbytes(rec1 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec1, inner if typ == 4 else r.getrandbits(32))
    rec2 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rec1 if k == 0 else rec2)
    w = obj(c, 0x20, {0x12c: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, deref={4: -4}, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    s = rnd(c, 0x20)
    e.w32(s + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [s, p]


def _g5c4c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 6, 9, 0xffffffff, 0x80000000])
    seq = [r.getrandbits(32), n]
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: seq[min(k, 1)])
    pat = bytes(r.getrandbits(8) for _ in range(12))
    hook_rec(c, 0x4e6180, 1, this=True, side=lambda em, k: em.wbytes(em.arg32(0), pat))

    def alloc(em, rr):
        sz = em.arg32(0)
        em.calllog.append(('malloc', sz))
        em.ret(eax=0 if sz > 0x1000 else rnd(c, max(sz, 16)), argbytes=0)
    e.hook(0x41e290, alloc)
    l = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    ob = rnd(c, 0x30)
    e.w32(ob + 0x18, l)
    s = rnd(c, 0xa0)
    e.w32(s + 0x44, ob)
    rr = rnd(c, 0x20)
    return [s, r.getrandbits(32), rr]


def _g5db910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    src = rnd(c, 0xa8)
    d = rnd(c, 0xa8)
    if r.random() < 0.85:
        elems = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3]))]
        e.w32(src + 0x48, reftab(c, elems))
    else:
        e.w32(src + 0x48, 0)
    e.w32(d + 0x48, obj(c, 0x20, {4: pystub(c, 1, this=True)}))
    e.w32(src + 0x4c, r.choice([0, 1, 1, 0, 2, 3, r.getrandbits(32)]))
    return [d, src]


S(0x427250, 'GUESS file time through GetFileTime', 'thiscall', None, ret='al', gen=_g427250, note='batch36037')
S(0x4d7170, 'GUESS packed date/time less-than', 'thiscall', None, ret='al', gen=_g4d7170, note='batch36037')
S(0x502a00, 'GUESS typed value to text send', 'thiscall', None, ret=None, gen=_g502a00, note='batch36037')
S(0x5c4c00, 'GUESS read counts and build entries', 'thiscall', None, ret=None, gen=_g5c4c00, note='batch36037')
S(0x5db910, 'GUESS copy a list and header fields', 'thiscall', None, ret=None, gen=_g5db910, note='batch36037')
