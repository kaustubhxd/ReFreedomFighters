"""specs_s12.py - inline session batch 12 (Haiku, overnight): 0x45dc60, 0x5df750, 0x485d30, 0x4d1c00."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x45dc60 thiscall: (this, arg). Flags drawn so the low nibble is 1 about a third of the time.
def _flag(c):
    r = c.rng
    o = _rnd(c, 0x40)
    c.emu.w32(o + 0x14, r.choice([0, 1, 3, 0x11, 0xf1, 0x10, 0x101, r.getrandbits(32)]))
    return [o, r.choice([0, 1, 0x100, 0x101, 0x2, r.getrandbits(32)])]


S(0x45dc60, 'flagUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_flag,
  note='batch12; only the low byte of the argument is tested')


# 0x5df750 thiscall: (this, a1, a2, a3, a4). Object of 0x40 bytes.
S(0x5df750, 'initFour (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x40)] + [c.rng.getrandbits(32) for _ in range(4)],
  note='batch12; constructor, vtable 0x6b7338')


# 0x485d30 thiscall: (this, a1..a5). Object of 0x40 bytes.
S(0x485d30, 'initFive (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x40)] + [c.rng.getrandbits(32) for _ in range(5)],
  note='batch12; constructor, vtable 0x68cbe4')


# 0x4d1c00 thiscall: (this, target). List of 0..6 nodes of 0x40 bytes; next pointer at +0x30; the target is a node
# (usually) or an unrelated value, so both the found and not-found returns occur.
def _find(c):
    r = c.rng
    o = _rnd(c, 0x40)
    n = r.randint(0, 6)
    nodes = [_rnd(c, 0x40) for _ in range(n)]
    for i, node in enumerate(nodes):
        c.emu.w32(node + 0x30, nodes[i + 1] if i + 1 < n else 0)
    c.emu.w32(o + 0x24, nodes[0] if nodes else 0)
    target = r.choice(nodes) if nodes and r.random() < 0.7 else r.getrandbits(32)
    return [o, target]


S(0x4d1c00, 'findIndex (unknown) thiscall', 'thiscall', None, ret='eax', gen=_find,
  note='batch12; returns the node index or -1')
