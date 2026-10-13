"""specs_s389.py - gap band batch 389: 0x410a20, cdecl(p, out, flag), returns 0, 1 or -1 (see src/batch389.cpp).
p: [0] and [0xc] random dwords, [0x10] -> 64 dword entries, [0x14] -> 64 8-byte records, [0x20] count 0..16,
[0x24] index 0..16, [0x158]/[0x15c] counter. Entries have random bits 0x100, 0x200, 0x400 and low bytes drawn from
{0, 1, 0x7f, 0xfe, 0xff} so the 0xff chain, the skip path and both flags run. The last entries are never 0xff, so the
chain always ends inside the array. out is NULL in a third of the cases and flag is 0, 1 or 2."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    p = E.zero_obj(c, 0x180)
    A = E.zero_obj(c, 64 * 4)
    B = E.zero_obj(c, 64 * 8)
    ents = []
    for i in range(64):
        if i >= 60:
            low = r.choice([0, 1, 0x7f])
        else:
            low = r.choice([0, 1, 0x7f, 0xfe, 0xff, 0xff, r.getrandbits(8)])
        hi = r.getrandbits(32) & ~0xff
        flags = 0
        if r.random() < 0.2:
            flags |= 0x400
        if r.random() < 0.4:
            flags |= 0x200
        if r.random() < 0.4:
            flags |= 0x100
        ents.append((hi & ~0x700) | flags | low)
    c.emu.wbytes(A, b''.join(int(x & 0xffffffff).to_bytes(4, 'little') for x in ents))
    c.emu.wbytes(B, bytes(r.getrandbits(8) for _ in range(64 * 8)))
    c.emu.w32(p + 0x0, r.getrandbits(32))
    c.emu.w32(p + 0xc, r.getrandbits(32))
    c.emu.w32(p + 0x10, A)
    c.emu.w32(p + 0x14, B)
    c.emu.w32(p + 0x20, r.randint(0, 16))
    c.emu.w32(p + 0x24, r.randint(0, 16))
    c.emu.w32(p + 0x158, 0xffffffff if r.random() < 0.5 else r.getrandbits(32))
    c.emu.w32(p + 0x15c, r.getrandbits(32))
    out = 0 if r.random() < 0.33 else E.zero_obj(c, 0x40)
    flag = r.choice([0, 1, 2])
    c.emu.mu.ctl_flush_tb()
    return [p, out, flag]


S(0x410a20, 'stream entry pick (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 389; leaf, no calls; unblocks skipped 0x410a00')
