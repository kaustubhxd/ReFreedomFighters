"""specs_s1144.py - unclaimed-11 batch 45 (slice 10): 0x656da0 (GUESS), thiscall with ecx unused, two stack args (ret 8):
arg1 = object pointer, arg2 = a float (passed as bits).
If the word at arg1+0x5a is nonzero: Y = render holder (global 0x70039c -> rm, rm+0x190f) vt[0x20](word) (rec stub returns Y);
Z = 0x63eab0(Y) (stubbed: rec, no args, returns Z); the dword at Z+0x48 = arg2 bits. All callees are stubs (unverified).
The arg1 object is 0x100 random bytes; the word is zero in a third of cases. Z is 0x80 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    Z = c.emu.alloc(0x80, 4)
    c.emu.wbytes(Z, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    Y = c.emu.alloc(0x40, 4)
    c.emu.wbytes(Y, bytes(0x40))
    holder = ss.mkobj(c, {0x20: ss.rec(c, 1, ret=Y)}, size=0x40)
    rm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(rm + 0x190f, holder)
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x63eab0, ss.rec(c, 0, ret=Z))
    c.emu._image_dirty = True
    obj = c.emu.alloc(0x100, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    word = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(16)
    c.emu.w16(obj + 0x5a, word)
    return [c.rng.getrandbits(32), obj, c.rng.getrandbits(32)]


S(0x656da0, 'GUESS (no name) conditional store into 0x63eab0 result thiscall ret 8', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 45 (slice 10); callees stubbed')
