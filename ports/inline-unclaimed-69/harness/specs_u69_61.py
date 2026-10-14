"""specs_u69_61.py - area 69, group 61 (slice 8): 0x433440, a float clamp and a call. The callee 0x4314c0 is a GUESS stub (thiscall, two stack args,
ret 8 assumed): it logs ECX as a boolean and the two args (a constant pointer and a float's bits, both small or fixed)."""
import struct
from pilot import S
from ckit import rnd


def _f(e, a):
    return struct.unpack('<f', struct.pack('<I', e.r32(a)))[0]


def _clamp(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x100)
    A = _f(e, 0x67a284)
    B = _f(e, 0x678858)
    x = r.choice([A, B, A - 1.0, B + 1.0, r.uniform(-50.0, 50.0), r.uniform(-1.0, 1.0)])
    x = struct.unpack('<f', struct.pack('<f', x))[0]
    stored = x if r.random() < 0.3 else r.uniform(-50.0, 50.0)
    e.wbytes(o + 0xe4, struct.pack('<f', stored))
    e.hook(0x4314c0, lambda e, res: (e.calllog.append(('t4314c0', int(e.reg('ecx') == o), e.arg32(0), e.arg32(1))), e.ret(argbytes=8)))
    return [o, struct.unpack('<I', struct.pack('<f', x))[0]]


S(0x433440, 'clamp433440 (thiscall, one float arg, ret 4)', 'thiscall', None, ret=None, gen=_clamp,
  note='u69 group 61; callee 0x4314c0 is a GUESS stub (thiscall, two stack args, ret 8 assumed)')
