"""specs_c1048.py - camera batch 1048: ZCAMERA destructor.

The base destructor 0x45c3e0 and the two helpers (0x45c510 free, 0x4690b0 reset) are hooked: each logs its tag and
returns. The hooks are the same in both builds, so the destructor's own writes and its calls are what is compared."""
from pilot import S
from camgen import rnd, Log


def _dtor(c):
    log = Log(c)
    r = c.rng
    c.emu.hook(0x45c3e0, lambda e, res: (log.put(0x45c3e0), e.ret(argbytes=0)))
    c.emu.hook(0x45c510, lambda e, res: (log.put(0x45c510), e.ret(argbytes=0)))
    c.emu.hook(0x4690b0, lambda e, res: (log.put(0x4690b0, e.arg32(1)), e.ret(argbytes=0)))
    self_ = rnd(c, 0x200)
    return [self_, r.choice([0, 1, 3, 4, 5, 7, 0x11, 0x14])]


S(0x445340, 'ZCAMERA::~ZCAMERA', 'thiscall', gen=_dtor)
