"""specs_c1052.py - camera batch 1052: ZFFCam destructor (0x5c9600).

Stubs (tag-only logs): the manager's slot 0x34 (unregister), the reset helper 0x4690b0 (cdecl) and the release
callback named by the global at 0x7003b0, which the spec sets to a stub address."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _dtor(c):
    log = Log(c)
    r = c.rng
    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x40)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x38 // 4, {
        0x34: lambda e, res: (log.put(0x34, e.arg32(0)), e.ret(argbytes=4)),
    }))
    c.emu.w32(s + 0x9b, mgr)
    c.emu.hook(0x4690b0, lambda e, res: (log.put(0x4690b0, e.arg32(1)), e.ret(argbytes=0)))
    c.emu.hook(0x445330, lambda e, res: (log.put(0x445330), e.ret(argbytes=0)))
    c.emu.w32(0x7003b0, 0x445330)   # always set: an unset callback is an int3 trap in the original (not compared)
    self_ = rnd(c, 0x200)
    return [self_, r.choice([0, 1, 3, 4, 5, 7, 0x11, 0x14])]


S(0x5c9600, 'ZFFCam::~ZFFCam', 'thiscall', gen=_dtor)
