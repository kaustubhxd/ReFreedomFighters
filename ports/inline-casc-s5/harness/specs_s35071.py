"""specs_s35071.py - 0x56cd90 (thiscall, no args). this = obj of 0x200 random bytes (unaligned fields compared as memory); 0x562440, 0x563510 (1 arg), 0x563610 (1 arg) hooked (thiscall);
engine table slots 0x138 (returns the object with slots 0x60 (2 args) and 0x68 (3 args)) and 0x134 (returns two more such objects, one per call) and 0x4c (2 args recorded, returns a call-dependent id)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g56cd90(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562440, 0, this=True)
    hook_rec(c, 0x563510, 1, this=True)
    hook_rec(c, 0x563610, 1, this=True)
    os_ = [obj(c, 0x20, {0x60: pystub(c, 2, this=True), 0x68: pystub(c, 3, this=True)}, nslots=0x1c) for _ in range(3)]
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=os_[0]),
                           0x134: pystub(c, 0, this=True, ret=lambda em, k: os_[1 + min(k, 1)]),
                           0x4c: pystub(c, 2, this=True, ret=r.getrandbits(32))}, table_size=0x140)
    return [rnd(c, 0x200)]


S(0x56cd90, 'GUESS initialise panel and register resources', 'thiscall', None, ret=None, gen=_g56cd90, note='batch35071')
