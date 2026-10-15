"""specs_s78001.py - batch 78001: 0x521bd0 (entity state update with SSE calculations)."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def _g521bd0(c):
    r = c.rng
    em = c.emu
    clear_hooks(c)

    # Create main object (thiscall this)
    main_obj = rnd(c, 0x3000)

    # Setup vtable with stubs for slots 2, 1, 3
    vtable = rnd(c, 0x100)
    em.w32(vtable + 8, pystub(c, 1, this=True))  # slot 2
    em.w32(vtable + 4, pystub(c, 3, this=True))  # slot 1
    em.w32(vtable + 0xc, pystub(c, 1, this=True, ret=lambda e,k: 0 if r.random() < 0.5 else 1))  # slot 3
    em.w32(main_obj + 0x2695, vtable)

    # Setup condition flag
    em.w32(main_obj + 0x216, r.choice([0, 1]))

    # Setup base object pointer at [this+0x5c]
    base_obj = rnd(c, 0x200)
    em.w32(main_obj + 0x5c, base_obj)

    # Setup float values
    f_val = r.uniform(0.1, 1000.0)
    bits = struct.unpack('<I', struct.pack('<f', f_val))[0]
    em.w32(base_obj + 0x24, bits)

    # Setup thresholds at fixed addresses
    em.w32(0x680a70, struct.unpack('<I', struct.pack('<f', r.uniform(0.0, 10.0)))[0])
    em.w32(0x680a84, struct.unpack('<I', struct.pack('<f', r.uniform(0.0, 10.0)))[0])
    em.w32(0x697880, struct.unpack('<I', struct.pack('<f', r.uniform(0.0, 100.0)))[0])

    # Setup vector fields
    for off in [0x2e4, 0x2e8, 0x2ec]:
        f = r.uniform(-100.0, 100.0)
        em.w32(main_obj + off, struct.unpack('<I', struct.pack('<f', f))[0])

    # Setup target area
    for off in range(0, 12, 4):
        f = r.uniform(-10.0, 10.0)
        em.w32(main_obj + 0x2d8 + off, struct.unpack('<I', struct.pack('<f', f))[0])

    # Hook external callees with proper argument counts
    hook_rec(c, 0x43e920, 3)  # 3 args: ptr1, ptr2, ptr3
    hook_rec(c, 0x4e0d00, 2)  # 2 args
    hook_rec(c, 0x521600, 1)  # 1 arg
    hook_rec(c, 0x44c840, 1)  # 1 arg

    return [main_obj]

S(0x521bd0, 'GUESS entity state update with SSE', 'thiscall', None, ret=None, gen=_g521bd0)
