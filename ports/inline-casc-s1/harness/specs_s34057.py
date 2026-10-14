"""specs_s34057.py - cascade tier E, batch 34057.
0x4800a0: the real 0x610100 stub runs; hooked 0x4e1600 (returns 3 in half the cases, else another byte), 0x4e12e0 and 0x4e12f0 (two args, ECX and args recorded), 0x4e1620 (one arg), 0x4e1b30 (returns random; EAX compared).
0x484c50: the unaligned counter at +0x60a is 0 in half the cases; this slots 0x418, 0x384 (two args), 0x428 (returns x), 0x368 and engine table slot 0x58 (object or 0, slot 0x94 two args) are recorders; hooked 0x4673d0.
0x492a90: the engine's +0x1a9f object exists in two thirds; the global at 0x70038c has slot 0x48 (1 arg, returns a handle); this slots 0x1f8 (returns n: -2..40) and 0x1fc (two args); the engine object's slot 0x90 (two args);
hooked 0x41e290 (cdecl) returns a fresh block."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4800a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e1600, 0, ret=r.choice([3, 3, 3, 0, 1, 0xff, r.getrandbits(8)]) | (r.getrandbits(24) << 8), this=True, pop=0)
    hook_rec(c, 0x4e12e0, 2, this=True)
    hook_rec(c, 0x4e12f0, 2, this=True)
    hook_rec(c, 0x4e1620, 1, this=True)
    hook_rec(c, 0x4e1b30, 0, ret=r.getrandbits(32), this=True, pop=0)
    return [rnd(c, 0x40), rnd(c, 0x20)]


def _g484c50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4673d0, 0, this=True, pop=0)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x94: pystub(c, 2, this=True)}, nslots=0x98 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)})
    me = obj(c, 0x620, {0x418: pystub(c, 0, this=True), 0x384: pystub(c, 2, this=True), 0x428: pystub(c, 0, ret=r.getrandbits(32), this=True),
                        0x368: pystub(c, 0, this=True)}, nslots=0x430 // 4)
    c.emu.wbytes(me + 0x60a, (0 if r.random() < 0.5 else r.choice([1, 2, 0xffffffff, r.getrandbits(32)])).to_bytes(4, 'little'))
    return [me]


def _g492a90(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x40), pop=0)
    g = obj(c, 0x20, {0x48: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=0x50 // 4)
    c.emu.w32(0x70038c, g)
    so = sysobj(c)
    w = 0 if r.random() < 1 / 3 else obj(c, 0x20, {0x90: pystub(c, 2, this=True)}, nslots=0x94 // 4)
    c.emu.wbytes(so + 0x1a9f, w.to_bytes(4, 'little'))
    n = r.choice([-2, 0, 1, 8, 40, r.randint(-2, 40)]) & 0xffffffff
    me = obj(c, 0x20, {0x1f8: pystub(c, 0, ret=n, this=True), 0x1fc: pystub(c, 2, this=True)}, nslots=0x200 // 4)
    return [me]


S(0x4800a0, 'GUESS read a record layout from a stream', 'thiscall', None, ret='eax', gen=_g4800a0, note='batch34057')
S(0x484c50, 'GUESS first-time setup guarded by a counter then a tail slot', 'thiscall', None, ret=None, gen=_g484c50, note='batch34057')
S(0x492a90, 'GUESS copy a service blob inside a logger scope', 'thiscall', None, ret=None, gen=_g492a90, note='batch34057')
