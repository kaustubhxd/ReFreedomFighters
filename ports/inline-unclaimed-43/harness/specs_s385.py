"""specs_s385.py - gap band batch 385: 0x410340, cdecl, one argument p (struct). p[0] = buf0, p[4] = n1, p[8] = buf1, p[0xc] = n2.
The loop runs over both buffers (n may be 0 or negative, which skips the loop) and the four result bytes are stored at
buf0 +0x16..+0x19. Buffers are random bytes, so the loop has to read them in the right order."""
from pilot import S
import engine_stubs as E


def _count(r):
    return r.choice([0, -1, -5, 1, r.randint(2, 40)]) & 0xffffffff


def _gen(c):
    r = c.rng
    obj = E.zero_obj(c, 0x20)
    b0 = E.zero_obj(c, 0x40)
    b1 = E.zero_obj(c, 0x40)
    c.emu.wbytes(b0, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.wbytes(b1, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(obj, b0)
    c.emu.w32(obj + 4, _count(r))
    c.emu.w32(obj + 8, b1)
    c.emu.w32(obj + 0xc, _count(r))
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x410340, 'crc-style pass over two byte buffers (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 385; table at 0x6f242c read from the exe')
