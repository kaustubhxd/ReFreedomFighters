"""specs_s35077.py - 0x48cf50 (thiscall, no args). this = random 0x20 bytes with [+0xc] = cap among 0, 1, 5, 32, 100, 0x20000000 (8*cap overflows), 0x40000000, random, and [+8] equal to cap, zero, or another
value; 0x634273 (cdecl, 2 args), 0x634d10 (cdecl, 3 args) recorders; 0x41e290 (cdecl, 1 arg) returns a fresh heap block per call."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g48cf50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x634d10, 3, pop=0)
    blocks = [rnd(c, 0x20), rnd(c, 0x20)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[min(k, 1)])
    cap = r.choice([0, 1, 5, 32, 100, 0x20000000, 0x40000000, 0x1fffffff, r.getrandbits(32)])
    t = r.random()
    cur = cap if t < 0.3 else (0 if t < 0.55 else r.choice([1, 7, 64, r.getrandbits(32)]))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, cap)
    e.w32(me + 8, cur)
    return [me]


S(0x48cf50, 'GUESS reallocate and clear parallel arrays', 'thiscall', None, ret=None, gen=_g48cf50, note='batch35077')
