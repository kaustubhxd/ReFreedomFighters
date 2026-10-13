"""specs_s386.py - gap band batch 386: 0x410cf0, cdecl(p, n), peek of n bits (n in 0..32) from a bit stream struct.
Struct: [0] byte position, [4] bit offset (0..7), [0xc] data pointer, [0x10] limit. Limits are drawn so both the
-1 (past the limit) and the read paths run. The stream is not moved by this function."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    obj = E.zero_obj(c, 0x20)
    buf = E.zero_obj(c, 0x40)
    c.emu.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(obj, r.randint(0, 0x30))
    c.emu.w32(obj + 4, r.randint(0, 7))
    c.emu.w32(obj + 0xc, buf)
    c.emu.w32(obj + 0x10, r.randint(0, 0x30))
    c.emu.mu.ctl_flush_tb()
    return [obj, r.randint(0, 32)]


S(0x410cf0, 'peek n bits from a bit stream (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 386; mask table at 0x6f2834 read from the exe')
