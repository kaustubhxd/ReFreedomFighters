"""specs_c1049.py - camera batch 1049: ZFFCameraClass destructor. Base 0x445330 and helpers are hooked (tag-only logs)."""
from pilot import S
from camgen import rnd, Log


def _dtor(c):
    log = Log(c)
    r = c.rng
    c.emu.hook(0x445330, lambda e, res: (log.put(0x445330), e.ret(argbytes=0)))
    c.emu.hook(0x45c510, lambda e, res: (log.put(0x45c510), e.ret(argbytes=0)))
    c.emu.hook(0x4690b0, lambda e, res: (log.put(0x4690b0, e.arg32(1)), e.ret(argbytes=0)))
    self_ = rnd(c, 0x200)
    return [self_, r.choice([0, 1, 3, 4, 5, 7, 0x11, 0x14])]


S(0x5b21b0, 'ZFFCameraClass::~ZFFCameraClass', 'thiscall', gen=_dtor)
