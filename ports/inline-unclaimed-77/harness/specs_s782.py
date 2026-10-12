"""specs_s782.py - unclaimed-77 claim 12 (docs/20-unclaimed-77.md): ZActorIf::BeamToNearestPathfinderPoint(OpaqueCallParameters_t&).
Thiscall, one argument (P), ret 4. Stubs (GUESS): the helper 0x5003d0 returns five blocks in call order (B, C, D from P+4, E from P+8,
and F from P+8 when the object returns a bool result); the object at this+0x18 has vtable slots 0x57c (writes three constants into its
second argument), 0x370 (counting, its arguments are stack addresses so they are not logged), and 0x5d0 (returns the bool object Q or 0);
Q's slot 0x218 logs its three float arguments and returns a bool. The original 0x5002f0 runs unchanged. The assert paths are excluded
(the helper blocks keep the byte at +4 in range); the null hook stays nonzero."""
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


def _stub57c(c, c1, c2, c3):
    """Thiscall, two stack arguments (ret 8): writes three dwords into the second argument, returns 0."""
    b = (b'\x8b\x44\x24\x08'
         + b'\xc7\x00' + ss.P(c1)
         + b'\xc7\x40\x04' + ss.P(c2)
         + b'\xc7\x40\x08' + ss.P(c3)
         + b'\x31\xc0' + b'\xc2\x08\x00')
    return ss.code(c, b)


def _stub218(c, boolval):
    """Thiscall, four stack arguments (ret 16): logs the three floats that the first argument points to (out1) and the three
    float arguments (8 entries of 8 dwords), then returns boolval in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(256, 4)
    c.emu.wbytes(ring, bytes(256))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + ss.P(ring)
         + b'\x8b\x4c\x24\x04'                    # mov ecx, [esp+4]  (out1)
         + b'\x8b\x11\x89\x10'                    # out1[0] -> [eax]
         + b'\x8b\x51\x04\x89\x50\x04'          # out1[1] -> [eax+4]
         + b'\x8b\x51\x08\x89\x50\x08'          # out1[2] -> [eax+8]
         + b'\x8b\x54\x24\x08\x89\x50\x0c'      # L0 -> [eax+12]
         + b'\x8b\x54\x24\x0c\x89\x50\x10'      # L1 -> [eax+16]
         + b'\x8b\x54\x24\x10\x89\x50\x14'      # L2 -> [eax+20]
         + b'\xb8' + ss.P(boolval) + b'\xff\x05' + ss.P(cnt) + b'\xc2\x10\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x1000)
    P = _rnd(c, 0x20)
    blocks = []
    for kind in ('B', 'C', 'D', 'E', 'F'):
        blk = _rnd(c, 0x20)
        byte = c.rng.choice([0, 2]) if kind in 'BCD' else c.rng.choice([0, 1])
        c.emu.wbytes(blk + 4, bytes([byte]))
        blocks.append(blk)
    ss.patch(c, 0x5003d0, ss.seqr(c, 1, blocks))             # GUESS-stub of the helper, call order B, C, D, E, F
    qpresent = c.rng.random() < 0.5
    Q = ss.mkobj(c, {0x218: _stub218(c, c.rng.choice([0, 1]))}, size=0x40) if qpresent else 0
    c1, c2, c3 = c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)
    O = ss.mkobj(c, {0x57c: _stub57c(c, c1, c2, c3), 0x370: ss.rec(c, 2, log=False), 0x5d0: ss.rec(c, 0, ret=Q)}, size=0x100)
    c.emu.w32(self + 0x18, O)
    return [self, P]


S(0x506500, 'ZActorIf::BeamToNearestPathfinderPoint (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 12; helper 0x5003d0 and vtable/bool stubs (GUESS); 0x5002f0 original; assert paths excluded')
