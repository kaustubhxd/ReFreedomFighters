"""specs_s35157.py - 0x51c3d0 (thiscall(a) ret 4, ret='eax'). this: object with slot 0x328 (3 args recorded; returns ch) and slot 0x8c (1 arg, the vector is recorded as its 3 dwords); unaligned dword +0x451 random. ch: object with [+8] = block and slot 0xbc (1 arg).
0x4db670 hooked (this = a, 1 arg flag-recorded; side effect overwrites a random subset of the 3 vector dwords with random values), 0x4de7a0 hooked (this on the caller's stack, marked; fills the 0x24 bytes with random bytes), 0x4dcb50 hooked (this = [ch+8], args: the 0x24 bytes as 9 dwords and the vector as 3 dwords)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g51c3d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ch = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0x30)
    e.w32(ch + 8, rnd(c, 0x20))

    def w670(em, k):
        v = em.arg32(0)
        for i in range(3):
            if r.random() < 0.5:
                em.w32(v + 4 * i, r.getrandbits(32))

    def w7a0(em, k):
        em.wbytes(em.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x24)))
    a = rnd(c, 0x20)
    hook_rec(c, 0x4db670, 1, this=True, nullflag=(0,), side=w670)
    hook_rec(c, 0x4de7a0, 0, this='mark', side=w7a0)
    hook_rec(c, 0x4dcb50, 2, this=True, deref={0: 9, 1: 3})
    me = obj(c, 0x470, {0x328: pystub(c, 3, this=True, ret=ch), 0x8c: pystub(c, 1, this=True, deref={0: 3})}, nslots=0xd0)
    return [me, a]


S(0x51c3d0, 'GUESS create child object, place it and apply a transform', 'thiscall', None, ret='eax', gen=_g51c3d0, note='batch35157')
