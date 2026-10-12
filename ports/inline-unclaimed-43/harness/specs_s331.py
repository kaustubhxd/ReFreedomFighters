"""specs_s331.py - area 71 batch 331: 0x5966e0, thiscall, one stack argument, returns bool (al). True only when the dword at
+0x9d3 equals the argument and the byte at +0x66c is nonzero. The spec makes the id match in half the cases, and the flag
byte is drawn from {0, 1, 0x80} so the nonzero test is exercised at a boundary."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x700)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x700)))
    idv = r.getrandbits(32)
    if r.random() < 0.5:
        c.emu.w32(o + 0x9d3, idv)
    else:
        c.emu.w32(o + 0x9d3, r.getrandbits(32))
    c.emu.wbytes(o + 0x66c, bytes([r.choice([0, 1, 0x80])]))
    c.emu.mu.ctl_flush_tb()
    return [o, idv]


S(0x5966e0, 'id match and flag (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='area 71 batch 331 (leaf, residue 10)')
