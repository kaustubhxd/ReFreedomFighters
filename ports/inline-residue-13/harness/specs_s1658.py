"""specs_s1658.py - residue 13 batch 1658: 0x47fd30 (vtable store, optional two cdecl frees, tail jump to 0x43de70).
The final target 0x45c3e0 (ZGEOM destructor, ret with no immediate) is hooked by address. 0x634273 (cdecl free) logs
every call into a heap array, so both sizes are compared, not only the last call."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _dellog(c):
    logi = c.emu.alloc(4, 4)
    log = c.emu.alloc(8 * 8, 4)

    def h(e, r):
        sp = e.reg('esp')
        i = e.r32(logi)
        e.w32(log + 8 * i, e.r32(sp + 4))
        e.w32(log + 8 * i + 4, e.r32(sp + 8))
        e.w32(logi, i + 1)
        e.ret(eax=0, argbytes=0)
    HOOKED.add(0x634273)
    c.emu.hook(0x634273, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _dellog(c)
    hook(c, seq, 0x45c3e0, 0, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    if r.random() < 0.8:
        p = rnd(c, 0x20)
        c.emu.w32(me + 0x8c, p)
    else:
        c.emu.w32(me + 0x8c, 0)
    return [me]


S(0x47fd30, 'GUESS FUN_47fd30', 'thiscall', None, ret='eax', gen=_gen,
  note='batch1658; tail jump 0x43de70 -> 0x45c3e0 hooked; every free logged')
