"""specs_s50006.py - u3 (Sonnet) batch 50006, tier H. 0x65be00: engine object +0x1aa3 (unaligned) -> M with [M+0x20] = base L and [M+0x18] = object whose slot 0xbc(K) returns the matrix array A;
container at this+0x1c8 (slot 0xc returns an iterator struct {cur, idx, node} over 1-3 blocks); entries E with [E+0x38] -> X, [X+0x6c] = K, counts N = dword at L + K + 0x7c (0..3, shared K values),
0x658d30 / 0x658d80 hooked (per-entry arrays B and C), 0x659c40 hooked; 0x4dfd10, 0x4de480 and 0x459fc0 run as exe code; C arrays are random-filled so every stored word is observable."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fl(r):
    return struct.pack('<f', r.uniform(-4, 4))


def _g65be00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    hook_rec(c, 0x659c40, 0, this=True, ret=r.getrandbits(32))
    so = sysobj(c)
    L = rnd(c, 0x400)
    nelem = r.choice([0, 1, 2, 3, 5])
    Ks = [r.choice([0, 0x10, 0x20, 0x40, 0x100]) for _ in range(nelem)]
    Ns = {}
    for k in set(Ks):
        Ns[k] = r.choice([0, 1, 2, 3, 5])
        e.w32(L + k + 0x7c, Ns[k])
    elems, As, Bs, Cs = [], [], [], []
    for k in Ks:
        n = Ns[k]
        X = rnd(c, 0x80)
        e.w32(X + 0x6c, k)
        E = rnd(c, 0x60)
        e.w32(E + 0x38, X)
        elems.append(E)
        for lst, fill in ((As, True), (Bs, True), (Cs, False)):
            a = rnd(c, 0x30 * max(n, 1) + 0x30)
            if fill:
                for j in range((0x30 * max(n, 1)) // 4):
                    e.wbytes(a + 4 * j, _fl(r))
            lst.append(a)
    hook_rec(c, 0x658d30, 0, this=True, ret=lambda em, k: Bs[min(k, len(Bs) - 1)])
    hook_rec(c, 0x658d80, 0, this=True, ret=lambda em, k: Cs[min(k, len(Cs) - 1)])
    o18 = obj(c, 0x20, {0xbc: pystub(c, 1, this=True, ret=lambda em, k: As[min(k, len(As) - 1)])}, nslots=0xc0 // 4)
    M = rnd(c, 0x40)
    e.w32(M + 0x18, o18)
    e.w32(M + 0x20, L)
    e.wbytes(so + 0x1aa3, M.to_bytes(4, 'little'))
    blocks = []
    i = 0
    while i < len(elems):
        n = min(len(elems) - i, r.randrange(1, 4))
        b = rnd(c, 0x10 + 4 * n + 8)
        e.w32(b, n)
        for j in range(n):
            e.w32(b + 0x10 + 4 * j, elems[i + j])
        blocks.append(b)
        i += n
    for j, b in enumerate(blocks):
        e.w32(b + 8, blocks[j + 1] if j + 1 < len(blocks) else 0)
    head = blocks[0] if blocks else 0
    st = rnd(c, 0x10)
    e.w32(st, head + 0x10 if head else 0)
    e.w32(st + 4, 0)
    e.w32(st + 8, head)

    def begin(em, k):
        em.calllog.append(('begin',))
        em.ret(st, 4)
    vt = e.alloc(0x20, 4)
    e.w32(vt + 0xc, e.stub_fn('begin', begin))
    me = rnd(c, 0x1e0)
    e.w32(me + 0x1c8, vt)
    return [me]


S(0x65be00, 'GUESS rebuild per-bone transform arrays', 'thiscall', None, ret=None, gen=_g65be00, nan_heap=True, note='batch50006')
