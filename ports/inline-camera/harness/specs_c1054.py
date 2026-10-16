"""specs_c1054.py - camera batch 1054: ZFFCamera1 constructor.

Stubs (tag-only logs): the base constructor 0x5c9530; operator new 0x41e290 (returns the spec's object, or 0);
the sub-object constructor 0x4d83b0 (returns its object); the sys vtable's slot 0x1a4 and the manager's 0x114
(returns a value derived from its arguments)."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _ctor(c):
    log = Log(c, 512)
    r = c.rng
    self_ = rnd(c, 0x900)
    sub = rnd(c, 0x120)
    news = sub if r.random() < 0.8 else 0

    s = sys_with_mgr(c, 0x2000)
    c.emu.w32(s, c.emu.fake_vtable('sys', 0x1a8 // 4, {
        0x1a4: lambda e, res: (log.put(0x1a4), e.ret(argbytes=4)),
    }))
    mgr = rnd(c, 0x40)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x118 // 4, {
        0x114: lambda e, res: (log.put(0x114, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)),
                               e.ret(eax=_mix(e.arg32(0) + 0x114), argbytes=16)),
    }))
    c.emu.w32(s + 0x9b, mgr)
    c.emu.hook(0x5c9530, lambda e, res: (log.put(0x5c9530), e.ret(argbytes=0)))
    c.emu.hook(0x41e290, lambda e, res: (log.put(0x41e290, e.arg32(0)), e.ret(eax=news, argbytes=0)))
    c.emu.hook(0x4d83b0, lambda e, res: (log.put(0x4d83b0, e.arg32(0), e.arg32(1)), e.ret(eax=e.reg('ecx'), argbytes=12)))
    return [self_]


S(0x5ca720, 'ZFFCamera1::ZFFCamera1', 'thiscall', gen=_ctor)
