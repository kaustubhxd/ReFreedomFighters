"""specs_s37055.py - cascade s6 batch 37055 (0x63e310). Pure memory free-list allocator state: bins at +0, node pool at +0x400 (12-byte nodes), counters at +0x3400/+0x3402,
shift at +0x3404; the dword before this is zero. Queries are built next to existing blocks (predecessor in the same or a lower bin, successor in its bin) or free-standing."""
from pilot import S


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g63e310(c):
    r = c.rng
    e = c.emu
    base = e.alloc(0x3480, 4)
    me = base + 8
    e.wbytes(base, bytes(0x3480))
    shift = r.choice([3, 4, 5])
    _w(c, me + 0x3404, shift)
    # blocks: disjoint ranges in 0..0x300
    blocks = []
    pos = r.randint(0, 20)
    for _ in range(r.choice([0, 1, 2, 3, 5])):
        pos += r.choice([0, 0, 3, 17, 40])
        ln = r.randint(4, 40)
        blocks.append((pos, ln))
        pos += ln
    bins = {}
    for i, (s, ln) in enumerate(blocks):
        nd = me + 0x400 + 12 * i
        b = s >> shift
        _w(c, nd, s)
        _w(c, nd + 4, ln)
        _w(c, nd + 8, bins.get(b, 0))
        bins[b] = nd
    for b, nd in bins.items():
        _w(c, me + 4 * b, nd)
    n = len(blocks)
    _w(c, me + 0x3400, n, 2)
    # free chain
    for i in range(n, n + 6):
        _w(c, me + 0x400 + 12 * i, i + 1 if i < n + 5 else 0xfffe, 2)
    _w(c, me + 0x3402, n, 2)
    # query
    mode = r.choice(['pred', 'succ', 'both', 'both', 'none', 'lower'])
    off = r.randint(0, 0x2c0)
    size = r.randint(1, 30)
    gaps = [i for i in range(len(blocks) - 1) if blocks[i + 1][0] - (blocks[i][0] + blocks[i][1]) > 0]
    if mode == 'both' and gaps:
        i = r.choice(gaps)
        off = blocks[i][0] + blocks[i][1]
        size = blocks[i + 1][0] - off
    elif blocks and mode in ('pred', 'lower', 'both'):
        s0, ln = r.choice(blocks)
        off = s0 + ln
    elif blocks and mode == 'succ':
        s2, _ = r.choice(blocks)
        if s2 > 1:
            off = r.randint(0, s2 - 1)
            size = s2 - off
    return [me, off, size]


S(0x63e310, 'GUESS free range into binned list', 'thiscall', None, ret=None, gen=_g63e310, note='batch37055')
