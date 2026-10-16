"""specs_s5781.py - unclaimed-57, batch 81: 0x5d88d0 (GUESS name unnamed_5d88d0). Deleting destructor shape: thiscall, one stack argument
(flags, ret 4), returns this. The owned pointers at this+0x20 and +0x24 are per-case allocations (null in about three cases in ten).
Hooked: 0x41e2c0 (cdecl delete, logs the pointer), 0x634273 (cdecl sized delete, logs the pointer and size), 0x43de70 (base destructor, a
logging stub with ECX), 0x4690b0 (cdecl sized free, logs pointer and size) and 0x45c510 (logs ECX). All are owned by other areas and
write nothing here; the pointers are the same in both executions of a case, so they can be logged."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d88d0(c):
    e = c.emu

    # all three are cdecl: the caller pops the arguments, so the stubs return with argbytes=0
    def cdel(name):
        def h(em, r):
            em.calllog.append((name, 0, None, (em.arg32(0),)))
            em.ret(eax=0, argbytes=0)
        return h

    def sized(name):
        def h(em, r):
            em.calllog.append((name, 0, None, (em.arg32(0), em.arg32(1))))
            em.ret(eax=0, argbytes=0)
        return h

    def thiscall_log(name):
        def h(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), ()))
            em.ret(eax=0, argbytes=0)
        return h

    e.hook(0x41e2c0, cdel('41e2c0'))
    e.hook(0x634273, sized('634273'))
    e.hook(0x4690b0, sized('4690b0'))
    e.hook(0x43de70, thiscall_log('43de70'))
    def cdecl_one(name):
        def h(em, r):
            em.calllog.append((name, 0, None, (em.arg32(0),)))
            em.ret(eax=0, argbytes=0)
        return h

    e.hook(0x45c510, cdecl_one('45c510'))
    self_obj = _rnd(c, 0x80)
    p20 = 0 if c.rng.random() < 0.3 else _rnd(c, 0x10)
    p24 = 0 if c.rng.random() < 0.3 else _rnd(c, 0x10)
    e.w32(self_obj + 0x20, p20)
    e.w32(self_obj + 0x24, p24)
    flags = c.rng.getrandbits(32)
    return [self_obj, flags]


S(0x5d88d0, 'unnamed_5d88d0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_d88d0,
  note='unclaimed-57 batch 81; deleting-dtor shape (SEH-free); cdecl deletes, base 0x43de70, 0x45c510 and 0x4690b0 hooked (log)')
