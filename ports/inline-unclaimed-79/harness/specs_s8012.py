"""specs_s8012.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _child(c, parent_size, off, child_size):
    o = _obj(c, parent_size)
    ch = _obj(c, child_size)
    c.emu.wbytes(o + off, ch.to_bytes(4, 'little'))
    return o

def _a497700(c):
    o = _obj(c, 0x60)
    a = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32)
    return [o, a]

def _cmp48d0c0(c):
    a = _obj(c, 16)
    b = _obj(c, 16)
    if c.rng.random() < 0.3:
        c.emu.wbytes(b + 4, c.emu.rbytes(a + 4, 4))
    return [a, b]

def _idx491a60(c):
    o = _obj(c, 0xc4d + 4 * 0x200)
    i = 0 if c.rng.random() < 0.1 else c.rng.getrandbits(9)
    return [o, (i | (c.rng.getrandbits(16) << 16)) & 0xffffffff]

S(0x49b360, '(GUESS) 0x49b360 stores two args', 'thiscall', None, ret=None,
  gen=lambda c: [_obj(c, 0x130), c.rng.getrandbits(32), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band thiscall, stores args at +0x128 and +0x12c')

S(0x497700, '(GUESS) 0x497700 shift from field', 'thiscall', None, ret='eax', gen=_a497700,
  note='unclaimed-79 gap-band thiscall, signed (arg - field) >> 5 + 1, zero case')

S(0x49a4f0, '(GUESS) 0x49a4f0 sub-object sum store', 'thiscall', None, ret=None,
  gen=lambda c: [_child(c, 0x20, 0xc, 0x20), _obj(c, 4), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band thiscall, sub-object sum to *arg, add arg to sub-object+0xc')

S(0x48d0c0, '(GUESS) 0x48d0c0 cmp of +4 dwords', 'cdecl', None, ret='eax', gen=_cmp48d0c0,
  note='unclaimed-79 gap-band cdecl, returns 0 / 1 / -1 from the +4 dwords of two objects')

S(0x491a60, '(GUESS) 0x491a60 word index table', 'thiscall', None, ret='eax', gen=_idx491a60,
  note='unclaimed-79 gap-band thiscall, word argument indexes the table at this+0xc4d')
