"""specs_s1697.py - residue 13 batch 1697: 0x4680e0. The fastcall target 0x467f80 is hooked with a recorder (ecx, edx, two
stack arguments; callee pops 8); the allocator 0x45c4b0 (cdecl, one argument) and ZIKLNKOBJ::ZIKLNKOBJ (0x4654b0, three
arguments, ret 0xc) are hooked."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _fastcall_hook(c, rv):
    rec = c.emu.alloc(16, 4)

    def h(e, r):
        sp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.reg('edx'))
        e.w32(rec + 8, e.r32(sp + 4))
        e.w32(rec + 12, e.r32(sp + 8))
        e.ret(eax=rv, argbytes=8)
    HOOKED.add(0x467f80)
    c.emu.hook(0x467f80, h)


def _alloc1(c, ret):
    def h(e, r):
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(0x45c4b0)
    c.emu.hook(0x45c4b0, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _fastcall_hook(c, r.getrandbits(32))
    _alloc1(c, rnd(c, 0x200) if r.random() < 0.8 else 0)   # the fields go up to +0x1da
    hook(c, seq, 0x4654b0, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x80)
    b = r.choice([0, 0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


S(0x4680e0, 'GUESS FUN_4680e0', 'thiscall', None, ret='eax', gen=_gen, note='batch1697; fastcall into 0x467f80 hooked; alloc 0x45c4b0')
