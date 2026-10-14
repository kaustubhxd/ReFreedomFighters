"""specs_s36059.py - cascade s4 batch 36059: 0x55c0c0 (typed value pair to a registry), 0x600860 (write table entries to a stream recursively)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _logger3(c):
    e = c.emu

    def pr(em, rr):
        fmt = em.arg32(1)
        args = [em.arg32(0), fmt]
        if fmt == 0x69c6b0:
            args.append(em.arg32(2))
        em.calllog.append(('log.printf', tuple(args)))
        em.ret(0, 0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)


def _g55c0c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger3(c)
    _assert_hook(c)
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    e.wbytes(rec0 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec0, inner if typ == 4 else r.getrandbits(32))
    rec1 = rnd(c, 0x10)
    e.w32(rec1, r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    rec2 = rnd(c, 0x10)
    recs = [rec0, rec1, rec2]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 2)])
    hook_rec(c, 0x5a2890, 2, this=True, ret=lambda em, k: 0x9100 + k)
    hook_rec(c, 0x5002f0, 1, this=True)
    s = rnd(c, 0x40)
    e.w32(s + 0x1c, rnd(c, 0x10))
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [s, p]


def _mk_this(c, depth, r, delta):
    e = c.emu
    s = rnd(c, 0xa8)
    off = r.choice([0, 0, 4, 8])
    e.w32(s + 0x98, off)
    for fld in (0x84, 0x80):
        n = r.choice([0, 1, 2, 3])
        blk = e.alloc(4 + 6 * 4 + off + 8, 4)
        e.wbytes(blk, bytes([0x33]) * (4 + 6 * 4 + off + 8))
        base = blk
        e.w32(base + off, n)
        for i in range(n):
            P = rnd(c, 0x40)
            e.w32(base + off + 4 + 6 * i, P)
        # field points so that field + s[0x98] == base + off ... keep field = blk, the code adds s[0x98]
        e.w32(s + fld, blk)
    e.w32(s + 0x9c, _mk_this(c, depth + 1, r, delta) if (depth < 1 and r.random() < 0.5) else 0)
    return s


def _g600860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5fa220, 1, this=True, ret=lambda em, k: 0xa000 + k)
    a = obj(c, 0x20, {0x2c: pystub(c, 1, this=True)})
    b = rnd(c, 0xb0)
    delta = r.choice([0, 4, 8, 0x10])
    e.w32(b + 0x9e, delta)
    cc = rnd(c, 0x10)
    s = _mk_this(c, 0, r, delta)
    return [s, a, b, cc]


S(0x55c0c0, 'GUESS typed value pair to a registry', 'thiscall', None, ret=None, gen=_g55c0c0, note='batch36059')
S(0x600860, 'GUESS write table entries to a stream recursively', 'thiscall', None, ret=None, gen=_g600860, note='batch36059')
