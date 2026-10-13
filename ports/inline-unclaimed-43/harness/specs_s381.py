"""specs_s381.py - gap band batch 381: 0x420b50 (cdecl, no arguments). It calls 0x41cf80 (exe; its own globals 0x6fcd44 and 0x6fcd48 are
set here as in batch 379), then cleans the globals 0x7003a8 and 0x7003a4: each is an object (or NULL) whose slot 0x10 takes nothing
and whose slot 0 takes one argument. The delete (0x634273) is hooked and logged; the object slots log their arguments."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('builtin_delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _obj(c, name):
    slots = {}
    for i in range(0x10 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0)] if off == 0 else []
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            e.ret(eax=0, argbytes=4 if off == 0 else 0)
        slots[off] = h
    o = E.zero_obj(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable(name, 0x10 // 4 + 1, slots))
    return o


def _gen(c):
    r = c.rng
    E.set_global(c, 0x6fcd44, 0 if r.random() < 0.5 else E.zero_obj(c, 0x20))
    E.set_global(c, 0x6fcd48, 0 if r.random() < 0.5 else _obj(c, 'ZCLEANA'))
    E.set_global(c, 0x7003a8, 0 if r.random() < 0.4 else _obj(c, 'ZCLEANB'))
    E.set_global(c, 0x7003a4, 0 if r.random() < 0.4 else _obj(c, 'ZCLEANC'))
    c.emu.mu.ctl_flush_tb()
    return []


S(0x420b50, 'cleanup two globals (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 381; calls 0x41cf80 (exe) and cleans 0x7003a8/0x7003a4')
