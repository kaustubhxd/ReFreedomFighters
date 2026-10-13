"""specs_s4027.py - area 70 batch 4027: 0x595510 (GUESS name). The float at [this+0x813] is drawn from zero, negative zero,
ordinary values and NaN (the NaN takes the body in both builds). Slot 0x4b4 records its four constant stack dwords and pops
0x10 (thiscall)."""
import struct
from pilot import S, F


def _cl(c):
    e, r = c.emu, c.rng
    def slot4b4(em, rr):
        em.calllog.append(('4b4', em.reg('ecx') & 0xffffffff, tuple(em.arg32(i) for i in range(4))))   # constants: safe to log
        em.ret(argbytes=0x10)

    lvt = e.fake_vtable('obj_595510', 0x130, {0x4b4: slot4b4})
    self_ = e.alloc(0x900, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x900)))
    e.w32(self_, lvt)
    k = r.random()
    if k < 0.4:
        v = 0.0
    elif k < 0.5:
        v = -0.0
    elif k < 0.6:
        e.w32(self_ + 0x813, 0x7fc00000)                  # quiet NaN: takes the body
        return [self_]
    else:
        v = r.uniform(-10, 10)
    e.wf32(self_ + 0x813, v)
    return [self_]


S(0x595510, 'clear the float at [this+0x813] and call slot 0x4b4 unless it is zero (name GUESS)', 'thiscall', None,
  gen=_cl, note='batch4027')
