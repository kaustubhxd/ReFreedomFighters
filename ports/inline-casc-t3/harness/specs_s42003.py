"""specs_s42003.py - batch 42003. 0x521ed0: /GS float function. Hooked: 0x633654 (ECX = cookie), vtable slot 0x84 (this + 1 arg, vec3 pointee recorded);
0x43e920 and 0x4e0030 run for real (vec3 subtract, x87 float result)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(r):
    return struct.unpack('<I', struct.pack('<f', r.choice([r.uniform(-10, 10), r.uniform(-1e4, 1e4), 0.0, 1.0, -1.0, r.uniform(-1, 1)])))[0]


def g521ed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    me = rnd(c, 0x2700)
    e.w32(me + 0x2610, r.choice([0, 1, 1, 1, r.getrandbits(32)]))
    sub = obj(c, 0x100, {0x84: pystub(c, 1, this=True, deref={0: 3})})
    e.wbytes(me + 0x25d1, sub.to_bytes(4, 'little'))
    for off in (0x25e5, 0x25e9, 0x25ed):
        e.wbytes(me + off, struct.pack('<I', _fb(r)))
    for off in (0x25fd, 0x2601, 0x2605, 0x78, 0x7c, 0x80):
        e.wbytes(me + off, struct.pack('<I', _fb(r)))
    return [me]


S(0x521ed0, 'GUESS vec3 offset clamp to float field (GS)', 'thiscall', None, ret=None, gen=g521ed0, note='batch42003')
