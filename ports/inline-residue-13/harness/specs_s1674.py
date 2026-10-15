"""specs_s1674.py - residue 13 batch 1674: 0x46ae40 (factory, tag 0x98). The allocators (0x45c4f0 cdecl two arguments,
0x45c4b0 cdecl one argument) return distinct random pointers or zero; the constructor 0x469b40 is hooked (three
arguments, ret 0xc, random eax)."""
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


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    p1 = rnd(c, 0x200) if r.random() < 0.8 else 0
    p2 = rnd(c, 0x200) if r.random() < 0.8 else 0
    _alloc(c, 0x45c4f0, 2, p1)
    _alloc(c, 0x45c4b0, 1, p2)
    hook(c, seq, 0x469b40, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x40)
    b = r.choice([0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


S(0x46ae40, 'GUESS FUN_46ae40', 'thiscall', None, ret='eax', gen=_gen, note='batch1674; allocators and ctor hooked; SEH not reproduced')
