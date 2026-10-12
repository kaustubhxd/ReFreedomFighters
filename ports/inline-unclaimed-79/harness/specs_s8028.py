"""specs_s8028.py - unclaimed core row 0x483300 (docs/20-unclaimed-79.md). Each function gets its own random object.
Helper 0x462640 and the vtable callees are stubbed and logged; stack pointers are logged as 'stack-slot'."""
from pilot import S
import os, sys, struct
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

def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1000.0, 1000.0)))[0]

def _content(e, p):
    # a stack-pointer argument: log the 8 bytes behind it (the local's value), not just the pointer
    return bytes(e.rbytes(p, 8)) if abs(p - e.reg('esp')) < 0x2000 else None

def _mk(c, tag, n, argb, eax=0, stack_norm=True):
    def h(e, r):
        raw = [e.arg32(k) for k in range(n)]
        args = [_norm(e, a) for a in raw] if stack_norm else raw
        contents = [_content(e, a) for a in raw]
        e.calllog.append((tag, e.reg("ecx"), tuple(args), tuple(contents)))
        e.ret(eax=eax, argbytes=argb)
    return h

def _fill59c(e, p0, p1):
    # the 0x59c callee writes a fixed pattern into its two output locals (no rng, so exe and port draw the same bytes)
    for p, k in ((p0, 3), (p1, 5)):
        if abs(p - e.reg('esp')) < 0x2000:
            e.wbytes(p, bytes(((i * 7 + k) & 0xff) for i in range(16)))

def _g(c):
    def hh(e, r):
        args = [_norm(e, e.arg32(k)) for k in range(4)]
        e.calllog.append(("helper 462640", e.reg("ecx"), tuple(args)))
        e.ret(eax=0, argbytes=16)
    ss.patch(c, 0x462640, c.emu.stub_fn("helper 462640", hh))
    self_ = _obj(c, 0x800)
    c.emu.w32(self_ + 0x601 - 0x601, 0)
    flag = 1 if c.rng.random() < 0.7 else 0
    c.emu.wbytes(self_ + 0x601, bytes([flag]))
    c.emu.w32(self_ + 0x43d, _fbits(c))
    c.emu.w32(self_ + 0x451, _fbits(c))
    def h59c(e, r):
        p0, p1 = e.arg32(0), e.arg32(1)
        _fill59c(e, p0, p1)
        e.calllog.append(("self slot 59c", e.reg("ecx"), (_norm(e, p0), _norm(e, p1))))
        e.ret(eax=0, argbytes=8)
    selfvt = c.emu.fake_vtable("VtSelf28", 0x180, {0x59c: h59c})
    c.emu.w32(self_, selfvt)
    a2 = _obj(c, 0x40)
    a2vt = c.emu.fake_vtable("VtA2_28", 0x180, {0x94: _mk(c, "a2 slot 94", 2, 8), 0x8c: _mk(c, "a2 slot 8c", 1, 4)})
    c.emu.w32(a2, a2vt)
    a1 = _obj(c, 0x40)
    a1vt = c.emu.fake_vtable("VtA1_28", 0x180, {0x88: _mk(c, "a1 slot 88", 3, 12), 0x90: _mk(c, "a1 slot 90", 3, 12)})
    c.emu.w32(a1, a1vt)
    return [self_, a1, a2, c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x483300, '(GUESS) 0x483300 helper then vcall chain on a1, a2, this', 'thiscall', None, ret=None, gen=_g,
  note='unclaimed core row (parked, resumed): helper 0x462640 stubbed; vtable callees stubbed and logged')
