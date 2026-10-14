"""specs_s3019.py - unclaimed-30 batch 19 (docs/20-unclaimed-30.md, claim 1): 0x5cfd90 (no name in the name map). The helper 0x5cf5d0 is
patched to a stub (not part of the claim) that returns the record vector's x in ST0, so the candidate test is driven by the records.
The squared-distance helper 0x4e0830 is exe code. The records and the reference vector are random; the output is a 3-float buffer
(memory compare). No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import sf


def _near(c):
    e = c.emu
    r = c.rng
    # 0x5cf5d0 -> mov eax,[esp+4]; fld dword [eax]; ret 4   (returns the vector's x)
    ss.patch(c, 0x5cf5d0, ss.code(c, b'\x8b\x44\x24\x04\xd9\x00\xc2\x04\x00'))
    count = r.randint(0, 4)
    self_ = e.alloc(0xd00)
    e.wbytes(self_, bytes(0xd00))
    e.w32(self_ + 0x48, count)
    for k in range(count):
        rec = self_ + 0x4c + 20 * k
        e.w32(rec, r.getrandbits(32))
        for j in range(3):
            # spread the squared distances across the window 0 .. 2e7 so the candidates are common
            e.wf32(rec + 4 + 4 * j, sf(r.uniform(-1200, 1200) if r.random() < 0.5 else r.uniform(-60, 60)))
        e.w32(rec + 16, r.getrandbits(32))
        if r.random() < 0.3:
            # the helper's x near its threshold (0.2618), so the g test decides
            e.wf32(rec + 4, sf(r.uniform(0.2, 0.35)))
        if k and r.random() < 0.3:
            # an exact copy of the previous record's vector: equal distances, the first one stays
            for j in range(3):
                e.wf32(rec + 4 + 4 * j, sf(struct.unpack('<f', e.rbytes(rec - 20 + 4 + 4 * j, 4))[0]))
    for j in range(3):
        e.wf32(self_ + 0xc71 + 4 * j, sf(r.uniform(-60, 60)))
    if r.random() < 0.4:
        # integer mode: reference at the origin, mirrored records (y negated, x <= 0 so both pass the g test) have exactly equal squared distances, so ties occur
        for j in range(3):
            e.wf32(self_ + 0xc71 + 4 * j, 0.0)
        for k in range(count):
            rec = self_ + 0x4c + 20 * k
            if k % 2 == 1:
                prev = self_ + 0x4c + 20 * (k - 1)
                x = struct.unpack('<f', e.rbytes(prev + 4, 4))[0]
                y = -struct.unpack('<f', e.rbytes(prev + 8, 4))[0]
                z = struct.unpack('<f', e.rbytes(prev + 0xc, 4))[0]
            else:
                x, y, z = float(-r.randint(0, 1000)), float(r.randint(-1000, 1000)), float(r.randint(-1000, 1000))
            e.wf32(rec + 4, x)
            e.wf32(rec + 8, y)
            e.wf32(rec + 0xc, z)
    out = e.alloc(16)
    e.wbytes(out, bytes(16))
    return [self_, out]


S(0x5cfd90, 'unnamed 0x5cfd90', 'thiscall', None, ret='al', gen=_near, n=300)
