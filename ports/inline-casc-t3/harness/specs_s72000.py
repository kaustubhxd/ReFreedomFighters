"""specs_s72000.py - Haiku t3 batch 72000. 0x4c95a0: /GS function with vtable calls and float state."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
from pe_emu import F


def g4c95a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Create self object
    me = rnd(c, 0x100)

    # Setup engine object at [0x70039c]
    engine = rnd(c, 0x200)
    e.wf32(engine + 0x48, r.uniform(100, 1000))
    e.wf32(0x67885c, r.uniform(0.1, 10.0))
    e.wbytes(engine + 0x40, struct.pack('<I', r.getrandbits(32)))
    hook_rec(c, 0x70039c, 0, ret=engine, this=False, pop=0)

    # Setup fields on self
    e.wbytes(me + 0x58, bytes([r.choice([0, 1])]))  # Flag 1
    e.wbytes(me + 0x59, bytes([r.choice([0, 1])]))  # Flag 2
    e.wbytes(me + 0x5b, struct.pack('<I', r.getrandbits(32)))  # Counter
    e.wbytes(me + 0x4c, struct.pack('<I', r.getrandbits(32)))  # Data field

    # Setup [self + 0x44] -> sub-object
    obj2 = rnd(c, 0x80)
    sub_obj = rnd(c, 0x80)
    e.wbytes(me + 0x44, struct.pack('<I', obj2))
    e.wbytes(obj2 + 8, struct.pack('<I', sub_obj))

    # Hook the function calls
    hook_rec(c, 0x4e0d40, 3, this=True, pop=0)
    hook_rec(c, 0x4db2a0, 2, this=True, pop=0)
    hook_rec(c, 0x4de7e0, 2, this=True, pop=0)

    # Setup vtable for self
    vt = rnd(c, 0x100)
    e.wbytes(me, struct.pack('<I', vt))
    hook_rec(c, vt + 0x68, 2, ret=None, pop=8, this=True)  # 2 pushes: 0 and 0x10
    hook_rec(c, vt + 0x84, 1, ret=None, pop=4, this=True)

    # Setup vtable for obj2
    vt2 = rnd(c, 0x100)
    e.wbytes(obj2, struct.pack('<I', vt2))
    hook_rec(c, vt2 + 0x6c, 1, ret=None, pop=4, this=True)

    return [me]


S(0x4c95a0, 'GUESS engine state with vtable calls', 'thiscall', None, ret=None, gen=g4c95a0, note='batch72000')
