"""specs_s42012.py - Sonnet t3 batch 42012. 0x445ca0: /GS float function, 4 stack args (obj, a, b, c). Hooked: 0x633654 (ECX = cookie), obj slots 0xc0 (3 args, vec3 at arg 2 recorded) and 0xbc (4 args);
the CRT function at 0x634dac runs for real. Bit 0 of [this+0x14] is clear in a fifth of the cases."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([r.uniform(-10, 10), r.uniform(-1e3, 1e3), r.uniform(-1, 1), 0.0, 1.0, -1.0])


def g445ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    o = obj(c, 0x40, {0xc0: pystub(c, 3, this=True, deref={2: 3}), 0xbc: pystub(c, 4, this=True)})
    me = rnd(c, 0x80)
    e.w32(me + 0x14, r.choice([0, 1, 9, 8, 0xff, r.getrandbits(32)]))
    for off in (0x5c, 0x40):
        e.wbytes(me + off, struct.pack('<f', _fv(r)))
    return [me, o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x445ca0, 'GUESS build vec3 from float field and notify object slots 0xc0/0xbc (GS)', 'thiscall', None, ret=None, gen=g445ca0, note='batch42012')
