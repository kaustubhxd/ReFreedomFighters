"""specs_s36011.py - cascade s4 batch 36011: 0x476970 (build two arrays from a node list), 0x497160 (release entry by computed index), 0x49c560 (mark objects and release list), 0x4f0e10 (write tables to a stream), 0x4f13f0 (set owned string)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, HEAP_LO, HEAP_HI


def _g476970(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = [rnd(c, 0x60), rnd(c, 0x60)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blk[min(k, 1)])
    prev = 0
    for i in range(r.choice([0, 1, 2, 4, 6])):
        t = rnd(c, 0x80)
        node = rnd(c, 0x70)
        e.w32(node + 0x54, t)
        e.w32(node + 0x60, prev)
        prev = node
    holder = rnd(c, 0x70)
    e.w32(holder + 0x50, prev)
    tabo = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=(0 if r.random() < 0.15 else holder)),
                        0x4c: pystub(c, 1, this=True, ret=lambda em, k: 0x1000 + k)})
    so = sysobj(c)
    e.w32(so + 0x9b, tabo)
    me = obj(c, 0x80, {0x28: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    n = r.choice([0, 1, 5, 0x3fffffff, 0x40000000, 0xffffffff, r.getrandbits(32)])
    e.w32(me + 0x5c, n)
    e.wbytes(me + 0x72, bytes([r.choice([0, 0, 1])]))
    e.wbytes(me + 0x73, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


def _g497160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = rnd(c, 0x60)
    if r.random() < 0.15:
        e.w32(a + 0x3c, e.r32(a + 0x3c) | 0x8000000)
    else:
        e.w32(a + 0x3c, e.r32(a + 0x3c) & ~0x8000000)
    q = r.randint(-3, 7)
    u = r.randint(0, 5)
    rem = r.choice([0, 1, 0x6f, 0x70 - 1, r.randint(0, 0x6f)])
    esi_target = q
    base = (a - 0x70 * q - (rem if q >= 0 else -rem)) & 0xffffffff
    P = rnd(c, 0x10)
    e.w32(P + 4, base)
    ux = (0x70 * u + r.choice([0, 1, 0x6f, r.randint(0, 0x6f)])) & 0xffffffff
    tab = e.alloc(0x80, 4)
    for i in range(0x20):
        e.w32(tab + 4 * i, 0 if r.random() < 0.15 else r.getrandbits(32))
    base_idx = 8
    me = obj(c, 0x80, {})
    mask = r.choice([0, 0xf, 0x7, 0x3])
    sl = obj(c, 0x20, {0x10: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100]))})
    e.w32(sl + 0x10, mask)
    # slot 0x10 lives in the vtable of sl; sl[0x10] is the mask field (distinct from the vtable slot)
    arr = rnd(c, 0x40)
    e.w32(me + 8, sl)
    e.w32(me + 0xc, arr)
    e.w32(me + 0x14, P)
    e.w32(me + 0x28, ux)
    idx = q - u
    e.wbytes(me + 0x5d, (tab + 4 * 8).to_bytes(4, 'little'))
    if r.random() < 0.8:
        e2 = obj(c, 0x20, {0x30: pystub(c, 3, this=True)})
        e.w32(0x70038c, e2)
    else:
        e.w32(0x70038c, 0)
    return [me, a]


def _g49c560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lo, hi = r.randint(0, 3), r.choice([0, 0, 1, 2])
    hook_rec(c, 0x49c980, 2, this=True, ret=(hi << 16) | lo)
    hook_rec(c, 0x49cbb0, 3, this=True, ret=lambda em, k: r.choice([0, 1, 3, 0x100, 2]))
    hook_rec(c, 0x49ccc0, 3, this=True, ret=1)
    hook_rec(c, 0x4e6bf0, 1, this=True)
    arrp = e.alloc(0x40, 4)
    for i in range(8):
        e.w32(arrp + 4 * i, rnd(c, 0x80))
    k = r.randint(0, 3)
    tbl = e.alloc(0x40, 4)
    prev = 0
    for i in range(r.choice([0, 1, 3])):
        n = rnd(c, 0x20)
        e.w32(n + 0xc, prev)
        prev = n
    e.w32(tbl + 4 * k, prev)
    me = e.alloc(0x80, 4)
    e.wbytes(me, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.wbytes(me + 0x39, arrp.to_bytes(4, 'little'))
    e.wbytes(me + 0x1d, tbl.to_bytes(4, 'little'))
    a = rnd(c, 0x80)
    e.w32(a + 0x68, k)
    return [me, a]


def _g4f0e10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def h(em, res):
        a0, a1 = em.arg32(0), em.arg32(1)
        if a1 == 8 and not (HEAP_LO <= a0 < HEAP_HI):
            em.calllog.append(('rec', em.r32(a0), em.r32(a0 + 4)))
        else:
            em.calllog.append(('buf', a0, a1))
        em.ret(eax=0, argbytes=8)
    s = obj(c, 0x20, {0x10: e.stub_fn('s10', h), 0x3c: pystub(c, 1, this=True)})
    me = rnd(c, 0x50)
    n = r.choice([0, 1, 2, 3])
    cnt = r.choice([0, 1, 2, 4])
    base = r.getrandbits(32)
    recs = e.alloc(0x40, 4)
    for i in range(4):
        e.w32(recs + 8 * i, r.getrandbits(32))
        d = r.choice([0, 40, 39, 41, -40, -41, 4000, r.randint(-0x10000, 0x10000), r.getrandbits(32)])
        e.w32(recs + 8 * i + 4, (base + d) & 0xffffffff)
    e.w32(me + 0x2e, n)
    e.w32(me + 0x2a, base)
    e.w32(me + 0x32, cnt)
    e.w32(me + 0x3a, recs)
    e.w32(me + 0x36, rnd(c, 0x20))
    return [me, s]


def _g4f13f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nxt = [0]

    def strncpy(em, rr):
        dst, src, cnt = em.arg32(0), em.arg32(1), em.arg32(2)
        data = bytearray(em.rbytes(src, cnt))
        out = bytearray(cnt)
        for i in range(cnt):
            if data[i] == 0:
                break
            out[i] = data[i]
        em.wbytes(dst, bytes(out))
        em.calllog.append(('strncpy', dst, src, cnt))
        em.ret(eax=dst, argbytes=0)
    e.stub_import('strncpy', strncpy)
    bufs = [rnd(c, 0x80), rnd(c, 0x80)]
    so = sysobj(c, slots={0xf8: pystub(c, 1, this=True, ret=lambda em, k: bufs[min(k, 1)]), 0xfc: pystub(c, 1, this=True)})
    me = obj(c, 0x300, {0x278: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0x230: pystub(c, 0, this=True)})
    e.wbytes(me + 0x97, (0 if r.random() < 0.4 else rnd(c, 0x10)).to_bytes(4, 'little'))
    e.wbytes(me + 0x9b, (0 if r.random() < 0.4 else rnd(c, 0x10)).to_bytes(4, 'little'))
    ln = r.choice([0, 1, 3, 20, r.randint(0, 40)])
    src = e.alloc(0x80, 4)
    e.wbytes(src, bytes(r.randint(1, 255) for _ in range(ln)) + bytes([0]) + bytes(r.getrandbits(8) for _ in range(0x20)))
    s = 0 if r.random() < 0.15 else src
    ln2 = ln if r.random() < 0.8 else r.choice([0, ln + 5 if ln + 5 < 0x40 else 3])
    return [me, s, ln2]


S(0x476970, 'GUESS build index arrays from node list', 'thiscall', None, ret=None, gen=_g476970, note='batch36011')
S(0x497160, 'GUESS release entry by computed index', 'thiscall', None, ret='al', gen=_g497160, note='batch36011')
S(0x49c560, 'GUESS mark objects and release waiting list', 'thiscall', None, ret=None, gen=_g49c560, note='batch36011')
S(0x4f0e10, 'GUESS write tables to stream', 'thiscall', None, ret=None, gen=_g4f0e10, note='batch36011')
S(0x4f13f0, 'GUESS set owned string and notify', 'thiscall', None, ret='al', gen=_g4f13f0, note='batch36011')
