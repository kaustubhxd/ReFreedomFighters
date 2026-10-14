"""specs_s35036.py - 0x4d7540 (thiscall, no args; unaligned fields). [+0xd] zero in 1/6; mode [+9] among 0, 1, 2, 4, random; buffers [+0x4e], [+0x5a] null in a third; owner [+0x15] is always a heap object with
slot 4 (1 arg) (the exe's static default 0x6e7b98 is never the owner here, so the reset to it is what is compared); [+0x6a] null in a third (object with slot 0); 0x4d7740 / 0x4d7ba0 thiscall recorders;
0x41e2c0 and 0x634273 cdecl recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d7540(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4d7740, 0, this=True)
    hook_rec(c, 0x4d7ba0, 0, this=True)
    hook_rec(c, 0x41e2c0, 1, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x80)

    def w32(off, v):
        e.wbytes(me + off, (v & 0xffffffff).to_bytes(4, 'little'))
    w32(0xd, 0 if r.random() < 1 / 6 else r.getrandbits(32) | 1)
    w32(9, r.choice([0, 1, 2, 4, 1, 4, r.getrandbits(32)]))
    for off in (0x4e, 0x5a):
        w32(off, 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1)
    owner = obj(c, 0x20, {4: pystub(c, 1, this=True)}, nslots=4)
    w32(0x15, owner)
    w32(0x6a, 0 if r.random() < 1 / 3 else obj(c, 0x20, {0: pystub(c, 1, this=True)}, nslots=2))
    return [me]


S(0x4d7540, 'GUESS tear down loaded resource', 'thiscall', None, ret=None, gen=_g4d7540, note='batch35036')
