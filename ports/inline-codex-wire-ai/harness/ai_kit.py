import struct
def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a
def _bool(c):
    return (c.rng.getrandbits(24) << 8) | c.rng.choice([0, 1])
def nostk(v):
    import pe_emu
    return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v
def _log_world(c):
    e = c.emu
    logobj = _rnd(c, 16)

    def printf(em, r):
        fmt = em.arg32(1)
        raw = em.rbytes(fmt, 200)
        nargs = raw[:raw.index(0)].count(b'%') if 0 in raw else 0   # only the real arguments (all %s here)
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(2 + nargs))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    if c.rng.random() < 0.8:
        e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    else:
        e.w32(0x7003b0, 0)
    e.hook(0x4cc1d0, lambda em, r: em.ret(eax=em.r32(em.reg('ecx')) + 8))
    e.hook(0x4cbec0, lambda em, r: em.ret())
