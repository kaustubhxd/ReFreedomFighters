"""specs_s38086.py - cascade s8 batch 38086. thiscall(list) ret 4. this = 0x10300-byte random block: segmented container (vtable at this+0x10199, slots 0xc begin / 0x10 advance, Python stubs over real node structures: count +0,
next +8, entry pointers from +0x10), entry table this[0x10071] (4096 pointers to chain heads), a vector at +0x1821d. Entries: flag byte +5 (bit 0 mostly set), type +0x14, object +8 (-> +0x38 -> +0x54 -> F with slot 0x24c (returns A with
slot 0x50), F[0x71], F[8][0x6c]; engine +0x1aa3 -> [+0x18] with slot 0xc4), chain +0x1c, +0x20 -> descriptor chain. 0x658e00 (hook) fills up to 3 node objects whose slot 0x50 walks a prepared object chain. 0x64ea30 hooked;
0x43e920 / 0x441a60 (register-convention vector helpers, normally x87) are replaced by byte-xor hooks; 0x658d30 stays the real exe code. The destination list starts at 0, 3 or near the 0x2000 limit (assert hook path)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g64c4b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    flagvals = [0x100000, 0x300000, 0x200000, 0, 0x100000 | r.getrandbits(8), r.getrandbits(32) & 0xfffff]

    def mkdesc():
        d = rnd(c, 0x40)
        e.wbytes(d + 0x23, struct.pack('<I', r.choice(flagvals)))
        n = rnd(c, 0x20)
        e.w32(n + 0xc, d)
        return n
    # entry-table chains
    def chain_of(k):
        prev = 0
        for _ in range(k):
            x = rnd(c, 0x30)
            e.w32(x + 0x1c, prev)
            prev = x
        return prev
    tbl = e.alloc(4 * 0x1000, 4)
    shared = [rnd(c, 0x30) for _ in range(4)]
    for sobj_ in shared:
        e.w32(sobj_ + 0x1c, chain_of(r.choice([0, 1, 2])))
    e.wbytes(tbl, struct.pack('<4096I', *[shared[(i % 7) % 4] for i in range(0x1000)]))
    this = rnd(c, 0x10300)
    e.wbytes(this + 0x10071, struct.pack('<I', tbl))
    e.wbytes(this + 0x1821d, bytes(r.getrandbits(8) for _ in range(12)))

    def A_obj():
        def s50(em, res_):
            p = em.arg32(0)
            em.calllog.append(('A50', em.reg('ecx') != 0, bytes(em.rbytes(p, 12)), em.arg32(1)))
            em.ret(eax=(r.getrandbits(32) & ~0xff) | r.choice([0, 1, 1]), argbytes=8)
        return obj(c, 0x20, {0x50: e.stub_fn('A50', s50)})
    Y = obj(c, 0x30, {0xc4: e.stub_fn('s-c4', lambda em, res_: (em.calllog.append(('c4', em.reg('ecx') != 0, em.arg32(0))), em.ret(eax=r.getrandbits(32), argbytes=4)))})
    X1 = rnd(c, 0x40)
    e.w32(X1 + 0x18, Y)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, struct.pack('<I', X1))
    Fs = []
    for _ in range(3):
        Ap = A_obj()
        G = rnd(c, 0x80)
        F = obj(c, 0x90, {0x24c: e.stub_fn('s24c', (lambda a: lambda em, res_: (em.calllog.append(('s24c', em.reg('ecx') != 0)), em.ret(eax=a)))(Ap))})
        e.w32(F + 8, G)
        e.wbytes(F + 0x71, bytes([r.choice([0, 1, 1])]))
        Fs.append(F)
    Ws = []
    for F in Fs:
        W = rnd(c, 0x80)
        e.w32(W + 0x54, F)
        Ws.append(W)
    Ps = []
    for _ in range(3):
        P = rnd(c, 0x20)
        Qd = rnd(c, 0x20)
        e.w32(Qd + 0xc, r.getrandbits(32))
        e.w32(P + 0xc, Qd)
        Ps.append(P)

    def mkentry():
        en = rnd(c, 0x40)
        o = rnd(c, 0x80)
        e.w32(o + 0x38, r.choice(Ws))
        e.wbytes(en + 5, bytes([r.choice([1, 1, 1, 0, 3])]))
        e.w32(en + 8, o)
        e.wbytes(en + 0x14, bytes([r.choice([0, 1, 2, 5])]))
        e.w32(en + 0x1c, chain_of(r.choice([0, 0, 1, 2])))
        e.w32(en + 0x20, r.choice(Ps))
        return en
    nsegs = r.choice([0, 1, 2, 3])
    segs = []
    for _ in range(nsegs):
        n = r.choice([1, 2, 3])
        nd = rnd(c, 0x40)
        e.w32(nd, n)
        for i in range(n):
            e.w32(nd + 0x10 + 4 * i, mkentry())
        segs.append(nd)
    for a, b in zip(segs, segs[1:] + [0]):
        e.w32(a + 8, b)

    def begin(em, res_):
        p = em.arg32(0)
        em.calllog.append(('begin', em.reg('ecx') != 0))
        if segs:
            em.w32(p, segs[0] + 0x10)
            em.w32(p + 4, 0)
            em.w32(p + 8, segs[0])
        else:
            em.w32(p, 0)
            em.w32(p + 4, 0)
            em.w32(p + 8, 0)
        em.ret(eax=0, argbytes=4)

    def adv(em, res_):
        p = em.arg32(0)
        em.calllog.append(('advance', em.reg('ecx') != 0))
        idx = em.r32(p + 4) + 1
        node = em.r32(p + 8)
        if idx == em.r32(node):
            node = em.r32(node + 8)
            em.w32(p + 8, node)
            if not node:
                em.w32(p, 0)
            else:
                em.w32(p + 4, 0)
                em.w32(p, node + 0x10)
        else:
            em.w32(p + 4, idx)
            em.w32(p, em.r32(p) + 4)
        em.ret(eax=0, argbytes=4)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0xc, e.stub_fn('begin', begin))
    e.w32(vt + 0x10, e.stub_fn('advance', adv))
    e.wbytes(this + 0x10199, struct.pack('<I', vt))

    def walker_obj():
        qs = []
        for _ in range(r.choice([0, 1, 2])):
            q = rnd(c, 0x80)
            e.wbytes(q + 0x5a, struct.pack('<H', r.choice([0, 1, 5, 0x1003, 0x2000 | 7, 0x805, 0x806])))
            e.w32(q + 0x54, r.choice([0, mkdesc()]))
            qs.append(q)
        st = {'i': 0}

        def s50(em, res_):
            st['i'] += 1
            nxt = qs[st['i']] if st['i'] < len(qs) else 0
            em.calllog.append(('N50', em.reg('ecx') != 0, st['i']))
            em.w32(em.arg32(0), nxt)
            em.ret(eax=0, argbytes=4)
        nb = obj(c, 0x40, {0x50: e.stub_fn('N50', s50)})
        e.w32(nb + 0xc, r.choice([0, 1]) and 0 or mkdesc_d())
        e.w32(nb + 8, qs[0] if qs else 0)
        return nb

    def mkdesc_d():
        d = rnd(c, 0x40)
        e.wbytes(d + 0x23, struct.pack('<I', r.choice(flagvals)))
        return d

    def h658e00(em, res_):
        arr, n = em.arg32(0), em.arg32(1)
        k = r.choice([0, 1, 1, 2, 3])
        em.calllog.append(('658e00', em.reg('ecx') != 0, n, k))
        for i in range(k):
            nk = rnd(c, 0x60)
            e.w32(nk + 0x54, r.choice([0, walker_obj(), walker_obj()]))
            em.w32(arr + 4 * i, nk)
        em.ret(eax=k, argbytes=8)
    e.hook(0x658e00, h658e00)
    hook_rec(c, 0x64ea30, 1, this=True, pop=4)

    def vsub(em, res_):
        out, a, b = em.reg('ecx'), em.reg('edx'), em.arg32(0)
        av, bv = em.rbytes(a, 12), em.rbytes(b, 12)
        em.calllog.append(('vsub', bytes(av), bytes(bv)))
        em.wbytes(out, bytes(x ^ y for x, y in zip(av, bv)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x43e920, vsub)

    def vmul(em, res_):
        v, m = em.reg('ecx'), em.reg('edx')
        vv, mv = em.rbytes(v, 12), em.rbytes(m, 12)
        em.calllog.append(('vmul', bytes(mv)))
        em.wbytes(v, bytes(x ^ y for x, y in zip(vv, mv)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x441a60, vmul)
    lst = rnd(c, 0x8400)
    e.w32(lst, r.choice([0, 0, 3, 0x1ffe, 0x1fff, 0x2000]))
    return [this, lst]


S(0x64c4b0, 'GUESS collect visible entry chains', 'thiscall', None, ret=None, gen=_g64c4b0, note='batch38086')
