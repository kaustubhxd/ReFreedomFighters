"""specs_s393.py - core batch 393: 0x489160 (thiscall, no arguments). Callee 0x488bc0 is hooked by address and logged (GUESS:
body not ported). Vtable slot 0x58 (one argument, 0x68d410) returns a random dword stored at +0x391; slot 0x54 takes the
address this+0x391 and logs it. Both are logging mocks."""
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x488bc0, lambda em, r: (em.calllog.append(('init488bc0', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    rv = r.getrandbits(32)
    slots = {}
    for i in range(0x60 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0)] if off in (0x58, 0x54) else []
            e.calllog.append(('FIELD391', off, e.reg('ecx'), tuple(args)))
            e.ret(eax=rv if off == 0x58 else 0, argbytes=4 if off in (0x58, 0x54) else 0)
        slots[off] = h
    vt = c.emu.fake_vtable('FIELD391', 0x60 // 4 + 1, slots)
    o = E.zero_obj(c, 0x400)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x489160, 'init field at +0x391 (core) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 393; callee 0x488bc0 hooked (GUESS); vtable slots 0x58 and 0x54 mocked')
