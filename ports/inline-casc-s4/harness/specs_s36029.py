"""specs_s36029.py - cascade s4 batch 36029: 0x49c6d0 (merge two sorted ranges), 0x4d2820 (append a record to a buffer), 0x4fa630 (write fields to a stream), 0x5098b0 (pick a random entry), 0x59e690 (select a range of entries)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g49c6d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n1 = r.choice([0, 1, 2, 4, 6])
    n2 = r.choice([0, 1, 2, 4, 6])
    pool = r.choice([[1, 2, 3, 5, 8, 8, 9, 0xffffffff, 0x80000000, 0], list(range(0, 20))])
    xs = sorted(r.choice(pool) for _ in range(n1))
    bs = sorted(r.choice(pool) for _ in range(n2))
    X = e.alloc(0x40, 4)
    B = e.alloc(0x40, 4)
    D = e.alloc(0x80, 4)
    e.wbytes(D, bytes(r.getrandbits(8) for _ in range(0x80)))
    for i, v in enumerate(xs):
        _w32(c, X + 4 * i, v)
    for i, v in enumerate(bs):
        _w32(c, B + 4 * i, v)
    return [D, X, n1, B, n2]


def _g4d2820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 2)

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(d, em.rbytes(s_, n))
        em.calllog.append(('memcpy', d, s_, n))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)
    p = e.alloc(0x80, 4)
    e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x80)))
    ln = r.choice([0, 1, 4, 0x10])
    _w32(c, p, ln)
    _w32(c, p + 8, r.choice([0, 3, 8]))
    total = e.r32(p + 8) + 0x11 + ln
    buf = e.alloc(0x200, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x200)))
    cap = r.choice([0x20, 0x40, 0x60, 0x80, 0x100])
    used = r.choice([0, 8, 0x30, 0x38, 0x70])
    grow = r.choice([0, 0x40])
    mm = r.random()
    if mm < 0.25:
        cap = used + total            # exactly full: no growth needed
    elif mm < 0.5 and grow:
        cap = used + total - grow     # exactly enough after the growth step
    rec = buf + used
    m = r.random()
    if m < 0.3:
        res = rec
        _w32(c, res, total if r.random() < 0.6 else total + 1)
    else:
        res = 0
    hook_rec(c, 0x4d2b40, 2, this=True, ret=res)

    def side(em, k):
        if grow:
            em.w32(em.reg('ecx') + 4, em.r32(em.reg('ecx') + 4) + grow)
    hook_rec(c, 0x4d29d0, 0, this=True, side=side)
    E = e.alloc(0x40, 4)
    _w32(c, E + 4, cap)
    _w32(c, E + 8, buf)
    _w32(c, E + 0xc, used)
    return [E, p]


def _g4fa630(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x441790, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101]))
    s = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True)})
    E = e.alloc(0xa0, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0xa0)))
    return [E, s]


def _g5098b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec1)
    hook_rec(c, 0x5002f0, 1, this=True)
    n = r.choice([0, 1, 3, 5, 7, -1, -3]) & 0xffffffff
    rv = r.choice([0, 1, 100, 0x7fffffff, 0x80000001, 0xfffffff0, r.getrandbits(32)])
    if n == 0xffffffff and rv == 0x80000000:
        rv = 1
    lst = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=n), 0x30: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    cc = rnd(c, 0x30)
    e.w32(cc + 0x18, lst)
    e.w32(0x70039c, 0)
    sysobj(c, slots={0x1bc: pystub(c, 2, this=True, ret=rv)})
    E = rnd(c, 0x20)
    e.w32(E + 0xc, 0 if r.random() < 0.2 else cc)
    a = rnd(c, 0x20)
    return [E, a]


def _g59e690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5a3690, 2, this=True)
    E = e.alloc(0x900, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x900)))
    n = r.choice([0, 1, 2, 4, 7])
    _w32(c, E + 0x7ce, n)
    for i in range(n):
        _w32(c, E + 0x7d2 + 16 * i, r.randint(-6, 6) & 0xffffffff)
    return [E, r.randint(-5, 6) & 0xffffffff, r.randint(-6, 5) & 0xffffffff]


S(0x49c6d0, 'GUESS merge two sorted dword ranges', 'fastcall', None, ret='eax', gen=_g49c6d0, note='batch36029')
S(0x4d2820, 'GUESS append a record to a growing buffer', 'thiscall', None, ret=None, gen=_g4d2820, note='batch36029')
S(0x4fa630, 'GUESS write fields to stream (J)', 'thiscall', None, ret='al', gen=_g4fa630, note='batch36029')
S(0x5098b0, 'GUESS pick a random entry from a list', 'thiscall', None, ret=None, gen=_g5098b0, note='batch36029')
S(0x59e690, 'GUESS select entries between two bounds', 'thiscall', None, ret=None, gen=_g59e690, note='batch36029')
