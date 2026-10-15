"""specs_s1673.py - residue 13 batch 1673: 0x46ac40 (factory). The allocators 0x45c4f0 (cdecl, two arguments) and 0x45c4b0
(cdecl, one argument) are hooked and return a random pointer (or zero); ZItem::ZItem (0x469980) is hooked with three
arguments (thiscall, ret 0xc). The entry edx is set in the harness as a register value through the wrapper's input."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _alloc(c, addr, nargs, ret):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)
    return rec


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    p1 = rnd(c, 0x200) if r.random() < 0.8 else 0
    p2 = rnd(c, 0x200) if r.random() < 0.8 else 0
    _alloc(c, 0x45c4f0, 2, p1)
    _alloc(c, 0x45c4b0, 1, p2)
    hook(c, seq, 0x469980, 3, ret=0, this=True, pop=True)
    me = rnd(c, 0x40)
    b = r.choice([0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


S(0x46ac40, 'GUESS FUN_46ac40', 'thiscall', None, ret='eax', gen=_gen, note='batch1673; allocators and ZItem ctor hooked; SEH not reproduced')
