"""specs_s379.py - gap band batch 379: 0x41cf80 (cdecl, no arguments). Globals: 0x6fcd44 (a block to delete with size 13, or NULL),
0x6fcd48 (an object whose slot 0x10 takes no arguments and whose slot 0 takes one argument, or NULL). __builtin_delete (0x634273)
is hooked and logged; the two object slots log their argument."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('builtin_delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    p = 0 if r.random() < 0.4 else E.zero_obj(c, 0x20)
    E.set_global(c, 0x6fcd44, p)
    if r.random() < 0.6:
        slots = {}
        for i in range(0x10 // 4 + 1):
            off = 4 * i

            def h(e, rr, off=off):
                args = [e.arg32(0)] if off == 0 else []
                e.calllog.append(('ZCLEANOBJ', off, e.reg('ecx'), tuple(args)))
                e.ret(eax=0, argbytes=4 if off == 0 else 0)
            slots[off] = h
        o = E.zero_obj(c, 0x20)
        c.emu.w32(o, c.emu.fake_vtable('ZCLEANOBJ', 0x10 // 4 + 1, slots))
    else:
        o = 0
    E.set_global(c, 0x6fcd48, o)
    c.emu.mu.ctl_flush_tb()
    return []


S(0x41cf80, 'global cleanup (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 379; __builtin_delete hooked')
