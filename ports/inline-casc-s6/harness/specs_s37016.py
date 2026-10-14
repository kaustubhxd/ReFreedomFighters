"""specs_s37016.py - cascade s6 batch 37016: 0x497470. Hooked: 0x41e290 (returns a spec buffer), 0x634d10 (memset, performs the fill), 0x496380 (logs the whole bit
buffer). a: slot 4 (1 arg). Entries (0x70 bytes) in a region; chain ends carry +0x54 objects with slot 0x50 that walk a list of entry pointers."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

TAGS = [0x100000, 0x300000, 0, 0x200002, 0x100bbd]


def _g497470(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    cnt = r.choice([0, 1, 3, 7, 8, 9, 13, 16, 20])
    nbytes = (cnt + 7) >> 3
    n = cnt * 0x70 + r.choice([0, 1, 0x6f])
    buf = rnd(c, nbytes + 8)
    hook_rec(c, 0x41e290, 1, pop=0, ret=buf)

    def fill(em, k):
        p, v, nn = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(p, bytes([v & 0xff]) * nn)
    hook_rec(c, 0x634d10, 3, pop=0, side=fill)

    def logbuf(em, k):
        em.calllog.append(('buf', bytes(em.rbytes(buf, nbytes))))
    hook_rec(c, 0x496380, 1, this=True, side=logbuf)
    reg = e.alloc(max(nbytes, 1) * 0x380 + 0x40, 4)
    nent = max(nbytes, 1) * 8
    ents = [reg + 0x70 * j for j in range(nent)]
    for j, a in enumerate(ents):
        e.wbytes(a, bytes(r.getrandbits(8) for _ in range(0x70)))
        fl = e.r32(a + 0x3c)
        fl = (fl | 0x4000000) if r.random() < 0.4 else (fl & ~0x4000000)
        e.w32(a + 0x3c, fl & 0xffffffff)
    nxt = {}

    def mkQ():
        lst = [r.choice(ents) for _ in range(r.choice([0, 1, 2, 3]))]
        for x, y in zip(lst, lst[1:] + [0]):
            nxt[x] = y
        T = rnd(c, 0x40)
        e.w32(T + 0x23, r.choice(TAGS))
        Q = obj(c, 0x20, {0x50: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), nxt.get(em.r32(em.arg32(0)), 0)))})
        e.w32(Q + 0xc, T)
        e.w32(Q + 8, lst[0] if lst else 0)
        return Q
    nodes = []
    for _ in range(4):
        nd = rnd(c, 0x60)
        e.w32(nd + 0x50, 0)
        e.w32(nd + 0x54, mkQ() if r.random() < 0.85 else 0)
        nodes.append(nd)
    e.w32(nodes[0] + 0x50, nodes[1])
    for a in ents:
        x = r.random()
        e.w32(a + 0x50, 0 if x < 0.4 else (r.choice(nodes) if x < 0.8 else r.choice(ents[:max(nent, 1)])) if False else (0 if x < 0.4 else r.choice(nodes)))
        e.w32(a + 0x54, mkQ() if r.random() < 0.3 else 0)
    # an ent used as chain end must have +0x50 == 0 only when reached via nodes; entries pointing to nodes end there.
    holder = rnd(c, 0x20)
    e.w32(holder + 0xc, n)
    e.w32(holder + 4, reg)
    me = rnd(c, 0x40)
    e.w32(me + 0x14, holder)
    a = obj(c, 0x20, {0x4: pystub(c, 1, this=True)})
    return [me, a]


S(0x497470, 'GUESS build and process bit set of entries', 'thiscall', None, ret=None, gen=_g497470, note='batch37016')
