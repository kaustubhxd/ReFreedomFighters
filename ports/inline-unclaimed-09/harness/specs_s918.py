"""specs_s918.py - unclaimed-09 batch 10 (docs/20-unclaimed-09.md, claim 10): ZRunParamAnim::Load(ZLoadGame*).

The object is 0x100 random bytes. The loader is a fake object with Python handlers (unverified callees):
- slot 0x50 writes a random dword at its pointer argument and logs the pointer (a heap address, stable);
- slot 0x68 writes a random byte at its pointer argument and logs the pointer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h50(e2, r):
        p = e2.arg32(0)
        e2.calllog.append(('L50', p))
        e2.w32(p, rng.getrandbits(32))
        e2.ret(argbytes=4)

    def h68(e2, r):
        p = e2.arg32(0)
        e2.calllog.append(('L68', p))
        e2.w8(p, rng.getrandbits(8))
        e2.ret(argbytes=4)

    ld = e.fake_object('runparam_loader', 0x40, slots={0x50: h50, 0x68: h68})
    return [_rnd(c, 0x100), ld]


S(0x4e6f40, 'ZRunParamAnim::Load (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b10; loader slots 0x50/0x68 stubbed (unverified callees)')
