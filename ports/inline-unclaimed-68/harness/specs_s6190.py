"""specs_s6190.py - unclaimed-68 batch 19 (claim 18): CFFCoverList::Command (0x4a9e20). The table at +0x48 holds 10-byte records
(key word at +4, a handler pointer at +6); the handlers are stubs with thiscall cleanup (ret 4) that return a fixed value, so a
match makes the handler run and its result is compared. Counts 0..4; keys 0..3; the command is 0..3."""
from pilot import S
from engine_stubs import zero_obj


def _gen(c):
    o = zero_obj(c, 0x100)
    n = c.rng.randrange(0, 5)
    table = c.emu.alloc(max(10 * n, 10), 4)
    c.emu.wbytes(table, bytes(max(10 * n, 10)))
    for i in range(n):
        c.emu.wbytes(table + 10 * i + 4, bytes([c.rng.randrange(0, 4), 0]))
        val = c.rng.getrandbits(32)
        h = c.emu.stub_fn('CoverList handler %d' % i, (lambda v: (lambda em, r: (em.calllog.append(('handler', 0, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=v, argbytes=4))))(val))
        c.emu.w32(table + 10 * i + 6, h)
    c.emu.w32(o + 0x48, table)
    c.emu.w32(o + 0x4c, n)
    return [o, c.rng.randrange(0, 4), c.rng.getrandbits(32)]


S(0x4a9e20, 'CFFCoverList::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-68 batch 19; records of 10 bytes; handlers are stubs (ret 4)')
