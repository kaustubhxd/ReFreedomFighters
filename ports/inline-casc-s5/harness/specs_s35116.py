"""specs_s35116.py - 0x5097b0 (thiscall(a) ret 4). a: block with [a+4] random; 0x5003d0 hooked (thiscall, 1 arg) returning a record whose first dword (the flag) is zero in half; [[this+0xc]+0x18] = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out pointer, first dword
zeroed after 0..4 calls, non-zero at the start in 4/5)); engine table slot 0x58 (1 arg recorded) returns an object (null in a quarter) with slots 0x28 and 0x2c (0 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g5097b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x10)
    if r.random() < 0.5:
        e.w32(rec, 0)
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3, 4])
    seq = [r.getrandbits(32) for _ in range(6)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)], side=s5c)}, nslots=0x20)
    mid = rnd(c, 0x40)
    e.w32(mid + 0x18, L)
    me = rnd(c, 0x20)
    e.w32(me + 0xc, mid)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0x28: pystub(c, 0, this=True), 0x2c: pystub(c, 0, this=True)}, nslots=0xc) for _ in range(5)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 4)])})
    return [me, rnd(c, 0x20)]


S(0x5097b0, 'GUESS enable or disable listed objects by flag', 'thiscall', None, ret=None, gen=_g5097b0, note='batch35116')
