"""specs_s382.py - gap band batch 382: 0x4067b0, cdecl(descriptor, A, B). The descriptor holds: +0 = N (a size, 0x40 here),
+4 = a stage count (small), +8 = a float array pointer, +0xc = a table of small integers (read as indices). A and B are large float
arrays with padding in front (the loops reach below the base). Values are drawn in gen; the same memory is seen by both builds."""
from pilot import S
import engine_stubs as E


def _floats(c, n):
    a = c.fbuf(n, pad=0)
    return a


def _gen(c):
    r = c.rng
    N = r.choice([0x40, 0x20, 0x80])
    stage = r.choice([7, 8])
    big = c.emu.alloc(0x20000, 16)
    c.emu.wbytes(big, bytes(r.getrandbits(8) for _ in range(0x20000)))
    A = big + 0x8000
    B = big + 0x10000
    # finite float contents only: a NaN sign can differ between the exe and the port when a NaN is an input (see doc)
    import struct as _st
    for base in (big, big + 0x8000, big + 0x10000):
        for k in range(0x4000 // 4):
            c.emu.wbytes(base + 4 * k, _st.pack('<f', r.uniform(-8.0, 8.0)))
    Tab = c.emu.alloc(0x400, 16)
    for k in range(0x100):
        c.emu.w32(Tab + 4 * k, r.randrange(0, 16))
    desc = E.zero_obj(c, 0x20)
    c.emu.w32(desc + 0, N)
    c.emu.w32(desc + 4, stage)
    c.emu.w32(desc + 8, A)
    c.emu.w32(desc + 0xc, Tab)
    c.emu.mu.ctl_flush_tb()
    return [desc, A, B]


S(0x4067b0, 'radix-4 twiddle transform (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 382; whole function translated from the disassembly; calls 0x4071d0 and 0x406cc0 are exe code')
