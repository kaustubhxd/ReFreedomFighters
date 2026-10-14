"""specs_c1079.py - camera batch 1079: ZCameraOverlay destructor (0x4572d0). The base destructor 0x451a00, the sized delete
0x634273, the free helper 0x45c510 and the reset helper 0x4690b0 are hooked (tag-only logs, sized delete logs its size)."""
from pilot import S
from camgen import rnd, Log


def _dtor(c):
    log = Log(c, 64)
    r = c.rng
    c.emu.hook(0x451a00, lambda e, res: (log.put(0x451a00), e.ret(argbytes=0)))
    c.emu.hook(0x45c510, lambda e, res: (log.put(0x45c510), e.ret(argbytes=0)))
    c.emu.hook(0x4690b0, lambda e, res: (log.put(0x4690b0, e.arg32(1)), e.ret(argbytes=0)))
    c.emu.hook(0x634273, lambda e, res: (log.put(0x634273, e.arg32(1)), e.ret(argbytes=0)))
    self_ = rnd(c, 0x200)
    if r.random() < 0.8:
        blk = rnd(c, 0x20)
        c.emu.w32(self_ + 0x84, blk)
    else:
        c.emu.w32(self_ + 0x84, 0)
    return [self_, r.choice([0, 1, 3, 4, 5, 7, 0x11, 0x14])]


S(0x4572d0, 'ZCameraOverlay::~ZCameraOverlay', 'thiscall', gen=_dtor)
