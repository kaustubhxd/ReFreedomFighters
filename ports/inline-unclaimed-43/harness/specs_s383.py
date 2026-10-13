"""specs_s383.py - gap band batch 383: 0x411009, stdcall(dst, src) (ret 8). The source and destination are 0x40-byte blocks
with random floats and dwords; in 25% of cases they are the same block (the je path, nothing copied)."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    src = E.zero_obj(c, 0x60)
    c.emu.wbytes(src, bytes(r.getrandbits(8) for _ in range(0x60)))
    if r.random() < 0.25:
        dst = src
    else:
        dst = E.zero_obj(c, 0x60)
        c.emu.wbytes(dst, bytes(r.getrandbits(8) for _ in range(0x60)))
    c.emu.mu.ctl_flush_tb()
    return [dst, src]


S(0x411009, 'copy struct fields (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='gap band batch 383; translated from the disassembly')
