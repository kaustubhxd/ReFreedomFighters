"""specs_s42010.py - Sonnet t3 batch 42010. 0x5621a0: /GS float function with a float stack argument (F()). Hooked: 0x633654 (ECX = cookie), this slot 0xd4 (1 arg, records the int from the CRT
helper 0x633910, which runs for real), optional helper object [this+0x54] slot 0x70 (1 arg: three floats recorded)."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([r.uniform(-5, 5), r.uniform(-1e3, 1e3), r.uniform(-0.5, 0.5), 0.0, 1.0, -1.0, r.uniform(-1e5, 1e5)])


def g5621a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    helper = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3})}) if r.random() < 0.8 else 0
    me = obj(c, 0x90, {0xd4: pystub(c, 1, this=True)})
    e.w32(me + 0x54, helper)
    for off in (0x6c, 0x78, 0x7c, 0x80):
        e.wbytes(me + off, struct.pack('<f', _fv(r)))
    return [me, F(_fv(r))]


S(0x5621a0, 'GUESS scale a value, notify slot 0xd4 and pass a vec3 to the helper (GS)', 'thiscall', None, ret=None, gen=g5621a0, note='batch42010')
