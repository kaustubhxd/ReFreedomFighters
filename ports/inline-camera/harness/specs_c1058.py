"""specs_c1058.py - camera batch 1058: CCameraBox::Init.

Stubs: operator new 0x41e290 returns a block whose word before it is set by the spec; the manager's slot 0x4c returns
a mix of its argument; the +0xadc object's slots 0x25c and 0x294 return the spec's object (0x25c may return 0); the
object's slots 0x154, 0x124, 0x21c and the event manager's slots 0x20 and 0xac log; the event manager's function at
+8 is a hook returning a mix of its ECX. The flag helper 0x4dc630 is not stubbed: it runs as original code.
Every value a handler returns is chosen in the generator, never by an RNG draw inside a handler."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _mix(x):
    return ((x * 2654435761) ^ 0x9e3779b9) & 0xffffffff


def _init(c):
    log = Log(c, 256)
    r = c.rng
    self_ = rnd(c, 0x100)
    c.emu.w32(self_ + 0x44, r.getrandbits(32))
    c.emu.w32(self_ + 0x48, r.getrandbits(32))

    pre = rnd(c, 0x20)           # the block: 16 bytes before it, so that p-4 is readable
    blk = pre + 0x10
    c.emu.hook(0x41e290, lambda e, res: (log.put(0x41e290, e.arg32(0)), e.ret(eax=blk, argbytes=0)))
    c.emu.w32(pre + 0xc, r.getrandbits(32) if r.random() < 0.5 else 0)

    obj = rnd(c, 0x80)
    c.emu.w32(obj, c.emu.fake_vtable('camobj', 0x230 // 4, {
        0x154: lambda e, res: (log.put(0x154), e.ret(argbytes=0)),
        0x124: lambda e, res: (log.put(0x124, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)), e.ret(argbytes=16)),
        0x21c: lambda e, res: (log.put(0x21c, e.arg32(0)), e.ret(argbytes=4)),
    }))
    c.emu.w32(obj + 8, rnd(c, 0x20))

    s = sys_with_mgr(c, 0x2000)
    mgr = rnd(c, 0x1000)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x50 // 4, {
        0x4c: lambda e, res: (log.put(0x4c, e.arg32(0)), e.ret(eax=_mix(e.arg32(0) + 0x4c), argbytes=4)),
    }))
    c.emu.w32(s + 0x9b, mgr)

    have = r.random() < 0.5          # does slot 0x25c find an object?
    o2 = rnd(c, 0x40)
    c.emu.w32(o2, c.emu.fake_vtable('o2', 0x300 // 4, {
        0x25c: lambda e, res: (log.put(0x25c, e.arg32(0), e.arg32(1)), e.ret(eax=obj if have else 0, argbytes=8)),
        0x294: lambda e, res: (log.put(0x294, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)), e.ret(eax=obj, argbytes=16)),
    }))
    c.emu.w32(mgr + 0xadc, o2)

    ev = rnd(c, 0x40)
    ev20 = r.choice([0, 1])          # does the event manager already know the block?
    c.emu.w32(ev, c.emu.fake_vtable('ev', 0xb0 // 4, {
        0x20: lambda e, res: (log.put(0x20, e.arg32(0)), e.ret(eax=ev20, argbytes=4)),
        0xac: lambda e, res: (log.put(0xac, e.arg32(0)), e.ret(argbytes=4)),
    }))
    c.emu.w32(ev + 0xc, 0 if r.random() < 0.7 else 0x80000000)
    c.emu.w32(ev + 0x10, 0xffffffff if r.random() < 0.7 else 0x1000)
    fresult = r.getrandbits(32)
    c.emu.hook(0x445330, lambda e, res: (log.put(0x445330), e.ret(eax=_mix(e.reg('ecx')) ^ fresult, argbytes=0)))
    c.emu.w32(ev + 8, 0x445330 if r.random() < 0.8 else 0)
    c.emu.w32(0x70038c, ev)
    return [self_]


S(0x5c7db0, 'CCameraBox::Init', 'thiscall', gen=_init)
