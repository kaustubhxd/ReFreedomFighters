"""specs_s388.py - gap band batch 388: 0x407140, cdecl, one argument: a pointer to eight floats (random finite values in
+-1000, so no NaN or overflow). The butterfly writes all eight floats back; the heap compare checks every one."""
import struct
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x20)
    vals = [r.uniform(-1000.0, 1000.0) for _ in range(8)]
    c.emu.wbytes(o, struct.pack('<8f', *vals))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x407140, 'eight-float butterfly (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 388; called by 0x406cc0 (batch 374)')
