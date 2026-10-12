"""specs_s336.py - gap band, batch 336: 0x61bfa0 (cdecl, four arguments). The exe callee 0x61bfe0 is hooked by address: it records its three
arguments and the three dwords of the record (the stack address is logged as its contents), and returns a per-run value."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def rec(em, r):
        a = [em.arg32(k) for k in range(3)]
        words = struct.unpack('<III', bytes(em.mu.mem_read(a[1], 12)))
        em.calllog.append(('h61bfe0', 0, None, (a[0], ('rec', words), a[2])))
        em.ret(eax=rv, argbytes=0)

    e.hook(0x61bfe0, rec)
    return [rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]


S(0x61bfa0, 'wrap61bfa0 (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch336; plain ret; callee 0x61bfe0 hooked')
