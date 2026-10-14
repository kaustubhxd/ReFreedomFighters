"""specs_s35070.py - 0x570e80 (thiscall(k) ret 4, ret='al'). k in 0..5 (1..3 favoured); this vtable slots 0xd8 (AL true in a third; garbage upper bytes) and 0xd0 (1 arg); 0x562c20 (thiscall, 1 arg),
0x5718b0, 0x5707d0, 0x59b710 (thiscall, no args) hooked; object random 0x1a0 bytes."""
from pilot import S
from recruits_util import obj, clear_hooks, hook_rec, pystub


def _g570e80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562c20, 1, this=True)
    hook_rec(c, 0x5718b0, 0, this=True)
    hook_rec(c, 0x5707d0, 0, this=True)
    hook_rec(c, 0x59b710, 0, this=True)
    t = (r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]) if r.random() < 1 / 3 else 0)
    me = obj(c, 0x1a0, {0xd8: pystub(c, 0, this=True, ret=t), 0xd0: pystub(c, 1, this=True)}, nslots=0x37)
    return [me, r.choice([0, 1, 2, 3, 1, 2, 3, 4, 5, r.getrandbits(32)])]


S(0x570e80, 'GUESS apply mode change by number', 'thiscall', None, ret='al', gen=_g570e80, note='batch35070')
