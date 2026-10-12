"""specs_s314.py - gap band (docs/20-unclaimed-76.md), batch 314: 0x6070b0, vector<unsigned short>::insert(pos, value) (thiscall, ret 8).
The vector object holds begin, end, capacity end. The exe allocator 0x6014a0 and free 0x54f870 run as exe code; they use the
harness heap, which both sides see identically. The value word pval is a heap word. Some vectors are empty with begin 0."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    # CRT malloc and free through their imports: the allocator 0x6014a0 calls malloc (cdecl); free is a no-op here
    e.stub_import('malloc', lambda em, rr: em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=0))
    e.stub_import('free', lambda em, rr: (em.calllog.append(('free', 0, None, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))
    vec = c.emu.alloc(0x20, 4)
    n = rng.randrange(0, 7)
    if n == 0 and rng.random() < 0.5:
        begin = 0
        cap = 0
        end = 0
    else:
        extra = 0 if rng.random() < 0.5 else rng.randrange(1, 4)
        capn = n + extra
        begin = e.alloc(2 * capn + 16, 4)
        e.wbytes(begin, bytes(rng.getrandbits(8) for _ in range(2 * capn + 16)))
        end = begin + 2 * n
        cap = begin + 2 * capn
    e.w32(vec, begin)
    e.w32(vec + 4, end)
    e.w32(vec + 8, cap)
    # the insertion point: any word boundary in [begin, end]
    k = rng.randrange(0, n + 1) if n else 0
    pos = begin + 2 * k
    pval = e.alloc(16, 4)
    e.w32(pval, rng.getrandbits(32))
    return [vec, pos, pval]


S(0x6070b0, 'vector<u16>::insert (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch314; ret 8; allocator 0x6014a0 and free 0x54f870 run as exe code')
