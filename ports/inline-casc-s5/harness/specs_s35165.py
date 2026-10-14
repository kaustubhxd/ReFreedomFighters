"""specs_s35165.py - 0x4baf60 (thiscall, no args, ret=None). this: 0x80 random bytes, [+0x48] = null in 1/5, else a collection (reftab_vt iterator stubs, destructor slot 0 recorded) yielding 0..4 entries of 0x30 random bytes; dword +0x70 zero in half; 0x634273 hooked (cdecl, 2 args recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, reftab_vt


def _g4baf60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    elems = [rnd(c, 0x30) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    coll = rnd(c, 0x20)
    e.w32(coll, reftab_vt(c, elems))
    me = rnd(c, 0x80)
    e.w32(me + 0x48, 0 if r.random() < 0.2 else coll)
    e.w32(me + 0x70, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [me]


S(0x4baf60, 'GUESS release entry buffers then destroy owned collection', 'thiscall', None, ret=None, gen=_g4baf60, note='batch35165')
