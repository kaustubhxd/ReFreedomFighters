"""specs_s8002.py - unclaimed-79 gap-band accessor group 2 (docs/20-unclaimed-79.md). Each function gets a random object; the object is big enough for its offset."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

S(0x48f750, 'GUESS FUN_48f750 zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 3021), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band zero store +0xbc5')

S(0x48f7d0, 'GUESS FUN_48f7d0 getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 3019)],
  note='unclaimed-79 gap-band getter +0xbc3')

S(0x48ffc0, 'GUESS FUN_48ffc0 getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 76)],
  note='unclaimed-79 gap-band getter +0x44')

S(0x490930, 'GUESS FUN_490930 getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 23885)],
  note='unclaimed-79 gap-band getter +0x5d45')

S(0x490d00, 'GUESS FUN_490d00 getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 23853)],
  note='unclaimed-79 gap-band getter +0x5d25')

S(0x490fe0, 'ZEngineDataBase::GetStaticBuffer() getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 7269)],
  note='unclaimed-79 gap-band getter +0x1c5d')

S(0x491b60, 'GUESS FUN_491b60 zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 3021), c.rng.getrandbits(32), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band zero store +0xbc5')

S(0x491eb0, 'GUESS FUN_491eb0 getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 3016)],
  note='unclaimed-79 gap-band getter +0xbc0')

