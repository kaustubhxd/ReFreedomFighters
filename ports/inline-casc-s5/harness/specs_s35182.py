"""specs_s35182.py - 0x5df1c0 (thiscall(s) ret 4, ret=None, nan_heap). this: 0x40 random bytes. s: object with slot 0x40 (1 arg, heap pointers recorded as is and stack pointers as a marker; writes a random dword, usually packed angles, through its argument; returns o2), slot 0x6c (1 arg), slot 0x50 (1 arg, flag-recorded stack
pointer; writes a random float through it). o2: slot 0x40 (1 arg). 0x5de9a0 and 0x4e0d80 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5df1c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5de9a0, 1, this=True, pop=4)
    hook_rec(c, 0x4e0d80, 1, this=True, pop=4)
    o2 = obj(c, 0x20, {0x40: pystub(c, 1, this=True)}, nslots=0x20)

    def w40(em, k):
        v = r.choice([r.getrandbits(32), r.getrandbits(32), 0, 0xffffffff, 0x80000000, 0x7fff7fff, 0xffff0000, 0x0000ffff])
        em.wbytes(em.arg32(0), v.to_bytes(4, 'little'))

    def w50(em, k):
        v = r.choice([r.getrandbits(32), int.from_bytes(__import__('struct').pack('<f', c.fv(-100, 100)), 'little'), 0, 0x80000000, 0x7f800000])
        em.wbytes(em.arg32(0), v.to_bytes(4, 'little'))
    s = obj(c, 0x20, {0x40: pystub(c, 1, this=True, ret=o2, stackmark=(0,), side=w40), 0x6c: pystub(c, 1, this=True),
                      0x50: pystub(c, 1, this=True, nullflag=(0,), side=w50)}, nslots=0x20)
    return [rnd(c, 0x40), s]


S(0x5df1c0, 'GUESS read transform record: packed angle pairs to direction vectors', 'thiscall', None, ret=None, gen=_g5df1c0, nan_heap=True, note='batch35182')
