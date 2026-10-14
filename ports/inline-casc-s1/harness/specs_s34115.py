"""specs_s34115.py - 0x497070: flag 0x8000000 of [a+0x3c] in a third; [this+0x14] -> block with an object pointer and a base address; engine object [0x70038c] with slots 0x30 and 0x50 (recorders). The exe faults when the engine object is null, so it is always set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g497070(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x497160, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4dc630, 2, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4ce1c0, 2, this=True, ret=r.getrandbits(32))
    eng = obj(c, 0x20, {0x30: pystub(c, 3, this=True), 0x50: pystub(c, 3, ret=r.getrandbits(32), this=True)}, nslots=0x54 // 4)
    c.emu.w32(0x70038c, eng)
    me = rnd(c, 0x30)
    blk = rnd(c, 0x20)
    c.emu.w32(blk, rnd(c, 0x20))
    base = rnd(c, 0x20)
    c.emu.w32(blk + 4, base)
    c.emu.w32(me + 0x14, blk)
    a = rnd(c, 0x50)
    fl = r.getrandbits(32)
    fl = fl | 0x8000000 if r.random() < 0.33 else fl & ~0x8000000
    c.emu.w32(a + 0x3c, fl)
    return [me, a]


S(0x497070, 'GUESS register node with engine', 'thiscall', None, ret='eax', gen=_g497070, note='batch34115')
