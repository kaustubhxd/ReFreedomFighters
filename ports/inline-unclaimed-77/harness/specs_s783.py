"""specs_s783.py - unclaimed-77 claim 13 (docs/20-unclaimed-77.md): CExplodeMolotov::CreateParticles(float*, float*, float*). Thiscall,
three arguments, ret 12. Callees are stubs (GUESS): each logs its arguments into a ring and writes deterministic results.
The render manager (global 0x70039c) is an object whose vtable slot 0x1c0 returns a float in st0; its +0x40 int is random.
T (the first callee's output) is all zero in a third of the cases, so the skip path runs too."""
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


def _fbits(c, zero_chance=0.0):
    if c.rng.random() < zero_chance:
        return 0
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-40.0, 40.0)))[0]


def _stub443ef0(c, t):
    """Thiscall, two stack arguments (C pointer, v float), ret 8: logs C's three floats and v (ring of 8 x 4 dwords), then writes T = t."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x8b\x12\x89\x10'
         + b'\x8b\x54\x24\x04\x8b\x52\x04\x89\x50\x04'
         + b'\x8b\x54\x24\x04\x8b\x52\x08\x89\x50\x08'
         + b'\x8b\x54\x24\x08\x89\x50\x0c'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(t[0]) + b'\x89\x01'
         + b'\xb8' + ss.P(t[1]) + b'\x89\x41\x04'
         + b'\xb8' + ss.P(t[2]) + b'\x89\x41\x08'
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _stub4e0d00(c, s):
    """Thiscall, one float argument (ret 4): logs it (ring of 8), writes its vector = s."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(s[0]) + b'\x89\x01'
         + b'\xb8' + ss.P(s[1]) + b'\x89\x41\x04'
         + b'\xb8' + ss.P(s[2]) + b'\x89\x41\x08'
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _log_only(c, nargs, ring_n=8):
    """Thiscall logger of its first stack argument (ring of 8), pops 4*nargs, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\xff\x05' + ss.P(cnt)
         + b'\x31\xc0' + b'\xc2' + struct.pack('<H', 4 * nargs))
    return ss.code(c, b)


def _stub4e0a10(c, l):
    """Thiscall, no arguments (ret 0): writes L = l."""
    b = (b'\xb8' + ss.P(l[0]) + b'\x89\x01'
         + b'\xb8' + ss.P(l[1]) + b'\x89\x41\x04'
         + b'\xb8' + ss.P(l[2]) + b'\x89\x41\x08'
         + b'\xc3')
    return ss.code(c, b)


def _copy43e920(c):
    """Fastcall (ecx = L, edx = T, one stack argument, ret 4): copies T (edx) into L (ecx)."""
    b = (b'\x8b\x02\x89\x01'
         + b'\x8b\x42\x04\x89\x41\x04'
         + b'\x8b\x42\x08\x89\x41\x08'
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _log4e73b0(c):
    """Thiscall, five stack arguments (ret 20): logs L's three floats, f1 and f2 (ring of 8 x 8 dwords); writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(256, 4)
    c.emu.wbytes(ring, bytes(256))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + ss.P(ring)
         + b'\x8b\x4c\x24\x08\x8b\x11\x89\x10'
         + b'\x8b\x51\x04\x89\x50\x04'
         + b'\x8b\x51\x08\x89\x50\x08'
         + b'\x8b\x54\x24\x10\x89\x50\x0c'
         + b'\x8b\x54\x24\x14\x89\x50\x10'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xc2\x14\x00')
    return ss.code(c, b)


def _stub1c0(c, retbits):
    """Thiscall, two stack arguments (ret 8), returns a float in st0 (fld of a constant after logging both arguments)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    const = c.emu.alloc(4, 4)
    c.emu.wbytes(const, struct.pack('<I', retbits))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xd9\x05' + ss.P(const)
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x400)
    A = _rnd(c, 12)
    B = _rnd(c, 12)
    C = _rnd(c, 12)
    t = [_fbits(c, 0.33) for _ in range(3)]
    if c.rng.random() < 0.33:
        t = [0, 0, 0]
    sc = [_fbits(c) for _ in range(3)]
    lc = [_fbits(c) for _ in range(3)]
    ss.patch(c, 0x443ef0, _stub443ef0(c, t))      # GUESS: writes T (= t), logs C and v
    ss.patch(c, 0x4e0d00, _stub4e0d00(c, sc))     # GUESS: writes its vector (= sc), logs the scalar
    ss.patch(c, 0x451890, _log_only(c, 1))        # GUESS: logs its scalar
    ss.patch(c, 0x4e0a10, _stub4e0a10(c, lc))     # GUESS: writes L (= lc)
    ss.patch(c, 0x43e920, _copy43e920(c))         # GUESS: copies T to L
    ss.patch(c, 0x4e73b0, _log4e73b0(c))          # GUESS: logs L, f1, f2
    rm = ss.mkobj(c, {0x1c0: _stub1c0(c, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-3.0, 3.0)))[0])}, size=0x100)
    c.emu.w32(rm + 0x40, c.rng.randint(-(1 << 20), 1 << 20))
    c.emu.w32(0x70039c, rm)
    # the inputs: A is copied to this+0x68, B to this+0x74, C to this+0x80 (C is also read by the first callee)
    return [self, A, B, C]


S(0x582880, 'CExplodeMolotov::CreateParticles (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 13; callees stubbed (GUESS); x87 leftover in the normalize path; cookie check not reproduced')
