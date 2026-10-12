"""specs_s299.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5eaab0. The allocator 0x41e290 is a GUESS stub that
fills the block with 0xA5. The first argument is stored (a dword) and the count gives the number of blocks."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    e = c.emu

    def alloc_fill(em, r):
        n = max(em.arg32(0), 1)
        p = em.alloc(n, 4)
        em.wbytes(p, b'\xa5' * n)
        em.ret(eax=p, argbytes=0)

    e.hook(0x41e290, alloc_fill)
    self_ = _rnd(c, 0x80)
    count = c.rng.choice([0, 1, 2, 5, c.rng.randrange(0, 12)])
    return [self_, c.rng.getrandbits(32), count]


S(0x5eaab0, 'initBlocks (GUESS)', 'thiscall', None, ret='eax', gen=_init, note='batch299; allocator stubbed; ret 8')
