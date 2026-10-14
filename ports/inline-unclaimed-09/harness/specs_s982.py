"""specs_s982.py - area 56 band, claim A48 (0x5368a0).

this is a 0x5400-byte object of random bytes whose first dword is a fake vtable with six GUESS recording stubs (slots 0x6c, 0x68,
0x64, 0x5c, 0x1d0, 0x1cc; thiscall, one argument; each returns its per-case value). Per case the field f at +0x5302 is non-zero
(a zero field returns at once). k in 0..4 is drawn: the first k of the slots 0x6c, 0x68, 0x64, 0x5c return -f (so their sums are zero
and the chain goes on), and the rest return random non-zero values, so the chain exits at slot k; with k = 4 the 0x1d0 path runs.
The 0x1d0 value is zero in about one case in two. ret='eax'."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    chain = (0x6c, 0x68, 0x64, 0x5c)
    slots = chain + (0x1d0, 0x1cc)
    f = rng.getrandbits(32) or 1
    k = rng.randint(0, 4)
    rv = {}
    for i, sl in enumerate(chain):
        rv[sl] = ((-f) & 0xffffffff) if i < k else (rng.getrandbits(32) | 1)
    rv[0x1d0] = 0 if rng.random() < 0.5 else (rng.getrandbits(32) | 1)
    rv[0x1cc] = rng.getrandbits(32)

    def mk(sl):
        def h(e2, r):
            e2.calllog.append(('V%x' % sl, e2.reg('ecx'), e2.arg32(0)))
            e2.ret(eax=rv[sl], argbytes=4)
        return h

    vt = e.fake_vtable('vt5368a0', 0x200, {sl: mk(sl) for sl in slots})
    this = e.alloc(0x5400, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x5400)))
    e.w32(this, vt)
    e.w32(this + 0x5302, f)
    return [this, rng.getrandbits(32)]


S(0x5368a0, 'unnamed 0x5368a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A48; six vt slots are GUESS recording stubs; per-case zero-sum prefix')
