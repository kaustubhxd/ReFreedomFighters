"""specs_s1679.py - residue 13 batch 1679: 0x469730 (tag 0x92) and 0x4697d0 (tag 0x94). The allocator 0x45c4f0 (cdecl, two
arguments; records them) returns a random pointer or zero; ZItem::ZItem (0x469980) is hooked (three arguments, ret 0xc)."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _alloc(c, ret):
    rec = c.emu.alloc(12, 4)

    def h(e, r):
        sp = e.reg('esp')
        e.w32(rec, e.r32(sp + 4))
        e.w32(rec + 4, e.r32(sp + 8))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(0x45c4f0)
    c.emu.hook(0x45c4f0, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    p = rnd(c, 0x100) if r.random() < 0.8 else 0
    _alloc(c, p)
    hook(c, seq, 0x469980, 3, ret=0, this=True, pop=True)
    me = rnd(c, 0x40)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x469730, 'GUESS FUN_469730', 'thiscall', None, ret='eax', gen=_gen, note='batch1679; tag 0x92; ZItem ctor hooked; SEH not reproduced')
S(0x4697d0, 'GUESS FUN_4697d0', 'thiscall', None, ret='eax', gen=_gen, note='batch1679; tag 0x94; ZItem ctor hooked; SEH not reproduced')
