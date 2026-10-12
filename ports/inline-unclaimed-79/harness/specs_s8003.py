"""specs_s8003.py - unclaimed-79 gap-band accessor group 3 (docs/20-unclaimed-79.md). Each function gets a random object; the object is big enough for its offset."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

S(0x491ec0, 'GUESS FUN_491ec0 getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 3000)],
  note='unclaimed-79 gap-band getter +0xbb0')

S(0x491ed0, 'GUESS FUN_491ed0 getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 3017)],
  note='unclaimed-79 gap-band getter +0xbc1')

S(0x493ff0, 'GUESS FUN_493ff0 getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 3018)],
  note='unclaimed-79 gap-band getter +0xbc2')

S(0x4951d0, 'GUESS FUN_4951d0 zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 3019)],
  note='unclaimed-79 gap-band zero store +0xbc3')

S(0x497310, 'ZGeomBuffer::GeomCreationLocked() getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 88)],
  note='unclaimed-79 gap-band getter +0x50')

S(0x499870, 'ZGeomBuffer::UnlockGeomCreation() zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 88)],
  note='unclaimed-79 gap-band zero store +0x50')

S(0x49c660, 'CListUser::GetFullBuffer() getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 37)],
  note='unclaimed-79 gap-band getter +0x1d')

S(0x49d6b0, 'ZEventList::NrEvents() getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 24)],
  note='unclaimed-79 gap-band getter +0x10')

