"""specs_u69_73.py - area 69, group 73 (slice 8): 0x5a5d00, ZOnScreenDisplay::CalcHealthColor (three float args, no callees). The float args are
wrapped with F() (single). The inputs cover negative, zero, between 0 and K1, above K1 and above K2, and large values (the truncation overflows to
0x80000000 the same way on both sides)."""
from pilot import S, F
from ckit import rnd
import struct


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


# boundary inputs found by a float32 search of the formula: the first channel truncates to 255, the second to 256
_EDGE = [(207.76144409179688, 89.3788833618164, 1.0005003213882446), (183.4898681640625, 11.228107452392578, 1.003509283065796),
         (44.07835388183594, 137.15472412109375, 1.002193808555603), (293.0543518066406, -37.573970794677734, 38.57859802246094),
         (-19.72842788696289, 290.8866882324219, 1.0042539834976196), (-6.690523147583008, 222.00706481933594, 1.0070724487304688)]


def _hc(c):
    r = c.rng
    if r.random() < 0.5:
        return [F(r.choice([0.0, 0.25, 0.375, 0.5, 0.75, 1.0, r.uniform(-0.2, 1.2)])), F(1.0), F(0.0)]
    if r.random() < 0.3:
        a, b, cc = _EDGE[r.randrange(len(_EDGE))]
        return [F(_f32(a)), F(_f32(b)), F(_f32(cc))]
    # a == K2 (0.5) or a == K1 (1.0) exercises the branch boundaries
    pick = lambda: r.choice([0.0, -0.0, -3.5, 0.25, 0.5, 1.0, 50.0, 99.0, 100.0, 120.0, 255.0, 1e4, -1e4,
                             r.uniform(-300.0, 300.0), r.uniform(-1.0, 1.0)])
    return [F(_f32(pick())), F(_f32(pick())), F(_f32(pick()))]


S(0x5a5d00, 'healthColor5a5d00 (stdcall, three float args)', 'stdcall', None, ret='eax', gen=_hc,
  note='u69 group 73; no callees; float constants at 0x678858, 0x67a6ac, 0x68af18, 0x68377c')
