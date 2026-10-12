"""specs_s8017.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _g(c):
    D = 0x40
    self_ = _obj(c, 0x100)
    c.emu.w32(self_ + 0x2c, D)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + D - 4, 0)
    res = c.rng.getrandbits(32)
    def h(e, r):
        e.calllog.append(("global slot d0", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=res, argbytes=4)
    g = _obj(c, 0x40)
    vt = c.emu.fake_vtable("GlobVt17", 0xd4, {0xd0: h})
    c.emu.w32(g, vt)
    c.emu.w32(0x70038c, g)
    return [self_]

S(0x4964b0, '(GUESS) 0x4964b0 cached global vcall', 'thiscall', None, ret='eax', gen=_g,
  note='unclaimed-79 gap-band thiscall, fills s-4 from global slot +0xd0 when zero, returns it')
