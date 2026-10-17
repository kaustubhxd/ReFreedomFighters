"""specs_s1233.py - pathfinding batch 1233: ZActor::FindPath(from, to) (0x478780). The actor's vtable has logged stubs for
slot 0x5e4 (the request hand-off); the engine's message table (+0x9b, slot 0x4c) and the pathfinder (+0x5b2, slot 0x214)
are stubs too. The debug reporter is installed for the null-pathfinder case. The exe's CChkPntLst constructor and the
allocator run as the exe's own code. The 7th argument to the message table is a BYTE flag pushed as a dword: the exe
leaves its upper three bytes as uninitialised stack, so the call log compares only the low byte (mask 0xff)."""
from pilot import S
from pfspec import rnd, reporter, vtable, sf, allocator


def _fp(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    allocator(c)
    actor = rnd(c, 0x1000)
    e.w32(actor, vtable(c, 'actor', 0x900, impl={0x5e4: lambda em, a: 0}, argwords={0x5e4: 1}))
    e.w8(actor + 0x690, r.choice([0, 0, 1, 2]))
    e.w8(actor + 0x6c3, r.choice([0, 1]))
    e.w8(actor + 0x6c4, r.choice([0, 1, 1]))
    m = e.alloc(16)
    e.w32(m, vtable(c, 'msgtable', 0x50, impl={0x4c: lambda em, a: r.getrandbits(32)}, argwords={0x4c: 7},
                                                opts={0x4c: {'mask': {6: 0xff}}}))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)
    pf = e.alloc(16) if r.random() < 0.9 else 0
    if pf:
        e.w32(pf, vtable(c, 'pathfinder', 0x240, impl={0x214: lambda em, a: a[0] ^ 0x3c3c3c3c},
                         argwords={0x214: 1}))
    e.w32(actor + 0x5b2, pf)
    frm = e.alloc(16)
    to = e.alloc(16)
    for k in range(3):
        e.wf32(frm + 4 * k, sf(c.fv(-300, 300)))
        e.wf32(to + 4 * k, sf(c.fv(-300, 300)))
    return [actor, frm, to]


S(0x478780, 'ZActor::FindPath', 'thiscall', None, gen=_fp, n=300)
