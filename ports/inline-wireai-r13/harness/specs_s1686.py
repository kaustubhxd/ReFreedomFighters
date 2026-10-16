"""specs_s1686.py - residue 13 batch 1686: 0x46ace0 and 0x46ad90 (fastcall branch into 0x469730 / 0x4697d0, zero branch via the
allocator 0x45c4b0 and ZItem::ZItem 0x469980). The fastcall targets record ecx, edx and two stack arguments and return a random
eax; the allocator returns a random pointer or zero; the constructor is hooked (three arguments, ret 0xc)."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _fastcall_hook(c, addr, rv):
    rec = c.emu.alloc(16, 4)

    def h(e, r):
        sp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.reg('edx'))
        e.w32(rec + 8, e.r32(sp + 4))
        e.w32(rec + 12, e.r32(sp + 8))
        e.ret(eax=rv, argbytes=8)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _alloc1(c, ret):
    def h(e, r):
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(0x45c4b0)
    c.emu.hook(0x45c4b0, h)


def _mk(fc):
    def gen(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        _fastcall_hook(c, fc, r.getrandbits(32))
        _alloc1(c, rnd(c, 0x100) if r.random() < 0.8 else 0)
        hook(c, seq, 0x469980, 3, ret=r.getrandbits(32), this=True, pop=True)
        me = rnd(c, 0x80)
        b = r.choice([0, 0, 1, r.getrandbits(32)])
        return [me, r.getrandbits(32), b]
    return gen


S(0x46ace0, 'GUESS FUN_46ace0', 'thiscall', None, ret='eax', gen=_mk(0x469730), note='batch1686; fastcall branch 0x469730 hooked')
S(0x46ad90, 'GUESS FUN_46ad90', 'thiscall', None, ret='eax', gen=_mk(0x4697d0), note='batch1686; fastcall branch 0x4697d0 hooked')
