"""specs_s8034.py - residue 18 unported list (docs/20-unclaimed-79.md). Each function gets its own random objects.
Virtual slots and the stdcall allocator 0x6014a0 (ret 4) are stubbed and logged."""
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

def _g563d60(c):
    v = c.rng.getrandbits(32)
    def h2f0(e, r):
        e.calllog.append(("o slot 2f0", e.reg("ecx")))
        e.ret(eax=v, argbytes=0)
    o = _obj(c, 0x40)
    c.emu.w32(o, c.emu.fake_vtable("VtS34_o", 0x200, {0x2f0: h2f0}))
    def h84(e, r):
        e.calllog.append(("this slot 84", e.reg("ecx")))
        e.ret(eax=o, argbytes=0)
    def hc4(e, r):
        e.calllog.append(("this slot c4", e.reg("ecx"), e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    self_ = _obj(c, 0x100)
    c.emu.w32(self_, c.emu.fake_vtable("VtS34_this", 0x200, {0x84: h84, 0xc4: hc4}))
    if c.rng.random() < 0.4:
        c.emu.w32(self_ + 0xf4, v)
    return [self_]

def _g4ffea0(c):
    n = c.rng.randrange(0, 9)
    cnt = c.rng.randrange(0, n + 1)
    block = _obj(c, 0x40)
    def halloc(e, r):
        e.calllog.append(("alloc 6014a0", e.arg32(0)))
        e.ret(eax=block, argbytes=4)
    ss.patch(c, 0x6014a0, c.emu.stub_fn("alloc 6014a0", halloc))
    src = _obj(c, 0x40) + 8
    if cnt == 0:
        end = src - c.rng.randrange(0, 9) if c.rng.random() < 0.5 else src
    else:
        end = src + 4 * cnt - c.rng.randrange(0, 4)
    return [n, src, end]

S(0x563d60, '(GUESS) 0x563d60 slot 2f0 value cached at +0xf4', 'thiscall', None, ret=None, gen=_g563d60,
  note='residue 18 unported: slot 0x84 object, its slot 0x2f0 value stored at +0xf4, slot 0xc4(1) on change')
S(0x4ffea0, '(GUESS) 0x4ffea0 allocate and copy dwords', 'stdcall', None, ret='eax', gen=_g4ffea0,
  note='residue 18 unported: 0x6014a0(4n) (stubbed), copies (end - begin + 3) / 4 dwords, returns the block')
