"""specs_s35134.py - 0x463430 (thiscall, no args). Engine (sysobj, 0x2000 bytes) with the unaligned pointer at +0x1aa3 -> X (slot 0x8c: 1 arg, returns m; [X+0x18] = O with slot 0xb0 (1 arg, returns n among 0, 1, 3, 10, 0x0aaaaaab (24 * n overflows), random)); m: slot 0x58 (1 arg); this: slots 0x2cc (0 args) and 0x284 (2 args), [+8] -> block with +0x6c;
0x41e290 (cdecl, 1 arg, returns a block) and 0x634d10 (cdecl, 3 args) recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g463430(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, pop=0, ret=blk)
    hook_rec(c, 0x634d10, 3, pop=0)
    n = r.choice([0, 1, 3, 10, 0x0aaaaaab, 0x10000000, r.getrandbits(32)])
    m = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x17)
    O = obj(c, 0x20, {0xb0: pystub(c, 1, this=True, ret=n)}, nslots=0x2d)
    X = obj(c, 0x30, {0x8c: pystub(c, 1, this=True, ret=m)}, nslots=0x24)
    e.w32(X + 0x18, O)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, X.to_bytes(4, 'little'))
    me = obj(c, 0x80, {0x2cc: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0x284: pystub(c, 2, this=True)}, nslots=0xb4)
    e.w32(me + 8, rnd(c, 0x80))
    return [me]


S(0x463430, 'GUESS allocate entry table sized by engine and register node', 'thiscall', None, ret=None, gen=_g463430, note='batch35134')
