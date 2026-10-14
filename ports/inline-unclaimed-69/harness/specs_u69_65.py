"""specs_u69_65.py - area 69, group 65 (slice 8): 0x549780 (SSE modelled as spec input: the float at +0x63d7 is the input, and the log10 thunk
0x634dd6 is the harness's own _libm_sse2_log10_precise stub, which takes and returns the double in xmm0). The argument on the stack is not read."""
import struct
from pilot import S
from ckit import rnd


def _lg(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x6400)
    A = struct.unpack('<f', struct.pack('<I', e.r32(0x67d9fc)))[0]
    B = struct.unpack('<f', struct.pack('<I', e.r32(0x67cd40)))[0]
    x = r.choice([0.0, -0.0, 1.0, 50.0, 150.0, -3.0, A, B, A + 1.0, B + 0.5, 1e-20, r.uniform(-200.0, 200.0)])
    e.wbytes(o + 0x63d7, struct.pack('<f', x))
    return [o, r.getrandbits(32)]


S(0x549780, 'logClamp549780 (thiscall, one unused arg, ret 4, returns int)', 'thiscall', None, ret='eax', gen=_lg,
  note='u69 group 65; SSE double modelled through the harness log10 import stub (0x634dd6 = _libm_sse2_log10_precise)')
