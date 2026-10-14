"""specs_s1022.py - unclaimed-10, batch 18: CMAINCAMERACONTROL::CopyEventDataBlock (0x4fc0d0). Thiscall, one argument (DBREAD),
ret 4. Readers 0x4e5e60 (A) and 0x4e5e40 (B) take ecx = DBREAD and no stack arguments. They are hooked with fixed results chosen
in gen (A and B differ), so both runs see the same values. Nothing else is called."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cp(c):
    e = c.emu
    va = c.rng.getrandbits(32)
    vb = c.rng.getrandbits(32)
    e.hook(0x4e5e60, lambda em, r: em.ret(eax=va, argbytes=0))
    e.hook(0x4e5e40, lambda em, r: em.ret(eax=vb, argbytes=0))
    return [_rnd(c, 0x800), _rnd(c, 0x40)]


S(0x4fc0d0, 'CMAINCAMERACONTROL::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_cp,
  note='unclaimed-10 batch 18; readers 0x4e5e60/0x4e5e40 hooked with fixed results')
