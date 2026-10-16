"""specs_s1693.py - residue 13 batch 1693: 0x461020 (ZLNKOBJ destructor). CloseObjMatBone (0x461f00), the destructor chain
(0x43de70) and the two cdecl exits (0x45c510, 0x4690b0) are hooked by address; the four release objects have slot 0 (one
argument, recorded); the object's own fields select which releases run (including the equality cases)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED


def _cdecl_rec(c, addr, nargs):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=0, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x461f00, 0, ret=0, this=True, pop=True)
    hook(c, seq, 0x43de70, 0, ret=0, this=True, pop=True)
    _cdecl_rec(c, 0x45c510, 1)
    _cdecl_rec(c, 0x4690b0, 2)
    rel = [obj(c, 0x40, {0: stub(c, seq, 1)}) for _ in range(3)]
    me = rnd(c, 0x100)
    pick = lambda: r.choice([0] + rel)
    c.emu.w32(me + 0x72, pick())
    c.emu.w32(me + 0x76, pick())
    c.emu.w32(me + 0x5c, pick())
    c.emu.w32(me + 0x60, pick())
    flags = r.choice([0, 1, 2, 4, 5, 0x100, r.getrandbits(32)])
    return [me, flags]


S(0x461020, 'GUESS FUN_461020', 'thiscall', None, ret='eax', gen=_gen, note='batch1693; ZLNKOBJ dtor; CloseObjMatBone and exits hooked')
