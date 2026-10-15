"""specs_c1076.py - camera batch 1076: ZCameraOverlay::UpdateWind (0x459f40).

The random direction (0x4e0a10) reads three floats from the sys object's slot 0x1c4; the stub returns one value per case
(chosen in the generator, the same in both builds). The vector helpers run as original code."""
import struct
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _wind(c):
    log = Log(c, 64)
    r = c.rng
    self_ = rnd(c, 0x100)
    for k in range(3):
        c.emu.w32(self_ + 0xa0 + 4 * k, _fl(c, -50, 50))
        c.emu.w32(self_ + 0xac + 4 * k, _fl(c, -3, 3))
    rnd_val = r.uniform(-1.0, 1.0)

    def v1c4(e, res):
        log.put(0x1c4, e.arg32(1))
        e.ret(st0=rnd_val, argbytes=8)

    s = sys_with_mgr(c, 0x2000)
    c.emu.w32(s, c.emu.fake_vtable('sys', 0x1c8 // 4, {0x1c4: v1c4}))
    out = rnd(c, 0x20)
    return [self_, out, _fl(c, 0.0, 1.0)]


S(0x459f40, 'ZCameraOverlay::UpdateWind', 'thiscall', gen=_wind)
