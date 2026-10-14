"""specs_s36020.py - cascade s4 batch 36020: 0x553830 (resolve and report result code), 0x597d30 (dispatch next entry), 0x5d81b0 (message handler), 0x476d30 (write record to stream), 0x45e660 (release attached children)."""
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


def _g553830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    rec1, rec2 = rnd(c, 0x10), rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    q = 0 if r.random() < 0.3 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100]))})
    p = 0 if r.random() < 0.3 else rnd(c, 0x10)
    x = 0 if r.random() < 0.2 else obj(c, 0x80, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100])),
                                                     0x20: pystub(c, 0, this=True, ret=q)})
    if x:
        _w32(c, x + 0x54, p)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=x)})
    a = rnd(c, 0x20)
    return [a]


def _g597d30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x594040, 2, this=True, ret=r.getrandbits(32))
    p = 0 if r.random() < 0.15 else rnd(c, 0x10)
    hook_rec(c, 0x597720, 1, this=True, ret=p)
    hook_rec(c, 0x597b50, 0, this=True)
    hook_rec(c, 0x5967b0, 1, this=True)
    hook_rec(c, 0x5a1ac0, 3, this=True)
    xo = 0 if r.random() < 0.25 else rnd(c, 0x10)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0x58: pystub(c, 1, this=True, ret=xo)})
    cc = obj(c, 0x20, {0x12c: pystub(c, 3, this=True, deref={2: 2})})
    E = e.alloc(0x2100, 4)
    _w32(c, E + 0x1d0b, cc)
    a = r.randint(-3, 3) & 0xffffffff
    b = (a + r.choice([-1, 0, 1, 5])) & 0xffffffff if r.random() < 0.7 else r.getrandbits(32)
    _w32(c, E + 0x1fae, a)
    _w32(c, E + 0x1fba, b)
    e.wbytes(E + 0x1d2d, r.getrandbits(16).to_bytes(2, 'little'))
    return [E]


def _g5d81b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5d8470, 0, this=True)
    n = r.choice([0, 1, 2, 3, 0xffffffff])
    obj190f = obj(c, 0x20, {0xbc: pystub(c, 0, this=True)})
    so = sysobj(c, slots={0x1cc: pystub(c, 1, this=True), 0xc: pystub(c, 4, this=True)},
                table_slots={0xac: pystub(c, 0, this=True, ret=n), 0xa4: pystub(c, 0, this=True), 0xa0: pystub(c, 1, this=True)})
    e.wbytes(so + 0x190f, obj190f.to_bytes(4, 'little'))
    E = e.alloc(0x100, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x100)))
    w1, w2 = r.getrandbits(16), r.getrandbits(16)
    e.wbytes(E + 0x4a, w1.to_bytes(2, 'little'))
    e.wbytes(E + 0x4c, w2.to_bytes(2, 'little'))
    cobj = obj(c, 0x20, {0x114: pystub(c, 1, this=True)})
    e.w32(E + 0x44, cobj)
    e.w32(E + 0xbc, r.choice([0, 0, 1, 5]))
    m = r.random()
    idv = w1 if m < 0.4 else (w2 if m < 0.8 else r.getrandbits(16))
    if m >= 0.4 and m < 0.8 and w1 == w2:
        idv = w2
    return [E, idv | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0), r.getrandbits(32)]


def _g476d30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x441790, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101]))
    s = obj(c, 0x20, {0x60: pystub(c, 1, this=True), 0x40: pystub(c, 1, this=True), 0x64: pystub(c, 1, this=True),
                      0x44: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True)})
    E = rnd(c, 0x80)
    n = r.choice([0, 1, 2, 3, 0xffffffff])
    e.w32(E + 0x5c, n)
    arr = e.alloc(0x20, 4)
    for i in range(6):
        e.w32(arr + 4 * i, r.getrandbits(32))
    e.w32(E + 0x64, arr)
    e.wbytes(E + 0x72, bytes([r.choice([0, 0, 1, 0xff])]))
    return [E, s]


def _g45e660(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    hook_rec(c, 0x4da3a0, 0, this=True, ret=r.choice([0, 1, 1, 0x100]))

    def fh(em, rr):
        em.calllog.append(('free', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, fh)
    z = obj(c, 0x20, {0x54: pystub(c, 1, this=True)})
    zz = 0 if r.random() < 0.3 else z
    e.w32(0x70038c, obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=zz)}))
    n = r.choice([0, 1, 2])
    seq = [1] * n + [0]
    c0 = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lambda em, k: seq[min(k, len(seq) - 1)]),
                       0x30: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0: pystub(c, 1, this=True)})
    X = rnd(c, 0x20)
    e.w32(X + 8, 0 if r.random() < 0.15 else c0)
    e.w32(X + 0x10, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    E = rnd(c, 0x20)
    e.w32(E + 0x10, X)
    return [E]


S(0x553830, 'GUESS resolve object and report result code', 'stdcall', None, ret=None, gen=_g553830, note='batch36020')
S(0x597d30, 'GUESS dispatch next pending entry', 'thiscall', None, ret=None, gen=_g597d30, note='batch36020')
S(0x5d81b0, 'GUESS message handler on two ids', 'thiscall', None, ret='eax', gen=_g5d81b0, note='batch36020')
S(0x476d30, 'GUESS write record to stream', 'thiscall', None, ret='al', gen=_g476d30, note='batch36020')
S(0x45e660, 'GUESS release attached child', 'thiscall', None, ret=None, gen=_g45e660, note='batch36020')
