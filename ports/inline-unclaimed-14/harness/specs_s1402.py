"""specs_s1402.py - unclaimed-14 batch 2 (docs/20-unclaimed-14.md): ZFFActor::GetLastHitPos (0x59fe80, thiscall, copy of
three dwords from +0x8fb/+0x8ff/+0x903 to the out pointer) and ZActor::GetAnimOffset (0x478ad0, stdcall).

GetAnimOffset reads the global at 0x70039c, so each case writes a fresh chain into the data section: the global points to
object A, A+0x9b points to object B, and B+0x44 is random. A null argument (about 1 case in 5) returns 0 without the chain."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lasthit(c):
    # The object is 0x1000 bytes, the same size as the ZFFActor object of batch 904 in docs/20-unclaimed-01.md.
    return [_rnd(c, 0x1000), _rnd(c, 12)]


def _animoff(c):
    a = c.emu.alloc(0x200, 4)
    b = c.emu.alloc(0x200, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(a + 0x9b, b)
    c.emu.w32(b + 0x44, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, a)
    p = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32)
    return [p]


S(0x59fe80, 'ZFFActor::GetLastHitPos (unknown) thiscall', 'thiscall', None, ret=None, gen=_lasthit,
  note='unclaimed-14 batch 2; copies +0x8fb/+0x8ff/+0x903 to the out pointer')
S(0x478ad0, 'ZActor::GetAnimOffset (unknown) stdcall', 'stdcall', None, ret='eax', gen=_animoff,
  note='unclaimed-14 batch 2; null arg returns 0, else arg - [[0x70039c]+0x9b]+0x44')
