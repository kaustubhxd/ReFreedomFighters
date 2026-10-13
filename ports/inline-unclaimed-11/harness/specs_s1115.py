"""specs_s1115.py - unclaimed-11 batch 16 (slice 10, full list): six leaves, no calls.
0x59b320 (GUESS name): eax = this + 0x121ac (a pointer).
0x5b2520 (GetActionDefinitions): eax = dword at 0x6edac8.
0x5d70a0 (GetActionDefinitions): eax = dword at 0x6ef660.
0x65ca20 (no name): eax = old dword at this+4; this+4 += 0xc.
0x65f5e0 (ZDrawBuffer::GetSizeY, low fit): inner = dword at this+0xc; eax = dword at inner+0x1006d minus dword at inner+0x10065.
0x64cda0 (no name), thiscall with one arg (ret 4): dword at (dword at this+0x10071) + 4*(arg & 0xfff) = 0.
Objects are 0x12000 random bytes; the inner object is a second 0x12000 buffer."""
from pilot import S


def _big(c):
    o = c.emu.alloc(0x12000, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x12000)))
    return o


def _obj(c):
    return [_big(c)]


def _inner(c):
    o = _big(c)
    inner = _big(c)
    c.emu.w32(o + 0xc, inner)
    return [o]


def _table(c):
    o = _big(c)
    tab = c.emu.alloc(0x1000 * 4 + 16, 4)
    c.emu.wbytes(tab, bytes(c.rng.getrandbits(8) for _ in range(0x1000 * 4 + 16)))
    c.emu.w32(o + 0x10071, tab)
    return [o, c.rng.getrandbits(32)]


S(0x59b320, 'GUESS ZFFSaveDeviceInterface::GetMaxNumberOfSaveGames (body is an address) thiscall', 'thiscall', None,
  ret='eax', gen=_obj, note='unclaimed-11 batch 16')
S(0x5b2520, 'ZActionMapP3Control::GetActionDefinitions (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 16')
S(0x5d70a0, 'ZActionMapMovieControlActionMap::GetActionDefinitions (low) thiscall', 'thiscall', None, ret='eax',
  gen=_obj, note='unclaimed-11 batch 16')
S(0x65ca20, 'GUESS (no name) pointer post-advance at +4 thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 16')
S(0x65f5e0, 'ZDrawBuffer::GetSizeY (low fit) thiscall', 'thiscall', None, ret='eax', gen=_inner,
  note='unclaimed-11 batch 16')
S(0x64cda0, 'GUESS (no name) zero table slot thiscall', 'thiscall', None, ret=None, gen=_table,
  note='unclaimed-11 batch 16')
