"""specs_s196.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x51b060 calls exe helper 0x5003d0 twice and child slot 0x390."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pair(c):
    e = c.emu
    data = _rnd(c, 0x1000)
    inner = _rnd(c, 0x200)
    e.w32(inner, data)
    e.w32(inner + 8, 0x100)
    table = _rnd(c, 0x40)
    e.w32(table, inner)
    base = c.rng.randrange(0, 0x80)
    e.w32(table + 4, base)
    e.w32(table + 8, 0x10)
    # the nonzero test reads entries base+1 (index 1) and base+2 (mutant index 2); make each zero half the time
    for k in (1, 2):
        if c.rng.random() < 0.5:
            e.w32(data + (base + k) * 8, 0)
    arg = _rnd(c, 0x40)
    e.w32(arg + 4, table)
    r = c.rng.getrandbits(32)
    vt = e.logging_vtable('child51b0', 0xe5, impl={0x390: lambda em, a: (r, None)}, argwords={0x390: 2})
    child = _rnd(c, 0x40)
    e.w32(child, vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, child)
    return [self_, arg]


S(0x51b060, 'pairForward (GUESS)', 'thiscall', None, ret='eax', gen=_pair, note='batch196; two exe 0x5003d0 calls; ret 4')
