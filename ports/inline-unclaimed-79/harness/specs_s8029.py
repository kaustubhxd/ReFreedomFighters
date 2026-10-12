"""specs_s8029.py - unclaimed medium core row 0x4840e0 (docs/20-unclaimed-79.md). Each function gets its own random object.
Callees and helpers are stubbed and logged. Stack-pointer arguments log 4 bytes; the stubs write a fixed 4-byte pattern there."""
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

def _stk(e, p, n=4):
    return bytes(e.rbytes(p, n)) if abs(p - e.reg('esp')) < 0x2000 else None

def _pat(e, p, k):
    if abs(p - e.reg('esp')) < 0x2000:
        e.wbytes(p, bytes(((i * 5 + k) & 0xff) for i in range(4)))

def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]

def _g(c):
    # helper patches first: ss.patch flushes the image and would overwrite .data writes made before it
    def h4de420(e, r):
        c_, d_ = e.reg('ecx'), e.reg('edx')
        _pat(e, c_, 1)
        e.calllog.append(("helper 4de420", _norm(e, c_), _norm(e, d_), _stk(e, c_)))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x4de420, c.emu.stub_fn("helper 4de420", h4de420))
    def h484b10(e, r):
        raw = [e.arg32(k) for k in range(5)]
        args = [raw[0], raw[1], _norm(e, raw[2]), _norm(e, raw[3]), raw[4]]
        e.calllog.append(("helper 484b10", e.reg("ecx"), tuple(args), _stk(e, raw[2]), _stk(e, raw[3])))
        e.ret(eax=0, argbytes=20)
    ss.patch(c, 0x484b10, c.emu.stub_fn("helper 484b10", h484b10))
    def h4ea300(e, r):
        e.calllog.append(("helper 4ea300", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, 0x4ea300, c.emu.stub_fn("helper 4ea300", h4ea300))
    al_2fc = c.rng.randrange(2)
    al_4c = c.rng.randrange(2)
    esi_obj = _obj(c, 0x40)
    def h4c(e, r):
        args = [_norm(e, e.arg32(k)) for k in range(6)]
        cont = [_stk(e, e.arg32(k)) for k in range(6)]
        e.calllog.append(("esi slot 4c", e.reg("ecx"), tuple(args), tuple(cont)))
        e.ret(eax=al_4c, argbytes=24)
    esi_vt = c.emu.fake_vtable("VtEsi29", 0x200, {0x4c: h4c})
    c.emu.w32(esi_obj, esi_vt)
    self_ = _obj(c, 0x500)
    def h2fc(e, r):
        e.calllog.append(("self slot 2fc", e.reg("ecx")))
        e.ret(eax=al_2fc, argbytes=0)
    def h640(e, r):
        e.calllog.append(("self slot 640", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=esi_obj, argbytes=4)
    def hplain(tag, n, argb):
        def h(e, r):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((tag, e.reg("ecx"), tuple(args)))
            e.ret(eax=0, argbytes=argb)
        return h
    def h600(e, r):
        args = [_norm(e, e.arg32(k)) for k in range(4)]
        cont = [_stk(e, e.arg32(k)) for k in range(4)]
        e.calllog.append(("self slot 600", e.reg("ecx"), tuple(args), tuple(cont)))
        e.ret(eax=0, argbytes=16)
    def h5f0(e, r):
        args = [_norm(e, e.arg32(k)) for k in range(2)]
        cont = [_stk(e, e.arg32(k)) for k in range(2)]
        e.calllog.append(("self slot 5f0", e.reg("ecx"), tuple(args), tuple(cont)))
        e.ret(eax=0, argbytes=8)
    def h5a8(e, r):
        e.calllog.append(("self slot 5a8", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    self_vt = c.emu.fake_vtable("VtSelf29", 0x200, {
        0x2fc: h2fc, 0x640: h640, 0x424: hplain("self slot 424", 1, 4),
        0x600: h600, 0x5f0: h5f0, 0x410: hplain("self slot 410", 0, 0), 0x5a8: h5a8,
    })
    c.emu.w32(self_, self_vt)
    # global chain: [0x70039c] -> S; S+0x1aa3 -> T; T+0x1c -> U; U has slots 0x48 and 0x4c
    def h48(e, r):
        p = e.arg32(0)
        _pat(e, p, 9)
        e.calllog.append(("U slot 48", e.reg("ecx"), (_norm(e, p), e.arg32(1)), _stk(e, p)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    def h4cU(e, r):
        e.calllog.append(("U slot 4c", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    U = _obj(c, 0x40)
    Uvt = c.emu.fake_vtable("VtU29", 0x200, {0x48: h48, 0x4c: h4cU})
    c.emu.w32(U, Uvt)
    T = _obj(c, 0x40)
    c.emu.w32(T + 0x1c, U)
    Sg = _obj(c, 0x1b00)
    c.emu.w32(Sg + 0x1aa3, T)
    c.emu.w32(0x70039c, Sg)
    # the pointer p: three floats
    pobj = _obj(c, 12)
    for k in range(3):
        c.emu.w32(pobj + 4 * k, _fbits(c))
    return [self_, c.rng.getrandbits(32), pobj]

S(0x4840e0, '(GUESS) 0x4840e0 medium body, callees stubbed', 'thiscall', None, ret=None, gen=_g,
  note='unclaimed medium core row: vector copy, slot 0x2fc branch, vtable chain, helpers 0x4de420 0x484b10 0x4ea300 stubbed')
