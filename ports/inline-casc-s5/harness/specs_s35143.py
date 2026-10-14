"""specs_s35143.py - 0x55fca0 (stdcall(a) ret 4). a: random block with [a+4]; 0x5003d0 hooked (thiscall, 1 arg; returns the record for index 0 (value id, zero in 1/5) then index 1 (value amount)); engine table slot 0x58 (1 arg) returns a value; global 0x7003b8 -> block with the unaligned dword at +0x2c21;
0x5a45c0 / 0x5a4610 hooked (thiscall, 1 arg; return heap blocks of random bytes or 0 in a third); logger at 0x700390 (slot 0x20 -> object with slot 0x30, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g55fca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0, rec1 = rnd(c, 8), rnd(c, 8)
    if r.random() < 0.2:
        e.w32(rec0, 0)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec0, rec1)[min(k, 1)])
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    blk_p = rnd(c, 0x10)
    blk_q = rnd(c, 0x10)
    hook_rec(c, 0x5a45c0, 1, this=True, ret=0 if r.random() < 1 / 3 else blk_p)
    hook_rec(c, 0x5a4610, 1, this=True, ret=0 if r.random() < 1 / 3 else blk_q)
    H = rnd(c, 0x2d00)
    e.w32(0x7003b8, H)
    lg2 = obj(c, 0x20, {0x30: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [rnd(c, 0x10)]


S(0x55fca0, 'GUESS add amount to counters of tracked object', 'stdcall', None, ret=None, gen=_g55fca0, note='batch35143')
