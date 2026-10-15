"""specs_s37115.py - cascade s6 batch 37115 (0x648890, thiscall(src) ret 4). a+8 -> +0x3c object slot 0x380 writes element pointers into the caller's stack buffer. Elements are 0x70-byte
spec records (flags at +0x3c, index word at +0x5a); the node table at this+0x10071 holds a random subset of nodes; the pool at +0x1016d creates nodes; 0x63f220 maps an element to
a target object or fails; 0x63ef90 / 0x63da80 are recording hooks; the queue object embedded at +0x10185 has slot 8 (1 arg, the pointed-to dword logged)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g648890(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    targets = []

    def mktarget():
        m = rnd(c, 0x50)
        e.wbytes(m + 5, bytes([r.choice([0, 1, 2, 3])]))
        targets.append(m)
        return m

    def mknode():
        nd = rnd(c, 0x20)
        e.wbytes(nd + 5, bytes([r.choice([0, 0, 1, 2, 3, 0xff])]))
        _w(c, nd + 8, mktarget())
        return nd
    this = rnd(c, 0x10200)
    tbl = e.alloc(0x4000, 4)
    e.wbytes(tbl, bytes(0x4000))
    used = [0, 1, 2, 3, 5, 0x7ff, 0xfff]
    for i in used:
        if r.random() < 0.45:
            _w(c, tbl + 4 * i, mknode())
    _w(c, this + 0x10071, tbl)
    cnt = [0]
    pool = obj(c, 0x20, {})
    newnodes = [mknode() for _ in range(8)]
    newn = lambda em, k: newnodes[k % 8] if r.random() < 0.85 else 0
    # pool: slot 8 returns a node (or 0), slot 0xc releases
    P1 = e.alloc(0x40, 4)
    _w(c, P1 + 8, pystub(c, 0, this=True, ret=newn))
    _w(c, P1 + 0xc, pystub(c, 1, this=True))
    pobj = rnd(c, 0x20)
    _w(c, pobj, P1)
    _w(c, this + 0x1016d, pobj)
    cobj = rnd(c, 0x20)
    _w(c, this + 0x1005d, cobj)
    hook_rec(c, 0x63ef90, 1, this=True)
    hook_rec(c, 0x63da80, 1, this=True)
    tg = [mktarget() for _ in range(6)]
    hook_rec(c, 0x63f220, 1, this=True, ret=lambda em, k: tg[k % 6] if r.random() < 0.7 else 0)
    qv = e.alloc(0x40, 4)
    _w(c, qv + 8, pystub(c, 1, this=True, deref={0: 1}))
    _w(c, this + 0x10185, qv)
    # element pointer list
    k = r.choice([0, 1, 2, 3, 4])
    ptrs = []
    for _ in range(k):
        arr = e.alloc(0x80, 4)
        e.wbytes(arr, bytes(r.getrandbits(8) for _ in range(0x80)))
        _w(c, arr + 0x3c, r.choice([0, 0, 0, 0x400, 0x800, 0xc00, 0x1, 0xfffff]))
        _w(c, arr + 0x5a, r.choice(used) | (r.getrandbits(4) << 12), 2)
        ptrs.append(arr)
    blob = b''.join(p.to_bytes(4, 'little') for p in ptrs)

    def fill(em, k2):
        em.wbytes(em.arg32(0), blob)
    obj3 = obj(c, 0x20, {0x380: pystub(c, 2, this=True, stackmark=(0,), nullflag=(1,), side=fill, ret=lambda em, k2: em.arg32(0) + len(blob))})
    x = rnd(c, 0x60)
    _w(c, x + 0x3c, obj3)
    src = rnd(c, 0x20)
    _w(c, src + 8, x)
    return [this, src]


S(0x648890, 'GUESS count_mapped_elements', 'thiscall', None, ret='eax', gen=_g648890, note='batch37115')
