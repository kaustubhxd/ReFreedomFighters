"""specs_s35099.py - 0x49a0e0 (thiscall(s) ret 4). this: slots 0xc (1 arg) and 0x10 (2 args); s: slots 0x14 and 0x18 (0 args, random results), 0x4c (1 arg, out pointer flag-recorded), 0x64 (1 arg, flag-recorded, hands out 0..4 random pointers then 0)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g49a0e0(c):
    clear_hooks(c)
    r = c.rng
    ps = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3, 4]))]
    me = obj(c, 0x20, {0xc: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True)}, nslots=5)
    s = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0x18: pystub(c, 0, this=True, ret=r.choice([0, 1, 5, 0x40000000, r.getrandbits(32)])),
                      0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ps[k] if k < len(ps) else 0)}, nslots=0x1a)
    return [me, s]


S(0x49a0e0, 'GUESS write list header and records to writer', 'thiscall', None, ret=None, gen=_g49a0e0, note='batch35099')
