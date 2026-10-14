"""specs_s34119.py - 0x50f9f0: three cells from hooked 0x5003d0 (values random, cells by call index), table object [[0x70039c]+0x9b] with slots 0x58 (returns an object or null) and 0x114 (returns a word-sized value); the object has slot 0x138; hooked 0x506040.
0x538220: owned member objects at the unaligned +0x52fe / +0x52fa / +0x5302 present or absent; slots 0, 0x208, 0x160, 0x19c on this; slot 0x19c returns a non-zero low byte after 0..2 zero results."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g50f9f0(c):
    clear_hooks(c)
    r = c.rng
    cells = [rnd(c, 0x10) for _ in range(3)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: cells[[0, 2, 1][k] if k < 3 else 0])
    hook_rec(c, 0x506040, 0, this=True, pop=0, ret=r.getrandbits(32))
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x138: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x13c // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=o, this=True), 0x114: pystub(c, 6, ret=lambda em, k: r.choice([0, 1, 0x12345, 0xffff0000 | r.getrandbits(16)]), this=True)}, nslots=0x118 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    a = rnd(c, 0x20)
    return [a]


def _g538220(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x53a8f0, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x534510, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x634273, 2, pop=0)
    zeros = r.choice([0, 0, 1, 2])
    m = obj(c, 0x20, {0: pystub(c, 1, this=True)}, nslots=1)
    me = obj(c, 0x5100, {0x208: pystub(c, 0, this=True), 0x160: pystub(c, 1, this=True),
                         0x19c: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0x100, 0x1, 0x101]) if k >= zeros else 0x100 * r.randrange(1, 100))}, nslots=0x1a0 // 4)
    c.emu.wbytes(me + 0x52fe, (m if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x5302, (rnd(c, 0x10) if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x52fa, (rnd(c, 0x30) if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x50ba, bytes([r.choice([0, 1, 1])]))
    return [me]


S(0x50f9f0, 'GUESS resolve handle and push value', 'stdcall', None, ret='eax', gen=_g50f9f0, note='batch34119')
S(0x538220, 'GUESS teardown with wait loop', 'thiscall', None, ret=None, gen=_g538220, note='batch34119')
