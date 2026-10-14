"""specs_s1009.py - unclaimed-10, batch 5: ZMovementBaseMove::Move (0x489490). The object's vtable is a logging fake:
slots +0x40 and +0x48 log (slot, args) and return nothing (both are unverified callees, stubbed). The five arguments
are random 16-byte buffers, so the stores and the logged argument values are compared exactly."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _move(c):
    e = c.emu
    o = _rnd(c, 0x800)
    vt = e.logging_vtable('movebase', 32, argwords={0x40: 5, 0x48: 5})
    e.w32(o, vt)
    return [o] + [_rnd(c, 16) for _ in range(5)]


S(0x489490, 'ZMovementBaseMove::Move (unknown) thiscall', 'thiscall', None, ret=None, gen=_move,
  note='unclaimed-10 batch 5; stubs slots +0x40 and +0x48 (unverified callees)')
