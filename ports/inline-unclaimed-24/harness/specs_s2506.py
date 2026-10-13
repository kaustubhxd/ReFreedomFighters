"""specs_s2506.py - decomp area 24, batch 2506.
0x601d30 (GUESS RunTimeTypeLibrary lookup + dispatch): stdcall(a, b, c), ret 0xc. 0x602d30 (cdecl, no argument) hooked: returns a
library pointer; 0x602ff0 (thiscall, one argument, pops 4) hooked: returns an entry (whose +0x1c holds an object with a vtable
whose slot 0 is a recorder, thiscall, 2 args, pops 8) or null. Result is the slot's return or 0."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lib = rnd(c, 0x40)
    hook_rec(c, 0x602d30, 0, ret=lib)
    slot = pystub(c, 2, this=True, ret=r.getrandbits(32))
    vt = e.alloc(0x20, 4)
    e.w32(vt, slot)
    o = rnd(c, 0x40)
    e.w32(o, vt)
    ent = rnd(c, 0x40)
    e.w32(ent + 0x1c, o)
    hook_rec(c, 0x602ff0, 1, ret=r.choice([0, ent, ent]), this=True, pop=4)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x601d30, 'GUESS RTTI library lookup + dispatch', 'stdcall', None, ret='eax', gen=_gen, note='batch2506')
