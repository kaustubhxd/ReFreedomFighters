"""specs_c1070.py - camera batch 1070: ZCAMERA::SetCam6ClipPlanes (0x446790).

The plane builder (0x4453c0) and the CRT memset (0x634d10) and the vector cross product (0x446ee0) run as original code;
the tangent is the CRT's. The sys object's list head (+0x190f) is a node whose flag byte at +0x81 is random."""
import struct
from pilot import S
from camgen import rnd, sys_with_mgr


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _clip(c):
    r = c.rng

    def memset(e, res):  # cdecl memset(p, v, n): the caller pops; returns p
        p, v, n = e.arg32(0), e.arg32(1) & 0xff, e.arg32(2)
        for i in range(n):
            c.emu.w8(p + i, v)
        e.ret(eax=p, argbytes=0)
    c.emu.stub_import('memset', memset)
    self_ = rnd(c, 0x400)
    c.emu.w32(self_ + 0x48, r.getrandbits(8))
    c.emu.w32(self_ + 0x3c, 0x3f800000 if r.random() < 0.3 else _fl(c, 0.5, 4.0))
    c.emu.w32(self_ + 0x40, _fl(c, 0.5, 4.0))
    c.emu.w32(self_ + 0x60, _fl(c, 0.5, 4.0))
    c.emu.w32(self_ + 0x181, _fl(c, 0.5, 2.5))
    s = sys_with_mgr(c, 0x2000)
    node = rnd(c, 0x100)
    c.emu.w32(node + 0x81, r.getrandbits(8))
    c.emu.w32(s + 0x190f, node)
    p1 = _fl(c, 0.2, 2.5)
    p2 = _fl(c, 0.1, 5.0)
    p3 = _fl(c, 10.0, 900.0)
    p4 = r.randint(1, 1000)
    p5 = r.randint(1, 1000)
    p6 = _fl(c, 0.5, 2.0)
    return [self_, p1, p2, p3, p4, p5, p6]


S(0x446790, 'ZCAMERA::SetCam6ClipPlanes', 'thiscall', gen=_clip)
