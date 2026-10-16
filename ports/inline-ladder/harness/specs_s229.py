"""specs_s229.py - ladder thread batch 229: ZIKLNKOBJ constructor and ClassInit."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _hk(c, addr, name, n, ab, ret=0):
    def h(e2, res):
        e2.calllog.append((name, e2.reg('ecx'), tuple(K.nostack(e2.arg32(i)) for i in range(n))))
        e2.ret(eax=ret, argbytes=ab)
    c.emu.hook(addr, h)


def _db(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x114: (4, lambda e2, a: ((a[3] * 0x10001 + 7) & 0xffffffff, None, None))}, nslots=0x50))
    return eng, d


def _ctor(c):
    _db(c)
    _hk(c, 0x460e40, 'ZLNKOBJ::ctor', 3, 0xc)
    _hk(c, 0x466220, 'ZTARGET::Clear', 0, 0)
    r = c.rng
    return [K.rnd(c, 0x200), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _ci(c):
    e, r = c.emu, c.rng
    eng, d = _db(c)
    _hk(c, 0x4dc630, 'SetControl', 2, 8)
    _hk(c, 0x461d60, 'ZLNKOBJ::ClassInit', 0, 0)
    chain = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))] + [0]
    state = {'i': 0}
    holder = K.rnd(c, 0x10)

    def nxt(e2, a):
        state['i'] += 1
        e2.w32(a[0], chain[min(state['i'], len(chain) - 1)])
        return 0, None, None
    e.w32(holder, K.vt(c, 'geomchain', {0x50: (1, nxt)}, nslots=0x20))
    e.w32(holder + 8, chain[0])
    if r.random() < 0.8:
        snd = K.rnd(c, 0x10)
        e.w32(snd, K.vt(c, 'sound', {0x5c: (1, lambda e2, a: ((a[0] * 5) & 0xffffffff, None, None))}, nslots=0x20))
        e.w32(eng + 0x1a9f, snd)
    else:
        e.w32(eng + 0x1a9f, 0)
    lst = K.rnd(c, 0x10)
    e.w32(lst, K.vt(c, 'list', {o: (n, lambda e2, a: (0, None, None)) for o, n in
                                ((0x10c, 2), (0x154, 0), (0x124, 4), (0x218, 1))}, nslots=0x100))
    found = lst if r.random() < 0.5 else 0
    lists = K.rnd(c, 0x10)
    e.w32(lists, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (found, None, None)),
                                   0x294: (4, lambda e2, a: (lst, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, lists)
    e.w32(0x7003b8, K.rnd(c, 0x500))
    bx = [c.fv(-200.0, 200.0) for _ in range(3)]

    def box(e2, a):
        K.wv3(e2, a[0], bx)
        return 0x5150, None, None
    s = K.rnd(c, 0x200)
    e.w32(s, K.vt(c, 'self', {0x20: (0, lambda e2, a: (holder, None, None)), 0x358: (0, lambda e2, a: (0, None, None)),
                              0x3a0: (1, box), 0x398: (1, lambda e2, a: (0, None, None)),
                              0x3d4: (0, lambda e2, a: (0, None, None))}, nslots=0x110))
    return [s]


S(0x4654b0, 'ZIKLNKOBJ::ZIKLNKOBJ', 'thiscall', None, ret='eax', gen=_ctor, note='batch229')
S(0x466040, 'ZIKLNKOBJ::ClassInit', 'thiscall', None, ret=None, gen=_ci, note='batch229')
