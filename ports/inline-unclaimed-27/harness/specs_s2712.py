"""specs_s2712.py - unclaimed-27 batch 12: ZPlayer::DisplayCollisionsBounds (0x4831c0, thiscall, ret 4) and ZGEOM::RecurGetNext
(0x45f7c0, thiscall, ret 4). No stubs: both are plain stores. The object is 0x800 random bytes; the argument for
RecurGetNext is a random dword pointing to a 4-byte cell in the heap (so the write is compared)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dcb(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


def _rgn(c):
    cell = _rnd(c, 8)
    return [_rnd(c, 0x800), cell]


S(0x4831c0, 'ZPlayer::DisplayCollisionsBounds (unknown) thiscall', 'thiscall', None, ret=None, gen=_dcb,
  note='unclaimed-27 batch 12; stores the low byte of the argument at +0x601')
S(0x45f7c0, 'ZGEOM::RecurGetNext (unknown) thiscall', 'thiscall', None, ret=None, gen=_rgn,
  note='unclaimed-27 batch 12; writes 0 to *arg')
