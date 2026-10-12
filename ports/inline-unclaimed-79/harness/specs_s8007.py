"""specs_s8007.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md)."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from helpers_trial import logged_slot
def _child(c, off, K):
    self_ = _obj(c, off + 16)
    child = _obj(c, 0x40)
    vt = c.emu.fake_vtable("ChildVt", 0x40, {K: logged_slot("Child::slot", eax=0, argbytes=4)})
    c.emu.w32(child, vt)
    c.emu.w32(self_ + off, child if c.rng.random() < 0.7 else 0)
    return [self_]

def _glob(c, K):
    self_ = _obj(c, 16)
    sysobj = _obj(c, 0x40)
    vt = c.emu.fake_vtable("SysVt", 0x40, {K: logged_slot("Sys::slot", eax=c.rng.getrandbits(32), argbytes=0)})
    c.emu.w32(sysobj, vt)
    c.emu.w32(0x70039c, sysobj)
    return [self_]

def _sys(c, sysobj):
    s = _obj(c, 0x200)
    return s


def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

S(0x485890, '(GUESS) 0x485890 child call', 'thiscall', None, ret=None, gen=lambda c: _child(c, 72, 0),
  note='unclaimed-79 gap-band child vcall slot 0x0')

S(0x48b330, '(GUESS) 0x48b330 global tail call', 'thiscall', None, ret='eax', gen=lambda c: _glob(c, 72),
  note='unclaimed-79 gap-band tail call through the global 0x70039c slot 0x48')

