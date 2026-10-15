"""specs_s71000.py - t2 (Haiku) batch 71000: 0x5d6960. Callees (0x43e920, 0x634dbe) stubbed."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct
import math


def _g5d6960(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Stub 0x43e920: vector subtraction result
    def sub_vec_stub(emu, k):
        # Get the result pointer from ecx
        result_ptr = emu.reg('ecx')
        # Generate random floats for the subtraction result
        for i in range(3):
            f = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
            emu.wbytes(result_ptr + 4*i, struct.pack('<f', f))
        emu.calllog.append(('sub_vec',))
        return None

    hook_rec(c, 0x43e920, 1, pop=0, side=sub_vec_stub)

    # Stub 0x634dbe: takes double, returns via xmm0 (as double)
    def pow_stub(emu, k):
        # The input is in xmm0 as a double, we need to return a result
        # For now, just keep xmm0 as is (or return a slightly modified value)
        emu.calllog.append(('pow',))
        return None

    hook_rec(c, 0x634dbe, 0, ret=None, side=pow_stub)

    # Set the assert hook with proper return
    def assert_hook(emu, k):
        emu.calllog.append(('assert',))
        emu.ret(eax=r.choice([0, 1]))

    e.w32(0x7003b0, e.stub_fn('assert', assert_hook))

    # Generate random vectors and threshold
    v1 = rnd(c, 0xc)  # 3 floats
    v2 = rnd(c, 0xc)  # 3 floats
    v3 = rnd(c, 0xc)  # 3 floats
    thresh_f = r.choice([0.0, 0.5, 1.0, -1.0, r.uniform(-10, 10)])
    thresh_bits = struct.unpack('<I', struct.pack('<f', thresh_f))[0]

    # Fill vectors with random floats
    for i in range(3):
        f = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        e.wbytes(v1 + 4*i, struct.pack('<f', f))
        f = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        e.wbytes(v2 + 4*i, struct.pack('<f', f))
        f = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        e.wbytes(v3 + 4*i, struct.pack('<f', f))

    # Return arguments for thiscall: v1, v2, v3, thresh
    return [v1, v2, v3, thresh_bits]


S(0x5d6960, 'GUESS vector normalize and compare', 'fastcall', None, ret='al', gen=_g5d6960, note='batch71000')
