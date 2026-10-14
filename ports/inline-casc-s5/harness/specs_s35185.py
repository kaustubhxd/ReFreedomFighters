"""specs_s35185.py - 0x443330 (thiscall(arr, a2, a3, mat, c, half, a7, flag) ret 0x20, ret='eax'). this: slot 0x340 (1 arg; returns obj2, null in 1/6) and slot 0x98 (2 args, the stack matrix copy Y as 9 dwords and W as 3 dwords recorded). obj2: slot 0x1c (3 args; logs the initialised L fields, records X1 and X2 as 3 dwords each and
writes the count 0..4 at L+0x68). Entries: 4 candidate blocks of 0x80 bytes in arr. 4db600 hooked (thiscall, 2 args: M as 9 dwords and Z as 3 dwords recorded, M randomised), 4df330 replaced by a Python handler (logs Y, W, M, Z and the pointer arguments; returns true/false from a random list).
mat, c, half: float vectors; flag: low byte zero in 1/4 (upper bytes random)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, _HOOKED


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _vec(c, n, lo=-20, hi=20):
    p = rnd(c, 4 * n)
    for i in range(n):
        c.emu.w32(p + 4 * i, _fb(c.fv(lo, hi)))
    return p


def _g443330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([0, 1, 2, 3, 4, 4])
    cnt2 = r.choice([cnt, cnt, cnt, 0, r.randint(1, 4)])
    Lseen = []

    def s1c(em, k):
        L = em.arg32(0)
        em.calllog.append(('L', em.r32(L), em.r32(L + 4), em.r32(L + 0x5c), em.r32(L + 0x60), em.r32(L + 0x64)))
        Lseen.append(L)
        em.w32(L + 0x68, cnt)
    obj2 = obj(c, 0x20, {0x1c: pystub(c, 3, this=True, nullflag=(0,), deref={1: 3, 2: 3}, side=s1c)}, nslots=0x10)
    this = obj(c, 0x20, {0x340: pystub(c, 1, this=True, ret=0 if r.random() < 1 / 6 else obj2),
                         0x98: pystub(c, 2, this=True, deref={0: 9, 1: 3}, side=lambda em, k: em.w32(Lseen[-1] + 0x68, cnt2))}, nslots=0xd2)

    def side600(em, k):
        m = em.arg32(0)
        for i in range(9):
            if r.random() < 0.5:
                em.w32(m + 4 * i, _fb(c.fv(-3, 3)))
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
    ptrs = [rnd(c, 0x80) for _ in range(4)]
    arr = rnd(c, 0x20)
    for i, p in enumerate(ptrs):
        e.w32(arr + 4 * i, p)
    flag = (r.getrandbits(24) << 8) | (0 if r.random() < 1 / 4 else r.randint(1, 255))
    return [this, arr, r.getrandbits(32), r.getrandbits(32), _vec(c, 9, -2, 2), _vec(c, 3), _vec(c, 3, 0, 10), r.getrandbits(32), flag]


S(0x443330, 'GUESS cull candidate array against a box', 'thiscall', None, ret='eax', gen=_g443330, note='batch35185')
