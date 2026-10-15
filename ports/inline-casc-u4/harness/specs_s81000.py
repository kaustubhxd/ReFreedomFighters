"""specs_s81000.py - u4 (Haiku) batch 81000: 0x4c9330 vector transform"""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _g4c9330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Object (self) with float fields and matrix data
    me = rnd(c, 0x500)

    # Fill object with float values at key offsets
    for off in [0x77, 0x7b, 0x7f]:
        f = r.uniform(-100, 100) if r.random() < 0.8 else r.choice([0.0, float('nan')])
        e.w32(me + off, _fb(f))

    # Matrix/interpolation data
    mat_obj = rnd(c, 0x100)
    mat_data = rnd(c, 0x100)
    e.w32(mat_obj + 8, mat_data)
    e.w32(me + 0x44, mat_obj)

    # Fill matrix with random values
    for i in range(0, 24, 4):
        val = r.getrandbits(32)
        e.w32(mat_data + i, val)

    # Pointer argument
    obj_ptr = rnd(c, 0x20)
    ptr_obj = rnd(c, 0x20)
    e.w32(obj_ptr, ptr_obj)
    byte_val = r.choice([0xff, 0x00, 0x03, 0x3f, 0x42])
    e.w32(ptr_obj, byte_val)

    # Hook external functions
    hook_rec(c, 0x4e5e80, 1, this=True)
    hook_rec(c, 0x4e5e60, 1, this=True)
    hook_rec(c, 0x4e0d00, 2, this=False, deref={0: 1})
    hook_rec(c, 0x4e0d80, 2, this=True, deref={0: 1})
    hook_rec(c, 0x4db2a0, 2, this=False, deref={1: 1})

    return [me, obj_ptr]


S(0x4c9330, 'fn4c9330', 'thiscall', None, ret=None, gen=_g4c9330)
