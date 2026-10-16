"""specs_s213062.py - batch 213062: kind dispatcher with slot calls, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g593af0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.choice([0, 0, 1, 0x100, 0x5500, 0xff, r.getrandbits(32)])
    sl = lambda n, ret=None, pop=None: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, pop=pop)
    t = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=lambda emu, k: rb(), this=True)}, nslots=0x90)
    b = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=lambda emu, k: rb(), this=True), 0x20: sl(0, t)}, nslots=0x90)
    kind = r.choice([0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 0x10, 0xffffffff, r.getrandbits(32)])
    a = obj(c, 0x120, {0x94: sl(1)}, nslots=0x60)
    e.w32(a + 0x44, b)
    e.w32(a + 0x48, kind)
    base = rnd(c, 0x840)
    this = base + 8
    e.w32(this, e.r32(obj(c, 8, {0x4e4: sl(1), 0x4e8: sl(1), 0x130: sl(3)}, nslots=0x140)))
    e.w32(this - 4, r.choice([0, 0, 1, r.getrandbits(32)]))
    if kind > 3 and r.random() < 0.1:
        this = 0
    cbk = sl(0)
    E = obj(c, 0x20, {0x20: sl(1, lambda emu, k: r.choice([0, 0, 0, 1, r.getrandbits(32)])), 0xac: sl(1), 0xcc: sl(1)}, nslots=0x60)
    e.w32(E + 8, r.choice([cbk, cbk, 0]))
    if this:
        e.w32(E + 0xc, this - r.choice([0, 1, 100]) if r.random() < 0.8 else this + 1)
        e.w32(E + 0x10, this + r.choice([1, 100]) if r.random() < 0.8 else this)
    else:
        e.w32(E + 0xc, 0)
        e.w32(E + 0x10, 0xffffffff)
    e.w32(0x70038c, E)
    hook_rec(c, 0x41e680, 0, ret=r.getrandbits(32), this=True)
    return [this, a]


S(0x593af0, 'kind_dispatch_slots', 'thiscall', None, ret=None, gen=g593af0)
