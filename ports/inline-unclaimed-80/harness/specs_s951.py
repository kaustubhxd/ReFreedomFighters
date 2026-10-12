"""specs_s951.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x43ac30. The global table at 0x6e48c0 (16-byte stride) has k in 0..3
nonzero entries (not the sentinel 0x6e49c0), then the sentinel at index k, and the value v (0..2) at 0x6e48b8 + 16k. The object's
dword at +0x1344 points to a 0x200-byte base holding two flag states at base+0x32+10v and base+0x3c+10v. Each state gets a flag byte
(zero 30%) and a list of 1..3 nodes whose items are as in specs_s950 (item dword zero 50%, byte +0x10 zero 40%). The global 0x70039c
points to a buffer whose +0x1c dword is random. The table search always finds the sentinel (never the not-found path)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _state(c, st):
    c.emu.wbytes(st + 8, bytes([0 if c.rng.random() < 0.3 else c.rng.randint(1, 255)]))
    nodes = []
    if c.rng.random() >= 0.2:
        for _ in range(c.rng.randint(1, 3)):
            nodes.append(_rnd(c, 0x20))
    for i, nd in enumerate(nodes):
        b = _rnd(c, 0x80)
        c.emu.wbytes(b + 0x10, bytes([0 if c.rng.random() < 0.4 else c.rng.randint(1, 255)]))
        pp = b + 4
        if c.rng.random() < 0.5:
            c.emu.w32(pp, 0)
        c.emu.w32(nd, pp)
        c.emu.w32(nd + 5, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(st + 4, nodes[0] if nodes else 0)


def _fn(c):
    g = _rnd(c, 0x40)
    c.emu.w32(0x70039c, g)
    k = c.rng.randint(0, 3)
    for i in range(k):
        c.emu.w32(0x6e48c0 + 16 * i, c.rng.getrandbits(31) | 1)
    c.emu.w32(0x6e48c0 + 16 * k, 0x6e49c0)
    v = c.rng.randint(0, 2)
    c.emu.w32(0x6e48b8 + 16 * k, v)
    base = _rnd(c, 0x200)
    _state(c, base + 0x32 + 10 * v)
    _state(c, base + 0x3c + 10 * v)
    self_o = _rnd(c, 0x1400)
    c.emu.w32(self_o + 0x1344, base)
    return [self_o]


S(0x43ac30, 'two flag walks through the table (unknown) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; table search at 0x6e48c0, v at 0x6e48b8+16i, two 0x43aca0 walks on base+0x32+10v and base+0x3c+10v')
