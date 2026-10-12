"""specs_s6339.py - unclaimed-63 gap-band batch 39: 0x4d8730 (x87 set; thiscall, one argument a, ret 4).
Fakes per case (the image is restored between runs):
  * global 0x6762d4 is a fake cdecl function (records its argument) that returns a random float in st0 (NaN included);
  * logger 0x700390: slot +0x20 (file, line) returns the log object (thiscall, ret 8), like the other specs; the log object's slot
    +0x2c is a cdecl printf-like that records its arguments (the log, the format, the name and the double, both dwords);
  * this: vtable slot +4 (thiscall; the caller cleans its argument, so it returns with a plain ret) records ECX and its argument and returns a pointer q; hook 0x4cc1d0 (thiscall,
    no arguments) returns the first dword of its object plus 8 (the same as the other specs);
  * this+0x104 points to a random float cell (NaN included), so both the store path and the print path read and write valid memory.
a is 0 in half the cases."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_8730(c):
    e = c.emu
    self_ = e.alloc(0x110, 4)
    e.wbytes(self_, bytes(0x110))
    fcell = _rnd(c, 8)
    e.w32(self_ + 0x104, fcell)
    qb = _rnd(c, 32)
    q = _rnd(c, 16)
    e.w32(q, qb)

    def slot4(em, args):
        em.calllog.append(('this.virt4', 4, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=q, argbytes=0)
    vt = e.fake_vtable('this', 8, {4: slot4})
    e.w32(self_, vt)
    e.hook(0x4cc1d0, lambda em, r: (em.calllog.append(('helper.4cc1d0', None, em.reg('ecx'), ())),
                                    em.ret(eax=em.r32(em.reg('ecx')) + 8)))

    def cdecl_f(em, args):
        em.calllog.append(('fn.6762d4', None, None, (em.arg32(0),)))
        em.ret(st0=c.rng.choice([0.0, 1.0, -0.0, 2.5, float('nan'), -3.25]) if c.rng.random() < 0.3
               else struct.unpack('<f', c.rng.getrandbits(32).to_bytes(4, 'little'))[0], argbytes=0)
    e.w32(0x6762d4, e.stub_fn('fn 0x6762d4', cdecl_f))

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=0)
    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.mu.ctl_flush_tb()
    a = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32) | 1
    return [self_, a]


S(0x4d8730, 'unnamed x87 0x4d8730 thiscall', 'thiscall', None, ret=None, gen=_gen_8730,
  note='unclaimed-63 band batch 39')
