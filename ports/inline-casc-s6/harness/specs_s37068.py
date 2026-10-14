"""specs_s37068.py - cascade s6 batch 37068 (0x5ff140, two-chain walker with u16 vectors). ctx holds a u32 key table (+0xe0) and a u16 link table (+0xf8) whose links only go
forward (so chains end at 0xffff). vecA's growth callee 0x5ff0a0 is a hook that raises its capacity (its data block is big enough); vecB grows through the hooked alloc 0x41e290
(returns spec blocks) and free 0x41e2c0."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5ff140(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nn = 0x20
    keys = e.alloc(4 * nn, 4)
    links = e.alloc(2 * nn, 2)
    kv = [r.randrange(0, 6) if r.random() < 0.6 else r.getrandbits(32) for _ in range(nn)]
    for i in range(nn):
        _w(c, keys + 4 * i, kv[i])
        nxt = i + r.choice([1, 1, 1, 2, 3, 5]) if r.random() < 0.88 else 0xffff
        _w(c, links + 2 * i, nxt if nxt < nn else 0xffff, 2)
    ctx = rnd(c, 0x110)
    _w(c, ctx + 0xe0, keys)
    _w(c, ctx + 0xf8, links)
    va = e.alloc(0x10, 4)
    cap = r.choice([0, 1, 2, 3, 4, 8])
    size = r.randrange(0, cap + 1) if cap else 0
    dbuf = e.alloc(0x200, 2)
    e.wbytes(dbuf, bytes(r.getrandbits(8) for _ in range(0x200)))
    for i in range(size):
        _w(c, dbuf + 2 * i, r.randrange(0, nn), 2)
    _w(c, va, dbuf)
    _w(c, va + 4, cap)
    _w(c, va + 8, size)

    def grow(em, k):
        cur = int.from_bytes(em.rbytes(va + 4, 4), 'little')
        _w(c, va + 4, cur * 2 + 2)
    hook_rec(c, 0x5ff0a0, 0, pop=0, this=True, side=grow)
    vb = e.alloc(0x10, 4)
    capb = r.choice([0, 1, 2, 3, 4, 8])
    sizeb = r.randrange(0, capb + 1) if capb else 0
    bb = e.alloc(0x100, 2)
    e.wbytes(bb, bytes(r.getrandbits(8) for _ in range(0x100)))
    _w(c, vb, bb)
    _w(c, vb + 4, capb)
    _w(c, vb + 8, sizeb)
    blocks = [e.alloc(0x100, 2) for _ in range(8)]
    for b in blocks:
        e.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x100)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[k % 8])
    hook_rec(c, 0x41e2c0, 1, pop=0)
    ta = r.choice(kv + [0x12345678]) if r.random() < 0.5 else 0x7777777
    tb = r.choice(kv + [0x12345678]) if r.random() < 0.5 else 0x7778888
    sa = r.choice([0xffff, 0xffff, 0, 1, 2, 5, 9, r.randrange(nn)])
    sb = r.choice([0xffff, 0, 1, 2, 3, 6, 10, r.randrange(nn)])
    return [va, vb, ctx, ta, tb, sb | (r.getrandbits(16) << 16), sa | (r.getrandbits(16) << 16)]


S(0x5ff140, 'GUESS chain_walk', 'stdcall', None, ret='al', gen=_g5ff140, note='batch37068')
