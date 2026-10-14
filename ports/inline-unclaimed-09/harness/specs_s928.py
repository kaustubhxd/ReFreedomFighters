"""specs_s928.py - unclaimed-09 batch 20 (docs/20-unclaimed-09.md, claim 22): CCheckVisible::Load(ZLoadGame*).

The object is 0x16000 random bytes (the fields reach 0x15e7c). The loader is a fake object with logged Python handlers
(unverified callees): slot 0x18 (array load: logs the pointer, a heap value, and the count; writes a random dword at the
pointer); slots 0x40 and 0x50 (dword load: log the pointer; write a random dword)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h18(e2, r):
        p, n = e2.arg32(0), e2.arg32(1)
        e2.calllog.append(('L18', p, n))
        e2.w32(p, rng.getrandbits(32))
        e2.ret(argbytes=8)

    def hdw(e2, r):
        p = e2.arg32(0)
        e2.calllog.append(('Ldw', p))
        e2.w32(p, rng.getrandbits(32))
        e2.ret(argbytes=4)

    ld = e.fake_object('checkvisible_loader', 0x40, slots={0x18: h18, 0x40: hdw, 0x50: hdw})
    return [_rnd(c, 0x16000), ld]


S(0x4aace0, 'CCheckVisible::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b20; residue-10 fallback; loader slots 0x18/0x40/0x50 stubbed (unverified callees)')
