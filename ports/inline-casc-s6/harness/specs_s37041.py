"""specs_s37041.py - cascade s6 batch 37041: 0x4ef210. this/src are packed-field objects (spec heap blocks with vtables); manager at [[0x70039c]+0x1aa3]+0x18 has slots
0x2c, 0x34, 0x38, 0xc; this has slots 0x48, 0x230, 0x218; src has slot 0x1e0; 0x634d22 does a real copy; 0x4de7a0 runs as original code."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4ef210(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x400:
            em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    nrec = r.choice([0, 1, 2, 3])
    cnt = r.choice([0, 1, 2])
    srcrecs = e.alloc(0x200, 4)
    for i in range(0x80):
        e.w32(srcrecs + 4 * i, r.getrandbits(32))
    newrecs = e.alloc(0x200, 4)
    arr36 = e.alloc(0x40, 4)
    arr3a = e.alloc(0x80, 4)
    handles = [r.getrandbits(32) for _ in range(4)]
    # manager
    rec_objs = [rnd(c, 0x30) for _ in range(4)]

    def mgr_lookup(em, k):
        return rec_objs[em.arg32(0) % 4]
    mg = obj(c, 0x40, {0x2c: pystub(c, 1, this=True, ret=newrecs),
                       0x34: pystub(c, 1, this=True, ret=arr36),
                       0x38: pystub(c, 1, this=True, ret=arr3a),
                       0xc: pystub(c, 1, this=True, ret=mgr_lookup)})
    holder = rnd(c, 0x30)
    e.w32(holder + 0x18, mg)
    so = sysobj(c)
    _w(c, so + 0x1aa3, holder)
    # src
    src = obj(c, 0xa0, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 1, 0x100, 0x1ff]))})
    for off in (0x18, 0x22, 0x26, 0x1c, 0x3e, 0x42):
        _w(c, src + off, r.getrandbits(32))
    for off in (0x21, 0x8e, 0x20):
        _w(c, src + off, r.getrandbits(8), 1)
    _w(c, src + 0x91, r.choice([0, 0, 1]), 1)
    _w(c, src + 0x2a, srcrecs if r.random() < 0.8 else 0)
    n32 = r.choice([0, 1, 2, 3])
    _w(c, src + 0x32, n32)
    s36 = e.alloc(0x40, 4)
    for i in range(4):
        e.w32(s36 + 4 * i, r.getrandbits(32))
    _w(c, src + 0x36, s36)
    s3a = e.alloc(0x80, 4)
    for i in range(3):
        e.w32(s3a + 8 * i, r.getrandbits(32))
        e.w32(s3a + 8 * i + 4, srcrecs + 40 * r.randrange(0, 6) + r.choice([0, 0, 7]))
    _w(c, src + 0x3a, s3a if r.random() < 0.8 else 0)
    # this
    for i in range(3):
        e.w32(rec_objs[i] + 0x1c, r.getrandbits(32))
    me = obj(c, 0xa0, {0x48: pystub(c, 1, this=True), 0x230: pystub(c, 0, this=True),
                       0x218: pystub(c, 3, this=True, ret=lambda em, k: handles[k % 4])})
    _w(c, me + 0x2e, cnt)
    for off in (0x46, 0x4a, 0x4e, 0x76, 0x7a, 0x7e, 0x82, 0x86, 0x8a):
        _w(c, me + off, r.getrandbits(32))
    return [me, src]


S(0x4ef210, 'GUESS copy entry from another', 'thiscall', None, ret=None, gen=_g4ef210, note='batch37041')
