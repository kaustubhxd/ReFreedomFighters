"""specs_s36045.py - cascade s4 batch 36045: 0x5d7610 (read an entry from a stream), 0x603790 (assign one variant slot from another)."""
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


def _g5d7610(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    n = r.choice([0, 1, 5, 0x62, 0x63, 0x64, 0x70])
    text = bytes(r.randint(0x41, 0x5a) for _ in range(n)) + b'\0'
    sp = e.alloc(0x90, 4)
    e.wbytes(sp, text + bytes(0x90 - len(text)))
    hook_rec(c, 0x4e5ea0, 0, this=True, ret=sp)

    def strncpy(em, rr):
        dst, src, cnt = em.arg32(0), em.arg32(1), em.arg32(2)
        data = bytes(em.rbytes(src, cnt))
        out = bytearray(cnt)
        for i in range(cnt):
            if data[i] == 0:
                break
            out[i] = data[i]
        em.wbytes(dst, bytes(out))
        em.ret(eax=dst, argbytes=0)
    e.stub_import('strncpy', strncpy)
    rv = [r.getrandbits(32) for _ in range(6)]
    rv[3] = r.choice([0, 1, 7])
    rr_ = rnd(c, 0x10)
    buf = e.alloc(16, 4)
    e.wbytes(buf, bytes(r.choice([0xff, 0xff, 0x3f, 0x00, 0x7f, 0xc0, 0x41, 0xbf]) for _ in range(16)))
    e.w32(rr_, buf)

    def side(em, k):
        p = em.reg('ecx')
        em.w32(p, em.r32(p) + 1)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k, _v=rv: _v[min(k, 5)], side=side)
    s = rnd(c, 0x1f0)
    return [s, rr_]


def _g603790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    cnt = r.choice([3, 4, 5])
    A = e.alloc(8 * (cnt + 6), 4)
    e.wbytes(A, bytes(r.getrandbits(8) for _ in range(8 * (cnt + 6))))
    kinds = [0, 1, 4, 4, 2, 4]

    def mkobj():
        return obj(c, 0x20, {0x28: pystub(c, 0, this=True), 0x24: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    for i in range(cnt + 3):
        k = r.choice(kinds)
        e.w32(A + 8 * i, mkobj() if k == 4 else r.getrandbits(32))
        e.wbytes(A + 8 * i + 4, bytes([k]))
    idx = r.randint(0, cnt - 1) if r.random() < 0.85 else cnt + r.randint(0, 2)
    rec1 = rnd(c, 0x10)
    e.w32(rec1, idx)
    mode = r.choice(['same', 'other', 'rec', 'rec', 'rec4'])
    if mode == 'same':
        rec0 = A + 8 * idx
    elif mode == 'other':
        rec0 = A + 8 * r.randint(0, cnt + 2)
    else:
        rec0 = rnd(c, 0x10)
        k0 = 4 if mode == 'rec4' else r.choice([0, 1, 2, 4, 3])
        e.wbytes(rec0 + 4, bytes([k0]))
        if k0 == 4:
            e.w32(rec0, mkobj())
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _a=(rec1, rec0): _a[min(k, 1)])
    d = rnd(c, 0x20)
    e.w32(d + 0xc, A)
    e.w32(d + 0x14, cnt)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [d, p]


S(0x5d7610, 'GUESS read an entry from a stream', 'thiscall', None, ret=None, gen=_g5d7610, note='batch36045')
S(0x603790, 'GUESS assign one variant slot from another', 'thiscall', None, ret=None, gen=_g603790, note='batch36045')
