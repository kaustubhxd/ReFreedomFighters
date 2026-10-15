"""specs_s48005.py - tier H. 0x545ee0: archive object with recorder slots 0x48 / 0x50 / 0x6c (the pointer argument is recorded as its offset-free value through a dword deref), this block with unaligned array pointers +0xf / +0x13 / +0x17 and counts +0x28 / +0x2c / +0x30,
log object at 0x700390 (slot 0x20 returns a second object whose cdecl slot 0x2c records 7 dwords)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g545ee0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ar = obj(c, 0x20, {0x48: pystub(c, 1, this=True, deref={0: 1}), 0x50: pystub(c, 1, this=True, deref={0: 1}), 0x6c: pystub(c, 1, this=True, deref={0: 1})}, nslots=0x70 // 4)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 7, pop=0)}, nslots=0x30 // 4)
    lo = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x24 // 4)
    em.w32(0x700390, lo)
    me = rnd(c, 0x60)
    for off, esize in ((0xf, 0x34), (0x13, 0xc), (0x17, 0xc)):
        n = r.choice([0, 1, 2, 3, 5])
        arr = em.alloc(0x34 * 6, 4)
        em.wbytes(arr, bytes(r.getrandbits(8) for _ in range(0x34 * 6)))
        em.wbytes(me + off, arr.to_bytes(4, 'little'))
    cnt = lambda: r.choice([0, 0, 1, 2, 3, 5, -1, 0x80000000])
    em.w32(me + 0x28, cnt() & 0xffffffff)
    em.w32(me + 0x2c, cnt() & 0xffffffff)
    em.w32(me + 0x30, cnt() & 0xffffffff)
    return [me, ar]


S(0x545ee0, 'GUESS stream three record arrays through archive', 'thiscall', None, ret='al', gen=_g545ee0, nan_heap=True, note='batch48005')
