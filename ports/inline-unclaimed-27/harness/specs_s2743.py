"""specs_s2743.py - unclaimed-27 batch 45: three splice functions (cdecl, void, no arguments) at 0x670120, 0x670260, 0x6703a0. Each uses its
own pair of globals (see docs/20-unclaimed-27.md). The shared globals 0x7003bc and 0x7003c0 start at random values. No callees."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(cg, ag):
    def f(c):
        cobj = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
        aobj = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
        c.emu.w32(cg, cobj)
        c.emu.w32(ag, aobj)
        c.emu.w32(0x7003bc, c.rng.getrandbits(32))
        c.emu.w32(0x7003c0, c.rng.getrandbits(32))
        c.emu.mu.ctl_flush_tb()
        return []
    return f


S(0x670120, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e5b00, 0x6e5b04), reg_values=True, note='residue-6 batch 45')
S(0x670260, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e5b9c, 0x6e5ba0), reg_values=True, note='residue-6 batch 45')
S(0x6703a0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e5df0, 0x6e5df4), reg_values=True, note='residue-6 batch 45')
