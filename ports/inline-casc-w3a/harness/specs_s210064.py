"""specs_s210064.py - Sonnet-w3a: 0x53b1b0. Consistent doubly linked list (head at this+0xe, next +0xc, prev +0x10, packed) enumerated by the container (this+4, slots 0x4c / 0x64 / 0x44); cached pointers at this+0x12 / +0x16 point at random nodes or null; the key is that of a random node (or absent)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g53b1b0(c):
    clear_hooks(c)
    e = c.emu
    n = c.rng.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x20) for _ in range(n)]
    keys = [c.rng.choice([_r(c), 5, 6]) for _ in range(n)]
    for i, nd in enumerate(nodes):
        _ub(c, nd + 4, keys[i])
        _ub(c, nd + 0xc, nodes[i + 1] if i + 1 < n else 0)
        _ub(c, nd + 0x10, nodes[i - 1] if i else 0)
    if n and c.rng.random() < 0.3:
        sl = c.rng.choice(nodes)
        _ub(c, sl + 0xc, sl)  # self-referencing next
    seq = nodes + [0]
    cont = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), stackmark=(0,), this=True),
                         0x64: pystub(c, 1, ret=lambda emu, k: seq[min(k, len(seq) - 1)], stackmark=(0,), this=True),
                         0x44: pystub(c, 1, ret=_r(c), stackmark=(0,), this=True)}, nslots=0x30)
    s = rnd(c, 0x30)
    _ub(c, s + 4, 0 if c.rng.random() < 0.1 else cont)
    _ub(c, s + 0xe, nodes[0] if n else 0)
    pool = nodes + [0]
    _ub(c, s + 0x12, c.rng.choice(pool)); _ub(c, s + 0x16, c.rng.choice(pool))
    key = c.rng.choice(keys + [7, 5]) if n else 5
    return [s, key]


S(0x53b1b0, 'unlink_entry_by_key', 'thiscall', None, ret=None, gen=g53b1b0, note='batch210064')
