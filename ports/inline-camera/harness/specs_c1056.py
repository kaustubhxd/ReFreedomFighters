"""specs_c1056.py - camera batch 1056: ZFFCameraClass registration helper at 0x5b22a0.

The manager's slot 0x138 returns an object whose slot 0x60 logs its arguments; slot 0x4c returns a value derived
from its second argument (not from the address, which is the same in both builds but is not logged anyway)."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _reg(c):
    log = Log(c, 128)
    obj = rnd(c, 0x40)
    c.emu.w32(obj, c.emu.fake_vtable('obj', 0x64 // 4, {
        0x60: lambda e, res: (log.put(0x60, e.arg32(0), e.arg32(1)), e.ret(argbytes=8)),
    }))
    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x40)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x140 // 4, {
        0x138: lambda e, res: e.ret(eax=obj, argbytes=0),
        0x4c: lambda e, res: (log.put(0x4c, e.arg32(1)), e.ret(eax=_mix(e.arg32(1) + 0x4c), argbytes=8)),
    }))
    c.emu.w32(s + 0x9b, mgr)
    self_ = rnd(c, 0x40)
    return [self_]


S(0x5b22a0, 'ZFFCameraClass::Register (unnamed)', 'thiscall', gen=_reg)
