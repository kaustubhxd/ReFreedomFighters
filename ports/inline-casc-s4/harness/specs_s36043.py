"""specs_s36043.py - cascade s4 batch 36043: 0x444910 (collect entries through an iterator), 0x4c4fc0 (push list nodes to a manager), 0x4ca820 (send a name or id text), 0x4acd10 (notify matching objects), 0x43f900 (read flags from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _g444910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    E1 = e.alloc(0x70 * 6 + 0x40, 16)
    e.wbytes(E1, bytes(r.getrandbits(8) for _ in range(0x70 * 6 + 0x40)))
    flagset = [0, 0x40000000, 0x10000000, 0x4000, 0x10004000, 0x40004000, 0x40010000, r.getrandbits(32)]
    for i in range(6):
        e.w32(E1 + 0x70 * i + 0x3c, r.choice(flagset))
    R = []
    for _ in range(3):
        blk = rnd(c, 0x50)
        e.w32(blk + 0x3c, r.choice(flagset))
        R.append(blk)
    hook_rec(c, 0x4dafb0, 0, this=True, ret=lambda em, k, _R=R: _R[k % len(_R)])

    def ptr(off8=None):
        if off8 is None:
            off8 = r.choice([0, 8])
        return E1 + 0x70 * r.randint(0, 5) + off8 + r.getrandbits(3)
    nn = r.choice([1, 2, 3])
    nodes = []
    for _ in range(3):
        n = rnd(c, 0x40)
        al = r.choice([0, 1, 2, 3, 3, 4, 5, 1])
        e.wbytes(n + 8, bytes([al]))
        for off in range(0xc, 0x28, 4):
            e.w32(n + off, ptr())
        nodes.append(n)
    for i, n in enumerate(nodes):
        al = e.rbytes(n + 8, 1)[0]
        if al & 1:
            e.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) and r.random() < 0.85 else 0)
    pairs = e.alloc(8 * 3, 4)
    for i in range(3):
        o8 = r.choice([0, 8])
        e.w32(pairs + 8 * i, ptr(o8))
        e.w32(pairs + 8 * i + 4, ptr(o8))
    p = 0 if r.random() < 0.1 else pairs
    end = pairs + 8 * nn
    cur = 0 if r.random() < 0.15 else nodes[0]

    def side(em, k):
        it = em.reg('ecx')
        em.w32(it, cur)
        em.w32(it + 4, p)
        em.w32(it + 8, end)
    hook_rec(c, 0x440ce0, 1, this='mark', side=side)
    s = rnd(c, 0xc8)
    out = e.alloc(0x60, 4)
    e.wbytes(out, bytes([0x55]) * 0x60)
    lim = out + 4 * r.choice([0, 1, 2, 3, 5, 8, 20])
    return [s, out, lim]


def _g4c4fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def nxt(em, rr):
        ptr = em.arg32(0)
        cur = em.r32(ptr)
        em.calllog.append(('o.50', em.reg('ecx'), cur))
        em.w32(ptr, em.r32(cur + 0x20))
        em.ret(0, 4)
    nxt_code = e.stub_fn('o50', nxt)
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    objs = {}
    for i in ids:
        if r.random() < 0.8:
            o = obj(c, 0x30, {0x50: nxt_code})
            chain = [rnd(c, 0x60) for _ in range(r.choice([0, 1, 2, 3]))]
            for j, n in enumerate(chain):
                e.w32(n + 0x20, chain[j + 1] if j + 1 < len(chain) else 0)
                e.w32(n + 0x54, 0 if r.random() < 0.3 else rnd(c, 0x10))
            e.w32(o + 8, chain[0] if chain else 0)
            objs[i] = o

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find),
                           0x114: pystub(c, 4, this=True, ret=lambda em, k: 0x12345678 * (k + 1) & 0xffffffff)})
    w = obj(c, 0x20, {0x130: pystub(c, 3, this=True)})
    s = rnd(c, 0x80)
    e.w32(s + 0x44, w)
    e.w32(s + 0x54, 0 if r.random() < 0.1 else reftab(c, ids))
    return [s]


def _g4ca820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    o = obj(c, 0x20, {0x60: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x4c: pystub(c, 2, this=True, ret=lambda em, k: 0x1000 + k)})
    t2 = rnd(c, 0x20)
    T = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=t2)})
    e.w32(T + 4, r.getrandbits(32))
    s = obj(c, 0x80, {0x58: pystub(c, 0, this=True)})
    e.w32(s + 0x44, T)
    e.wbytes(s + 0x48, bytes([r.choice([0, 0, 1, 0x80])]))
    mode = r.choice(['none', 'empty', 'text', 'text'])
    if mode == 'none':
        e.w32(s + 0x49, 0)
    else:
        a = e.alloc(16, 4)
        e.wbytes(a, (b'\0' if mode == 'empty' else b'abc\0') + bytes(12))
        e.w32(s + 0x49, a)
    return [s]


def _g4acd10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    objs = {}
    for i in ids:
        v = r.choice([0, 1, 1, 0x100])
        o = obj(c, 0x120, {0x14: pystub(c, 0, this=True, ret=v)})
        objs[i] = o

    def cc(em, rr):
        em.calllog.append(('slot0xcc', em.arg32(0)))
        em.ret(objs[em.arg32(0)], 4)
    g = obj(c, 0x20, {0xcc: e.stub_fn('cc', cc)})
    e.w32(0x70038c, g)
    e._image_dirty = True

    def m4cc(em, rr):
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=r.choice([0, 0, 1, 0x100]), argbytes=0)
    e.hook(0x4cc850, m4cc)
    hook_rec(c, 0x41e680, 0, this=True, ret=lambda em, k: 0x7000 + k)
    X = rnd(c, 0x20)
    e.w32(X + 8, 0 if r.random() < 0.1 else reftab(c, ids))
    W = rnd(c, 0x20)
    e.w32(W + 0x10, X)
    s = rnd(c, 0x1e0)
    e.w32(s + 0x44, W)
    vt1 = e.alloc(0x40, 4)
    e.w32(vt1 + 0x28, pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])))
    e.w32(s + 0x11a, vt1)
    vt2 = e.alloc(0x10, 4)
    e.w32(vt2 + 4, pystub(c, 1, this=True))
    e.w32(s + 0x1c6, vt2)
    return [s]


def _g43f900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x610100, 1)
    kinds = [r.choice([3, 3, 2, 0, 1, 0x103, 0x302]) for _ in range(6)]
    hook_rec(c, 0x4e1600, 0, this=True, ret=lambda em, k, _k=kinds: _k[min(k, 5)])
    vals = [r.choice([0, 1, 5, 0x100]) for _ in range(6)]
    cnt = [0]

    def side11(em, k):
        em.w32(em.arg32(0), vals[min(cnt[0], 5)])
        cnt[0] += 1
    hook_rec(c, 0x4e11e0, 2, this=True, stackmark=(0,), side=side11)
    hook_rec(c, 0x4e12f0, 2, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True)
    d = rnd(c, 0x80)
    a = rnd(c, 0x20)
    return [d, a]


S(0x444910, 'GUESS collect entries through an iterator', 'thiscall', None, ret='eax', gen=_g444910, note='batch36043')
S(0x4c4fc0, 'GUESS push list nodes to a manager', 'thiscall', None, ret=None, gen=_g4c4fc0, note='batch36043')
S(0x4ca820, 'GUESS send a name or id text', 'thiscall', None, ret=None, gen=_g4ca820, note='batch36043')
S(0x4acd10, 'GUESS notify matching objects', 'thiscall', None, ret=None, gen=_g4acd10, note='batch36043')
S(0x43f900, 'GUESS read flags from a stream', 'thiscall', None, ret=None, gen=_g43f900, note='batch36043')
