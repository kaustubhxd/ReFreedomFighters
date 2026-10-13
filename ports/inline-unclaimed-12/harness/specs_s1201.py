"""specs_s1201.py - unclaimed-12 batch 1 (docs/20-unclaimed-12.md): four CopyData copies, a movement gate, an item
template check and one move setter. All are thiscall leaves. Objects are random bytes so each store lands inside them
and an overrun shows as a heap or data difference."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    # this (0x800 random bytes) and the source (0x100 random bytes, covers every offset read up to +0x8d)
    return [_rnd(c, 0x800), _rnd(c, 0x100)]


def _want(c):
    # this+4 points at an object whose dword +0x417 carries flag 0x80000 in about 60% of cases; this+0x21 is 0 in 30%
    inner = _rnd(c, 0x800)
    flag = 0x80000
    word = c.rng.getrandbits(32)
    word = (word | flag) if c.rng.random() < 0.6 else (word & ~flag & 0xffffffff)
    c.emu.w32(inner + 0x417, word)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj + 4, inner)
    c.emu.w8(obj + 0x21, 0 if c.rng.random() < 0.3 else c.rng.randint(1, 255))
    return [obj, _rnd(c, 12), _rnd(c, 12), _rnd(c, 12)]


def _verify(c):
    # template t: null in 20% of cases; else t+0xc points at a block whose dword +0x23 equals 0x1007d5 in half
    self_ = c.rng.getrandbits(32)
    if c.rng.random() < 0.2:
        t = 0
    else:
        t = _rnd(c, 0x40)
        inner = _rnd(c, 0x40)
        c.emu.w32(t + 0xc, inner)
        c.emu.w32(inner + 0x23, 0x1007d5 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [self_, t]


def _tspeed(c):
    # this+0x24 is a float compared with the first argument; edge floats come from c.fv
    o = _rnd(c, 0x100)
    c.emu.wf32(o + 0x24, c.fv(-10.0, 10.0))
    return [o, F(c.fv()), F(c.fv())]


S(0x4b85f0, 'ZRelayMessage::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-12; word +0x48, word +0x4a, dword +0x4c from src')
S(0x4fb880, 'CCHECKOBJINOBJ::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-12; dword +0x51, +0x55, +0x59; word +0x4d, +0x4f from src')
S(0x582700, 'CExplodeMolotov::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-12; dword +0x48, +0x4c; word +0x54, +0x56 from src')
S(0x5b1b70, 'ZKillBox::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-12; dword/word/16-byte/byte copies from src (27 instructions)')
S(0x489d80, 'ZMovementAction::WantControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_want,
  note='unclaimed-12; bool: flag 0x80000 at [[this+4]+0x417] and byte this+0x21')
S(0x471a40, 'ZItemAmmo::VerifyItemTemplate (unknown) thiscall', 'thiscall', None, ret='al', gen=_verify,
  note='unclaimed-12; bool: template->+0xc->+0x23 == 0x1007d5')
S(0x523e80, 'CMoveAlongPath::SetTargetSpeed (unknown) thiscall', 'thiscall', None, ret=None, gen=_tspeed,
  note='unclaimed-12; stores arg1 at +0x2c, arg2 (negated when this+0x24 > arg1) at +0x28')
