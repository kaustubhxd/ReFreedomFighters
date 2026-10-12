"""specs_s1008.py - unclaimed-07 batch 8 (slice 6): CMsgForwardToActors::Load (0x49f260).
The load object is a fake vtable: slots +0x44 and +0x50 take a heap pointer and write a random dword through it
(logged with their argument), slot +0x40 writes a flag through the argument slot (a stack address, not logged).
The controller chain g_sys+0x9b+0xadc returns a random value for slot +0x25c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _msg(c):
    e = c.emu
    o = _rnd(c, 0x200)
    flag = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    vals = [c.rng.getrandbits(32) for _ in range(2)]

    def writer(off, v):
        def h(em, r):
            p = em.arg32(0)
            em.calllog.append(('zload', off, em.reg('ecx'), (p,)))
            em.w32(p, v)
            em.ret(eax=0, argbytes=4)
        return h

    def w40(em, r):
        em.w32(em.arg32(0), flag)
        em.ret(eax=0, argbytes=4)

    load = _rnd(c, 0x100)
    e.w32(load, e.fake_vtable('zloadgame', 0x60 // 4 + 1, {0x44: writer(0x44, vals[0]), 0x50: writer(0x50, vals[1]),
                                                       0x40: w40}))
    b = _rnd(c, 0x100)
    e.w32(b, e.logging_vtable('lookup', 0x260 // 4, impl={0x25c: _const(c.rng.getrandbits(32))},
                              argwords={0x25c: 2}))
    a = _rnd(c, 0x1000)
    e.w32(a + 0xadc, b)
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, a)
    e.w32(0x70039c, sys)
    return [o, load]


S(0x49f260, 'CMsgForwardToActors::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_msg,
  note='unclaimed-07 batch 8; load slots +0x44, +0x44, +0x50 (heap pointers), +0x40 flag; chain sys+0x9b+0xadc slot +0x25c')
