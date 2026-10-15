"""specs_s42019.py - Sonnet t3 batch 42019. 0x4bf3e0: 0x634d2e hooked (5 args, returns a source block, or this itself in a fifth), 0x4c3070 hooked (this), engine +0x1a9f set in two thirds."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4bf3e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1b0)
    src = me if r.random() < 0.2 else rnd(c, 0x1b0)
    hook_rec(c, 0x634d2e, 5, ret=src, pop=0)
    hook_rec(c, 0x4c3070, 0, this=True, pop=0)
    so = sysobj(c)
    e.wbytes(so + 0x1a9f, struct.pack('<I', r.choice([0, 1, 1, r.getrandbits(32)])))
    return [me, r.getrandbits(32)]


S(0x4bf3e0, 'GUESS copy state from a dynamic-cast source object', 'thiscall', None, ret=None, gen=g4bf3e0, note='batch42019')
