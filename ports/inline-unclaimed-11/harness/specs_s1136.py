"""specs_s1136.py - unclaimed-11 batch 37 (gap band): 0x5b7710 (GUESS, no name), thiscall, one object argument (ret 4), returns true.
this+4 &= ~0x40; arg vt[0x48](this+0x4c); arg vt[0x40](this+0x48); this+0x50 = render object vt[0x58](dword at this+0x48), where the
render object is global 0x70039c -> rm, rm+0x9b -> object. The arg object and the render object are serial_stubs.mkobj with rec
stubs (unverified callees, no GC names). The object is 0x100 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    arg = ss.mkobj(c, {0x48: ss.rec(c, 1), 0x40: ss.rec(c, 1)}, size=0x40)
    ro = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=c.rng.getrandbits(32))}, size=0x40)
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, ro)
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True
    return [o, arg]


S(0x5b7710, 'GUESS (no name) two arg-vtable calls and render slot 0x58 thiscall ret 4', 'thiscall', None, ret='al',
  gen=_gen, note='unclaimed-11 batch 37 (gap band); callees stubbed')
