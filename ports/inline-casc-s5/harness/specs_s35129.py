"""specs_s35129.py - 0x4f61b0 (thiscall(A, b, c, d) ret 0x10, ret='eax'). A: factory with slot 0x294 (4 args, returns o, null in 1/4); this: slot 0x2d8 (3 args, returns x); x: slots 0x270, 0x260 (1 arg); o: slots 0x30c, 0x2ec (1 arg), 0x154, 0x158 (0 args), [o+8] random; 0x4dc630 hooked (thiscall, 2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4f61b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    x = obj(c, 0x20, {0x270: pystub(c, 1, this=True), 0x260: pystub(c, 1, this=True)}, nslots=0x9d)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x30c: pystub(c, 1, this=True), 0x2ec: pystub(c, 1, this=True), 0x154: pystub(c, 0, this=True), 0x158: pystub(c, 0, this=True)}, nslots=0xc4)
    if o:
        e.w32(o + 8, rnd(c, 0x10))
    A = obj(c, 0x20, {0x294: pystub(c, 4, this=True, ret=o)}, nslots=0xa6)
    me = obj(c, 0x20, {0x2d8: pystub(c, 3, this=True, ret=x)}, nslots=0xb7)
    return [me, A, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4f61b0, 'GUESS create named child via factory and configure', 'thiscall', None, ret='eax', gen=_g4f61b0, note='batch35129')
