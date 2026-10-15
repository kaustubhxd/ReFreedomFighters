"""specs_s38097.py - cascade s8 batch 38097. thiscall(list, key) ret 8 -> object. Engine table slots 0x54 (id -> pool object 1..6, 0 otherwise), 0x58 (id -> record whose +0x50 is a pool object or null), 0x50 (key -> key + 1).
Pool objects: flags +0x3c (bit 10 usually set), key2 +0x50, descriptor +0x54 (name pointer at +4 or null, chain object at +0x54 -> +0x54 -> +0xc -> flag dword at +0x23). The list argument (null 10%) has 0..3 nodes {id +0,
key +0xc}; this+0x4c (null 15%) -> owner whose +0x18 is a second list of 0..3 ids (next stub: it[0] = valid, it[4] = index). 0x4db9a0 (random bool), 0x4dc130, 0x4db520 are hooks; _stricmp (IAT 0x676414) compares
the names case-insensitively and logs."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _cstr(em, p, lim=0x40):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g4b00e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nm = {}
    for s in (b'alpha', b'ALPHA', b'beta'):
        p = e.alloc(0x10, 1)
        e.wbytes(p, s + b'\0')
        nm[s] = p
    names = list(nm.values()) + [0, 0]
    flagvals = [0, 0x100000, 0x200000, 0x300000, 0x80]
    Es = []

    def mkE():
        E = rnd(c, 0x80)
        if r.random() < 0.8:
            G = rnd(c, 0x40)
            e.wbytes(G + 0x23, struct.pack('<I', r.choice(flagvals)))
            F = rnd(c, 0x40)
            e.w32(F + 0xc, G)
            e.w32(E + 0x54, F)
        else:
            e.w32(E + 0x54, 0)
        Es.append(E)
        return E

    def mkpool():
        o = rnd(c, 0x80)
        e.w32(o + 0x3c, r.getrandbits(32) | (0x400 if r.random() < 0.8 else 0) if True else 0)
        if r.random() < 0.2:
            e.w32(o + 0x3c, e.r32(o + 0x3c) & ~0x400)
        e.w32(o + 0x50, r.choice([1, 2, 3]))
        D = rnd(c, 0x80)
        e.w32(D + 4, r.choice(names))
        e.w32(D + 0x54, r.choice([0, mkE(), mkE()]))
        e.w32(o + 0x54, D)
        return o
    pool = {i: mkpool() for i in range(1, 7)}
    rec = {}
    for i in range(1, 7):
        x = rnd(c, 0x60)
        e.w32(x + 0x50, r.choice([0] + list(pool.values())))
        rec[i] = x

    def t54(em, res_):
        i = em.arg32(0)
        em.calllog.append(('t54', i))
        em.ret(eax=pool.get(i, 0), argbytes=4)

    def t58(em, res_):
        i = em.arg32(0)
        em.calllog.append(('t58', i))
        em.ret(eax=rec.get(i, 0), argbytes=4)

    def t50(em, res_):
        k = em.arg32(0)
        em.calllog.append(('t50', k))
        em.ret(eax=k + 1, argbytes=4)
    sysobj(c, table_slots={0x54: e.stub_fn('t54', t54), 0x58: e.stub_fn('t58', t58), 0x50: e.stub_fn('t50', t50)})

    def mklist(ids_nodes):
        def begin(em, res_):
            em.calllog.append(('begin',))
            em.w32(em.arg32(0), 0)
            em.ret(eax=0, argbytes=4)

        def nxt(em, res_):
            p = em.arg32(0)
            i = em.r32(p)
            em.calllog.append(('next', i))
            em.w32(p, i + 1)
            em.ret(eax=(ids_nodes[i] if i < len(ids_nodes) else 0), argbytes=4)
        return obj(c, 0x40, {0x4c: e.stub_fn('begin', begin), 0x64: e.stub_fn('next', nxt)})
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n = rnd(c, 0x20)
        e.w32(n, r.choice([1, 2, 3, 4, 5, 6]))
        e.w32(n + 0xc, r.choice([1, 2, 3, 4, 5]))
        nodes.append(n)
    L = mklist(nodes) if r.random() > 0.1 else 0
    ids = [r.choice([1, 2, 3, 4, 5, 6]) for _ in range(r.choice([0, 1, 2, 3]))]

    def begin2(em, res_):
        em.calllog.append(('begin2',))
        em.w32(em.arg32(0), 0)
        em.w32(em.arg32(0) + 4, 0)
        em.ret(eax=0, argbytes=4)

    def nxt2(em, res_):
        p = em.arg32(0)
        i = em.r32(p + 4)
        ok = i < len(ids)
        em.calllog.append(('next2', i, ok))
        em.w32(p, 1 if ok else 0)
        em.w32(p + 4, i + 1)
        em.ret(eax=(ids[i] if ok else 0), argbytes=4)
    L2 = obj(c, 0x40, {0x4c: e.stub_fn('begin2', begin2), 0x5c: e.stub_fn('next2', nxt2)})
    owner = rnd(c, 0x40)
    e.w32(owner + 0x18, L2 if r.random() > 0.1 else 0)
    this = rnd(c, 0x80)
    e.w32(this + 0x4c, owner if r.random() > 0.15 else 0)
    qs = []
    for _ in range(3):
        q = rnd(c, 0x20)
        e.w32(q + 4, r.choice(names))
        qs.append(q)
    hook_rec(c, 0x4db9a0, 1, this=True, pop=4, ret=lambda em, k: r.choice([0, 1, 1]))
    hook_rec(c, 0x4dc130, 0, this=True, pop=0, ret=lambda em, k: r.choice(qs))
    hook_rec(c, 0x4db520, 0, this=True, pop=0, ret=lambda em, k: r.choice(Es + [0]))

    def sic(em, res_):
        a, b = _cstr(em, em.arg32(0)).lower(), _cstr(em, em.arg32(1)).lower()
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a == b else 1, argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', sic))
    return [this, L, r.choice([1, 2, 3, 4, 5, 6, 9])]


S(0x4b00e0, 'GUESS resolve object by key', 'thiscall', None, ret='eax', gen=_g4b00e0, note='batch38097')
