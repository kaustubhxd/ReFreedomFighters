"""specs_s8022.py - unclaimed-79 unclaimed small rows (docs/20-unclaimed-79.md). Each function gets its own random object."""
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

def _str(c, text):
    a = c.emu.alloc(len(text) + 4, 4)
    c.emu.wbytes(a, text + b'\x00\x00\x00\x00')
    return a

def _g48f780(c):
    alpha = b'ab'
    n = c.rng.randrange(0, 7)
    s1 = bytes(c.rng.choice(alpha) for _ in range(n))
    s2 = s1 if c.rng.random() < 0.5 else bytes(c.rng.choice(alpha) for _ in range(n))
    p1 = _str(c, s1)
    p2 = _str(c, s2)
    cell1 = _obj(c, 4); c.emu.w32(cell1, p1)
    cell2 = _obj(c, 4); c.emu.w32(cell2, p2)
    return [cell1, cell2]

def _g4972c0(c):
    self_ = _obj(c, 0x80)
    arr = _obj(c, 0x200)
    c.emu.w32(self_ + 0x51, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x55, arr)
    c.emu.w32(self_ + 0x59, c.rng.randrange(1, 60))
    def h(e, r):
        e.calllog.append(("global slot 30", e.reg("ecx"), tuple(e.arg32(k) for k in range(3))))
        e.ret(eax=0, argbytes=12)
    g = _obj(c, 0x40)
    vt = c.emu.fake_vtable("GlobVt22", 0x50, {0x30: h})
    c.emu.w32(g, vt)
    c.emu.w32(0x70038c, g)
    a = c.rng.getrandbits(32) if c.rng.random() < 0.8 else 0
    return [self_, a]

def _g4947c0(c):
    def h5c(e, r):
        e.calllog.append(("slot 5c", e.reg("ecx"), tuple(e.arg32(k) for k in range(3))))
        e.ret(eax=0, argbytes=12)
    p = _obj(c, 0x40)
    vtp = c.emu.fake_vtable("VtP22", 0x50, {0x5c: h5c})
    c.emu.w32(p, vtp)
    def h134(e, r):
        e.calllog.append(("slot 134", e.reg("ecx")))
        e.ret(eax=p, argbytes=0)
    sub = _obj(c, 0x40)
    vts = c.emu.fake_vtable("VtS22", 0x50, {0x134: h134})
    c.emu.w32(sub, vts)
    sysobj = _obj(c, 0xa4)
    c.emu.w32(sysobj + 0x9b, sub)
    c.emu.w32(0x70039c, sysobj)
    return [c.rng.getrandbits(32)]

S(0x48f780, '(GUESS) 0x48f780 string equal two-byte compare', 'stdcall', None, ret='eax', gen=_g48f780,
  note='unclaimed-79 unclaimed small row: strings at *arg1 and *arg2 equal -> 1')
S(0x4972c0, '(GUESS) 0x4972c0 word store and global vcall 0x30', 'thiscall', None, ret=None, gen=_g4972c0,
  note='unclaimed-79 unclaimed small row: word store at this+0x55[counter], global slot 0x30 with 3 args')
S(0x4947c0, '(GUESS) 0x4947c0 sub-object chain vcall 0x134 then 0x5c', 'stdcall', None, ret='eax', gen=_g4947c0,
  note='unclaimed-79 unclaimed small row: slot 0x134 on sub-object, then slot 0x5c with (0x68e208, arg, 2)')
