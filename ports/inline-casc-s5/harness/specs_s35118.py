"""specs_s35118.py - 0x4f0ce0 (thiscall(s) ret 4, ret='al'). 0x4f0d70 hooked (thiscall, 1 arg, AL true in 3/4 with garbage upper bytes); this: random 0xb0 bytes with the unaligned dword at +0x97 zero in a third; s: slots 0x44, 0x3c, 0x5c (1 arg, recorded); engine table slot 0x4c (1 arg recorded) returns a random value."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g4f0ce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4f0d70, 1, this=True, ret=((r.getrandbits(24) << 8) | 1) if r.random() < 0.75 else (r.getrandbits(24) << 8))
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    s = obj(c, 0x20, {0x44: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True), 0x5c: pystub(c, 1, this=True)}, nslots=0x18)
    me = rnd(c, 0xb0)
    if r.random() < 1 / 3:
        e.wbytes(me + 0x97, bytes(4))
    return [me, s]


S(0x4f0ce0, 'GUESS write unaligned fields to stream', 'thiscall', None, ret='al', gen=_g4f0ce0, note='batch35118')
