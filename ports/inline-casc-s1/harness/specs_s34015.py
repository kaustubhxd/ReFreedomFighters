"""specs_s34015.py - cascade tier E, batch 34015: 0x495d60. Pool object (+0x2c a pool pointer, +0x30 base, +0x38 / +0x3c counters, random); 0x4cd9b0 is a recorder
returning a random 16-aligned offset; the engine object at 0x70038c has recorder slots 0x2c and 0x50 (3 args each). n is 0..0x60."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4cd9b0, 2, ret=lambda em, k: r.randrange(0, 0x40, 16), this=True)
    eng = obj(c, 0x40, {0x2c: pystub(c, 3, this=True), 0x50: pystub(c, 3, this=True)}, nslots=0x20)
    c.emu.w32(0x70038c, eng)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x30, rnd(c, 0x200))
    return [me, r.choice([0, 1, 0xd, 0x10, 0x11, 0x5f, r.randint(0, 0x60)])]


S(0x495d60, 'GUESS pool bump-allocate 16-aligned block', 'thiscall', None, ret='eax', gen=_g, note='batch34015')
