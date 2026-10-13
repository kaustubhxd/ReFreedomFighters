"""specs_s335.py - decomp area 64 (docs/20-unclaimed-64.md): 0x561330 conditional string append; exe 0x59be70 compare."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tag(c):
    e = c.emu
    # The exe compare 0x59be70 faults on these inputs (cause not found; see the doc), so it is stubbed on both sides.
    # The stub returns al = 0 or 1 per case, so both branches of the caller run.
    al = c.rng.getrandbits(1)
    ss.patch(c, 0x59be70, ss.code(c, b'\xb8' + ss.P(al) + b'\xc3'))   # mov eax, al; ret
    A = _rnd(c, 0x1100)
    # Flags the port reads: A[+0x103c], A[+0x103e], A[+0x103f], A[+0x1043] (each zero or one), biased toward both paths.
    for off in (0x103c, 0x103e, 0x103f, 0x1043):
        e.wbytes(A + off, bytes([1 if c.rng.random() < 0.5 else 0]))
    if c.rng.random() < 0.3:
        e.wbytes(A + 0x103c, bytes([0]))
    # The string at A[+0x48] is short and zero-terminated (the compare's input, see the stub above).
    sl = c.rng.randrange(0, 0x10)
    e.wbytes(A + 0x48, bytes([c.rng.randrange(1, 256) for _ in range(sl)]) + bytes(0x10 - sl))
    self_ = _rnd(c, 0x100)
    e.wbytes(self_ + 0x87, bytes([1 if c.rng.random() < 0.8 else 0]))
    e.w32(self_ + 0x94, A)
    # buf: a random string with a zero terminator inside the first 0x20 bytes, so the six-byte suffix stays in bounds.
    buf = _rnd(c, 0x40)
    n = c.rng.randrange(0, 0x20)
    e.wbytes(buf, bytes([c.rng.randrange(1, 256) for _ in range(n)]) + bytes(0x40 - n))
    return [self_, buf]


S(0x561330, 'appendTag (GUESS)', 'thiscall', None, ret=None, gen=_tag,
  note='batch335; one stack pointer buf; ret 4; exe 0x59be70 (string compare on A) runs as original code')
