"""specs_s1050.py - area 81, batch 1050: 0x45b8c0 (thiscall: this; ret 4 from tail-jump). Loads a global double,
multiplies a float from eax+0x48 by a constant, calls 0x634db2 (pow-like with xmm0, xmm1 as args),
stores result as float at this+0x647c, and tail-jumps to 0x45c180. Both helpers are GUESS stubs."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def g(c):
    # Global object at 0x70039c, with float at offset 0x48
    obj_addr = 0x70039c
    float_offset = 0x48
    result_offset = 0x647c

    # Create a value to read from the global object at offset 0x48
    test_float_bits = struct.unpack('<I', struct.pack('<f', c.rng.uniform(0.5, 5.0)))[0]

    # Allocate and initialize global object
    global_obj = c.emu.alloc(float_offset + 4, 4)
    c.emu.w32(obj_addr, global_obj)
    # Zero out the object
    for i in range(0, float_offset, 4):
        c.emu.w32(global_obj + i, 0)
    # Write the test float at offset 0x48
    c.emu.w32(global_obj + float_offset, test_float_bits)

    # Patch 0x45c180 (tail target): simple return
    ss.patch(c, 0x45c180, ss.code(c, b'\xc3'))  # ret

    # Patch 0x634db2 (pow-like helper): takes xmm0, xmm1 (doubles), returns xmm0
    ss.patch(c, 0x634db2, ss.code(c, b'\xc3'))  # ret (result stays in xmm0)

    # Create the this object with space for result at offset 0x647c
    this_ = c.emu.alloc(result_offset + 4, 4)

    return [this_]


S(0x45b8c0, 'GUESS 0x45b8c0 pow scale and store', 'thiscall', None, ret=None, gen=g)
