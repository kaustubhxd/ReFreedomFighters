"""specs_s42013.py - Sonnet t3 batch 42013. 0x5df440: writer object with vtable slots 0x3c (1 arg, returns the writer itself), 0x4c (1 float arg recorded as bits), 0x68 (1 pointer, 3 dwords recorded);
0x5deaf0 hooked (this + 1 arg); 0x44e630 and 0x5df4d0 (math, CRT imports) run for real. This object holds float vectors at +0x1c and +0x28 (zero components in about a fifth of the cases)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([r.uniform(-10, 10), r.uniform(-1, 1), r.uniform(-1e3, 1e3), 0.0, 0.0, 1.0, -1.0])


def g5df440(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5deaf0, 1, this=True)
    w = rnd(c, 0x40)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x3c, pystub(c, 1, this=True, ret=w))
    e.w32(vt + 0x4c, pystub(c, 1, this=True))
    e.w32(vt + 0x68, pystub(c, 1, this=True, deref={0: 3}))
    e.w32(w, vt)
    me = rnd(c, 0x60)
    for off in (0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30):
        e.wbytes(me + off, struct.pack('<f', _fv(r)))
    return [me, w]


S(0x5df440, 'GUESS serialise two ids, a vec3, a normalised direction and angles', 'thiscall', None, ret=None, gen=g5df440, note='batch42013')
