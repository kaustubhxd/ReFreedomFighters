"""specs_s3409.py - area 73 batch 9 (residue 12): ZActorIf::addMethodDefinitions (0x508680). The list argument has its flag byte
at +0xc (85% set). The count at 0x701048 is 0..0x37, so the full-table path (slot +0x44 on this and the assert) runs in some
cases. The tail 0x505a00 is a logged thiscall with one argument; it also logs the table contents and the count, because the
checker compares values of globals only through what the code logs or what a hook sees."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _addmethods(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o, e.logging_vtable('actorif', 0x48 // 4 + 1, impl={0x44: lambda em, a: (0, None)}, argwords={0x44: 1}))
    lst = _rnd(c, 0x40)
    e.wbytes(lst + 0xc, bytes([1 if c.rng.random() < 0.85 else 0]))
    e.w32(0x701048, c.rng.randint(0, 0x37))

    def tail(em, r):
        n = em.r32(0x701048)
        table = tuple(em.r32(0x701050 + 4 * i) for i in range(min(n, 0x35)))
        em.calllog.append(('505a00', 0, em.reg('ecx'), (em.arg32(0), n) + table))
        em.ret(argbytes=4)

    e.hook(0x505a00, tail)

    def assert_fn(em, r):
        em.calllog.append(('assert7003b0', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))
    return [self_o, lst]


S(0x508680, 'ZActorIf::addMethodDefinitions (unknown) thiscall', 'thiscall', None, ret=None, gen=_addmethods,
  note='area 73 batch 9; 53 table adds at 0x701050 (count 0x701048, limit 0x35); tail 0x505a00')
