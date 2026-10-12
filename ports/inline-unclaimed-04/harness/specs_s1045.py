"""specs_s1045.py - unclaimed-04 batch 45 (docs/20-unclaimed-04.md): 0x5f3370 (thiscall, two stack arguments p, n; ret 8).
off = this+8; if off + n exceeds this+0xc (unsigned), the callback at 0x7003b0 runs first (non-null stub: a null is an int3 assert);
then 0x634d22(off, p, n) when p != 0, else 0x634d10(off, 0, n) (both cdecl, hooked and logged); this+8 += n. Object zeroed 0x100 bytes."""
from pilot import S


def _setup(c):
    def cdecl3(name):
        def h(em, r):
            em.calllog.append((name, 0, 0, tuple(em.arg32(i) for i in range(3))))
            em.ret(eax=0, argbytes=0)
        return h

    def cb(em, r):
        em.calllog.append(('7003b0', 0, 0, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x634d22, cdecl3('634d22'))
    c.emu.hook(0x634d10, cdecl3('634d10'))
    c.emu.w32(0x7003b0, c.emu.stub_fn('cb7003b0', cb))


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    off = c.rng.randrange(0, 64)
    lim = c.rng.choice([off + 200, off + 3, off, c.rng.randrange(0, 128)]) & 0xffffffff
    c.emu.w32(o + 8, off)
    c.emu.w32(o + 0xc, lim)
    p = c.rng.choice([0, c.emu.alloc(16, 4), c.rng.getrandbits(32)])
    n = c.rng.randrange(0, 32)
    return [o, p, n]


S(0x5f3370, 'unknown::append_copy_advance (unknown) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 45; 0x634d22, 0x634d10 and the callback 0x7003b0 stubbed (GUESS)')
