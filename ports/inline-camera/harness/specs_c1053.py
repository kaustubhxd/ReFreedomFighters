"""specs_c1053.py - camera batch 1053: ZFFCamera1 destructor.

Stubs (tag-only logs): the sys object's slot 0x1a8, the owner's slot 0 (deleting dtor), the base destructor 0x4f6b20,
the reset helper 0x4690b0 (cdecl) and the release callback named by the global at 0x7003b0."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _dtor(c):
    log = Log(c)
    r = c.rng
    s = sys_with_mgr(c, 0x2000)
    c.emu.w32(s, c.emu.fake_vtable('sys', 0x1ac // 4, {
        0x1a8: lambda e, res: (log.put(0x1a8, e.arg32(0)), e.ret(argbytes=4)),
    }))
    owner = 0
    if r.random() < 0.8:
        owner = rnd(c, 0x40)
        c.emu.w32(owner, c.emu.fake_vtable('owner', 0x4 // 4, {
            0x0: lambda e, res: (log.put(0x0, e.arg32(0)), e.ret(argbytes=4)),
        }))
    self_ = rnd(c, 0x800)
    c.emu.w32(self_ + 0x5a8, owner)
    c.emu.hook(0x4f6b20, lambda e, res: (log.put(0x4f6b20), e.ret(argbytes=0)))
    c.emu.hook(0x4690b0, lambda e, res: (log.put(0x4690b0, e.arg32(1)), e.ret(argbytes=0)))
    c.emu.hook(0x445330, lambda e, res: (log.put(0x445330), e.ret(argbytes=0)))
    c.emu.w32(0x7003b0, 0x445330)
    return [self_, r.choice([0, 1, 3, 4, 5, 7, 0x11, 0x14])]


S(0x5cac20, 'ZFFCamera1::~ZFFCamera1', 'thiscall', gen=_dtor)
