"""specs_s5747.py - unclaimed-57, band batch 47: 0x5d5510 (GUESS). Thiscall, no args. The engine (global 0x70039c) has dwords at +0x6f and +0x73
(random, so the signed rounding runs on negative values too). The sub-object (this+0x44) has a fake vtable whose slot +0x258 (two arguments:
the pair pointer and 0) logs the pair's two float bit patterns and the second argument, not the pointer (which differs between runs)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _p(c):
    def h(em, r):
        p = em.arg32(0)
        x, y = struct.unpack('<II', em.rbytes(p, 8))
        em.calllog.append(('258', 0, em.reg('ecx'), (x, y, em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    vt = c.emu.fake_vtable('band5d5510_sub', 160, {0x258: h})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x6f, c.rng.getrandbits(32))
    c.emu.w32(eng + 0x73, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, eng)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x44, sub)
    return [obj]


S(0x5d5510, 'unnamed_5d5510 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_p,
  note='unclaimed-57 band batch 47; slot +0x258 fake (logs the pair values, not the stack pointer); engine dwords random')
