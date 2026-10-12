"""specs_s1006.py - unclaimed-07 batch 6 (slice 6): CCheckInsideByType::Init2Wrapper (0x5bd8e0).
The sys object, the controller and the lookup object are fake per case (logging vtables). The result object r always
exists; its slot +0x100 returns 0 (the log path, with the engine logger at global 0x700390) or a random value."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _init2(c):
    e = c.emu
    o = _rnd(c, 0x200)
    # this->vtable slot +0x68 (two arguments)
    e.w32(o, e.logging_vtable('checkinside', 0x70 // 4, impl={0x68: _const(0)}, argwords={0x68: 2}))
    # r: slot +0x100 gives v; r+0x18 is an object whose slot +0x14 gives the result
    v = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32) | 1
    inner = _rnd(c, 0x100)
    e.w32(inner, e.logging_vtable('inner', 0x18 // 4 + 1, impl={0x14: _const(c.rng.getrandbits(32))}))
    r = _rnd(c, 0x40)
    e.w32(r, e.logging_vtable('enemyflag_r', 0x104 // 4, impl={0x100: _const(v)}, argwords={0x100: 1}))
    e.w32(r + 0x18, inner)
    # the controller/lookup object b returns r for slot +0x25c
    b = _rnd(c, 0x100)
    e.w32(b, e.logging_vtable('lookup', 0x260 // 4, impl={0x25c: _const(r)}, argwords={0x25c: 2}))
    a = _rnd(c, 0x1000)
    e.w32(a + 0xadc, b)
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, a)
    e.w32(0x70039c, sys)
    # the engine log: slot +0x20 gives a stream, the stream's cdecl slot +0x2c is logged
    stream = _rnd(c, 16)

    def printf(em, rr):
        em.calllog.append(('log.printf', 0x2c, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    e.w32(stream, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a2: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [o]


S(0x5bd8e0, 'CCheckInsideByType::Init2Wrapper (unknown) thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='unclaimed-07 batch 6; sys+0x9b+0xadc slot +0x25c, slot +0x100, log path when 0; r+0x18 slot +0x14')
