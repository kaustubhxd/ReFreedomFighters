"""specs_s42000.py - Sonnet t3 batch 42000. 0x514c70: /GS float function. Hooked: 0x633654 (zero-arg recorder, ECX = cookie), 0x523330 (this + 1 arg, fills the
caller's local vec3 with random floats), 0x4e0d80 (this = &local + float arg bits, rewrites local), vtable slot 0x84; 0x441940 (fadd vec3) runs for real."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fl(r):
    return struct.unpack('<I', struct.pack('<f', r.uniform(-1000, 1000)))[0]


def g514c70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(emu, k):
        p = emu.arg32(0)
        for i in range(3):
            emu.w32(p + 4 * i, _fl(r))
    hook_rec(c, 0x523330, 1, this=True, nullflag=(0,), side=fill, ret=r.getrandbits(32))

    def scale(emu, k):
        p = emu.reg('ecx')
        for i in range(3):
            emu.w32(p + 4 * i, _fl(r))
    hook_rec(c, 0x4e0d80, 1, this='mark', side=scale)
    me = obj(c, 0x2c0, {0x84: pystub(c, 1, this=True)})
    c.emu.w32(me + 0x223, _fl(r))
    for i in range(3):
        c.emu.w32(me + 0x29b + 4 * i, r.getrandbits(32))
    return [me]


S(0x514c70, 'GUESS zero vec3, slot 0x84, local vec3 scaled and added (GS)', 'thiscall', None, ret=None, gen=g514c70, note='batch42000')
