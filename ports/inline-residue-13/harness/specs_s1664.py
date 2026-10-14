"""specs_s1664.py - residue 13 batch 1664: 0x476300 (word compare, tick-based store at +0x52, slot 0x64 recorder). The
system object (0x70039c) has tick count +0x40 (sysobj). The float at +0x48 is kept small so the truncation is in range."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    sysobj(c, t=r.randint(0, 1 << 22))
    me = obj(c, 0x100, {0x64: stub(c, seq, 1)})
    c.emu.w16(me + 0x4c, r.getrandbits(16))
    c.emu.wf32(me + 0x48, r.uniform(-2000, 2000) if r.random() < 0.9 else r.choice([0.0, -0.0, float('nan')]))
    c.emu.w32(me + 0x52, r.getrandbits(32))
    word = c.emu.r32(me + 0x4c) & 0xffff if r.random() < 0.6 else r.getrandbits(16)
    return [me, word | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0), r.getrandbits(32)]


S(0x476300, 'GUESS FUN_476300', 'thiscall', None, ret='eax', gen=_gen, note='batch1664; ret 8; tick store and slot 0x64')
