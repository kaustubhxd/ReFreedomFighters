"""specs_s1024.py - unclaimed-04 batch 25 (docs/20-unclaimed-04.md): 0x44e970 (thiscall, five stack arguments, ret 0x14).
It stores vtable 0x680ce4 at this and tail-jumps to 0x43ea20 (thiscall, ecx = this, the same five arguments). The
target is hooked by address with a logging stub that pops 0x14 (the arity of 0x43ea20 from its first ret, GUESS)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def h43ea20(em, r):
        em.calllog.append(('43ea20', 0, em.reg('ecx'), tuple(em.arg32(i) for i in range(5))))
        em.ret(eax=0, argbytes=0x14)

    c.emu.hook(0x43ea20, h43ea20)


def _args(c):
    o = _rnd(c, 0x100)
    return [o] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x44e970, 'unknown::set_vtable_680ce4_tail_43ea20 (unknown) thiscall', 'thiscall', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 25; five stack arguments (tail target ret 0x14, GUESS); 0x43ea20 hooked')
