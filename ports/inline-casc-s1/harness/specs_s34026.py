"""specs_s34026.py - cascade tier E, batch 34026.
0x57e2e0: hooked 0x562e90; the engine object at +0x1907 is null in a third of the cases; members at +0x314, +0x310, +0x50 have slot 0xbc recorders; this slot 0x84 returns an object
whose slot 0x350 records (0x100000, 0, [this+0x44]); the return is al (false).
0x5cdab0: all ten helpers are recorders (this recorded); byte +0xb45 and dword +0xad5 (5 or other) pick the two modes, +0xb46 / +0xa4c / +0xaf9 / +0xafd start random.
0x5d4250: hooked 0x4e5e60 returns a, b, c (zero in a quarter each) recording the stream; engine table slot 0x58 returns random values."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g57e2e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562e90, 2, this=True)
    w = 0 if r.random() < 0.33 else obj(c, 0x20, {0x14: pystub(c, 1, this=True)}, nslots=0x20)
    so = sysobj(c)
    c.emu.wbytes(so + 0x1907, w.to_bytes(4, 'little'))
    mem = lambda: obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0x50)
    o = obj(c, 0x20, {0x350: pystub(c, 3, this=True)}, nslots=0x360 // 4)
    me = obj(c, 0x340, {0x84: pystub(c, 0, ret=o, this=True)}, nslots=0x50)
    for off in (0x314, 0x310, 0x50):
        c.emu.w32(me + off, mem())
    return [me, r.getrandbits(32), r.getrandbits(32)]


HELPERS = [0x5d0c90, 0x5d0f10, 0x5d2eb0, 0x5d2ab0, 0x5d1530, 0x5d2280, 0x5cd890, 0x5d2080, 0x5cdc60, 0x5ce0b0]


def _g5cdab0(c):
    clear_hooks(c)
    r = c.rng
    for a in HELPERS:
        hook_rec(c, a, 0, this=True, pop=0, side=(lambda a_: lambda em, k: em.calllog.append(('call', hex(a_))))(a))   # logs the order of calls across helpers
    me = rnd(c, 0xb60)
    c.emu.wbytes(me + 0xb45, bytes([r.choice([0, 0, 1, r.getrandbits(8)])]))
    c.emu.wbytes(me + 0xad5, (5 if r.random() < 0.4 else r.getrandbits(32)).to_bytes(4, 'little'))
    return [me]


def _g5d4250(c):
    clear_hooks(c)
    r = c.rng
    vals = [0 if r.random() < 0.25 else (r.getrandbits(32) | 1) for _ in range(3)]
    hook_rec(c, 0x4e5e60, 0, ret=lambda em, k: vals[min(k, 2)], this=True, pop=0)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    return [rnd(c, 0x80), rnd(c, 0x20)]


S(0x57e2e0, 'GUESS reset view and release focus', 'thiscall', None, ret='al', gen=_g57e2e0, note='batch34026')
S(0x5cdab0, 'GUESS re-initialise screen in one of two modes', 'thiscall', None, ret=None, gen=_g5cdab0, note='batch34026')
S(0x5d4250, 'GUESS read three ids, resolve two', 'thiscall', None, ret=None, gen=_g5d4250, note='batch34026')
