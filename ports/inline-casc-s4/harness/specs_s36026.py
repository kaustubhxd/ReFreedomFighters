"""specs_s36026.py - cascade s4 batch 36026: 0x474eb0 (transform a basis through register helpers), 0x5057e0 (log by result code), 0x50c290 (bind record to engine id C), 0x537160 (name lookup in a table), 0x53e830 (read tagged fields)."""
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


def _g474eb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill34_10(em, k):
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(36)))
        em.wbytes(em.arg32(2), bytes(r.getrandbits(8) for _ in range(12)))

    def fill_t(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(36)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(12)))

    def h70(em, rr):
        ec, ed, mat = em.reg('ecx'), em.reg('edx'), em.arg32(0)
        em.calllog.append(('441970', em.rbytes(ed, 12), em.rbytes(mat, 36)))
        em.wbytes(ec, bytes(r.getrandbits(8) for _ in range(12)))
        em.ret(eax=0, argbytes=4)

    def h40(em, rr):
        ec, ed = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('441940', em.rbytes(ec, 12), em.rbytes(ed, 12)))
        em.wbytes(ec, bytes(r.getrandbits(8) for _ in range(12)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x441970, h70)
    e.hook(0x441940, h40)
    a = obj(c, 0x20, {0x2b4: pystub(c, 3, this=True, ret=r.getrandbits(32), side=fill34_10, stackmark=(1, 2)),
                      0x390: pystub(c, 1, this=True), 0x98: pystub(c, 2, this=True, deref={0: 9, 1: 3})})
    t = obj(c, 0x20, {0x94: pystub(c, 2, this=True, side=fill_t, stackmark=(0, 1))})
    b = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=t), 0x2d4: pystub(c, 2, this=True, deref={0: 9, 1: 3})})
    E = rnd(c, 0x80)
    return [E, a, b]


def _g5057e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)

    def pf(em, rr):
        em.calllog.append(('print', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('printf', pf)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)}))
    x = rnd(c, 0x10)
    e.w32(x + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    cc = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=x)})
    E = rnd(c, 0x40)
    e.w32(E + 0x14, cc)
    return [E, r.getrandbits(32), r.choice([0xffffffff, 0, 1, 2, r.getrandbits(32)])]


def _g50c290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 3)
    rec1, rec2 = rnd(c, 0x10), rnd(c, 0x10)
    e.wbytes(rec2 + 4, bytes([r.choice([0, 1, 2, 4, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    y = r.getrandbits(32)
    xo = 0 if r.random() < 0.25 else obj(c, 0x20, {0x500: pystub(c, 0, this=True, ret=y)})
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    E = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, ret=xo)})
    return [E, rnd(c, 0x20)]


def _g537160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    res = [r.choice([0, 1, 2]) for _ in range(6)]
    st = {'i': 0}

    def m(em, rr):
        k = st['i']
        st['i'] += 1
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=res[min(k, 5)], argbytes=0)
    e.hook(0x4cc850, m)
    base = rnd(c, 0x60)
    n = r.choice([0, 1, 2, 3])
    tab = rnd(c, 0x20)
    e.wbytes(tab + 8, (n | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0)).to_bytes(4, 'little'))
    e.w32(tab + 0x10, 0 if r.random() < 0.08 else 0x10)
    for i in range(4):
        e.w32(base + 0x10 + 4 * i, 0 if r.random() < 0.12 else r.getrandbits(32))
    rets = [0 if r.random() < 0.15 else r.getrandbits(32) | 1 for _ in range(4)]
    E = obj(c, 0x5400, {0x1e8: pystub(c, 1, this=True, ret=lambda em, k: rets[min(k, 3)])})
    e.wbytes(E + 0x5302, (0 if r.random() < 0.1 else base).to_bytes(4, 'little'))
    return [E, 0 if r.random() < 0.08 else tab, 0 if r.random() < 0.08 else rnd(c, 0x10), r.choice([0, 1, 5, 0xffffffff])]


def _g53e830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    recs = []
    for i in range(3):
        rc = e.alloc(0x10, 4)
        t = r.choice([0xff, 3, 3, 0xb, 0x43, 0x4b, 0x83, 0xc3, 0x0a, 1, 0x23, 0x63, 0x2b, 0x6b])
        e.wbytes(rc, bytes([t]) + bytes(r.getrandbits(8) for _ in range(8)))
        recs.append(rc)
    vals = [r.choice([0, 1, 5, r.getrandbits(32)]) for _ in range(6)]

    def side(em, k):
        em.w32(em.reg('ecx'), recs[min(k + 1, 2)])
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: vals[min(k, 5)], side=side)
    so = sysobj(c)
    e.wbytes(so + 0x1a9f, (r.choice([0, 1, 7])).to_bytes(4, 'little'))
    nobj = rnd(c, 0x10)
    e.w32(nobj + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    E = rnd(c, 0x160)
    e.w32(E + 0x44, nobj)
    s = rnd(c, 0x10)
    e.w32(s, 0 if r.random() < 0.15 else recs[0])
    return [E, s]


S(0x474eb0, 'GUESS transform basis through register helpers', 'thiscall', None, ret=None, gen=_g474eb0, note='batch36026')
S(0x5057e0, 'GUESS log by result code', 'thiscall', None, ret=None, gen=_g5057e0, note='batch36026')
S(0x50c290, 'GUESS bind record to engine id (C)', 'thiscall', None, ret=None, gen=_g50c290, note='batch36026')
S(0x537160, 'GUESS name lookup in a table (B)', 'thiscall', None, ret='eax', gen=_g537160, note='batch36026')
S(0x53e830, 'GUESS read tagged fields from stream', 'thiscall', None, ret='eax', gen=_g53e830, note='batch36026')
