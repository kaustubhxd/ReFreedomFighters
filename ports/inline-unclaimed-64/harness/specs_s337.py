"""specs_s337.py - decomp area 64 (docs/20-unclaimed-64.md): 0x55acb0 vtbl slot 0x6dc, lookup (exe 0x5003d0), exe 0x5002f0 (stubbed)."""
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


def _query(c):
    e = c.emu
    # 0x5002f0 faults on random entry pointers: stub on both sides. The stub stores ecx and its stack word, returns 0.
    blk = e.alloc(8, 4)
    e.wbytes(blk, bytes(8))
    stub = (b'\x89\x0d' + ss.P(blk)
            + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(blk + 4)
            + b'\xb8' + ss.P(0) + b'\xc2\x04\x00')
    ss.patch(c, 0x5002f0, ss.code(c, stub))

    # Table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 8))
    e.w32(T + 0x8, c.rng.randrange(1, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x8, T)

    # obj's slot 0x6dc takes one word and returns a per-case value.
    rv = c.rng.getrandbits(32)
    obj_vt = e.logging_vtable('obj55ac', 0x800, argwords={0x6dc: 1}, impl={0x6dc: lambda em, a: (rv, None)})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)
    return [self_, p]


S(0x55acb0, 'storeQuery (GUESS)', 'thiscall', None, ret='eax', gen=_query,
  note='batch337; one stack pointer p; ret 4; obj vtbl 0x6dc (1 word); exe 0x5003d0 and stubbed 0x5002f0')
