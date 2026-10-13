"""specs_s4021.py - area 70 batch 4021: 0x59e610 (stack pop, pure) and 0x4a2f90 (two word globals from slot 0x114 calls on the
render manager). The engine global 0x70039c points to a heap fake whose +0x9b is the render manager; its vtable slot 0x114 is
a raw fake handler (four stack arguments, ret 0x10, per-case EAX). The globals 0x7002e8 and 0x7002ec are compared as data."""
from pilot import S, F


def _pop(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x7e0, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x7e0)))
    n = r.randrange(0, 8)
    e.w32(o + 0x7ce, n)
    for k in range(n + 1):
        e.w32(o + 0x7c2 + 16 * k, r.randrange(-50, 50) & 0xffffffff)
    return [o, r.randrange(-50, 50) & 0xffffffff]


def _words(c):
    e, r = c.emu, c.rng
    retv = [r.getrandbits(32), r.getrandbits(32)]
    k = [0]

    def slot114(em, rr):
        # first call of each run answers with retv[0], the second with retv[1]
        v = retv[k[0] % 2]
        k[0] += 1
        em.calllog.append(('114', em.reg('ecx') & 0xffffffff, tuple(em.arg32(i) for i in range(4))))   # constants: safe to log
        em.ret(eax=v, argbytes=16)

    vt = e.fake_vtable('rm_4a2f90', 0x46, {0x114: slot114})
    rm = e.alloc(0x40, 4)
    e.w32(rm, vt)
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    return [e.alloc(0x10, 4)]          # thiscall: ECX is unused by the body


S(0x59e610, 'pop the count while the top entry is not below the argument (name GUESS)', 'thiscall', None, gen=_pop,
  note='batch4021')
S(0x4a2f90, 'two word globals from render-manager slot 0x114 (name GUESS)', 'thiscall', None, gen=_words, note='batch4021')
