"""specs_s37006.py - cascade s6 batch 37006: 0x64c2d0. List object at this+0x10199 (slot 0xc starts an iterator {ptr, idx, chunk}, slot 0x10 advances it);
hooks: 0x645c10, 0x658e00 (fills up to 8 object pointers), 0x64d030, 0x658fd0; engine +0x3c is the key; chain objects have slot 0x50."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

TAGS = [0x100000, 0x300000, 0, 0x200002, 0x100bbd]


def _tag(c, tagp_owner_off=None):
    r = c.rng
    e = c.emu
    T = rnd(c, 0x40)
    e.w32(T + 0x23, r.choice(TAGS) if r.random() < 0.9 else r.getrandbits(32))
    O = rnd(c, 0x20)
    e.w32(O + 0xc, T)
    return O


def _g64c2d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    so = sysobj(c)
    key = r.getrandbits(32)
    e.w32(so + 0x3c, key)
    # chain objects (F) and holders
    nxt = {}

    def mkF():
        F = rnd(c, 0x80)
        fl = e.r32(F + 0x3c)
        fl = (fl | 0x2c00) if r.random() < 0.2 else (fl & ~0x2c00)
        e.w32(F + 0x3c, fl & 0xffffffff)
        if r.random() < 0.15:
            e.w32(F + 0x6c, 0)
        if r.random() < 0.3:
            e.wbytes(F + 0x5a, bytes(2))
        e.w32(F + 0x54, _tag(c) if r.random() < 0.8 else 0)
        return F
    holders = []
    for _ in range(5):
        chain = [mkF() for _ in range(r.choice([0, 1, 2, 3]))]
        for a, b in zip(chain, chain[1:] + [0]):
            nxt[a] = b
        E = obj(c, 0x40, {0x50: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), nxt.get(em.r32(em.arg32(0)), 0)))})
        if chain:
            e.w32(E + 8, chain[0])
        else:
            e.w32(E + 8, mkF())
            nxt[e.r32(E + 8)] = 0
        e.w32(E + 0xc, _tag(c) if False else 0)
        T = rnd(c, 0x40)
        e.w32(T + 0x23, r.choice(TAGS))
        e.w32(E + 0xc, T)
        cobj = rnd(c, 0x80)
        e.w32(cobj + 0x54, E if r.random() < 0.85 else 0)
        holders.append(cobj)

    def fill(em, k):
        arr = em.arg32(0)
        for i in range(8):
            em.w32(arr + 4 * i, holders[(k + i) % 5])
    holder_me = []

    def rec4d(em, k):
        em.calllog.append(('p4d', em.r32(holder_me[0] + 0x1004d)))

    def fill2(em, k):
        rec4d(em, k)
        fill(em, k)
    hook_rec(c, 0x658e00, 2, this=True, nullflag=(0,), ret=lambda em, k: r.choice([0, 1, 2, 3, 8]), side=fill2)
    rr = [rnd(c, 0x20) for _ in range(3)]
    for x in rr:
        e.w32(x + 8, rnd(c, 0x20))
    hook_rec(c, 0x64d030, 4, this=True, side=rec4d, ret=lambda em, k: 0 if k % 4 == 2 else rr[k % 3])
    hook_rec(c, 0x658fd0, 1, this=True, side=rec4d)
    hook_rec(c, 0x645c10, 1, this=True)
    Rr = rnd(c, 0x10)
    Q = obj(c, 0x20, {0x24c: pystub(c, 0, this=True, ret=Rr)})
    # nodes
    chunks = []
    nch = r.choice([1, 1, 2])
    nodes_total = []
    for ci in range(nch):
        n = r.choice([1, 2, 3])
        ch = rnd(c, 0x10 + 4 * n + 8)
        e.w32(ch, n)
        e.w32(ch + 8, 0)
        for j in range(n):
            node = rnd(c, 0x40)
            e.w32(node + 0x10, key if r.random() < 0.7 else r.getrandbits(32))
            B = rnd(c, 0x60)
            Pp = rnd(c, 0x60)
            e.w32(Pp + 0x54, Q)
            e.w32(B + 0x38, Pp)
            e.w32(node + 8, B)
            cell = ch + 0x10 + 4 * j
            e.w32(cell, node)
        chunks.append(ch)
    for a, b in zip(chunks, chunks[1:]):
        e.w32(a + 8, b)
    me = e.alloc(0x10300, 4)
    holder_me.append(me)
    L = me + 0x10199

    def begin(em, k):
        it = em.arg32(0)
        if r.random() < 0.08:
            em.w32(it, 0)
            em.w32(it + 4, 0)
            em.w32(it + 8, 0)
        else:
            em.w32(it, chunks[0] + 0x10)
            em.w32(it + 4, 0)
            em.w32(it + 8, chunks[0])

    def advance(em, k):
        it = em.arg32(0)
        idx = em.r32(it + 4) + 1
        chk = em.r32(it + 8)
        if idx == em.r32(chk):
            nx = em.r32(chk + 8)
            em.w32(it + 8, nx)
            if nx:
                em.w32(it + 4, 0)
                em.w32(it, nx + 0x10)
            else:
                em.w32(it, 0)
                em.w32(it + 4, idx)
        else:
            em.w32(it + 4, idx)
            em.w32(it, em.r32(it) + 4)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0xc, pystub(c, 1, this=True, nullflag=(0,), side=begin))
    e.w32(vt + 0x10, pystub(c, 1, this=True, nullflag=(0,), side=advance))
    e.w32(L, vt)
    return [me]


S(0x64c2d0, 'GUESS walk node list and dispatch chain', 'thiscall', None, ret=None, gen=_g64c2d0, note='batch37006')
