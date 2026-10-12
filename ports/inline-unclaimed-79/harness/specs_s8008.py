"""specs_s8008.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _child(c, size, parent_off):
    # the sub-object pointer at this+parent_off, as the exe loads it before the store
    o = _obj(c, 0x20)
    ch = _obj(c, size)
    c.emu.wbytes(o + parent_off, ch.to_bytes(4, 'little'))
    return o

S(0x48db50, '(GUESS) 0x48db50 stdcall second arg', 'stdcall', None, ret='eax',
  gen=lambda c: [c.rng.getrandbits(32), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band stdcall, ret 8, returns the second argument')

S(0x493130, '(GUESS) 0x493130 setg', 'thiscall', None, ret='al',
  gen=lambda c: [_obj(c, 0xbd0)],
  note='unclaimed-79 gap-band compare to zero, setg al at this+0xbc9')

S(0x49d6a0, '(GUESS) 0x49d6a0 stdcall field read', 'stdcall', None, ret='eax',
  gen=lambda c: [_obj(c, 16)],
  note='unclaimed-79 gap-band stdcall, reads (arg)+0x8')

S(0x499800, '(GUESS) 0x499800 stdcall global store', 'stdcall', None, ret=None,
  gen=lambda c: [c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band stdcall, stores its argument to global 0x6ffa9c')

S(0x49b380, '(GUESS) 0x49b380 child store +0xc', 'thiscall', None, ret=None,
  gen=lambda c: [_child(c, 0x20, 0xc), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band store through sub-object at this+0xc, +0xc')

S(0x49b390, '(GUESS) 0x49b390 child store +0x8', 'thiscall', None, ret=None,
  gen=lambda c: [_child(c, 0x20, 0xc), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band store through sub-object at this+0xc, +0x8')
