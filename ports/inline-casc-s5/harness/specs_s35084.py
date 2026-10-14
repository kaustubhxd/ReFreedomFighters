"""specs_s35084.py - 0x63fce0 (thiscall(obj) ret 4, ret='al'). Registry: this = 0x400 random bytes with count [+0xec] 0..6 (up to 6 entries at +0xf0, obj among them in 2/3 of the cases at any position), vtable slots
0x64 and 0x60 (0 args); obj: object (0x10100 bytes, vtable slot 0x10) with the index dword at +0x10055 (unaligned, 0..8); 0x64b070, 0x648280 (thiscall) and 0x634273 (cdecl, 2 args) hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g63fce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x64b070, 0, this=True)
    hook_rec(c, 0x648280, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    o = obj(c, 0x10100, {0x10: pystub(c, 0, this=True)}, nslots=5)
    e.wbytes(o + 0x10055, r.randint(0, 8).to_bytes(4, 'little'))
    me = obj(c, 0x400, {0x64: pystub(c, 0, this=True), 0x60: pystub(c, 0, this=True)}, nslots=0x1a)
    n = r.randint(0, 6)
    e.w32(me + 0xec, n)
    for i in range(n):
        e.w32(me + 0xf0 + 4 * i, rnd(c, 0x10))
    if n and r.random() < 2 / 3:
        e.w32(me + 0xf0 + 4 * r.randrange(n), o)
    return [me, o]


S(0x63fce0, 'GUESS remove object from registry and destroy', 'thiscall', None, ret='al', gen=_g63fce0, note='batch35084')
