"""specs_s1629.py - soundtimers batch 1629: ZDllSound::Reset (embedded lists and the DLL virtual are stubs)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    l1 = obj(c, 0x40, {0xc: stub(c, seq, 0)})
    l2 = obj(c, 0x40, {0xc: stub(c, seq, 0)})
    d = rnd(c, 0x5400)
    dvt = obj(c, 0x200, {0xf4: stub(c, seq, 1)})
    c.emu.w32(d, c.emu.r32(dvt))
    c.emu.w32(d + 0x53b2, c.emu.r32(l1))
    c.emu.w32(d + 0x5306, c.emu.r32(l2))
    return [d]


S(0x5396d0, 'ZDllSound::Reset', 'thiscall', None, ret=None, gen=_gen, note='batch1629')
