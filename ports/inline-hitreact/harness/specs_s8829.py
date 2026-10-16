"""specs_s8829.py - hitreact batch 8829: 0x641a40 (ZRagdollContainer's debug variables nailgun / flymo / forcemult). operator new 0x41e290,
the debug variable ctor 0x4d8330 and its string copies 0x4cbe80 / 0x4cc630 run as exe code in both builds (only the CRT malloc under new is
stubbed: a fresh block per call, or 0 now and then); the engine object at [0x70039c] has a recording stub at slot 0x1a4. The heap compare
covers the three variable objects (their name buffers and the value address at +0x104) and the container's unaligned slots."""
from pilot import S
from wkit import rnd, stub, obj


def _gen(c):
    r = c.rng
    emu = c.emu
    self = rnd(c, 0x40)
    fail = r.random() < 0.2
    sizes = emu.alloc(0x20, 4)
    emu.wbytes(sizes, bytes(0x20))
    k = [0]

    def ml(em, rr):   # the requested sizes go into a heap block the compare covers
        n = em.arg32(0)
        if k[0] < 8:
            em.w32(sizes + 4 * k[0], n)
        k[0] += 1
        if fail and r.random() < 0.4:
            em.ret(eax=0, argbytes=0)
            return
        b = em.alloc(max(n, 4) + 0x20, 16)
        em.wbytes(b, bytes(max(n, 4) + 0x20))
        em.w32(b + n, n)   # the size marker just past the requested end (a smaller new leaves it inside the object)
        em.ret(eax=b, argbytes=0)
    emu.stub_import('malloc', ml)
    eng = obj(c, 0x200, {0x1a4: stub(c, 1, rec_ecx=True)})
    emu.w32(0x70039c, eng)
    emu.mu.ctl_flush_tb()
    return [self]


S(0x641a40, 'ZRagdollContainer debug variables', 'thiscall', ret=None, gen=_gen)
