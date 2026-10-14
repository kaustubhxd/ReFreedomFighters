"""specs_s34109.py - seven items; callees are recorders (this recorded). 0x42d3e0: pp points at a cursor into a block; the end pointer [[this+0x1b6d]+4] equals the cursor in a third of the cases."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4cbe80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4cc630, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x20), r.choice([0, 0, r.getrandbits(32)])]


def _g5e1110(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5e0e10, 2, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x5a0), r.getrandbits(32), r.getrandbits(32)]


def _g49a4a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d22, 3, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, rnd(c, 0x20))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g574c60(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x573590, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x2e0)]


def _g5efd10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5edd80, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0xa0)]


def _g42d3e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5f2c60, 2, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1b80)
    blk = rnd(c, 0x40)
    pp = rnd(c, 0x10)
    c.emu.w32(pp, blk)
    g = rnd(c, 0x20)
    c.emu.w32(g + 4, blk if r.random() < 0.33 else blk + 0xc)
    c.emu.wbytes(me + 0x1b6d, g.to_bytes(4, 'little'))
    return [me, rnd(c, 0x20), pp]


def _g4d4d60(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x20), r.choice([0, 1, 2, 3, r.getrandbits(32)])]


S(0x4cbe80, 'GUESS forward with default string', 'thiscall', None, ret='eax', gen=_g4cbe80, note='batch34109')
S(0x5e1110, 'GUESS constructor with base args 3', 'thiscall', None, ret='eax', gen=_g5e1110, note='batch34109')
S(0x49a4a0, 'GUESS append bytes to stream', 'thiscall', None, ret='eax', gen=_g49a4a0, note='batch34109')
S(0x574c60, 'GUESS constructor G', 'thiscall', None, ret='eax', gen=_g574c60, note='batch34109')
S(0x5efd10, 'GUESS constructor H', 'thiscall', None, ret='eax', gen=_g5efd10, note='batch34109')
S(0x42d3e0, 'GUESS call and advance cursor', 'thiscall', None, ret=None, gen=_g42d3e0, note='batch34109')
S(0x4d4d60, 'GUESS destructor with owned buffer', 'thiscall', None, ret='eax', gen=_g4d4d60, note='batch34109')
