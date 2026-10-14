"""specs_s32078.py - h2 () batch 32078: 0x4d14a0. 0x41e290 (alloc, returns a fixed buffer) and 0x634d22 (memcpy) are cdecl recorders."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g4d14a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x100)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)
    me = rnd(c, 0x20)
    owner = rnd(c, 0x40)
    if r.random() < 0.7:
        e.w32(owner + 0x1c, rnd(c, 0x20))
    else:
        e.w32(owner + 0x1c, 0)
    after = 0
    if r.random() < 0.6:
        after = rnd(c, 0x20)
        e.w32(after + 4, rnd(c, 0x20) if r.random() < 0.6 else 0)
    return [me, rnd(c, 0x40), r.choice([0, 1, r.randrange(0, 0x100), r.getrandbits(32) & 0xff]), owner, after]


S(0x4d14a0, 'GUESS new list node with byte copy, link after/at tail', 'thiscall', None, ret='eax', gen=g4d14a0, note='batch32078')
