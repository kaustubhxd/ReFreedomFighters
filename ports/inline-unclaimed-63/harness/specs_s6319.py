"""specs_s6319.py - unclaimed-63 batch 19 (docs/20-unclaimed-63.md): GUESS FUN_4ae220 (0x4ae220), fastcall (ECX begin, EDX end) with
one unused stack argument (ret 4). The array is a sentinel record (key -inf) followed by N records (0 to 7) of 0x35 bytes with a
float key at offset 0. Keys are drawn from small integers (so equal keys occur) or finite random floats; the other bytes are random.
The sentinel's key is below all others, so the shift loop stops at it. No stubs; no callees."""
from pilot import S
import struct, sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _gen(c):
    n = c.rng.randint(0, 7)
    base = c.emu.alloc(0x35 * (n + 1) + 16, 4)
    body = bytearray(c.rng.getrandbits(8) for _ in range(0x35 * (n + 1)))
    for i in range(n):
        if c.rng.random() < 0.5:
            key = float(c.rng.randint(-1, 2))
        else:
            key = c.fv(-100.0, 100.0)
        body[0x35 * (i + 1):0x35 * (i + 1) + 4] = struct.pack('<f', key)
    body[0:4] = struct.pack('<f', float('-inf'))    # sentinel key: below every finite key, including -FLT_MAX
    c.emu.wbytes(base, bytes(body))
    begin = base + 0x35
    end = base + 0x35 * (n + 1)
    return [begin, end, c.rng.getrandbits(32)]


S(0x4ae220, 'GUESS FUN_4ae220 fastcall', 'fastcall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 19; insertion sort of 0x35-byte records; sentinel record before begin')
