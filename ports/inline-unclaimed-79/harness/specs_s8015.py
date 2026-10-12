"""specs_s8015.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a

def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p

def _slot(c, k):
    # this + a slot +0x10 that logs (ecx, first arg normalized, second arg) and pops 8
    def h(e, r):
        raw0 = e.arg32(0)
        content = bytes(e.rbytes(raw0, 4)) if abs(raw0 - e.reg('esp')) < 0x2000 else None
        e.calllog.append(("slot 10", e.reg("ecx"), (_norm(e, raw0), e.arg32(1)), content))
        e.ret(eax=0, argbytes=8)
    o = _rnd(c, 0x40)
    vt = c.emu.fake_vtable("VtS15", 0x50, {0x10: h})
    c.emu.w32(o, vt)
    return o

def _g(c):
    return [_slot(c, 0x10), c.rng.getrandbits(32), c.rng.getrandbits(32)]

def _g1(c):
    return [_slot(c, 0x10), c.rng.getrandbits(32)]

S(0x499c30, '(GUESS) 0x499c30 pointer to arg, const 8', 'thiscall', None, ret='eax', gen=_g,
  note='unclaimed-79 gap-band thiscall, calls slot +0x10 with (&arg, 8), returns this')
S(0x499ce0, '(GUESS) 0x499ce0 pointer to arg, const 4', 'thiscall', None, ret='eax', gen=_g1,
  note='unclaimed-79 gap-band thiscall, calls slot +0x10 with (&arg, 4), returns this')
S(0x499d00, '(GUESS) 0x499d00 pointer to arg, const 1', 'thiscall', None, ret='eax', gen=_g1,
  note='unclaimed-79 gap-band thiscall, calls slot +0x10 with (&arg, 1), returns this')
S(0x499db0, '(GUESS) 0x499db0 pointer to arg, const 4, void', 'thiscall', None, ret=None, gen=_g1,
  note='unclaimed-79 gap-band thiscall, calls slot +0x10 with (&arg, 4), returns nothing')
