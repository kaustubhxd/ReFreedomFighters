"""specs_s1657.py - residue 13 batch 1657: 0x476500 (two cdecl frees through 0x634273, then a tail jump to 0x43ea20) and
0x4690c0 (flag-gated slot 0x4c on this, then the manager's slot 0x148). Callees are hooked; blocks are heap pointers."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen500(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x634273, 2, ret=0, this=False, pop=False)
    hook(c, seq, 0x43ea20, 0, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x64, rnd(c, 0x10) if r.random() < 0.7 else 0)
    c.emu.w32(me + 0x68, rnd(c, 0x10) if r.random() < 0.7 else 0)
    return [me]


def _gen4690(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    mgr = obj(c, 0x100, {0x148: stub(c, seq, 2)})
    sysobj(c, db=mgr)
    me = obj(c, 0x100, {0x4c: stub(c, seq, 0)})
    c.emu.w32(me + 4, r.getrandbits(32))
    o = rnd(c, 0x20)
    return [me if r.random() < 0.9 else 0, o]


S(0x476500, 'GUESS FUN_476500', 'thiscall', None, ret='eax', gen=_gen500, note='batch1657; tail jump hooked')
S(0x4690c0, 'GUESS FUN_4690c0', 'thiscall', None, ret=None, gen=_gen4690, note='batch1657; ret 4; manager slot 0x148')
