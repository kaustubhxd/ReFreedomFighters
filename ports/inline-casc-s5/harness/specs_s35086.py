"""specs_s35086.py - 0x6060a0 (thiscall(s, x) ret 8). this: random 0x20 bytes with the array pointer [+0] (8 dwords), count [+8] 0..4, +0x18 random; s: object with slots 0x40, 0x2c, 0x30 (1 arg each, recorded);
0x602d30 hooked (cdecl, no args, returns a fixed singleton), 0x602d80 hooked (thiscall with ECX recorded, two stack args, call-dependent result)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g6060a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x602d30, 0, pop=0, ret=rnd(c, 0x10))
    vals = [r.getrandbits(32) for _ in range(5)]
    hook_rec(c, 0x602d80, 2, this=True, ret=lambda em, k: vals[min(k, 4)])
    s = obj(c, 0x20, {0x40: pystub(c, 1, this=True), 0x2c: pystub(c, 1, this=True), 0x30: pystub(c, 1, this=True)}, nslots=0x14)
    me = rnd(c, 0x20)
    arr = rnd(c, 0x20)
    e.w32(me, arr)
    e.w32(me + 8, r.choice([0, 1, 2, 3, 4]))
    return [me, s, r.getrandbits(32)]


S(0x6060a0, 'GUESS write header and converted values to stream', 'thiscall', None, ret=None, gen=_g6060a0, note='batch35086')
