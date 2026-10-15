"""specs_s46006.py - cascade t7 batch 46006: 0x52d750 recursive octree/box walk (thiscall this + 9 stack args). The walk object has visitor objects at +0/+4/+8
(slot 0) and a stop flag at +0x10; 0x52d580 (the depth-0 leaf step) is a recorder that may rewrite the node index through its pointer. The recursion runs the
exe's own code in the original and the port's own code in the port."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g52d750(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 6
    tab = rnd(c, 0x16 * (N + 1) + 8)
    for i in range(N + 1):
        for off in (6, 8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14):
            e.wbytes(tab + i * 0x16 + off, r.choice([0, 0, 1, 2, 3, 4, 5, 6, r.randrange(0, N + 1)]).to_bytes(2, 'little'))
    me = rnd(c, 0x80)
    e.w32(me + 0x54, tab)
    M = 64
    rv1 = [r.random() > 0.08 for _ in range(M)]
    rv2 = [r.choice([0, 0, 0, 1, 2]) for _ in range(M)]
    rv3 = [r.choice([0, 0, 1, 3]) for _ in range(M)]
    rv5 = [r.choice([0, 1, 5, r.getrandbits(32)]) for _ in range(M)]
    boxw = [(r.randrange(0, 6), r.getrandbits(32)) for _ in range(M)]
    idxw = [r.choice([None, None, r.randrange(0, N + 1)]) for _ in range(M)]

    def logbox(em, ptr_lo):
        em.calllog.append(('box',) + tuple(em.r32(ptr_lo + 4 * i) for i in range(6)))

    def s1(em, k):
        lo = em.arg32(2)
        logbox(em, lo)
        w = boxw[k % M]
        if w[0] < 3:
            em.w32(lo + 4 * (w[0] * 2 % 6), w[1])

    def s2(em, k):
        lo = em.arg32(2)
        logbox(em, lo)
        em.calllog.append(('idx', em.r32(em.arg32(1)) & 0xffff))

    def s5(em, k):
        em.calllog.append(('idx5', em.r32(em.arg32(1)) & 0xffff))
        w = idxw[k % M]
        if w is not None:
            em.w32(em.arg32(1), w)
    n1 = [0]
    v1 = obj(c, 0x20, {0: pystub(c, 4, this=True, stackmark=(2, 3), ret=lambda em, k: int(rv1[k % M]), side=s1)}) if r.random() < 0.8 else 0
    v2 = obj(c, 0x20, {0: pystub(c, 5, this=True, stackmark=(1, 2, 3), ret=lambda em, k: rv2[k % M], side=s2)}) if r.random() < 0.7 else 0
    v3 = obj(c, 0x20, {0: pystub(c, 5, this=True, stackmark=(1, 2, 3), ret=lambda em, k: rv3[k % M], side=s2)}) if r.random() < 0.7 else 0
    a0 = rnd(c, 0x20)
    e.w32(a0, v1)
    e.w32(a0 + 4, v2)
    e.w32(a0 + 8, v3)
    e.wbytes(a0 + 0x10, bytes([r.choice([0, 0, 1])]))
    hook_rec(c, 0x52d580, 9, this=True, stackmark=(1,), ret=lambda em, k: rv5[k % M], side=s5)
    idx = rnd(c, 4)
    e.wbytes(idx, r.choice([0, 1, 1, 2, 3, 5, 6, r.getrandbits(16)]).to_bytes(2, 'little') if r.random() < 0.9 else b'\x00\x00')
    # idx values above N would read past the table: keep within it
    if e.r32(idx) & 0xffff > N:
        e.wbytes(idx, (r.randrange(0, N + 1)).to_bytes(2, 'little'))
    depth = r.choice([0, 1, 1, 2, 2, 3])

    def coord():
        return r.choice([r.randrange(-5000, 5000), r.randrange(-100, 100), r.getrandbits(32) - 0x80000000, 0x7fffffff, 0x80000000 - 0x100000000])
    args = [a0, idx, depth] + [coord() & 0xffffffff for _ in range(6)]
    return [me] + args


S(0x52d750, 'GUESS octree box walk', 'thiscall', None, ret='eax', gen=g52d750, note='batch46006')
