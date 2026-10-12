"""specs_s1010.py - unclaimed-07 batch 10 (slice 6): ZFFActor::ConcealItem (0x59e9e0).
The controller at g_sys+0x9b returns b from its slot +0x58 (b is 0 about 10% of cases). The actor's slots +0x504, +0x500
(which pick the branch: b equals one of them, or neither), +0x3f0, +0x20 and +0x45c are logging stubs. b's slot +0x2e8
gives a named object (name at +4). The engine log (global 0x700390) gives a stream whose cdecl slot +0x2c is logged."""
from pilot import S

NSLOTS = 0x520 // 4


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _named(c):
    """An object whose dword at +4 is a name pointer (random, or 0 about 30% of the time)."""
    o = _rnd(c, 0x20)
    c.emu.w32(o + 4, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    return o


def _concealitem(c):
    e = c.emu
    mode = c.rng.choice(['504', '500', 'other'])
    has_b = c.rng.random() < 0.9
    other = c.rng.getrandbits(32)
    bptr = 0
    if has_b:
        p = _named(c)
        bptr = _rnd(c, 0x40)
        e.w32(bptr, e.logging_vtable('itemref', 0x2f0 // 4, impl={0x2e8: _const(p)}, argwords={0x2e8: 0}))
    x504 = bptr if mode == '504' else other
    x500 = bptr if mode == '500' else other + 1

    actor = _rnd(c, 0x400)
    q = _named(c)
    e.w32(actor, e.logging_vtable('actor', NSLOTS,
                                  impl={0x504: _const(x504), 0x500: _const(x500),
                                        0x3f0: _const(c.rng.choice([5, 6, 7])), 0x20: _const(q), 0x45c: _const(0)},
                                  argwords={0x504: 0, 0x500: 0, 0x3f0: 0, 0x20: 0, 0x45c: 2}))

    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('controller', 0x60 // 4, impl={0x58: _const(bptr)}, argwords={0x58: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=0)

    stream = _rnd(c, 16)
    e.w32(stream, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [actor, c.rng.getrandbits(32)]


S(0x59e9e0, 'ZFFActor::ConcealItem (unknown) thiscall', 'thiscall', None, ret='al', gen=_concealitem,
  note='unclaimed-07 batch 10; g_sys+0x9b slot +0x58; actor slots +0x504, +0x500, +0x3f0, +0x45c; log path')
