"""specs_s1675.py - residue 13 batch 1675: three factory variants of 0x46ac40 (tags 0x7c, 0xa4, 0x80). The allocators
0x45c4f0 (cdecl, two arguments) and 0x45c4b0 (cdecl, one argument) return distinct random pointers or zero; each variant's
constructor is hooked (thiscall, three arguments, ret 0xc, random eax)."""
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


def _mk(ctor):
    def gen(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        p1 = rnd(c, 0x200) if r.random() < 0.8 else 0
        p2 = rnd(c, 0x200) if r.random() < 0.8 else 0
        _alloc(c, 0x45c4f0, 2, p1)
        _alloc(c, 0x45c4b0, 1, p2)
        hook(c, seq, ctor, 3, ret=r.getrandbits(32), this=True, pop=True)
        me = rnd(c, 0x40)
        b = r.choice([0, 1, r.getrandbits(32)])
        return [me, r.getrandbits(32), b]
    return gen


S(0x46aee0, 'GUESS FUN_46aee0', 'thiscall', None, ret='eax', gen=_mk(0x469da0), note='batch1675; tag 0x7c; SEH not reproduced')
S(0x46af80, 'GUESS FUN_46af80', 'thiscall', None, ret='eax', gen=_mk(0x469ea0), note='batch1675; tag 0xa4; SEH not reproduced')
S(0x46b020, 'GUESS FUN_46b020', 'thiscall', None, ret='eax', gen=_mk(0x469f80), note='batch1675; tag 0x80; SEH not reproduced')
