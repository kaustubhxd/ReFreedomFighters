"""specs_s931.py - unclaimed-09 batch 23 (docs/20-unclaimed-09.md, claim 25): ZStartAnim::Init().

The object is 0x100 random bytes (the fields used are at +0x44, +0x48 and +0x4c). this+0x48 is non-zero in about 80%
of cases; the global's +0x9b object returns x (null in about one case in five). Every virtual call is a logged Python
handler (unverified callees): x's vt+0x80 writes two random dwords through its pointers and logs them; z's vt+0x7c logs
its two values (read through the pointers); this+0x44 has vt+0x20 (returns z) and vt+0x22c (logs its arguments: the
pointer this+0x4c is a heap value); this has vt+0x58 (logs)."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    v1 = rng.getrandbits(32)
    v2 = rng.getrandbits(32)
    x_null = rng.random() < 0.2

    def h_m58(e2, r):
        e2.calllog.append(('M58', e2.arg32(0)))
        e2.ret(eax=0 if x_null else xobj, argbytes=4)

    def h_x80(e2, r):
        e2.w32(e2.arg32(0), v1)
        e2.w32(e2.arg32(1), v2)
        e2.calllog.append(('X80',))
        e2.ret(eax=0, argbytes=8)

    def h_z7c(e2, r):
        a, b = e2.arg32(0), e2.arg32(1)
        e2.calllog.append(('Z7c', int.from_bytes(e2.rbytes(a, 4), 'little'), int.from_bytes(e2.rbytes(b, 4), 'little')))
        e2.ret(eax=0, argbytes=8)

    def h_y20(e2, r):
        e2.calllog.append(('Y20',))
        e2.ret(eax=zobj, argbytes=0)

    def h_y22c(e2, r):
        e2.calllog.append(('Y22c', e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=0, argbytes=8)

    def h_this58(e2, r):
        e2.calllog.append(('This58',))
        e2.ret(eax=0, argbytes=0)

    xobj = e.fake_object('startanim_x', 0x40, slots={0x80: h_x80})
    zobj = e.fake_object('startanim_z', 0x40, slots={0x7c: h_z7c})
    m = e.fake_object('startanim_m', 0x40, slots={0x58: h_m58})
    yobj = e.fake_object('startanim_y', 0x40, slots={0x20: h_y20, 0x22c: h_y22c})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    this = e.fake_object('startanim_this', 0x100, slots={0x58: h_this58})
    e.wbytes(this + 4, bytes(rng.getrandbits(8) for _ in range(0x100 - 4)))
    e.w32(this + 0x44, yobj)
    e.w32(this + 0x48, 0 if rng.random() < 0.2 else rng.getrandbits(32) | 1)
    return [this]


S(0x485b30, 'ZStartAnim::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b23; every vtable call stubbed (unverified callees)')
