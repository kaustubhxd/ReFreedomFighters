"""specs_s72002.py - Haiku t3 batch 72002. 0x5db4f0: Boolean function, clears flag bit, calls vtable methods."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
from pe_emu import F


def g5db4f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Create self object
    me = rnd(c, 0x100)

    # Setup [self + 4] with bit 0x40 that will be cleared
    e.wbytes(me + 4, struct.pack('<I', r.getrandbits(32) | 0x40))

    # Setup [self + 0x48] - pushed on stack in original
    e.wbytes(me + 0x48, struct.pack('<I', r.getrandbits(32)))

    # Setup [self + 0x4c] - float value
    e.wf32(me + 0x4c, r.uniform(-100, 100))

    # Setup [self + 0x50] - another float value
    e.wf32(me + 0x50, r.uniform(-100, 100))

    # Setup [self + 0x84] - pointer to another object
    obj2 = rnd(c, 0x80)
    e.wbytes(me + 0x84, struct.pack('<I', obj2))

    # Create argument object (edi in original)
    arg = rnd(c, 0x80)

    # Setup vtable for arg
    vt_arg = rnd(c, 0x100)
    e.wbytes(arg, struct.pack('<I', vt_arg))

    # Hook the vtable methods
    hook_rec(c, vt_arg + 0x64, 1, this=True, pop=0)
    hook_rec(c, vt_arg + 0x4c, 2, this=True, pop=0)  # Takes xmm0 float on stack
    hook_rec(c, vt_arg + 0x3c, 1, this=True, pop=0)
    hook_rec(c, vt_arg + 0x14, 1, this=True, pop=0)

    # Setup [obj2]'s vtable
    vt_obj2 = rnd(c, 0x100)
    e.wbytes(obj2, struct.pack('<I', vt_obj2))
    hook_rec(c, vt_obj2 + 0x4c, 2, this=True, pop=0)
    hook_rec(c, vt_obj2 + 0x5c, 2, this=True, pop=0)

    return [me, arg]


S(0x5db4f0, 'GUESS clear flag bit and call vtable methods', 'thiscall', None, ret='al', gen=g5db4f0, note='batch72002')
