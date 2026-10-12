"""specs_s1006.py - unclaimed-04 batch 6 (docs/20-unclaimed-04.md): ZFFHERO::CreateMovementStand (0x590db0, medium name).
thiscall, no stack arguments, ret 0. The function allocates 0x189 bytes through 0x41e290 (operator new, cdecl, one
argument); if that returns null it returns null, else it runs the constructor 0x5e1240 on the new object with (this, 2)
and returns the constructor's eax. The prologue and epilogue install and restore an SEH frame at fs:[0] (page 0 of the
harness's fake TEB); the net effect on memory is nil, so the port omits the frame.
The allocator is a Python hook (GUESS: operator new, an unverified callee): 30% of cases return null, the rest return a
zeroed 0x189-byte block from the harness heap. The hook decision is made in setup (the same rng draw on both sides).
The constructor 0x5e1240 is original code. The object is 0x1000 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    e = c.emu
    null = c.rng.random() < 0.3

    def new41(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, 0, (size,)))
        if null:
            em.ret(eax=0, argbytes=0)
            return
        p = em.alloc(size, 4)
        em.wbytes(p, bytes(size))
        em.ret(eax=p, argbytes=0)

    e.hook(0x41e290, new41)


def _args(c):
    return [_rnd(c, 0x1000)]


S(0x590db0, 'ZFFHERO::CreateMovementStand (medium) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup,
  note='unclaimed-04 batch 6; operator new 0x41e290 is a hook (GUESS), 0x5e1240 is original code')
