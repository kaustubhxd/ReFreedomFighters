"""specs_s780.py - unclaimed-77 claim 10 (docs/20-unclaimed-77.md): ZMoveOnSplineIf::FindSplineVal. Thiscall, one argument (arg),
ret 4. The helper 0x5003d0 is stubbed (GUESS): a table stub returning four block pointers in call order (p1, p2, p3, p4). The
blocks are set so the excluded assert paths never run: p1's dword is nonzero, p4's byte at +4 is 0 or 2. The virtual slot 0x2fc of
this+0x14 is a stub (GUESS) that logs its two arguments and returns a random float in st0."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _float_stub(c, const_bits):
    """Thiscall virtual stub with two stack arguments: logs ecx and the two arguments (ring of 8 entries, 8 dwords), then loads a
    float constant onto st0 and returns with ret 8."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(256, 4)
    c.emu.wbytes(ring, bytes(256))
    const = c.emu.alloc(4, 4)
    c.emu.wbytes(const, struct.pack('<I', const_bits))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + ss.P(ring)
         + b'\x89\x08'
         + b'\x8b\x54\x24\x04\x89\x50\x04'
         + b'\x8b\x54\x24\x08\x89\x50\x08'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xd9\x05' + ss.P(const)            # fld dword ptr [const]
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x1000)
    arg = _rnd(c, 0x20)
    p1 = _rnd(c, 0x40)
    c.emu.w32(p1, c.rng.randint(1, 0xffffffff))             # nonzero dword: the zero case is excluded
    p2 = _rnd(c, 0x40)
    p3 = _rnd(c, 0x40)
    p4 = _rnd(c, 0x40)
    c.emu.wbytes(p4 + 4, bytes([c.rng.choice([0, 2])]))      # byte is 0 or 2: the other values are excluded
    rets = [p1, p2, p3, p4]
    ss.patch(c, 0x5003d0, ss.seqr(c, 1, rets))                # GUESS-stub of the indexed accessor
    import struct as _s
    fbits = _s.unpack('<I', _s.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]
    obj = ss.mkobj(c, {0x2fc: _float_stub(c, fbits)})
    c.emu.w32(self + 0x14, obj)
    return [self, arg]


S(0x5194c0, 'ZMoveOnSplineIf::FindSplineVal (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 10; helper 0x5003d0 stubbed (GUESS), slot 0x2fc float stub; assert paths excluded')
