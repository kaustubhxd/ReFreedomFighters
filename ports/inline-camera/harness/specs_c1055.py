"""specs_c1055.py - camera batch 1055: ZShakeCamera constructor. The base constructor 0x469870 is hooked (tag only);
the manager's slot 0x114 returns a value derived from its arguments."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _ctor(c):
    log = Log(c, 256)
    self_ = rnd(c, 0x80)
    c.emu.w32(self_ + 4, c.rng.getrandbits(32))
    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x40)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x118 // 4, {
        0x114: lambda e, res: (log.put(0x114, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)),
                               e.ret(eax=_mix(e.arg32(0) + e.arg32(3)), argbytes=16)),
    }))
    c.emu.w32(s + 0x9b, mgr)
    c.emu.hook(0x469870, lambda e, res: (log.put(0x469870), e.ret(argbytes=0)))
    return [self_]


S(0x5d3360, 'ZShakeCamera::ZShakeCamera', 'thiscall', gen=_ctor)
