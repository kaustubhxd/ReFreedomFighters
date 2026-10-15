"""specs_s1695.py - residue 13 batch 1695: 0x467f80 (single-allocation factory). The allocator 0x45c4f0 (cdecl, two arguments,
recorded) returns a block or zero; the ZIKLNKOBJ constructor 0x4654b0 is hooked (three arguments, ret 0xc, recorded)."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, HOOKED


def _alloc(c, ret):
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(e.reg('esp') + 8))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(0x45c4f0)
    c.emu.hook(0x45c4f0, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _alloc(c, rnd(c, 0x200) if r.random() < 0.8 else 0)
    hook(c, seq, 0x4654b0, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x40)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x467f80, 'GUESS FUN_467f80', 'thiscall', None, ret='eax', gen=_gen, note='batch1695; tag 0x1e2; ZIKLNKOBJ ctor hooked')
