"""specs_s18.py - inline session batch 18 (Haiku, overnight): 0x430960, 0x4463b0, 0x446320."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x430960 fastcall: (node ECX, head slot EDX). Fields +1 and +5 always hold pool nodes (both are read through);
# +9 is a pool node or 0 (tested before use).
def _move(c):
    r = c.rng
    pool = [c.emu.alloc(16, 4) for _ in range(6)]
    for p in pool:
        c.emu.wbytes(p, bytes(16))
        c.emu.w32(p + 1, r.choice(pool))
        c.emu.w32(p + 5, r.choice(pool))
        c.emu.w32(p + 9, 0 if r.random() < 0.2 else r.choice(pool))
    head = c.emu.alloc(4, 4)
    c.emu.w32(head, r.choice(pool))
    return [r.choice(pool), head]


S(0x430960, 'moveNodeAlt (unknown) fastcall', 'fastcall', None, ret=None, gen=_move,
  note='batch18; relinks u32 fields at +1, +5, +9 in a different order from batch 17; pool nodes only')


# Shared object for the two float functions: floats at +0x3c, +0x40, +0x58 and +0x181, flag byte at +0x48.
def _obj(c):
    r = c.rng
    obj = _rnd(c, 0x190)
    c.emu.wf32(obj + 0x3c, c.fv())
    c.emu.wf32(obj + 0x40, c.fv())
    c.emu.wf32(obj + 0x58, c.fv())
    c.emu.wf32(obj + 0x181, c.fv())
    c.emu.wbytes(obj + 0x48, bytes([r.getrandbits(8)]))
    return obj


# 0x4463b0 thiscall with stack pointers out (3 floats, out[2] is read) and in (2 floats).
def _pairAlt(c):
    obj = _obj(c)
    return [obj, c.fbuf(3), c.fbuf(2)]


S(0x4463b0, 'scalePairAlt (unknown) thiscall', 'thiscall', None, ret=None, gen=_pairAlt,
  note='batch18; both paths; path 2 multiplies by the float at this+0x181 before the sign flip')


# 0x446320 thiscall with stack pointers out (2 floats) and in (3 floats, in[2] is read in path 2).
def _mul(c):
    obj = _obj(c)
    return [obj, c.fbuf(2), c.fbuf(3)]


S(0x446320, 'scaleMul (unknown) thiscall', 'thiscall', None, ret=None, gen=_mul,
  note='batch18; path 2 clamps in[2] from below by the constant at 0x67d9fc with maxss')
