"""specs_s1684.py - residue 13 batch 1684: 0x476400 (factory, tag 0x77). The allocator 0x45c4f0 (cdecl, two arguments)
returns a random pointer or zero; ZGROUP::ZGROUP (0x43e990) is hooked (three arguments, ret 0xc, random eax)."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _alloc(c, ret):
    def h(e, r):
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(0x45c4f0)
    c.emu.hook(0x45c4f0, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _alloc(c, rnd(c, 0x100) if r.random() < 0.8 else 0)
    hook(c, seq, 0x43e990, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x80)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x476400, 'GUESS FUN_476400', 'thiscall', None, ret='eax', gen=_gen, note='batch1684; tag 0x77; ZGROUP ctor hooked')
