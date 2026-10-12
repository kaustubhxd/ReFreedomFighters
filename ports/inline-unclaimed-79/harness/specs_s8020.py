"""specs_s8020.py - unclaimed-79 resumed parked row (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S, F
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
    # slot +0x5ec: plain ret, logs ecx
    def h(e, r):
        e.calllog.append(("slot 5ec", e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    o = _obj(c, 0x600)
    vt = c.emu.fake_vtable("VtS20", 0x180, {0x5ec: h})
    c.emu.w32(o, vt)
    return [o, F(c.rng.uniform(-1000.0, 1000.0))]

S(0x485060, '(GUESS) 0x485060 float store then vcall 0x5ec', 'thiscall', None, ret=None, gen=_g,
  note='unclaimed-79 resumed parked row: stores float arg at this+0x4dd, calls slot +0x5ec')
