"""specs_s213060.py - batch 213060: scanner driver loop with callback and three helpers, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def g61f400(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hot = [-15, -4, -2, -1, 0]
    cont = [11, 13, 15, 15, 11, 13]
    n = r.randint(0, 4)
    seq = [r.choice(cont) for _ in range(n)]
    seq.append(r.choice(hot + hot + [r.choice([-16, 16, 17, 100, -1000, 0x7fffffff, -0x80000000, 1, 5, -3, -14, 14, 12, -5])]))
    curs = [rnd(c, 4) for _ in seq]

    def cb_ret(emu, k):
        return seq[min(k, len(seq) - 1)] & 0xffffffff

    def cb_side(emu, k):
        if r.random() < 0.25:
            return
        emu.w32(emu.arg32(3), r.choice([0x1000, 0x2000, 0x1234, r.getrandbits(32)]) if r.random() < 0.3 else r.getrandbits(32))
    cb = pystub(c, 4, ret=cb_ret, pop=0, nullflag=(3,), side=cb_side)
    obj = rnd(c, 0x20)
    e.w32(obj, cb)
    s = rnd(c, 0x130)
    e.w32(s + 0x8c, obj)
    e.w32(s + 0x50, r.choice([0, 0, 1, r.getrandbits(32)]))
    for a in (0x620cb0, 0x620d50, 0x620c00):
        hook_rec(c, a, 4, ret=lambda emu, k: r.choice([0, 1, 1, 7, r.getrandbits(32)]), pop=0)
    out = 0 if r.random() < 0.3 else rnd(c, 8)
    return [s, r.choice([0x1000, 0x3000, r.getrandbits(32)]), r.choice([0x5000, 0x2000, r.getrandbits(32)]), out]


S(0x61f400, 'scan_driver_loop', 'cdecl', None, ret='eax', gen=g61f400)
