"""specs_s8026.py - unclaimed core row, ContactMove (docs/20-unclaimed-79.md). Each function gets its own random object.
Helpers are stubbed and logged; stack-pointer arguments are logged as 'stack-slot'."""
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

def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p

def _helper(c, addr, nstack):
    # fastcall helper: ecx, edx, then nstack stack arguments (the callee pops 4*nstack)
    def h(e, r):
        ec, ed = e.reg('ecx'), e.reg('edx')
        for k, p in enumerate((ec, ed)):
            if abs(p - e.reg('esp')) < 0x2000:
                e.wbytes(p, bytes(((i * 13 + addr + k) & 0xff) for i in range(4)))
        args = [_norm(e, ec), _norm(e, ed)]
        args += [e.arg32(k) for k in range(nstack)]
        contents = [bytes(e.rbytes(p, 4)) if abs(p - e.reg('esp')) < 0x2000 else None for p in (ec, ed)]
        e.calllog.append(("helper %x" % addr, tuple(args), tuple(contents)))
        e.ret(eax=0, argbytes=4 * nstack)
    ss.patch(c, addr, c.emu.stub_fn("helper %x" % addr, h))

def _g(c):
    for addr, n in ((0x43e920, 1), (0x441a60, 0), (0x4de4b0, 1), (0x4419f0, 0), (0x441940, 0), (0x4de480, 0), (0x4de420, 0)):
        _helper(c, addr, n)
    def h59c(e, r):
        p0, p1 = e.arg32(0), e.arg32(1)
        for p, k in ((p0, 3), (p1, 5)):
            if abs(p - e.reg('esp')) < 0x2000:
                e.wbytes(p, bytes(((i * 7 + k) & 0xff) for i in range(4)))
        contents = tuple(bytes(e.rbytes(p, 4)) if abs(p - e.reg('esp')) < 0x2000 else None for p in (p0, p1))
        e.calllog.append(("slot 59c", e.reg("ecx"), tuple(_norm(e, p) for p in (p0, p1)), contents))
        e.ret(eax=0, argbytes=8)
    self_ = _obj(c, 0x100)
    vt = c.emu.fake_vtable("VtC26", 0x180, {0x59c: h59c})
    c.emu.w32(self_, vt)
    def hcb(e, r):
        e.calllog.append(("callback 7003b0",))
        e.ret(eax=0, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn("callback 7003b0", hcb))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x4825c0, '(GUESS) 0x4825c0 ContactMove, helpers stubbed', 'thiscall', None, ret=None, gen=_g,
  note='unclaimed core row (ContactMove): vtable 0x59c and seven fastcall helpers stubbed and logged; callback 0x7003b0 is a logged stub')
