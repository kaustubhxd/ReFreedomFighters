"""specs_s67517.py - cascade s6 batch 67517 (0x49cbb0, thiscall(bucket, value, remove) ret 0xc, returns al). Buckets (head slots at [this+0x1d]) hold chains of 16-byte nodes
{v0, v1, v2, next} (0..4 nodes, values from a small set so matches, shifts across nodes and empty-node unlinking all happen); the node pool release 0x4e6bf0 (this+4) is a recording hook."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g49cbb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e6bf0, 1, this=True)
    vals = [1, 2, 3, 4, 5]
    heads = e.alloc(0x20, 4)
    e.wbytes(heads, bytes(0x20))
    for b in range(4):
        n = r.choice([0, 1, 1, 2, 3, 4])
        nodes = [rnd(c, 0x10) for _ in range(n)]
        for i, nd in enumerate(nodes):
            for s in range(3):
                _w(c, nd + 4 * s, r.choice(vals + [0, 0]))
            _w(c, nd + 12, nodes[i + 1] if i + 1 < n else 0)
        _w(c, heads + 4 * b, nodes[0] if nodes else 0)
    t = rnd(c, 0x40)
    _w(c, t + 0x1d, heads)
    return [t, r.randrange(0, 4), r.choice(vals + [0, 9]), r.choice([0, 1, 1, 1, 0x100])]


S(0x49cbb0, 'GUESS remove_from_bucket', 'thiscall', None, ret='al', gen=_g49cbb0, note='batch67517')
