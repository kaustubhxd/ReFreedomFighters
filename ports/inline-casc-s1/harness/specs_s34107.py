"""specs_s34107.py - seven call wrappers; callees are recorders (this recorded). 0x4487f0: engine object [0x70039c] with a table block at +0x9b whose byte +0xbad is random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4f8c20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f9c60, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x1d0), rnd(c, 0x1d0)]


def _g549380(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x40c0), r.choice([0, 1, 2, 3, r.getrandbits(32)])]


def _g5af230(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5af040, 1, this=True, ret=lambda em, k: r.choice([0, 1, 7, 8, 8, 2]))
    return [rnd(c, 0x40), r.getrandbits(32)]


def _g5fef70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fe560, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x41e2c0, 1, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x20), rnd(c, 0xb0)]


def _g4487f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45d5b0, 1, this=True, ret=r.getrandbits(32))
    so = rnd(c, 0xa0)
    tbl = rnd(c, 0xbc0)
    c.emu.wbytes(tbl + 0xbad, bytes([r.choice([0, 0, 1, 5])]))
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    return [rnd(c, 0x40), rnd(c, 0x40)]


def _g4ee210(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43e990, 3, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x60), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g5227c0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    c.emu.w32(cell, r.choice([0, 0, 1, r.getrandbits(32)]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    tgt = obj(c, 0x20, {0x380: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x384 // 4)
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x1c, tgt)
    return [me, rnd(c, 0x20)]


S(0x4f8c20, 'GUESS copy two fields after base', 'thiscall', None, ret='eax', gen=_g4f8c20, note='batch34107')
S(0x549380, 'GUESS scalar deleting destructor L', 'thiscall', None, ret='eax', gen=_g549380, note='batch34107')
S(0x5af230, 'GUESS indexed lookup', 'thiscall', None, ret='eax', gen=_g5af230, note='batch34107')
S(0x5fef70, 'GUESS release and decrement', 'thiscall', None, ret='eax', gen=_g5fef70, note='batch34107')
S(0x4487f0, 'GUESS copy field and notify', 'thiscall', None, ret=None, gen=_g4487f0, note='batch34107')
S(0x4ee210, 'GUESS constructor with base args', 'thiscall', None, ret='eax', gen=_g4ee210, note='batch34107')
S(0x5227c0, 'GUESS forward cell flag to slot 0x380', 'thiscall', None, ret='eax', gen=_g5227c0, note='batch34107')
