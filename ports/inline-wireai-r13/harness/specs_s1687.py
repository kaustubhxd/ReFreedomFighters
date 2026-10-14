"""specs_s1687.py - residue 13 batch 1687: 0x476560. The two blocks (+0x64, +0x68) are freed through 0x634273 (cdecl, logged
through a recorder); 0x43ea20 (thiscall, no arguments) is hooked; 0x45c510 (cdecl, one argument) and 0x4690b0 (cdecl, two
arguments) are hooked. The flags argument picks the branch."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _cdecl_rec(c, addr, nargs):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=0, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)
    return rec


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _cdecl_rec(c, 0x634273, 2)
    _cdecl_rec(c, 0x45c510, 1)
    _cdecl_rec(c, 0x4690b0, 2)
    hook(c, seq, 0x43ea20, 0, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x64, rnd(c, 0x10) if r.random() < 0.7 else 0)
    c.emu.w32(me + 0x68, rnd(c, 0x10) if r.random() < 0.7 else 0)
    return [me, r.choice([0, 1, 2, 4, 5, 0x100, r.getrandbits(32)])]


S(0x476560, 'GUESS FUN_476560', 'thiscall', None, ret='eax', gen=_gen, note='batch1687; frees, 0x43ea20 and cdecl exits hooked')
