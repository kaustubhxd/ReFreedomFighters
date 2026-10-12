"""specs_s6301.py - unclaimed-63 batch 1 (docs/20-unclaimed-63.md): leaves 0x484ce0 (ZPlayer::RegisterMovement), 0x4ce520
(LINKREFTAB::GetPrevRefPtr) and 0x4545e0 (ZItemTemplate::SetItemHands). No stubs, no callees. Objects are random bytes;
the index read from the argument (+0x10) is kept in 0..30 so the array write stays in the object; GetPrevRefPtr's count
(+0x18) is 2..20 so the read stays in its array."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _register(c):
    self_ = _rnd(c, 0x800)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 0x10, c.rng.randint(0, 30))
    return [self_, a]


def _getprev(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, c.rng.randint(2, 20))
    arr = _rnd(c, 0x100) + 8
    return [self_, arr]


def _hands(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x484ce0, 'ZPlayer::RegisterMovement (unknown) thiscall', 'thiscall', None, ret=None, gen=_register,
  note='unclaimed-63 batch 1; stores a at +0x45d+4*idx, max at +0x459')
S(0x4ce520, 'LINKREFTAB::GetPrevRefPtr (unknown) thiscall', 'thiscall', None, ret='eax', gen=_getprev,
  note='unclaimed-63 batch 1; arr[n-2] and v+4*(2-n)')
S(0x4545e0, 'ZItemTemplate::SetItemHands (unknown) thiscall', 'thiscall', None, ret=None, gen=_hands,
  note='unclaimed-63 batch 1; stores arg at +0x5c')
