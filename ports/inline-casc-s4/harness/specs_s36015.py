"""specs_s36015.py - cascade s4 batch 36015: 0x4d3900 (serialize records), 0x4d41b0 (parse command line with strtok), 0x4d5000 (walk packed records and log), 0x4dc1e0 (find owner entry), 0x4f3d40 (setup and notify)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, HEAP_LO, HEAP_HI


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _logger(c):
    """[0x700390]: slot 0x20 returns a log object whose slot 0x2c is a cdecl printf (2 args for fmt 0x696728 / 0x6993ac-1, else 3)."""
    e = c.emu

    def pf(em, rr):
        a = [em.arg32(i) for i in range(3)]
        fmt = a[1]
        if fmt == 0x696728:
            em.calllog.append(('log', a[0], fmt))
        else:
            em.calllog.append(('log', a[0], fmt, a[2]))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('printf', pf)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)


def _g4d3900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def h(em, rr):
        a0, a1 = em.arg32(0), em.arg32(1)
        if a1 == 4 and not (HEAP_LO <= a0 < HEAP_HI):
            em.calllog.append(('v', em.r32(a0)))
        else:
            em.calllog.append(('buf', a0, a1))
        em.ret(eax=0, argbytes=8)
    s = obj(c, 0x20, {0x10: e.stub_fn('s10', h), 0x3c: pystub(c, 1, this=True)})
    blk = e.alloc(0x600, 4)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x600)))
    off = 0
    bounds = []
    for i in range(r.choice([0, 1, 2, 4])):
        L = r.choice([0x20, 0x28, 0x30])
        _w32(c, blk + off, L)
        e.wbytes(blk + off + 4, bytes([r.choice([0, 1, 1, 0xff])]))
        _w32(c, blk + off + 5, r.randint(0, 0x10))
        _w32(c, blk + off + 9, 0x6e7a30 + 40 * r.randint(-3, 5) + r.choice([0, 1, 39, 20]))
        _w32(c, blk + off + 0xd, r.randint(0, 0x10))
        off += L
        bounds.append(off)
    total = off
    if bounds and r.random() < 0.4:
        total = r.choice(bounds) + r.choice([-1, 0, 1]) if len(bounds) > 1 else off
        total = min(total, off)
    me = rnd(c, 0x20)
    e.w32(me + 8, blk)
    e.w32(me + 0xc, total)
    return [me, s]


def _g4d41b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t1 = r.choice([0, 1, 1, 2])
    s_ne = rnd(c, 0x10)
    e.wbytes(s_ne, bytes([0x41]))
    s_em = rnd(c, 0x10)
    e.wbytes(s_em, bytes([0]))
    t1p = {0: 0, 1: s_ne, 2: s_em}[t1]
    t2p = 0 if r.random() < 0.3 else rnd(c, 0x10)
    seq = [t1p, t2p]
    st = {'i': 0}

    def stk(em, rr):
        k = st['i']
        st['i'] += 1
        em.calllog.append(('strtok', em.arg32(0), em.arg32(1)))
        em.ret(eax=seq[min(k, 1)], argbytes=0)
    e.stub_import('strtok', stk)

    def lg(em, rr):
        a = [em.arg32(i) for i in range(4)]
        em.calllog.append(('slot4', a[0], a[1], a[2], a[3]) if a[1] == 0x6965cc else ('slot4', a[0], a[1], a[2]))
        em.ret(eax=0, argbytes=0)
    vt = e.r32(obj(c, 0x10, {0x34: pystub(c, 1, this=True), 4: e.stub_fn('slot4', lg)}))
    sub = e.r32(obj(c, 0x10, {8: pystub(c, 2, this=True, ret=r.choice([0, 1, 0x100, 0x1]))}))
    me = e.alloc(0x1200, 4)
    e.w32(me, vt)
    e.wbytes(me + 0xfa0, bytes(r.getrandbits(8) for _ in range(0x30)))
    e.wbytes(me + 0x1008, bytes([r.choice([0, 0x41])]) + bytes(r.getrandbits(8) for _ in range(7)))
    _w32(c, me + 0x10db, sub)
    return [me]


def _g4d5000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger(c)
    hdr = e.alloc(0x400, 4)
    e.wbytes(hdr, bytes(r.getrandbits(8) for _ in range(0x40)))
    neg = r.random() < 0.85
    b30 = r.random() < 0.5
    flags = (0x80000000 if neg else 0) | (0x40000000 if b30 else 0) | r.getrandbits(30) & 0x3fffffff
    n = r.choice([0, 1, 2, 3])
    m = r.choice([0, 1, 3])
    if not neg and r.random() < 0.4:
        flags = 0
    _w32(c, hdr + 4, flags & 0x7fffffff | (0x80000000 if neg else 0))
    _w32(c, hdr + 0xc, n)
    _w32(c, hdr + 0x10, m)
    pos = hdr + (0x14 + 4 * m if b30 else 0x10)
    for i in range(n):
        kind = r.choice([0, 0x40000000, 0x80000000, 0xc0000000])
        L = r.choice([0x10, 0x14, 0x20])
        _w32(c, pos + 4, kind | L)
        _w32(c, pos + 8, r.randint(0, 0x30))
        pos += L
    me = rnd(c, 0x40)
    _w32(c, me + 0x11, hdr)
    return [me]


def _g4dc1e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc140, 1, this=True)
    hook_rec(c, 0x4da770, 1, this=True)
    a = obj(c, 0x20, {0x36c: pystub(c, 1, this=True)})
    x = rnd(c, 0x40)
    n = r.choice([0, 1, 3, 7])
    e.wbytes(x + 0x1c, bytes([n]))
    pos = r.randrange(n) if n and r.random() < 0.6 else -1
    for i in range(7):
        e.w32(x + 4 * i, a if i == pos else r.getrandbits(32))
    o = 0 if r.random() < 0.2 else rnd(c, 0x10)
    y = rnd(c, 0x10)
    seq = [o, x, y]
    so = sysobj(c)
    tab = e.r32(so + 0x9b)
    o8 = obj(c, 0x10, {0x5c: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 2)])})
    e.w32(tab + 8, o8)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x5c, (0 if r.random() < 0.15 else r.randint(1, 0xffff)).to_bytes(2, 'little'))
    return [me, a]


def _g4f3d40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger(c)
    hook_rec(c, 0x45d3a0, 0, this=True)
    X = obj(c, 0x20, {0x288: pystub(c, 3, this=True), 0x2ec: pystub(c, 1, this=True)})
    first = 0 if r.random() < 0.3 else X
    y = rnd(c, 0x10)
    d = e.alloc(0x40, 4)
    _w32(c, d + 0x23, 0x10002e if r.random() < 0.5 else r.getrandbits(32))
    e.w32(y + 0xc, d)
    z = 0 if r.random() < 0.3 else rnd(c, 0x10)
    me = obj(c, 0x40, {0x2c4: pystub(c, 0, this=True, ret=lambda em, k: first if k == 0 else X),
                       0x20: pystub(c, 0, this=True, ret=y), 0x210: pystub(c, 1, this=True), 0x2e0: pystub(c, 0, this=True, ret=z)})
    e.w32(me + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    w = rnd(c, 0x50)
    e.w32(w + 0x3c, r.getrandbits(32))
    e.w32(me + 8, w)
    return [me]


S(0x4d3900, 'GUESS serialize record list to stream', 'thiscall', None, ret=None, gen=_g4d3900, note='batch36015')
S(0x4d41b0, 'GUESS parse command line with strtok', 'thiscall', None, ret=None, gen=_g4d41b0, note='batch36015')
S(0x4d5000, 'GUESS walk packed records and log', 'thiscall', None, ret=None, gen=_g4d5000, note='batch36015')
S(0x4dc1e0, 'GUESS find owner entry and release', 'thiscall', None, ret=None, gen=_g4dc1e0, note='batch36015')
S(0x4f3d40, 'GUESS setup and notify owner', 'thiscall', None, ret=None, gen=_g4f3d40, note='batch36015')
