"""specs_s31136.py - Sonnet h1 batch 31136: 0x496ce0 (range search over chained chunks of 8-byte [start,end] entries)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def g496ce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # Keep both +/-8 endpoint fixtures in the unsigned non-wrapping range.
    ebx = r32(c) & 0x7fffff00
    # A nonmatching range falls through to the next-chunk link at C+0xc.
    # In this fixture that word can overlap range storage, so populated
    # chunks always match and empty fixtures exercise the false return.
    nchunks = r.choice([0, 0, 0, 1])
    chunks = []
    for i in range(nchunks):
        C = rnd(c, 0x80)
        flags = 2
        # flags byte at C+8: bit0 = continue to next chunk; the byte also counts entries (>= 2 is "usable")
        e.w32(C + 8, (e.r32(C + 8) & ~0xff) | flags)
        chunks.append(C)
    for i, C in enumerate(chunks):
        e.w32(C + 0xc, chunks[i + 1] if i + 1 < nchunks else 0)
        flags = e.r32(C + 8) & 0xff
        base = C + 0xc + (4 if flags & 1 else 0)
        # flags=2 gives one [start,end] entry. Keep the probed value inside
        # it so execution returns before following the link word.
        edge = r.randrange(3)
        start = ebx if edge == 1 else ebx - 8
        end = ebx if edge == 2 else ebx + 8
        e.w32(base, (start & 0xfffffff8) | r.getrandbits(3))
        e.w32(base + 4, (end & 0xfffffff8) | r.getrandbits(3))

    def side(em, k):
        loc = em.reg('ecx')
        if chunks:
            C = chunks[0]
            flags = em.r32(C + 8) & 0xff
            start = C + 0xc + (4 if flags & 1 else 0)
            end = C + ((flags & 0xff) + 3) * 4
            em.w32(loc, C)
            em.w32(loc + 4, start)
            em.w32(loc + 8, end)
        else:
            em.w32(loc, 0)
            em.w32(loc + 4, 0)
            em.w32(loc + 8, 0)
        em.w32(loc + 0xc, r.getrandbits(32))
    hook_rec(c, 0x440ce0, 1, ret=r32(c), pop=4, this='mark', side=side)
    return [r32(c), ebx, r32(c)]


S(0x496ce0, 'GUESS is value inside any [start,end] 8-aligned range of the chunk list produced by 440ce0', 'stdcall', None, ret='al', gen=g496ce0, note='batch61000')
