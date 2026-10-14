"""specs_s35135.py - 0x44bb70 (thiscall, no args). this: vtable slots 0x210 (1 arg) and 0x20 (0 args, returns an id); [this+0x18] = c (null in 1/4: the slot 0x210 path) a random 0x90-byte block; engine (sysobj) dword +0x1c random; engine table (the tab object's own vtable at its start has slots 0x4c (1 arg: id, ECX = tab) and 0x64 (1 arg: c)); 0x44c2b0 hooked (thiscall)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g44bb70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x44c2b0, 0, this=True)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0x64: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    me = obj(c, 0x40, {0x210: pystub(c, 1, this=True), 0x20: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0x85)
    e.w32(me + 0x18, 0 if r.random() < 0.25 else rnd(c, 0x90))
    return [me]


S(0x44bb70, 'GUESS bind node to data record and engine default', 'thiscall', None, ret=None, gen=_g44bb70, note='batch35135')
