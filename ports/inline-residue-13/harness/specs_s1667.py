"""specs_s1667.py - residue 13 batch 1667: 0x476390 (GetInput hooked with one stack argument; DBREAD operators hooked as
in batch 1660; the object's slots 0x58 (one argument) and 0x68 (one argument, random eax) are recorders)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, HOOKED


def _float_hook(c, addr, val):
    def h(e, r):
        e.ret(eax=0, argbytes=0, st0=val)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _dw_hook(c, addr, val):
    def h(e, r):
        e.ret(eax=val, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    cnt = c.emu.alloc(4, 4)

    def gi(e, rr):   # GetInput: counts calls; the stack argument is a stack address, so it is not recorded
        e.w32(cnt, e.r32(cnt) + 1)
        e.ret(eax=0, argbytes=4)
    HOOKED.add(0x6352f0)
    c.emu.hook(0x6352f0, gi)
    _float_hook(c, 0x4e5e80, r.uniform(-100, 100))
    _dw_hook(c, 0x4e5e40, r.getrandbits(32))
    _dw_hook(c, 0x4e5e60, r.getrandbits(32))
    o = obj(c, 0x100, {0x58: stub(c, seq, 1), 0x68: stub(c, seq, 1, ret=r.getrandbits(32))})
    me = rnd(c, 0x100)
    return [me, o]


S(0x476390, 'GUESS FUN_476390', 'thiscall', None, ret='eax', gen=_gen, note='batch1667; GetInput and DBREAD hooked; ret 4')
