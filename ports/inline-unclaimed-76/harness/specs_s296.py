"""specs_s296.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4312f0, a sliced call on a [begin, end] range.
The exe helper 0x42b2e0 (SEH frame, 62 instructions) is stubbed by address: a GUESS call-recording stub that logs its first two
arguments and the byte at the third (a stack address; the byte is logged, not the address) and pops 12 bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slice(c):
    e = c.emu

    def h(em, r):
        hi = em.mu.mem_read(em.arg32(2), 1)[0]          # the byte the third argument points at (not its address)
        em.calllog.append(('h42b2e0', 0x42b2e0, em.reg('ecx'), (em.arg32(0), em.arg32(1), hi)))
        em.ret(eax=0, argbytes=12)

    e.hook(0x42b2e0, h)
    base = _rnd(c, 0x200)
    begin = base + 4 * c.rng.randrange(0, 16)
    end = begin + 4 * c.rng.randrange(0, 24)
    rng_obj = _rnd(c, 0x20)
    e.w32(rng_obj, begin)
    e.w32(rng_obj + 4, end)
    off = c.rng.choice([0, 4, 8, 0x40, c.rng.getrandbits(32) & 0xffff, c.rng.getrandbits(32)])
    count = c.rng.choice([0, 1, 4, 16, c.rng.getrandbits(16)])
    out = _rnd(c, 0x20)
    return [rng_obj, out, off, count]


S(0x4312f0, 'sliceCall (GUESS)', 'thiscall', None, ret='eax', gen=_slice, note='batch296; ret 0xc; 0x42b2e0 stubbed')
