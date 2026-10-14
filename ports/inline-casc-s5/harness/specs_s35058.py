"""specs_s35058.py - 0x468420 (thiscall(src) ret 4). this and src are 0x100 random bytes; 0x4cbee0 hooked (thiscall, 1 arg); [this+0x44] = owner object with slot 0x20 (returns w, an object with slots 0x1e0 (1 arg,
AL true in half; garbage upper bytes) and 0x2dc (2 args)); this vtable slot 0x58 (0 args). this == src is not generated (the stores read and write the same bytes in a fixed order)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g468420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4cbee0, 1, this=True)
    w = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=(r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]) if r.random() < 0.5 else 0)),
                      0x2dc: pystub(c, 2, this=True)}, nslots=0xb8)
    own = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=w)}, nslots=10)
    me = obj(c, 0x100, {0x58: pystub(c, 0, this=True)}, nslots=0x18)
    e.w32(me + 0x44, own)
    return [me, rnd(c, 0x100)]


S(0x468420, 'GUESS copy state from another object and notify owner', 'thiscall', None, ret=None, gen=_g468420, note='batch35058')
