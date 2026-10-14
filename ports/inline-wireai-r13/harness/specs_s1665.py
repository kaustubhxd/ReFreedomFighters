"""specs_s1665.py - residue 13 batch 1665: 0x476240 (no arguments). The gate is the byte at +0x56 and bit 10 of
[[+0x44]+8]+0x3c; both values are random, so every branch (gate off, bit set, bit clear) is taken."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    sysobj(c, t=r.randint(0, 1 << 22))
    q = rnd(c, 0x40)
    c.emu.w32(q + 0x3c, r.getrandbits(32))
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, q)
    me = obj(c, 0x100, {0x64: stub(c, seq, 1)})
    c.emu.w32(me + 0x44, o)
    c.emu.w8(me + 0x56, r.choice([0, 1, 0x80]))
    c.emu.wf32(me + 0x48, r.uniform(-2000, 2000))
    c.emu.w32(me + 0x52, r.getrandbits(32))
    return [me]


S(0x476240, 'GUESS FUN_476240', 'thiscall', None, ret=None, gen=_gen, note='batch1665; no args; gate bit 10 and byte +0x56')
