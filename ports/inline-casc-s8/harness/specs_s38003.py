"""specs_s38003.py - cascade s8 batch 38003: 0x630ec0 (send_all_trees). Deflate state: pending_buf (+8) points to a 0x400 buffer, pending (+0x14) random 0..0x100,
bi_buf (+0x16b0) / bi_valid (+0x16b4) random (bi_valid mostly 0..16, sometimes outside). 0x631100 hooked (cdecl, 3 args, records)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g630ec0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x1700)
    e.w32(s + 8, rnd(c, 0x400, 1))
    e.w32(s + 0x14, r.randrange(0x100))
    e.w32(s + 0x16b4, r.choice([r.randrange(0, 17), r.randrange(0, 17), r.randrange(0, 17), r.randrange(-3, 40)]) & 0xffffffff)
    hook_rec(c, 0x631100, 3, pop=0)
    if r.random() < 0.8:
        lc, dc, bc = r.randrange(257, 287), r.randrange(1, 31), r.randrange(4, 20)
    else:
        lc, dc, bc = [r.choice([0, 1, 256, 257, 300, 0xffff, 0x10000, r.getrandbits(32)]) for _ in range(2)] + [r.choice([0, -1 & 0xffffffff, 1, 4, 19, 25])]
    return [s, lc & 0xffffffff, dc & 0xffffffff, bc & 0xffffffff]


S(0x630ec0, 'GUESS send_all_trees', 'cdecl', None, ret=None, gen=_g630ec0, note='batch38003')
