"""specs_s8010.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _p(c):
    return _obj(c, 4)

def _child496330(c):
    o = _obj(c, 0x20)
    ch = _obj(c, 0x20)
    c.emu.wbytes(o + 0x14, ch.to_bytes(4, 'little'))
    return [o, c.rng.getrandbits(32)]

S(0x486e30, '(GUESS) 0x486e30 returns the constant 0x68cc08', 'cdecl', None, ret='eax', gen=lambda c: [],
  note='unclaimed-79 gap-band: returns the constant 0x68cc08')

S(0x486e40, '(GUESS) 0x486e40 returns the constant 0x68cc78', 'cdecl', None, ret='eax', gen=lambda c: [],
  note='unclaimed-79 gap-band: returns the constant 0x68cc78')

S(0x486e60, '(GUESS) 0x486e60 returns the constant 0x68cc40', 'cdecl', None, ret='eax', gen=lambda c: [],
  note='unclaimed-79 gap-band: returns the constant 0x68cc40')

S(0x4951e0, '(GUESS) 0x4951e0 decrements the dword at this+0xbc9', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 0xbd0)],
  note='unclaimed-79 gap-band: decrements the dword at this+0xbc9')

S(0x49def0, '(GUESS) 0x49def0 stores vtable 0x68f008 at this', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 16)],
  note='unclaimed-79 gap-band: stores vtable 0x68f008 at this, zeros this+4, returns this')

S(0x49c620, '(GUESS) 0x49c620 stores this+0x31 to the dword at its argument', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 0x40), _p(c)],
  note='unclaimed-79 gap-band: stores this+0x31 to the dword at its argument, returns this+0x35')

S(0x49c640, '(GUESS) 0x49c640 stdcall', 'stdcall', None, ret='eax', gen=lambda c: [_p(c)],
  note='unclaimed-79 gap-band: stdcall, stores 0x200 at its argument, returns 0x6ffaa8')

S(0x496330, '(GUESS) 0x496330 returns (arg - field) < field', 'thiscall', None, ret='al', gen=_child496330,
  note='unclaimed-79 gap-band: returns (arg - field) < field, unsigned, on the sub-object at this+0x14 (setb al)')

