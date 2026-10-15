"""specs_s1613.py - soundtimers batch 1613: ZDllSound::AddSound3d (allocation, free path hooked)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _add(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = r.getrandbits(32) | 1
    o = rnd(c, 0x100)
    hook(c, seq, 0x533e00, 0, ret=h if r.random() < 0.9 else 0)
    hook(c, seq, 0x44b610, 0)
    hook(c, seq, 0x44b740, 1, this=False, pop=False)
    db = obj(c, 0xb00, {0x60: stub(c, seq, 1, ret=o), 0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    me = obj(c, 0x200, {0x4c: stub(c, seq, 1, ret=(r.getrandbits(24) << 8) | r.choice([0, 1, 1]))})
    return [me, rnd(c, 0x40), r.getrandbits(32), rnd(c, 0x24), rnd(c, 0xc)]


S(0x535150, 'ZDllSound::AddSound3d', 'thiscall', None, ret='eax', gen=_add, note='batch1613')


def _add2(c):
    a = _add(c)
    db = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    return [a[0], c.rng.getrandbits(32), c.rng.choice([4, 4, 0, 1, 3, 5, c.rng.getrandbits(32)])]


S(0x534fd0, 'ZDllSound::AddSound2d', 'thiscall', None, ret='eax', gen=_add2, note='batch1613')
