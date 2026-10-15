"""specs_s1701.py - residue 13 batch 1701: 0x47f810 and 0x47fc30 (factories with the ZSTDOBJ constructor 0x43de40, hooked).
The allocators 0x45c4f0 (cdecl, two arguments) and 0x45c4b0 (cdecl, one argument) return blocks or zero (recorded)."""
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
    _alloc(c, 0x45c4f0, 2, rnd(c, 0x200) if r.random() < 0.8 else 0)
    _alloc(c, 0x45c4b0, 1, rnd(c, 0x200) if r.random() < 0.8 else 0)
    hook(c, seq, 0x43de40, 3, ret=0, this=True, pop=True)
    me = rnd(c, 0x80)
    b = r.choice([0, 0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


S(0x47f810, 'GUESS FUN_47f810', 'thiscall', None, ret='eax', gen=_gen, note='batch1701; two alloc branches; ZSTDOBJ ctor hooked')
S(0x47fc30, 'GUESS FUN_47fc30', 'thiscall', None, ret='eax', gen=_gen, note='batch1701; tag 0x90; ZSTDOBJ ctor hooked')
