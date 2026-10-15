"""specs_s37122.py - cascade s6 batch 37122 (0x4d19c0, thiscall(flag) ret 4, returns eax). Child chain (+0x24 / +0x30, slot 0x10 returns sizes incl. huge ones), second list
(+0x18, value +0x10, next +8), old header pointer (+0xc) and the allocator / release hooks (0x41e290 returns spec blocks, 0x634273 recording). The flag argument has a low
byte that is zero or non-zero and random upper bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4d19c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [e.alloc(0x80, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x80)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: pool[k % 2])
    hook_rec(c, 0x634273, 2, pop=0)
    t = rnd(c, 0x60)
    kids = []
    for _ in range(r.choice([0, 0, 1, 2, 3])):
        k = obj(c, 0x40, {0x10: pystub(c, 1, this=True, ret=lambda em, k2: r.choice([0, 4, 0x10, 0x3ffffff0, 0x7ffffffc, 0xfffffff0, r.randrange(0, 0x40) * 4]))})
        kids.append(k)
    for i, k in enumerate(kids):
        _w(c, k + 0x30, kids[i + 1] if i + 1 < len(kids) else 0)
    _w(c, t + 0x24, kids[0] if kids else 0)
    nodes = [rnd(c, 0x20) for _ in range(r.choice([0, 0, 1, 2, 3]))]
    for i, nd in enumerate(nodes):
        _w(c, nd + 8, nodes[i + 1] if i + 1 < len(nodes) else 0)
        _w(c, nd + 0x10, r.choice([0, 1, 3, 4, 0x20, 0x3ffffff0, r.randrange(0, 0x40)]))
    _w(c, t + 0x18, nodes[0] if nodes else 0)
    _w(c, t + 0x20, r.getrandbits(32))
    _w(c, t + 0xc, r.choice([0, pool[1]]))
    flag = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    return [t, flag]


S(0x4d19c0, 'GUESS compute_header', 'thiscall', None, ret='eax', gen=_g4d19c0, note='batch37122')
