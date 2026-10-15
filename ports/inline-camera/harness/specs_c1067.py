"""specs_c1067.py - camera batch 1067: ZFFCam::CalcCollisionParameters (0x5c9910).

The vector helpers (0x441940, 0x43e920, 0x4e0d00, 0x451890) run as original code. The object at +0x44 has a fake vtable
whose slot 0x88 logs the three floats of the ray it is given (read at call time, the same in both builds)."""
import struct
from pilot import S
from camgen import rnd, Log, fbits


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _ccp(c):
    log = Log(c, 128)
    r = c.rng
    self_ = rnd(c, 0x900)
    c.emu.w32(self_ + 0x2fa, _fl(c, -2.0, 2.0) if r.random() < 0.9 else 0)
    for off in (0x78, 0x7c, 0x80):
        c.emu.w32(self_ + off, _fl(c, -40, 40) if r.random() < 0.9 else 0)
    for off in (0x30c, 0x310, 0x314, 0x444, 0x448, 0x44c):
        c.emu.w32(self_ + off, _fl(c, -300, 300) if r.random() < 0.9 else fbits(c))

    def v88(e, res):
        p = e.arg32(0)
        log.put(0x88, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)

    obj = rnd(c, 0x80)
    c.emu.w32(obj, c.emu.fake_vtable('obj', 0x8c // 4 + 1, {0x88: v88}))
    c.emu.w32(self_ + 0x44, obj)
    return [self_]


S(0x5c9910, 'ZFFCam::CalcCollisionParameters', 'thiscall', gen=_ccp)
