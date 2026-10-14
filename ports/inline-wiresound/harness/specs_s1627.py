"""specs_s1627.py - soundtimers batch 1627: ZDllSound::SetListener (database resolve stub, log object)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    ok = r.random() < 0.6
    db = obj(c, 0x80, {0x58: stub(c, seq, 1, ret=rnd(c, 8) if ok else 0)})
    sysobj(c, db=db)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    d = rnd(c, 0x5300)
    return [d, r.getrandbits(32)]


S(0x539be0, 'ZDllSound::SetListener', 'thiscall', None, ret=None, gen=_gen, note='batch1627')
