"""specs_s5748.py - unclaimed-57, band batch 48: 0x5da670 (GUESS). Thiscall, two stack args (object, pointer to three floats), ret 8. The float
fields of this and the three floats are chosen from a few exact values (no NaN), so the arithmetic is compared. Callees: the object's slot +0x23c
(one argument: the stack pointer to the three floats) is a fake slot that logs the three values, not the pointer; the stack cookie check
0x633654 is a hook that does nothing (the cookie is unchanged)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fb(c, vals):
    return struct.unpack('<I', struct.pack('<f', c.rng.choice(vals)))[0]


VALS = [0.5, -1.25, 3.0, 0.0, 100.0, -0.75, 2.0]


def _vec(c):
    def h(em, r):
        x, y, z = struct.unpack('<fff', em.rbytes(em.arg32(0), 12))
        em.calllog.append(('23c', 0, em.reg('ecx'), (struct.unpack('<I', struct.pack('<f', x))[0],
                                                     struct.unpack('<I', struct.pack('<f', y))[0],
                                                     struct.unpack('<I', struct.pack('<f', z))[0])))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x633654, lambda em, r: em.ret(eax=0, argbytes=0))
    vt = c.emu.fake_vtable('band5da670_o', 160, {0x23c: h})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    obj = _rnd(c, 0x200)
    for off in (0x7e, 0x76, 0x82, 0x7a):
        c.emu.w32(obj + off, _fb(c, VALS))
    p = _rnd(c, 0x20)
    for k in range(3):
        c.emu.w32(p + 4 * k, _fb(c, VALS))
    return [obj, o, p]


S(0x5da670, 'unnamed_5da670 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_vec,
  note='unclaimed-57 band batch 48; slot +0x23c fake (logs the three values); cookie check 0x633654 hooked as a no-op')
