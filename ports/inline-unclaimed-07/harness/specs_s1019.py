"""specs_s1019.py - unclaimed-07 batch 19 (residue-07): ZFFHeroIf::addMethodDefinitions (0x55f6b0).
The list argument has the flag byte at +0xc (set 85% of cases). The global count at 0x7140c8 is 0..0x32 + 2, so the
full-table path (slot +0x44 on this, and the assert at 0x7003b0) runs in some cases. The tail 0x505a00 is a logged thiscall
with one argument. The table writes land in the exe's data, which is restored and compared each case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _addmethods(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o, e.logging_vtable('heroif', 0x48 // 4 + 1, impl={0x44: lambda em, a: (0, None)}, argwords={0x44: 1}))
    lst = _rnd(c, 0x40)
    e.wbytes(lst + 0xc, bytes([1 if c.rng.random() < 0.85 else 0]))
    e.w32(0x7140c8, c.rng.randint(0, 0x34))

    def tail(em, r):
        # the harness compares only which .data bytes a run changed, not their values, so the table contents and the
        # count are logged here (the tail runs at the end of every path)
        n = em.r32(0x7140c8)
        table = tuple(em.r32(0x7140d0 + 4 * i) for i in range(min(n, 0x32)))
        em.calllog.append(('505a00', 0, em.reg('ecx'), (em.arg32(0), n) + table))
        em.ret(argbytes=4)

    e.hook(0x505a00, tail)

    def assert_fn(em, r):
        em.calllog.append(('assert7003b0', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))
    return [self_o, lst]


S(0x55f6b0, 'ZFFHeroIf::addMethodDefinitions (unknown) thiscall', 'thiscall', None, ret=None, gen=_addmethods,
  note='unclaimed-07 batch 19; six table adds at 0x7140d0 (count 0x7140c8); full-table path; tail 0x505a00')
