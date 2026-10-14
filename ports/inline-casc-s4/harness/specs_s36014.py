"""specs_s36014.py - cascade s4 batch 36014: 0x64d170 (find or create a node), 0x432030 (classify a pointer), 0x459ab0 (frame-counted dispatch), 0x461f00 (release owned objects), 0x4c9660 (write fields to a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _g64d170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    E = e.alloc(0x10200, 4)
    blkw = rnd(c, 0x60)
    hook_rec(c, 0x63f2d0, 1, this=True, ret=blkw)
    hook_rec(c, 0x63da80, 1, this=True)
    T = e.alloc(0x4010, 4)
    X = rnd(c, 0x10)
    edi = rnd(c, 0x80)
    a = rnd(c, 0x20)
    e.w32(a + 8, edi)
    idx = e.rbytes(edi + 0x5a, 2)
    i = int.from_bytes(idx, 'little') & 0xfff

    def mknode():
        n = rnd(c, 0x60)
        e.wbytes(n + 5, bytes([r.choice([0, 1, 2, 3, 0x80])]))
        e.w32(n + 8, rnd(c, 0x60))
        return n
    if r.random() < 0.5:
        e.w32(T + 4 * i, mknode())
    nn = mknode()
    pool = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=nn)})

    def side(em, k):
        if r.random() < 0.0:
            pass
    vt = e.r32(obj(c, 0x10, {8: pystub(c, 1, this=True, deref={0: 1})}))
    e.w32(E + 0xc, vt)
    e.wbytes(E + 0x1005d, X.to_bytes(4, 'little'))
    e.wbytes(E + 0x10071, T.to_bytes(4, 'little'))
    e.wbytes(E + 0x10155, pool.to_bytes(4, 'little'))
    return [E, a, r.getrandbits(32)]


def _g432030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    S_ = rnd(c, 0x40)
    s8 = r.randint(0x1000, 0x2000)
    n1 = r.choice([0, 1, 2, 5])
    s18 = s8 + 12 * n1 + r.choice([0, 12, 0x40, -12]) if r.random() < 0.7 else r.randint(0x1000, 0x3000)
    n2 = r.choice([0, 1, 3])
    s28 = r.choice([s18 + 12 * n2, s18 + 12 * n2 + 0x30, r.randint(0x1000, 0x3000)])
    n3 = r.choice([0, 1, 4])
    for off, v in ((8, s8), (0xc, n1), (0x18, s18), (0x1c, n2), (0x28, s28), (0x2c, n3)):
        e.w32(S_ + off, v & 0xffffffff)
    so = sysobj(c)
    e.wbytes(so + 0x190b, S_.to_bytes(4, 'little'))
    cands = [s8 - 1, s8, s8 + 12 * n1 - 1, s8 + 12 * n1, s18 - 1, s18, s18 + 12 * n2 - 1, s18 + 12 * n2, s28 - 1, s28, s28 + 12 * n3 - 1, s28 + 12 * n3,
             r.randint(0x800, 0x3400)]
    p = r.choice(cands) & 0xffffffff
    hi = r.choice([0, 1, 2, 3, 0x7fff, 0xffff])
    v = (hi << 16) | r.getrandbits(16)
    me = obj(c, 0x20, {0x10: pystub(c, 1, this=True, ret=v), 0xc: pystub(c, 1, this=True, ret=p)})
    return [me, r.getrandbits(32)]


def _g459ab0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    frame = e.r32(so + 0x3c)

    def w(n):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
            em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0xc)))
        return side
    me = obj(c, 0x200, {0x80: pystub(c, 2, this=True, side=w(0), stackmark=(0, 1))})
    e.w32(me + 0x20, frame if r.random() < 0.6 else r.getrandbits(32))
    e.w32(me + 0x1c, r.choice([0, 1, 2, 3, 4, 5, 0xffffffff, r.getrandbits(32)]))
    e.w32(me + 0x40, 0 if r.random() < 0.25 else r.getrandbits(32) | 1)
    a = obj(c, 0x20, {0x28: pystub(c, 6, this=True, deref={2: 9, 3: 3})})
    return [me, a, rnd(c, 0x80)]


def _g461f00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub0 = pystub(c, 1, this=True)
    rs = []
    for i in range(r.choice([0, 1, 3])):
        n = rnd(c, 0x80)
        e.w32(n + 0x70, 0 if r.random() < 0.3 else obj(c, 0x10, {0: stub0}))
        rs.append(n)
    seq = rs + [0]
    cont = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0: stub0,
                         0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x80)
    e.w32(me + 0x18, 0 if r.random() < 0.3 else cont)
    e.w32(me + 0x1c, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    e.w32(me + 0x6c, 0 if r.random() < 0.4 else obj(c, 0x10, {0x2c: pystub(c, 1, this=True)}))
    return [me]


def _g4c9660(c):
    clear_hooks(c)
    slots = {off: pystub(c, 1, this=True) for off in (0x68, 0x60, 0x40, 0x54)}
    s = obj(c, 0x20, slots)
    return [rnd(c, 0x90), s]


S(0x64d170, 'GUESS find or create node by index', 'thiscall', None, ret='eax', gen=_g64d170, note='batch36014')
S(0x432030, 'GUESS classify pointer into region name', 'thiscall', None, ret='eax', gen=_g432030, note='batch36014')
S(0x459ab0, 'GUESS frame-counted dispatch of slot entry', 'thiscall', None, ret='al', gen=_g459ab0, note='batch36014')
S(0x461f00, 'GUESS release owned objects', 'thiscall', None, ret=None, gen=_g461f00, note='batch36014')
S(0x4c9660, 'GUESS write fields to stream (D)', 'thiscall', None, ret='al', gen=_g4c9660, note='batch36014')
