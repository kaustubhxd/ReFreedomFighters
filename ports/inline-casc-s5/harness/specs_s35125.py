"""specs_s35125.py - 0x5797e0 (thiscall(k) ret 4, ret='al'). this: vtable slots 0xd8 (AL true in a third, garbage upper bytes) and 0xd0 (1 arg); [+0x44] object with slot 0x12c (2 args); engine table slot 0x114 (five args: the pointer to this+0x194 is a heap address) returning a dword with garbage upper bytes;
0x562c20 hooked (thiscall, 1 arg, random result), 0x579880 hooked (thiscall, 1 arg); k = 1 in half the cases."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g5797e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562c20, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x579880, 1, this=True)
    t = (r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]) if r.random() < 1 / 3 else 0)
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, ret=r.getrandbits(32))}, table_size=0x120)
    me = obj(c, 0x1a0, {0xd8: pystub(c, 0, this=True, ret=t), 0xd0: pystub(c, 1, this=True)}, nslots=0x3a)
    e.w32(me + 0x44, obj(c, 0x20, {0x12c: pystub(c, 2, this=True)}, nslots=0x4c))
    return [me, 1 if r.random() < 0.5 else r.choice([0, 2, 3, r.getrandbits(32)])]


S(0x5797e0, 'GUESS handle mode k by resource word or helper', 'thiscall', None, ret='al', gen=_g5797e0, note='batch35125')
