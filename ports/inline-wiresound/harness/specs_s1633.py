"""specs_s1633.py - soundtimers batch 1633: ZDllSound::GetCurrentRoom (ZCAMERA::CurrentRoom hooked with a recorder)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x445c50, 0, ret=r.getrandbits(32), this=True, pop=False)
    db = obj(c, 0x1000, {})
    c.emu.w32(db + 0xadc, r.getrandbits(32))
    sysobj(c, db=db)
    geom = rnd(c, 0x40) if r.random() < 0.7 else 0
    return [rnd(c, 0x40), geom]


S(0x536c40, 'ZDllSound::GetCurrentRoom', 'thiscall', None, ret='eax', gen=_gen, note='batch1633')
