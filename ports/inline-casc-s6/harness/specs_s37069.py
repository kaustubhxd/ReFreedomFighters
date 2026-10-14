"""specs_s37069.py - cascade s6 batch 37069 (0x5e4790, thiscall binder). The object's vtable has recording stubs at slots 0x54 (1 arg) and 0x58 (1 arg, returns a distinct handle per
call); the four embedded sub-objects (+0x10d, +0x13d, +0x155, +0x16d) each get their own vtable whose slot 8 is a recording stub (3 args: pointer, 0, float bits)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g5e4790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    handles = [r.getrandbits(32) for _ in range(8)]
    t = obj(c, 0x1c0, {0x54: pystub(c, 1, this=True), 0x58: pystub(c, 1, this=True, ret=lambda em, k: handles[k % 8])})
    for off in (0x10d, 0x13d, 0x155, 0x16d):
        vt = e.alloc(0x10, 4)
        e.w32(vt + 8, pystub(c, 3, this=True, nullflag=()))
        e.wbytes(t + off, vt.to_bytes(4, 'little'))
    return [t]


S(0x5e4790, 'GUESS bind_resources', 'thiscall', None, ret=None, gen=_g5e4790, note='batch37069')
