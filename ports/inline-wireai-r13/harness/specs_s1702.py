"""specs_s1702.py - residue 13 batch 1702: 0x47fd70 (ZSTDOBJ-family destructor). The frees (0x634273, cdecl, two arguments)
log every call (the recorder keeps only the last call otherwise); 0x43de70 (no arguments) and the exits 0x45c510 (cdecl, one
argument) and 0x4690b0 (cdecl, two arguments) are hooked. The block at +0x8c is set or zero."""
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


def _cdecl_rec(c, addr, nargs):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=0, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _dellog(c)
    hook(c, seq, 0x43de70, 0, ret=0, this=True, pop=True)
    _cdecl_rec(c, 0x45c510, 1)
    _cdecl_rec(c, 0x4690b0, 2)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x8c, rnd(c, 0x10) if r.random() < 0.8 else 0)
    return [me, r.choice([0, 1, 2, 4, 5, 0x100, r.getrandbits(32)])]


S(0x47fd70, 'GUESS FUN_47fd70', 'thiscall', None, ret='eax', gen=_gen, note='batch1702; ZSTDOBJ-family dtor; frees logged; exits hooked')
