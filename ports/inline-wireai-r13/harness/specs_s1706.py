"""specs_s1706.py - residue 13 batch 1706: four functions. Hooked callees: 0x41e290 (cdecl, one argument, recorded, returns a
block), 0x504880 (no arguments, random eax), 0x4e5e60 (DBREAD operator, no arguments, random eax). The virtual slots are stubs."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED, sysobj


def _alloc(c, addr, ret):
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen_64f(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    obj_ = obj(c, 0x40, {0x4c: stub(c, seq, 0, ret=r.getrandbits(32))})
    me = rnd(c, 0x100)
    c.emu.w32(me + 0xbd, obj_)
    return [me]


def _gen_4ce(c):
    r = c.rng
    clear_hooks(c)
    _alloc(c, 0x41e290, rnd(c, 0x200))
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x10, r.randint(0, 0x40))
    return [me]


def _gen_607(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x504880, 0, ret=0, this=True, pop=True)
    me = obj(c, 0x40, {0x9c: stub(c, seq, 1, ret=r.getrandbits(32))})
    return [me]


def _gen_57c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x4e5e60, 0, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x200)
    return [me, rnd(c, 0x40)]


S(0x64f850, 'GUESS FUN_64f850', 'thiscall', None, ret='eax', gen=_gen_64f, note='batch1706; virtual tail to slot 0x4c')
S(0x4ce850, 'GUESS FUN_4ce850', 'thiscall', None, ret='eax', gen=_gen_4ce, note='batch1706; allocation of (n*4+0x10)')
S(0x607910, 'GUESS FUN_607910', 'thiscall', None, ret='eax', gen=_gen_607, note='batch1706; ZRenderBaseDll::Init hooked')
S(0x57c1d0, 'GUESS FUN_57c1d0', 'thiscall', None, ret=None, gen=_gen_57c, note='batch1706; DBREAD operator hooked; ret 4')
