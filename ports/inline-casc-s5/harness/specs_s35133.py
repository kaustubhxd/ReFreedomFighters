"""specs_s35133.py - 0x473f20 (thiscall(out) ret 4, ret='al'). this: random 0x400 bytes with the real 0x4666d0 / 0x4673c0 helpers reading the unaligned dword at +0x2a3 (zero in 1/4) and the dword at +0x28f (0x7fffffff in 1/3, which makes the second helper return null);
engine table slot 0x58 (1 arg recorded) returns an object or 0 (half); this vtable slot 0x84 (1 arg: the out block pointer); out: 12 random heap bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g473f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = 0 if r.random() < 0.5 else rnd(c, 0x10)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o)})
    me = obj(c, 0x400, {0x84: pystub(c, 1, this=True)}, nslots=0x22)
    e.wbytes(me + 0x2a3, (0 if r.random() < 0.25 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    if r.random() < 1 / 3:
        e.w32(me + 0x28f, 0x7fffffff)
    return [me, rnd(c, 0x10)]


S(0x473f20, 'GUESS fetch current 3-dword value', 'thiscall', None, ret='al', gen=_g473f20, note='batch35133')
