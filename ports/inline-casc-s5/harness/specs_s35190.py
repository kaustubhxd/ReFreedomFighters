"""specs_s35190.py - 0x4ecd30 (stdcall(arr, a2, a3, items, count, mat, c, half, a9, flag) ret 0x28, ret='eax', nan_heap). Engine table +0xadc -> manager with slot 0x314 (0 args; returns M, null in 1/6). items: 0..3 pointers to candidate blocks (0x80 random bytes); count in 0..3 (matching). 0x4e4420 replaced by a Python handler (ecx = M raw, X1 / X2 as 3 dwords, L fields logged:
L[0], L[1], +0x5c, +0x60, +0x68, +0x6c, +0x70; appends the item at L+0x70 to the array at L+0x5c with probability 0.7 and bumps the count at L+0x64), 0x4ec6d0 replaced (logs L+0x64 and L+0x1074), 0x4db600 hooked (2 args, M2 and Z as dwords, M2 randomised), 0x4df330 replaced (logs mat, c, M2, Z and pointer args; returns bool from a random list).
mat, c, half: float vectors (heap); flag: low byte zero in 1/4."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj, _HOOKED


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _vec(c, n, lo=-20, hi=20):
    p = rnd(c, 4 * n)
    for i in range(n):
        v = c.fv(lo, hi)
        c.emu.w32(p + 4 * i, _fb(v if v == v else 0.5))
    return p


def _g4ecd30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    Mobj = rnd(c, 0x20)
    mgr = obj(c, 0x20, {0x314: pystub(c, 0, this=True, ret=0 if r.random() < 1 / 6 else Mobj)}, nslots=0xd0)
    so = sysobj(c, table_size=0xae0)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, mgr)
    ncount = r.choice([0, 1, 2, 3, 3])
    blocks = [rnd(c, 0x80) for _ in range(3)]
    items = rnd(c, 0x10)
    for i in range(3):
        e.w32(items + 4 * i, blocks[i])
    arr = rnd(c, 0x20)
    for i in range(3):
        e.w32(arr + 4 * i, blocks[i])
    take = [r.random() < 0.7 for _ in range(4)]
    cnt4 = [0]

    def h4420(em, res_):
        L, x1, x2 = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('4e4420', em.reg('ecx'), tuple(em.r32(x1 + 4 * i) for i in range(3)), tuple(em.r32(x2 + 4 * i) for i in range(3)),
                           tuple(em.r32(L + o) for o in (0, 4, 0x5c, 0x60, 0x68, 0x6c, 0x70, 0x1074))))
        k = cnt4[0]
        cnt4[0] += 1
        if take[min(k, 3)]:
            n = em.r32(L + 0x64)
            em.w32(em.r32(L + 0x5c) + 4 * n, em.r32(L + 0x70))
            em.w32(L + 0x64, n + 1)
        em.ret(argbytes=0xc)

    def h6d0(em, res_):
        L = em.reg('ecx')
        em.calllog.append(('4ec6d0', em.r32(L + 0x64), em.r32(L + 0x1074)))
        em.ret(argbytes=0)
    e.hook(0x4e4420, h4420)
    e.hook(0x4ec6d0, h6d0)
    _HOOKED.add(0x4e4420)
    _HOOKED.add(0x4ec6d0)

    def side600(em, k):
        m = em.arg32(0)
        for i in range(9):
            if r.random() < 0.5:
                em.w32(m + 4 * i, _fb(c.fv(-3, 3) if True else 0))
    hook_rec(c, 0x4db600, 2, this=True, pop=8, deref={0: 9, 1: 3}, side=side600)
    oks = [r.random() < 0.55 for _ in range(8)]
    n330 = [0]

    def h330(em, res_):
        y, w = em.reg('ecx'), em.reg('edx')
        m, z = em.arg32(1), em.arg32(2)
        em.calllog.append(('4df330', tuple(em.r32(y + 4 * i) for i in range(9)), tuple(em.r32(w + 4 * i) for i in range(3)), em.arg32(0),
                           tuple(em.r32(m + 4 * i) for i in range(9)), tuple(em.r32(z + 4 * i) for i in range(3)), em.arg32(3)))
        v = oks[min(n330[0], 7)]
        n330[0] += 1
        em.ret(eax=((r.getrandbits(24) << 8) | 1) if v else (r.getrandbits(24) << 8), argbytes=0x10)
    e.hook(0x4df330, h330)
    _HOOKED.add(0x4df330)
    flag = (r.getrandbits(24) << 8) | (0 if r.random() < 1 / 4 else r.randint(1, 255))
    return [arr, r.getrandbits(32), r.getrandbits(32), items, ncount, _vec(c, 9, -2, 2), _vec(c, 3), _vec(c, 3, 0, 10), r.getrandbits(32), flag]


S(0x4ecd30, 'GUESS collect scene objects in a box and cull them', 'stdcall', None, ret='eax', gen=_g4ecd30, nan_heap=True, note='batch35190')
