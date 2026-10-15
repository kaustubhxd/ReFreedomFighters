"""specs_c1066.py - camera batch 1066: ZFFCam::AdjustForObstacles (0x5c97f0).

The vector helpers (0x4e0d80 vsetlen, 0x43e8e0 vector add) run as original code. The object at +0x44 has a fake vtable whose
slot 0x78 logs the three floats it is given."""
import struct
from pilot import S
from camgen import rnd, Log


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _adj(c):
    log = Log(c, 64)
    r = c.rng
    self_ = rnd(c, 0x800)
    c.emu.w32(self_ + 0x64, r.randint(0, 2))
    for off in (0x78, 0x7c, 0x80):
        c.emu.w32(self_ + off, _fl(c, -40, 40))
    c.emu.w32(self_ + 0x2fa, _fl(c, -2, 2))
    for k in range(0, 0x200, 4):
        c.emu.w32(self_ + 0xd9 + k, _fl(c, 0.0, 300.0) if r.random() < 0.9 else 0)
    for off in (0x30c, 0x310, 0x314):
        c.emu.w32(self_ + off, _fl(c, -300, 300))

    def v78(e, res):
        p = e.arg32(0)
        log.put(0x78, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    obj = rnd(c, 0x80)
    c.emu.w32(obj, c.emu.fake_vtable('obj', 0x7c // 4 + 1, {0x78: v78}))
    c.emu.w32(self_ + 0x44, obj)
    return [self_]


S(0x5c97f0, 'ZFFCam::AdjustForObstacles', 'thiscall', gen=_adj)
