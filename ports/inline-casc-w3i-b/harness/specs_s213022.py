"""specs_s213022.py - batch 213022: effect starter with a float argument and engine clock stamps, Sonnet-w3b."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5253b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0xc8)
    a = obj(c, 0x20, {0x80: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x24)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x40, r.choice([0, 1000, 123456, r.getrandbits(32), r.getrandbits(20)]))
    hook_rec(c, 0x5257a0, 1, ret=r.choice([1, 1, 1, 0, 0x100, 0x1ff, r.getrandbits(32)]), this=True)
    for a_ in (0x5266e0, 0x526540, 0x5267b0, 0x526610):
        hook_rec(c, a_, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5254c0, 0, ret=r.getrandbits(32), this=True)
    sel = r.randint(0, 4) if r.random() < 0.92 else r.getrandbits(32)
    x = r.choice([0.0, 1.0, -0.5, r.uniform(-50, 50)])
    return [this, a, sel, F(x), r.getrandbits(32), r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])]


S(0x5253b0, 'start_effect', 'thiscall', None, ret='eax', gen=g5253b0)
