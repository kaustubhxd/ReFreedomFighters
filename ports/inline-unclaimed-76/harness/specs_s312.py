"""specs_s312.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 312: 0x61cbe0, recursive cdecl emitter (plain ret).
The table at this+0x1e8 holds 7-dword records in a random tree (no cycles, depth <= 3). Leaves (kind 4) carry a heap C string."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _emit(c):
    e = c.emu
    rng = c.rng
    nodes = []

    def mk(depth):
        i = len(nodes)
        nodes.append(None)
        kind = rng.choice([0, 1, 2, 4, 4, 7])
        r1 = rng.getrandbits(32)
        if kind == 4:
            s = ''.join(rng.choice('abcdefgh') if rng.random() < 0.7 else chr(rng.randrange(1, 32)) for _ in range(rng.randrange(0, 7)))
            nodes[i] = [kind, r1, e.cstr(s), rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]
        else:
            cnt = rng.randrange(0, 4) if depth < 3 else 0
            kids = [mk(depth + 1) for _ in range(cnt)]
            first = kids[0] if kids else rng.getrandbits(32)
            nxt = [kids[k + 1] if k + 1 < cnt else 0 for k in range(cnt)]
            for k, kid in enumerate(kids):
                nodes[kid][6] = nxt[k]          # sibling is dword 6 of the record
            nodes[i] = [kind, r1, rng.getrandbits(32), first, rng.getrandbits(32), cnt, 0]
        return i
    mk(0)
    tab = _rnd(c, 28 * len(nodes))
    for i, rec in enumerate(nodes):
        for k, v in enumerate(rec):
            e.w32(tab + 28 * i + 4 * k, v)
    self_ = _rnd(c, 0x200)
    e.w32(self_ + 0x1e8, tab)
    out = _rnd(c, 0x14)
    buf = _rnd(c, 4096)
    cur = _rnd(c, 4096)
    pbase = _rnd(c, 4)
    e.w32(pbase, buf)
    pcur = _rnd(c, 4)
    e.w32(pcur, cur)
    return [self_, rng.randrange(len(nodes)), out, pbase, pcur]


S(0x61cbe0, 'emit61cbe0 (GUESS)', 'cdecl', None, ret=None, gen=_emit, note='batch312; plain ret; recursive')
