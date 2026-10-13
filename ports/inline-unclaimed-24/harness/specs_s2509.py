"""specs_s2509.py - decomp area 24, batch 2509.
0x575970 (GUESS UI object refresh): thiscall(a, b), ret 8. 0x574280 (thiscall, 2 args) and 0x5738c0 (thiscall, 1 arg) hooked;
this->vtable[0x84] returns an object whose vtable[0x350] is a recorder (thiscall, 3 args, pops 12); the object at +0x20e has
vtable[0xbc] (thiscall, 1 arg, pops 4). The low byte of b gates the store of 0 to +0x20a."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x574280, 2, this=True, pop=8)
    hook_rec(c, 0x5738c0, 1, this=True, pop=4)
    t = obj(c, 0x40, {0x350: pystub(c, 3, this=True, pop=12)})
    sub = obj(c, 0x40, {0xbc: pystub(c, 1, this=True, pop=4)})
    me = obj(c, 0x230, {0x84: pystub(c, 0, this=True, ret=t)})
    e.w32(me + 0x20e, sub)
    b = r.getrandbits(32)
    if r.random() < 0.4:
        b &= ~0xff
    return [me, r.getrandbits(32), b]


S(0x575970, 'GUESS UI object refresh', 'thiscall', None, ret=None, gen=_gen, note='batch2509')
