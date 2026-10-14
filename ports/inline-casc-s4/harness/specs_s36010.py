"""specs_s36010.py - cascade s4 batch 36010: 0x501f80 (resolve id and notify), 0x5270f0 (read fields from a stream), 0x62de00 (message handler with callback), 0x64d5f0 (queue a node and drop references), 0x6590e0 (replicate 26 dwords four times)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g501f80(c):
    clear_hooks(c)
    _assert(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    t = r.choice([3, 4, 4, 3, 0, 1, 7])
    rec1 = rnd(c, 0x10)
    e.wbytes(rec1 + 4, bytes([t]))
    if t == 4:
        e.w32(rec1, obj(c, 0x10, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))}))
    rec2 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=r.getrandbits(32))})
    w = obj(c, 0x20, {0x12c: pystub(c, 3, this=True)})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, w)
    a = rnd(c, 0x10)
    return [me, a]


def _g5270f0(c):
    clear_hooks(c)
    r = c.rng

    def w(n):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(n)))
        return side

    def wn(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(em.arg32(1) & 0xff)))
    s = obj(c, 0x20, {0x50: pystub(c, 1, this=True, side=w(4)), 0x68: pystub(c, 1, this=True, side=w(1)),
                      0x18: pystub(c, 2, this=True, side=wn)})
    return [rnd(c, 0x40), s]


def _g62de00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.choice([0, 1, 5]) for _ in range(4)]
    cb = pystub(c, 4, pop=0, ret=lambda em, k: seq[min(k, 3)])
    ob = rnd(c, 0x40)
    e.w32(ob + 0x1c, cb)
    out = rnd(c, 0x20)
    if r.random() < 0.4:
        e.w32(out + 0xc, 0)
    code = r.choice([0xf, 0x12, 0x12, 0x12, 0x1c, 0x1c, 0, r.getrandbits(8)])
    return [out, code, r.getrandbits(32), r.getrandbits(32), ob]


def _g64d5f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    hook_rec(c, 0x63ef00, 1, this=True)
    k = r.choice([0, 1, 5, 0x1ffe, 0x1ffd, r.randint(0, 0x1ffd)])
    vt = e.r32(obj(c, 0x10, {0xa4: pystub(c, 1, this=True)}))
    X = e.alloc(0x8300, 4)
    e.w32(X, vt)
    R = X + 0x268
    e.w32(R, R + 8 + 4 * k)
    vt2 = e.r32(obj(c, 0x10, {0x50: pystub(c, 1, this=True)}))
    me = e.alloc(0x10100, 4)
    e.w32(me, vt2)
    e.wbytes(me + 0x1005d, X.to_bytes(4, 'little'))
    p = rnd(c, 0x20)
    q = rnd(c, 0x20)
    A = rnd(c, 0x20)
    B = rnd(c, 0x20)
    idx = r.getrandbits(16)
    e.wbytes(B + 6, idx.to_bytes(2, 'little'))
    e.w32(A + 8, B)
    e.wbytes(A + 0xc, r.choice([1, 1, 2, 0, 0xffff]).to_bytes(2, 'little'))
    e.w32(q + 0x10, A)
    e.wbytes(q + 9, bytes([r.choice([1, 1, 2, 0])]))
    e.w32(p + 8, q)
    tab = e.alloc(0x4010, 4)
    cnt = rnd(c, 0x10)
    e.w32(cnt + 0xc, r.choice([1, 1, 2, 0, 0xffffffff]))
    e.w32(tab + 4 * (idx & 0xfff), cnt)
    e.wbytes(me + 0x10071, tab.to_bytes(4, 'little'))
    return [me, p]


def _g6590e0(c):
    clear_hooks(c)
    return [rnd(c, 0x240)]


S(0x501f80, 'GUESS resolve id and notify listener', 'thiscall', None, ret=None, gen=_g501f80, note='batch36010')
S(0x5270f0, 'GUESS read fields from stream (C)', 'thiscall', None, ret='al', gen=_g5270f0, note='batch36010')
S(0x62de00, 'GUESS message handler with callback tests', 'cdecl', None, ret='eax', gen=_g62de00, note='batch36010')
S(0x64d5f0, 'GUESS queue node, drop references', 'thiscall', None, ret=None, gen=_g64d5f0, note='batch36010')
S(0x6590e0, 'GUESS replicate dwords four times', 'thiscall', None, ret=None, gen=_g6590e0, note='batch36010')
