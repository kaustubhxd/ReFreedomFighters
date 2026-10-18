"""specs_s213009.py - batch 213009: float-driven state machine (x87 callee result, SSE compare), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

T = struct.unpack('<d', struct.pack('<Q', 0x3f91df46a0000000))[0]

TU = struct.unpack('<d', struct.pack('<Q', 0x3f91df46c0000000))[0]
TD = struct.unpack('<d', struct.pack('<Q', 0x3f91df4680000000))[0]


def g524270(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x50)
    st = r.choice([0, 1, 2, 3, 4, 2, 3, 5, r.getrandbits(32)])
    c.emu.wbytes(o + 0x35, struct.pack('<I', st))
    v = r.choice([T, -T, TU, TD, -TU, -TD, TU, TD, 0.0, -0.0, 1.0, -1.0, 0.0175, 0.017, 0.0176, T * 1.0000001, T * 0.9999999,
                  r.uniform(-0.05, 0.05), r.uniform(-100, 100), float('nan'), float('inf'), -float('inf')])
    hook_rec(c, 0x523f50, 0, ret=r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)]), this=True)
    hook_rec(c, 0x522f60, 2, pop=8, st0=v)
    return [o]


S(0x524270, 'state_machine_float', 'thiscall', None, ret=None, gen=g524270)
