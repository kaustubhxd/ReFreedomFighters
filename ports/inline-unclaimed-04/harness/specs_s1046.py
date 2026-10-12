"""specs_s1046.py - unclaimed-04 batch 46 (docs/20-unclaimed-04.md): 0x497670 (thiscall, one stack argument, ret 4).
The argument is an object pointer (its +0x3c flag bit 0x8000000 is kept clear: the other path reads address 0 in the exe, so
it is outside the contract). The index comes from two magic-number divisions; the table at this+0x5d is 4096 dwords, and this+0x28
is a count from 64 to 2000 (the second division is non-zero from 64 on) (out-of-table reads are not part of the contract)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _args(c):
    o = _rnd(c, 0x100)
    P = _rnd(c, 0x20)
    arg = _rnd(c, 0x100)
    # x = arg - [P+4] is kept small, so the index stays inside the table (the magic divisions are then small)
    c.emu.w32(P + 4, (arg - c.rng.randrange(0, 200)) & 0xffffffff)
    c.emu.w32(o + 0x14, P)
    c.emu.w32(o + 0x28, c.rng.randrange(64, 2000))  # below 64 the second division is always 0
    table = _rnd(c, 0x4000)
    c.emu.w32(o + 0x5d, table)
    c.emu.w32(arg + 0x3c, c.rng.getrandbits(32) & ~0x8000000 & 0xffffffff)
    return [o, arg]


S(0x497670, 'unknown::magic_div7_index_table (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 46; pure leaf; the flagged path faults in the exe (outside the contract)')
