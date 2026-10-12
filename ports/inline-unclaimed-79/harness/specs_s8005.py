"""specs_s8005.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
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

def _tail(c, tgt, off, nargs):
    o = _obj(c, off + 16)
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append(("tail callee", e.reg("ecx"), tuple(args)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=4 * nargs)
    ss.patch(c, tgt, c.emu.stub_fn("tail callee %x" % tgt, h))
    return [o] + [c.rng.getrandbits(32) for _ in range(nargs)]

S(0x48cf40, '(GUESS) 0x48cf40 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x496350, 8, 1),
  note='unclaimed-79 gap-band tail call to 0x496350, ret 4, 1 stack arg(s)')

S(0x48ff80, '(GUESS) 0x48ff80 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x497320, 8, 1),
  note='unclaimed-79 gap-band tail call to 0x497320, ret 4, 1 stack arg(s)')

S(0x48ff90, '(GUESS) 0x48ff90 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x497390, 8, 1),
  note='unclaimed-79 gap-band tail call to 0x497390, ret 4, 1 stack arg(s)')

S(0x48ffa0, '(GUESS) 0x48ffa0 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x4973b0, 8, 1),
  note='unclaimed-79 gap-band tail call to 0x4973b0, ret 4, 1 stack arg(s)')

S(0x48ffb0, '(GUESS) 0x48ffb0 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x497450, 8, 1),
  note='unclaimed-79 gap-band tail call to 0x497450, ret 4, 1 stack arg(s)')

S(0x499dd0, '(GUESS) 0x499dd0 tail call', 'thiscall', None, ret='eax', gen=lambda c: _tail(c, 0x499de0, 12, 2),
  note='unclaimed-79 gap-band tail call to 0x499de0, ret 8, 2 stack arg(s)')
