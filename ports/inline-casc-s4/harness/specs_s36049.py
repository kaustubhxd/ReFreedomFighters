"""specs_s36049.py - cascade s4 batch 36049: 0x424ee0 (format a text and register an atom), 0x52a600 (destructor freeing buffers), 0x52dfc0 (compare two three-word keys)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g424ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def pr(em, rr):
        fmt = em.arg32(1)
        args = [em.arg32(0), fmt]
        if fmt == 0x678770:
            args.append(bytes(em.rbytes(em.arg32(2), 8)))
        em.calllog.append(('log.printf', tuple(args)))
        em.ret(0, 0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)
    mode = r.choice(['empty', 'text', 'text', 'zero'])
    text = {'empty': b'\0', 'text': b'Hello\0', 'zero': b'Zz\0'}[mode]
    pat = text + bytes(7)

    def fmt(em, k):
        em.wbytes(em.arg32(0), pat)
    hook_rec(c, 0x42abee, 3, pop=0, stackmark=(0,), deref={2: 2}, side=fmt)
    rets = {'empty': 7, 'text': r.choice([0x1234, 0x10000, 0xc001, 0x10005]), 'zero': 0x10000}[mode]

    def atom(em, rr):
        em.calllog.append(('GlobalAddAtomA', bytes(em.rbytes(em.arg32(0), 8))))
        em.ret(eax=rets, argbytes=4)
    e.stub_import('GlobalAddAtomA', atom)
    p = obj(c, 0x40, {0x18: pystub(c, 3, this=True)})
    e.w32(p + 0x24, 0 if r.random() < 0.15 else r.getrandbits(32) | 1)
    return [p, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g52a600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x41e2c0, 1, pop=0)
    hook_rec(c, 0x43de70, 0, this=True)
    s = rnd(c, 0x90)
    for off in (0x3a, 0x1c, 0x18, 0x42, 0x7d):
        e.w32(s + off, 0 if r.random() < 0.3 else r.getrandbits(32) | 1)
    for off in (0x65, 0x2d, 0x32):
        e.w32(s + off, 0 if r.random() < 0.3 else obj(c, 0x20, {0: pystub(c, 1, this=True)}))
    if r.random() < 0.7:
        ent = rnd(c, 0x10)
        e.w32(ent, 0 if r.random() < 0.3 else r.getrandbits(32) | 1)
        e.w32(s + 0x79, ent)
    else:
        e.w32(s + 0x79, 0)
    return [s]


def _g52dfc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    dxv = r.getrandbits(16)

    def h531(em, rr):
        this_c = em.reg('ecx')
        em.calllog.append(('531740', em.r32(this_c), em.r32(this_c + 4) , em.r32(this_c + 8), em.arg32(0), em.arg32(1)))
        em.w32(this_c + 0x10, 0)
        em.wbytes(this_c + 0x16, dxv.to_bytes(2, 'little'))
        em.ret(0, 8)
    e.hook(0x531740, h531)

    def h52d(em, rr):
        pa, pb = em.arg32(0), em.arg32(1)
        def fields(p):
            return tuple(int.from_bytes(em.rbytes(p + o, 2), 'little') for o in (0, 4, 6, 8))
        em.calllog.append(('52dbb0', em.reg('ecx'), fields(pa), fields(pb), em.arg32(2)))
        em.ret(eax=r.choice([0, 1, 0x100, 0x10000]), argbytes=12)
    e.hook(0x52dbb0, h52d)
    s = rnd(c, 0xa0)
    a = rnd(c, 8)
    b = rnd(c, 8)
    mode = r.choice(['same', 'd0', 'd1', 'd2', 'diff'])
    ab = e.rbytes(a, 6)
    e.wbytes(b, ab)
    if mode != 'same':
        idx = {'d0': 0, 'd1': 1, 'd2': 2}.get(mode, r.randint(0, 2))
        e.wbytes(b + 2 * idx, ((int.from_bytes(ab[2 * idx:2 * idx + 2], 'little') + 1) & 0xffff).to_bytes(2, 'little'))
    return [s, a, b]


S(0x424ee0, 'GUESS format a text and register an atom', 'cdecl', None, ret=None, gen=_g424ee0, note='batch36049')
S(0x52a600, 'GUESS destructor freeing buffers', 'thiscall', None, ret=None, gen=_g52a600, note='batch36049')
S(0x52dfc0, 'GUESS compare two three-word keys', 'thiscall', None, ret='al', gen=_g52dfc0, note='batch36049')
