"""specs_s8004.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _tail(c, tgt, off):
    o = _obj(c, off + 16)
    def h(e, r):
        e.calllog.append(("tail callee", e.reg("ecx")))
        e.ret(eax=c.rng.getrandbits(32), argbytes=0)
    ss.patch(c, tgt, c.emu.stub_fn("tail callee %x" % tgt, h))
    return [o]

S(0x481920, '(GUESS) 0x481920 address getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 1109)],
  note='unclaimed-79 gap-band address getter +0x445')

S(0x48f6f0, '(GUESS) 0x48f6f0 increment', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 23881)],
  note='unclaimed-79 gap-band increment +0x5d39')

S(0x490cf0, '(GUESS) 0x490cf0 address getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 7281)],
  note='unclaimed-79 gap-band address getter +0x1c61')

S(0x492b20, '(GUESS) 0x492b20 increment', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 3033)],
  note='unclaimed-79 gap-band increment +0xbc9')

S(0x49b720, '(GUESS) 0x49b720 argument getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 16), c.rng.getrandbits(32)],
  note='unclaimed-79 gap-band argument getter')

S(0x49df20, '(GUESS) 0x49df20 address getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 276)],
  note='unclaimed-79 gap-band address getter +0x104')

S(0x49eec0, '(GUESS) 0x49eec0 address getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 298)],
  note='unclaimed-79 gap-band address getter +0x11a')

