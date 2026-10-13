"""specs_s327.py - decomp area 64 (docs/20-unclaimed-64.md): 0x55f670 lookup (exe 0x5003d0) then exe 0x5002f0 with a per-object value."""
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


def _store(c):
    e = c.emu
    # 0x5002f0 faults on random entry pointers, so it is stubbed for both sides: the stub stores ecx (the entry) and
    # its stack word in a heap block and returns 0 with ret 4. The port calls the same address.
    blk = e.alloc(8, 4)
    e.wbytes(blk, bytes(8))
    stub = (b'\x89\x0d' + ss.P(blk)                       # mov [blk], ecx
            + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(blk + 4)   # mov edx,[esp+4]; mov [blk+4], edx
            + b'\xb8' + ss.P(0) + b'\xc2\x04\x00')         # mov eax, 0; ret 4
    ss.patch(c, 0x5002f0, ss.code(c, stub))
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    table = _rnd(c, 0x10)
    e.w32(table, inner)
    e.w32(table + 0x4, c.rng.randrange(0, 8))
    e.w32(table + 0x8, c.rng.randrange(1, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x8, table)
    # self[+0x18] = obj; obj[+0x54] = T; the value pushed for 0x5002f0 is T[+4].
    T = _rnd(c, 0x10)
    obj = _rnd(c, 0x80)
    e.w32(obj + 0x54, T)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x18, obj)
    return [self_, p]


S(0x55f670, 'storeLookup (GUESS)', 'thiscall', None, ret='eax', gen=_store,
  note='batch327; one stack pointer p; ret 4; exe 0x5003d0 (lookup) and 0x5002f0 (ecx = entry) run as original code')
