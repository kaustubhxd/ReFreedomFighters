"""specs_s2758.py - unclaimed-27 batch 58: Copy 3 dwords function 0x460e20 (GUESS name).
Takes two pointers, copies 3 dwords from src to dst."""
from pilot import S


def _gen(c):
    # Allocate source and destination buffers
    src = c.emu.alloc(0x100, 16)
    dst = c.emu.alloc(0x100, 16)

    # Fill with random data
    c.emu.wbytes(src, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(0x100)))

    # Fastcall: ecx = dst, edx = src
    return [dst, src]


S(0x460e20, 'FUN_Copy3Dwords (GUESS) fastcall', 'fastcall', None, gen=_gen,
  note='unclaimed-27 batch 58; copy 3 dwords')
