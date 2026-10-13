"""specs_s367.py - gap band batch 367: 0x410220, cdecl(p); p points to a holder whose dword points to a block with random bytes; the
result packs bytes +0xe..+0x11 big-endian."""
from pilot import S
import engine_stubs as E


def _gen(c):
    blk = E.zero_obj(c, 0x40)
    c.emu.wbytes(blk, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    h = E.zero_obj(c, 0x10)
    c.emu.w32(h, blk)
    c.emu.mu.ctl_flush_tb()
    return [h]


S(0x410220, 'pack bytes +0xe..+0x11 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 367')
