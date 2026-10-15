"""specs_s1694.py - residue 13 batch 1694: 0x4657b0 (factory, tag 0x1d2). The allocators (0x45c4f0 cdecl two arguments, 0x45c4b0
cdecl one argument; both recorded) return distinct pointers or zero; ZLNKOBJ::ZLNKOBJ (0x4654b0) is hooked (three arguments, ret
0xc, random eax)."""
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
    hook(c, seq, 0x4654b0, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x40)
    b = r.choice([0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


S(0x4657b0, 'GUESS FUN_4657b0', 'thiscall', None, ret='eax', gen=_gen, note='batch1694; tag 0x1d2; ZIKLNKOBJ ctor hooked')
