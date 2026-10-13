"""specs_s2744.py - unclaimed-27 batch 46: fifteen splice functions (cdecl, void, no arguments), the same template as batch 45. Each uses
its own pair of globals (see docs/20-unclaimed-27.md). The shared globals 0x7003bc and 0x7003c0 start at random values. No callees."""
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


S(0x6704e0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e6024, 0x6e6028), reg_values=True, note='residue-6 batch 46')
S(0x670620, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e60cc, 0x6e60d0), reg_values=True, note='residue-6 batch 46')
S(0x670760, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e62a0, 0x6e62a4), reg_values=True, note='residue-6 batch 46')
S(0x6708a0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e63cc, 0x6e63d0), reg_values=True, note='residue-6 batch 46')
S(0x6709e0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e64e4, 0x6e64e8), reg_values=True, note='residue-6 batch 46')
S(0x670b20, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e658c, 0x6e6590), reg_values=True, note='residue-6 batch 46')
S(0x670c60, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e6708, 0x6e670c), reg_values=True, note='residue-6 batch 46')
S(0x670da0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e6c1c, 0x6e6c20), reg_values=True, note='residue-6 batch 46')
S(0x670ee0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6e689c, 0x6e68a0), reg_values=True, note='residue-6 batch 46')
S(0x674fe0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6ef704, 0x6ef708), reg_values=True, note='residue-6 batch 46')
S(0x675120, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6ef7e4, 0x6ef7e8), reg_values=True, note='residue-6 batch 46')
S(0x675260, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6ef8e4, 0x6ef8e8), reg_values=True, note='residue-6 batch 46')
S(0x6753a0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6ef9c4, 0x6ef9c8), reg_values=True, note='residue-6 batch 46')
S(0x6754e0, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6efaa4, 0x6efaa8), reg_values=True, note='residue-6 batch 46')
S(0x675620, 'GUESS splice (cdecl)', 'cdecl', None, ret=None, gen=_gen(0x6efb84, 0x6efb88), reg_values=True, note='residue-6 batch 46')
