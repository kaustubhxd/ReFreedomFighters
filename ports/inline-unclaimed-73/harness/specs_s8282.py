"""specs_s8282.py - residue 6 batch 82 (GUESS name). FUN_00454620 (thiscall, zero arguments: the only direct caller, 0x43dcb8,
pushes none): [this] = 0x6820b8; then tail-jump to 0x43ea20 with the same zero arguments (hooked by address, logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h(em, r):
        em.calllog.append(('43ea20', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)
    e.hook(0x43ea20, h)
    return [_rnd(c, 0x100)]


S(0x454620, 'GUESS FUN_00454620 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='residue 6 batch 82; [this]=0x6820b8; jmp 0x43ea20 (zero args, hooked)')
