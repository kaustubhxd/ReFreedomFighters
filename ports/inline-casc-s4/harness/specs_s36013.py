"""specs_s36013.py - cascade s4 batch 36013: 0x5aee60 (collect unique entries), 0x5ed0b0 (read vector fields + list), 0x403ee0 (free a table structure), 0x427320 (file size by handle), 0x57f750 (format string and hand it on)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g5aee60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [rnd(c, 0x60) for _ in range(4)]
    n = r.choice([0, 1, 2, 3, 4, 0xffffffff])
    kids = []
    for i in range(max(0, min(n, 4)) if n < 0x80000000 else 0):
        p = 0 if r.random() < 0.2 else r.choice(pool)
        kids.append(obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=p)}))
    lst = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=n),
                        0x30: pystub(c, 1, this=True, ret=lambda em, k: 0x40 + k)})
    o = rnd(c, 0x30)
    e.w32(o + 0x18, lst)
    seq = [o] + kids
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    E = e.alloc(0x60, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x60)))
    cnt = r.choice([0, 1, 2, 5, 0x13, 0x14, 0x15, r.randint(0, 0x16)])
    e.w32(E, cnt)
    for k in range(min(cnt, 0x14)):
        e.w32(E + 4 + 4 * k, (r.choice(pool) + 0x48) if r.random() < 0.4 else r.getrandbits(32))
    return [E, r.getrandbits(32)]


def _g5ed0b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    blocks = [rnd(c, 0x10) for _ in range(6)]
    hook_rec(c, 0x5ebf10, 1, this=True)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[min(k, 5)])
    hook_rec(c, 0x5fe3b0, 2, this=True, deref={1: 1})

    def w12(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))

    def wn(em, k):
        em.w32(em.arg32(0), n)

    def w16(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(16)))
    s = obj(c, 0x20, {0x6c: pystub(c, 1, this=True, side=w12), 0x40: pystub(c, 1, this=True, side=wn, stackmark=(0,)),
                      0x18: pystub(c, 2, this=True, side=w16)})
    E = e.alloc(0x120, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x120)))
    arr = rnd(c, 0x40)
    m = r.random()
    if m < 0.3:
        cur, end = arr, arr
    elif m < 0.45:
        cur, end = 0, 8
    elif m < 0.5:
        cur, end = 0, 0
    else:
        cur, end = arr, arr + 4 * r.choice([1, 2, 3, 8])
    e.wbytes(E + 0xcf, cur.to_bytes(4, 'little'))
    e.wbytes(E + 0xd3, end.to_bytes(4, 'little'))
    return [E, s]


def _g403ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fh(em, res):
        em.calllog.append(('free', em.arg32(0)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634d52, fh)
    if r.random() < 0.08:
        return [0]
    p = e.alloc(0x40, 4)
    e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x40)))
    for off in (0x14, 0x18, 0x1c):
        e.w32(p + off, 0 if r.random() < 0.4 else r.getrandbits(32))
    if r.random() < 0.8:
        arr = e.alloc(0x48, 4)
        for i in range(17):
            blk = e.alloc(0x2c, 4)
            e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x2c)))
            e.w32(arr + 4 * i, blk)
        e.w32(p + 8, arr)
    else:
        e.w32(p + 8, 0)
    return [p]


def _g427320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    sz = r.choice([0xffffffff, 0xffffffff, 5, r.getrandbits(32)])

    def gfs(em, rr):
        em.calllog.append(('gfs', em.arg32(0), em.arg32(1)))
        em.ret(eax=sz, argbytes=8)
    e.stub_import('GetFileSize', gfs)
    v = r.choice([0xffffffff, 7, r.getrandbits(32)])
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x10: pystub(c, 1, this=True, ret=v)})
    h = 0 if r.random() < 0.15 else r.getrandbits(32) | 1
    me = obj(c, 0x40, {0x130: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0x70: pystub(c, 1, this=True, ret=o),
                       8: pystub(c, 1, this=True, ret=h), 0x1c: pystub(c, 1, this=True)})
    return [me, r.getrandbits(32), r.choice([0, 0, 1, 0x100, 0x101, r.getrandbits(32)])]


def _g57f750(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r1, r2 = r.getrandbits(32), r.getrandbits(32)

    def sprintf(em, res):
        a = [em.arg32(i) for i in range(5)]
        s = bytes(r.randint(1, 255) for _ in range(r.choice([0, 3, 40, 200]))) + b'\0'
        em.wbytes(a[1], s)
        em.calllog.append(('fmt', a[0], a[2], a[3], a[4]))
        em.ret(eax=len(s) - 1, argbytes=0)
    y = obj(c, 0x20, {0x198: e.stub_fn('sprintf', sprintf)})
    w = obj(c, 0x20, {0xb8: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100]))})
    o = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=lambda em, k: (r1, r2)[min(k, 1)])})
    so = sysobj(c, slots={0xbc: pystub(c, 0, this=True, ret=w), 0x190: pystub(c, 0, this=True, ret=y)}, table_size=0xaf8)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xae4, o)

    def h(em, res):
        p = em.arg32(1)
        s = b''
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            s += ch
            p += 1
        em.calllog.append(('563710', em.reg('ecx'), em.arg32(0), s))
        em.ret(eax=0, argbytes=8)
    e.hook(0x563710, h)
    E = e.alloc(0x200, 4)
    e.wbytes(E + 0x180, bytes(r.getrandbits(8) for _ in range(8)))
    return [E]


S(0x5aee60, 'GUESS collect unique entries from list', 'thiscall', None, ret=None, gen=_g5aee60, note='batch36013')
S(0x5ed0b0, 'GUESS read vector, flags and handle list', 'thiscall', None, ret=None, gen=_g5ed0b0, note='batch36013')
S(0x403ee0, 'GUESS free a table structure', 'cdecl', None, ret=None, gen=_g403ee0, note='batch36013')
S(0x427320, 'GUESS file size by handle with fallback', 'thiscall', None, ret='eax', gen=_g427320, note='batch36013')
S(0x57f750, 'GUESS format status line and hand it on', 'thiscall', None, ret=None, gen=_g57f750, note='batch36013')
