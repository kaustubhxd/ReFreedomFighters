"""specs_s5844.py - 0x590cd0 (FUN_00590cd0, SEH allocate + construct with two arguments): thiscall, no args, returns eax. operator new 0x41e290 (cdecl, one argument)
is a stub that returns a fresh block in about 80% of the cases and 0 otherwise; the constructor 0x5e0e10 (thiscall, two stack arguments, ret 8) is a logging stub that
returns a per-case eax. The argument order is logged (the object and the this argument as an offset from this)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d0cd0(c):
    e = c.emu
    rnd = c.rng
    null = rnd.random() < 0.2
    ctor_ret = rnd.getrandbits(32)
    self_obj = _rnd(c, 0x100)
    blocks = []

    def hnew(em, r):
        size = em.arg32(0)
        em.calllog.append(('new', size, None, ()))
        if null:
            em.ret(eax=0, argbytes=0)
        else:
            p = em.alloc(max(size, 4), 4)
            blocks.append(p)
            em.ret(eax=p, argbytes=0)

    def hctor(em, r):
        o = em.reg('ecx')
        own = 'new' if blocks and o == blocks[-1] else 'other'
        a = em.arg32(0)
        em.calllog.append(('ctor', own, 'self' if a == self_obj else 'other', em.arg32(1)))
        em.ret(eax=ctor_ret, argbytes=8)

    e.hook(0x41e290, hnew)
    e.hook(0x5e0e10, hctor)
    return [self_obj]


S(0x590cd0, 'FUN_00590cd0 (SEH allocate + construct, two args) thiscall', 'thiscall', None, ret='eax', gen=_d0cd0,
  note='fresh-12 family, naked frame: new 0x41e290 and ctor 0x5e0e10 hooked (logging; ctor returns eax)')
