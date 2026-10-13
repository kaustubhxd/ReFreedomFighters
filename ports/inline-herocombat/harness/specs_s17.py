"""specs_s17.py - inline session batch 17 (Haiku, overnight): 0x430910, 0x44c230, 0x446430."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x430910 fastcall: (node ECX, head slot EDX). Nodes are 16 bytes. Fields +1 and +9 always hold pool nodes (the
# original reads through them); +5 is a pool node or 0 (the original tests it before use).
def _move(c):
    r = c.rng
    pool = [c.emu.alloc(16, 4) for _ in range(6)]
    for p in pool:
        c.emu.wbytes(p, bytes(16))
        c.emu.w32(p + 1, r.choice(pool))
        c.emu.w32(p + 5, 0 if r.random() < 0.2 else r.choice(pool))
        c.emu.w32(p + 9, r.choice(pool))
    head = c.emu.alloc(4, 4)
    c.emu.w32(head, r.choice(pool))
    return [r.choice(pool), head]


S(0x430910, 'moveNode (unknown) fastcall', 'fastcall', None, ret=None, gen=_move,
  note='batch17; relinks u32 fields at +1, +5, +9; pool nodes keep every dereference valid')


# 0x44c230 thiscall, one float arg. this+0x18 -> p; the float at p+0x88 is 0.0 in about one case in five.
def _scales(c):
    r = c.rng
    p = _rnd(c, 0x100)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj + 0x18, p)
    c.emu.wf32(p + 0x88, 0.0 if r.random() < 0.2 else c.fv())
    return [obj, F(c.fv())]


S(0x44c230, 'setScales (unknown) thiscall', 'thiscall', None, ret=None, gen=_scales,
  note='batch17; zero branch stores 1.0f and 2.0f; NaN takes the scale path (ucomiss with jp)')


# 0x446430 thiscall with two stack pointers: out (3 floats, out[2] is read) and in (2 floats). Bit 0 of this+0x48
# picks the path.
def _pair(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    c.emu.wf32(obj + 0x3c, c.fv())
    c.emu.wf32(obj + 0x40, c.fv())
    c.emu.wf32(obj + 0x58, c.fv())
    c.emu.wbytes(obj + 0x48, bytes([r.getrandbits(8)]))
    out = c.fbuf(3)
    inp = c.fbuf(2)
    return [obj, out, inp]


S(0x446430, 'scalePair (unknown) thiscall', 'thiscall', None, ret=None, gen=_pair,
  note='batch17; both paths; the sign flip is xorps with the 0x80000000 lane at 0x67af40')
