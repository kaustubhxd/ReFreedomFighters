"""specs_s960.py - area 56 band, claims A22-A23.

A22 (0x5373d0): the global function pointer at 0x7003b0 is a GUESS recording stub (thiscall, no arguments; logs ecx); the argument
p is a heap dword (random). A23 (0x536350): this (0x5400 random bytes; +0x5302 random) has a fake vtable whose slot 0x1ec is a
GUESS recording stub (thiscall, one argument; logs ecx and the argument, returns a random dword); the argument is zero in one case
in five (the plain path). ret is None for A23 (the null path leaves eax undefined)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_a22(c):
    e = c.emu
    rng = c.rng

    def hg(e2, r):
        e2.calllog.append(('G7003b0', e2.reg('ecx')))
        e2.ret(argbytes=0)

    e.w32(0x7003b0, e._new_stub('global 7003b0', hg))
    p = _rnd(c, 0x10)
    e.w32(p, rng.getrandbits(32))
    return [_rnd(c, 0x40), p]


def _gen_a23(c):
    e = c.emu
    rng = c.rng

    def h1ec(e2, r):
        e2.calllog.append(('V1ec', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rv, argbytes=4)

    rv = rng.getrandbits(32)
    vt = e.fake_vtable('tail536350', 0x80, {0x1ec: h1ec})
    this = _rnd(c, 0x5400)
    e.w32(this, vt)
    e.w32(this + 0x5302, rng.getrandbits(32))
    a = 0 if rng.random() < 0.2 else rng.getrandbits(32)
    return [this, a]


S(0x5373d0, 'unnamed 0x5373d0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_a22,
  note='unclaimed-56 A22; 0x7003b0 global is a GUESS recording stub')
S(0x536350, 'unnamed 0x536350 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_a23,
  note='unclaimed-56 A23; vt slot 0x1ec is a GUESS recording stub; ret None (null path eax undefined)')
