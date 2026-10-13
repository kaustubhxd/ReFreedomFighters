"""specs_s408.py - residue 2 leaf 0x60db20 (thiscall, no arguments): returns the unaligned dword at this+0x13e7. The object is
random bytes, so every byte of the read matters."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x1400)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x1400)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x60db20, 'dword at +0x13e7 (residue 2 leaf) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='residue 2 batch 408')
