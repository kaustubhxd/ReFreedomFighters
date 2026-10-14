"""specs_s35167.py - 0x496fe0 (thiscall(a) ret 4, ret=None). a: 0x100 random bytes with a[0x2c] = sz in 4..0x60 (random multiples and non-multiples of 16) and the dword at a + sz - 4 zero in 1/3; this: 0x60 random bytes ([+0x2c] a heap block as ECX of the hook).
0x4ce1c0 hooked (thiscall, 2 args); engine object at 0x70038c with slots 0xd4 (1 arg), 0x30 (3 args), 0x50 (3 args), all recorded."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g496fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4ce1c0, 2, this=True)
    lg = obj(c, 0x20, {0xd4: pystub(c, 1, this=True), 0x30: pystub(c, 3, this=True), 0x50: pystub(c, 3, this=True)}, nslots=0x40)
    e.w32(0x70038c, lg)
    a = rnd(c, 0x100)
    sz = r.choice([4, 8, 0xc, 0x10, 0x11, 0x1f, 0x20, 0x21, r.randint(4, 0x60)])
    while 0x2c < sz + 0 < 0x34 and sz != 0x30:   # the trailing dword would overlap the size field itself
        sz = r.randint(4, 0x60)
    e.w32(a + 0x2c, sz)
    if sz != 0x30:   # at 0x30 the trailing dword is the size field itself
        e.w32(a + sz - 4, 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1)
    me = rnd(c, 0x60)
    e.w32(me + 0x2c, rnd(c, 0x10))
    return [me, a]


S(0x496fe0, 'GUESS release pool block with trailing reference and logging', 'thiscall', None, ret=None, gen=_g496fe0, note='batch35167')
