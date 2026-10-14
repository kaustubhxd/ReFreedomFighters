"""specs_s34130.py - 0x646350: engine object [[0x70039c]+0x1aa3]->[+0x18] slot 0xc8 returns a table; this slot 0x10 (4 args) returns a random low byte (zero in half); hooked 0x4de7a0; printer via 0x700390 slot 0x20, its slot 0x2c a cdecl recorder.
0x497320: this+0x14 block with base at +4, this+0x24 flag, +0x28 offset; p below, at and above base+off, null in a tenth; hooked 0x497670 (zero in half), 0x4964e0, 0x499810."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g646350(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4de7a0, 0, this=True, pop=0, ret=r.getrandbits(32))
    tbl = rnd(c, 0x40)
    pr = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    sysx = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, sysx)
    sub = obj(c, 0x20, {0xc8: pystub(c, 1, ret=tbl, this=True)}, nslots=0xcc // 4)
    eng = obj(c, 0x20, {}, nslots=1)
    c.emu.w32(eng + 0x18, sub)
    so = rnd(c, 0x1ab0)
    c.emu.wbytes(so + 0x1aa3, eng.to_bytes(4, 'little'))
    c.emu.w32(0x70039c, so)
    me = obj(c, 0x20, {0x10: pystub(c, 4, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101, r.getrandbits(32)]), this=True)}, nslots=0x14 // 4)
    d = rnd(c, 0x20)
    inner = rnd(c, 0x80)
    c.emu.w32(d + 8, inner)
    b = rnd(c, 0x10)
    return [me, rnd(c, 0x10), b, r.randrange(0x38), d]


def _g497320(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x497670, 1, this=True, ret=lambda em, k: r.choice([0, 0, r.getrandbits(32) | 1]))
    hook_rec(c, 0x4964e0, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x499810, 2, this=True)
    base = r.getrandbits(31) + 0x1000
    blk = rnd(c, 0x10)
    c.emu.w32(blk + 4, base)
    off = r.choice([0, 0x10, 0x1000, r.getrandbits(16)])
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x14, blk)
    c.emu.w32(me + 0x24, r.choice([0, 1, 1, 7]))
    c.emu.w32(me + 0x28, off)
    lim = (base + off) & 0xffffffff
    p = r.choice([0, lim, lim + 1, lim - 1, base, base + 1, r.getrandbits(32), lim + r.getrandbits(12), 0xffffffff])
    if r.random() < 0.05:
        p = 0
    return [me, p & 0xffffffff]


S(0x646350, 'GUESS checked lookup with error print', 'thiscall', None, ret=None, gen=_g646350, note='batch34130')
S(0x497320, 'GUESS pointer to handle', 'thiscall', None, ret='eax', gen=_g497320, note='batch34130')
