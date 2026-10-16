"""specs_s5776.py - unclaimed-57, batch 76: 0x5c2f90 (GUESS name unnamed_5c2f90). Thiscall, no stack args, plain ret. The object's
+4 is a per-case object (null in about one case in seven: the function returns early). The table at +0x14 has a count at +0x2c0
(0 to 4 entries of 14 bytes; flags at +0 and +1, pointers at -8 and -4). The helper 0x5b0b70 (one argument, ECX = this+4) is a logging
stub that returns the argument's low two bits (so both results occur); 0x5c2c10 (one argument: the index; ECX = this) is a logging
stub that writes nothing. Both are owned by other areas. The argument values come from the table, so they are stable across runs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c2f90(c):
    e = c.emu
    o_obj = _rnd(c, 0x40)

    def h_b70(em, r):
        a = em.arg32(0)
        tag = 'O' if em.reg('ecx') == o_obj else 'other'
        em.calllog.append(('b70', 0, tag, (a,)))
        em.ret(eax=a & 3, argbytes=4)

    def h_c10(em, r):
        tag = 'O' if em.reg('ecx') == self_obj else 'other'
        em.calllog.append(('c2c10', 0, tag, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    e.hook(0x5b0b70, h_b70)
    e.hook(0x5c2c10, h_c10)
    self_obj = _rnd(c, 0x400)
    n = c.rng.randrange(0, 5)
    e.w32(self_obj + 4, 0 if c.rng.random() < 1 / 7 else o_obj)
    e.w32(self_obj + 0x2c0, n)
    for i in range(4):
        ent = self_obj + 0x14 + 0xe * i
        e.w32(ent - 8, c.rng.getrandbits(32))
        e.w32(ent - 4, c.rng.getrandbits(32))
        e.wbytes(ent, bytes([c.rng.getrandbits(1), c.rng.getrandbits(1)]))
    return [self_obj]


S(0x5c2f90, 'unnamed_5c2f90 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c2f90,
  note='unclaimed-57 batch 76; helpers 0x5b0b70 (returns arg low bits) and 0x5c2c10 (logs) hooked; table of 0 to 4 entries')
