"""specs_s1037.py - unclaimed-04 batch 37 (docs/20-unclaimed-04.md): 0x495af0 (thiscall, three stack arguments a1, a2, a3; ret 0xc).
a2+0x54 selects the code c (a read through two pointers, or 0x200002); r = 0x4daf20(c, a2+0x3c) (fastcall; hooked by address
with a recording stub); then 0x495950 (thiscall on this+0x1c, five stack arguments a1, a2, a3, r, 8; ret 0x14; hooked by address)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def h4daf20(em, r):
        em.calllog.append(('4daf20', 0, 0, (em.reg('ecx'), em.reg('edx'))))
        em.ret(eax=r4, argbytes=0)

    def h495950(em, r):
        em.calllog.append(('495950', 0, em.reg('ecx'), tuple(em.arg32(i) for i in range(5))))
        em.ret(eax=0, argbytes=0x14)

    r4 = c.rng.getrandbits(32)
    c.emu.hook(0x4daf20, h4daf20)
    c.emu.hook(0x495950, h495950)


def _args(c):
    self_o = _rnd(c, 0x100)
    O = _rnd(c, 0x100)
    c.emu.w32(self_o + 0x1c, O)
    a2 = _rnd(c, 0x100)
    if c.rng.random() < 0.6:
        p1 = _rnd(c, 0x40)
        p2 = _rnd(c, 0x40)
        c.emu.w32(p1 + 0xc, p2)
        c.emu.w32(a2 + 0x54, p1)
    else:
        c.emu.w32(a2 + 0x54, 0)
    a1 = c.rng.getrandbits(32)
    a3 = c.rng.getrandbits(32)
    return [self_o, a1, a2, a3]


S(0x495af0, 'unknown::pass_through_4daf20_495950 (unknown) thiscall', 'thiscall', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 37; 0x4daf20 and 0x495950 hooked by address (GUESS)')
