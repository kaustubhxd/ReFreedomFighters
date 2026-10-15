"""helpers01.py - shared spec helpers for fresh slice 01 (docs/20-fresh-01.md).
rnd: random buffer. hk: replace an exe callee by a logging stub (logs the named registers and stack words, pops
nargs words when callee-pops, returns eax). Logged values must never be stack addresses (they differ between runs)."""


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def hk(c, addr, name, nargs=0, eax=None, regs=('ecx',), pop=True):
    def h(e, r):
        e.calllog.append((name, tuple(e.reg(x) for x in regs), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=eax(e) if callable(eax) else eax, argbytes=4 * nargs if pop else 0)
    c.emu.hook(addr, h)


def lvt(c, name, nslots, impl=None, argwords=None):
    return c.emu.logging_vtable(name, nslots, impl, argwords)


def obj(c, n, name, nslots, impl=None, argwords=None):
    """Random object of n bytes whose first dword is a logging vtable."""
    o = rnd(c, n)
    c.emu.w32(o, lvt(c, name, nslots, impl, argwords))
    return o
