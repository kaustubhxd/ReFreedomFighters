"""specs_s36042.py - cascade s4 batch 36042: 0x513510 (read a record from a stream), 0x62d2b0 (token class by code), 0x54ef60 (check two interface properties, set one), 0x597b50 (find an object of kind 5 and notify), 0x630ce0 (deflate heap sift-down)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g513510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {'k': 0}

    def mk(width, slot):
        def h(em, rr):
            ptr = em.arg32(0)
            cnt['k'] += 1
            em.calllog.append(('stream', slot, em.reg('ecx')))
            em.wbytes(ptr, bytes(((cnt['k'] * 37 + i * 11 + slot) & 0xff) for i in range(width)))
            em.ret(0, 4)
        return h
    s = obj(c, 0x60, {0x40: e.stub_fn('s40', mk(4, 0x40)), 0x50: e.stub_fn('s50', mk(4, 0x50)), 0x6c: e.stub_fn('s6c', mk(12, 0x6c))})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0xbb000000 + k * 16)})
    d = rnd(c, 0x60)
    return [d, s]


def _g62d2b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.choice([0, 0, 1, 0x100]), r.choice([0, 1, 5])]
    ob = obj(c, 0x40, {})
    e.w32(ob + 0x1c, pystub(c, 4, pop=0, ret=lambda em, k, _v=vals: _v[min(k, 1)]))
    p = rnd(c, 0x20)
    if r.random() < 0.5:
        e.w32(p + 0xc, 0)
    code = r.choice([0xf, 0x12, 0x12, 0x17, 0x1c, 0x1c, 0x1d, 0, 0x11])
    return [p, code, r.getrandbits(32), r.getrandbits(32), ob]


def _g54ef60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    hr = [0, 1, 0xffffffff, 0x80000000, 0x7fffffff]

    def v14(em, res):
        k = cnt14[0]
        cnt14[0] += 1
        em.calllog.append(('s14', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.w32(em.arg32(3), vals14[min(k, 1)])
        em.ret(eax=rets14[min(k, 1)], argbytes=16)
    cnt14 = [0]
    vals14 = [r.choice([3, 7, 0xffffff03, 1, 2, 0x103, 0]), r.choice([3, 7, 0xffffff03, 1, 2, 0x103, 0])]
    rets14 = [r.choice(hr + [0, 1, 1]), r.choice(hr + [0, 1, 1])]
    if r.random() < 0.4:
        vals14 = [3, 3]
        rets14 = [0, 0]

    def v10(em, res):
        em.calllog.append(('s10', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4), em.r32(em.arg32(5)), em.arg32(6)))
        em.ret(eax=r.choice(hr), argbytes=28)
    s = obj(c, 0x20, {0x14: e.stub_fn('s14', v14), 0x10: e.stub_fn('s10', v10)})
    return [0 if r.random() < 0.08 else s]


def _g597b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([-1, 0, 1, 2, 3, 4])
    m = r.choice([-2, -1, 0, 1, 2, 5, n, n + 1, n - 1])
    d = rnd(c, 0x2000)
    e.w32(d + 0x1fae, n & 0xffffffff)
    e.w32(d + 0x1fba, m & 0xffffffff)
    seq = [r.choice([5, 5, 3, 0, 1]) for _ in range(6)]
    hook_rec(c, 0x59ffc0, 0, this=True, ret=lambda em, k, _s=seq: _s[min(k, 5)])
    hook_rec(c, 0x597e00, 1, this=True)
    hook_rec(c, 0x594460, 1, this=True)
    cvalue = r.getrandbits(32)
    o = obj(c, 0x20, {0x128: pystub(c, 3, this=True, deref={1: 1})})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k, _o=o: _o),
                           0x4c: pystub(c, 1, this=True, ret=cvalue),
                           0x114: pystub(c, 4, this=True, ret=lambda em, k: 0x12345678 * (k + 1) & 0xffffffff)})
    return [d]


def _g630ce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 12
    s = rnd(c, 0x1500)
    L = r.randint(0, 8)
    e.w32(s + 0x1448, L)
    for i in range(0, 12):
        e.w32(s + 0xb54 + 4 * i, r.randint(0, N - 1))
    e.wbytes(s + 0x1450, bytes(r.choice([0, 1, 2, 3, 0xff]) for _ in range(N)))
    tree = e.alloc(4 * N, 4)
    for i in range(N):
        e.wbytes(tree + 4 * i, r.choice([0, 1, 2, 3, 0x8000, 0xffff]).to_bytes(2, 'little') + bytes([r.getrandbits(8), r.getrandbits(8)]))
    k = r.randint(1, max(L, 1))
    return [s, tree, k]


S(0x513510, 'GUESS read a record from a stream', 'thiscall', None, ret='al', gen=_g513510, note='batch36042')
S(0x62d2b0, 'GUESS token class by code', 'cdecl', None, ret='eax', gen=_g62d2b0, note='batch36042')
S(0x54ef60, 'GUESS check two interface properties and set one', 'thiscall', None, ret='al', gen=_g54ef60, note='batch36042')
S(0x597b50, 'GUESS find an object of kind 5 and notify', 'thiscall', None, ret=None, gen=_g597b50, note='batch36042')
S(0x630ce0, 'GUESS deflate heap sift-down', 'cdecl', None, ret=None, gen=_g630ce0, note='batch36042')
