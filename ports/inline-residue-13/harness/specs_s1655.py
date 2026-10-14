"""specs_s1655.py - residue 13 batch 1655: 0x480620 (calls 0x45f3c0 with one argument, then 0x4805a0) and 0x46a5c0 (vtable
store, optional slot-0 call on +0x70, then a tail jump to 0x43ea20). Callees are hooked by address."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen480(c):
    seq = Seq(c)
    clear_hooks(c)
    hook(c, seq, 0x45f3c0, 1, ret=0, this=True, pop=True)
    hook(c, seq, 0x4805a0, 0, ret=0, this=True, pop=True)
    return [rnd(c, 0x100), c.rng.getrandbits(32)]


def _gen46a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43ea20, 0, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    if r.random() < 0.7:
        p = obj(c, 0x40, {0: stub(c, seq, 1, ret=0)})
        c.emu.w32(me + 0x70, p)
    else:
        c.emu.w32(me + 0x70, 0)
    return [me]


S(0x480620, 'GUESS FUN_480620', 'thiscall', None, ret='al', gen=_gen480, note='batch1655; ret 4; callees hooked')
S(0x46a5c0, 'GUESS FUN_46a5c0', 'thiscall', None, ret='eax', gen=_gen46a, note='batch1655; tail jump to 0x43ea20 hooked')
