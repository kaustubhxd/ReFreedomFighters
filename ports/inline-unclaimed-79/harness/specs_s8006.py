"""specs_s8006.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md)."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from helpers_trial import logged_slot

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

S(0x4831c0, '(GUESS) 0x4831c0 byte setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 1553), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band byte argument setter +0x601')

S(0x484fe0, '(GUESS) 0x484fe0 byte setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 1084), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band byte argument setter +0x42c')

S(0x4850b0, '(GUESS) 0x4850b0 dword setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 1566), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band dword argument setter +0x60e')

S(0x4870b0, '(GUESS) 0x4870b0 dword setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 24), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band dword argument setter +0x8')

S(0x493190, '(GUESS) 0x493190 byte setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 3009), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band byte argument setter +0xbb1')

S(0x494690, '(GUESS) 0x494690 dword setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 23893), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band dword argument setter +0x5d45')

S(0x4946a0, '(GUESS) 0x4946a0 dword setter', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 20), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band dword argument setter +0x4')

