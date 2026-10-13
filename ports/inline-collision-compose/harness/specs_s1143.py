"""specs_s1143.py - collision thread batch 1143 (GUESS name): 0x45edf0. Two logged fakes on this: slots 0xa4 and 0xa8 (four stack
words each; the pointers are heap addresses, the float is logged as its bits). The arrays A and B hold six dwords (equal in
40% of the cases, sometimes differing in the last one), C and D hold three dwords (equal in half of the equal-array cases)."""
import struct
from pilot import S, F


def _t(c):
    e, r = c.emu, c.rng
    lvt = e.logging_vtable('this_45edf0', 0xb0, impl={0xa4: (lambda em, a: (None, None)), 0xa8: (lambda em, a: (None, None))},
                           argwords={0xa4: 4, 0xa8: 4})
    self_ = e.alloc(0x40, 4)
    e.w32(self_, lvt)
    A = e.alloc(24, 4)
    B = e.alloc(24, 4)
    vals = [r.getrandbits(32) for _ in range(6)]
    for k in range(6):
        e.w32(A + 4 * k, vals[k])
        e.w32(B + 4 * k, vals[k])
    if r.random() < 0.6:
        e.w32(B + 4 * r.randrange(0, 6), r.getrandbits(32))     # a differing dword (some cases stay equal by chance)
    C = e.alloc(12, 4)
    D = e.alloc(12, 4)
    cv = [r.getrandbits(32) for _ in range(3)]
    for k in range(3):
        e.w32(C + 4 * k, cv[k])
        e.w32(D + 4 * k, cv[k])
    if r.random() < 0.5:
        e.w32(D + 4 * r.randrange(0, 3), r.getrandbits(32))
    f = r.uniform(-50, 50)
    return [self_, r.getrandbits(32), r.getrandbits(32), A, B, C, D, _f2w(f)]


def _f2w(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


S(0x45edf0, 'equal arrays return 0; else two virtual calls with the float (name GUESS)', 'thiscall', None, ret='al',
  gen=_t, note='batch1143')
