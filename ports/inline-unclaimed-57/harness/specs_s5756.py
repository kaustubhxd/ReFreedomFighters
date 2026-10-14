"""specs_s5756.py - unclaimed-57, band batch 56 (GUESS): 0x5d8740. Thiscall, no args. The helpers 0x4db500 and 0x4db7c0 (thiscall, one argument: an
output pointer into the caller's frame) are hooked; each writes a fixed float (chosen in gen, from exact values) through the pointer, and the hook
does not log the pointer (it differs between the runs); it logs ECX (the inner heap pointer, the same in both runs). The cookie check 0x633654 is a no-op hook. The sub-object (this+0x44) has an inner
pointer at +8 (a random block)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    v1 = c.rng.choice([0.5, -1.25, 3.0, 0.0, 100.0])
    v2 = c.rng.choice([0.75, -2.0, 8.0, -0.0, 1.5])
    b1 = struct.unpack('<I', struct.pack('<f', v1))[0]
    b2 = struct.unpack('<I', struct.pack('<f', v2))[0]
    def h1(em, r):
        em.calllog.append(('4db500', 0, em.reg('ecx'), ()))
        em.w32(em.arg32(0), b1)
        em.ret(eax=0, argbytes=4)

    def h2(em, r):
        em.calllog.append(('4db7c0', 0, em.reg('ecx'), ()))
        em.w32(em.arg32(0), b2)
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x4db500, h1)
    c.emu.hook(0x4db7c0, h2)
    c.emu.hook(0x633654, lambda em, r: em.ret(eax=0, argbytes=0))
    inner = _rnd(c, 0x40)
    sub = _rnd(c, 0x40)
    c.emu.w32(sub + 8, inner)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x44, sub)
    return [obj]


S(0x5d8740, 'unnamed_5d8740 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f,
  note='unclaimed-57 band batch 56; helpers 0x4db500/0x4db7c0 hooked (write through out, pointer not logged); cookie check no-op')
