"""specs_s67505.py - cascade s6 batch 67505 (0x4377e0, thiscall(key, flag) ret 8). Owner link at +0xc (tag 3 or tag 1) -> block with world pointer at +0x11; the world holds the counter
(+0x1210) and a 10-byte bucket table (+0x1344). 0x4382e0 returns spec nodes (hook); the list object at +0x15 has slot 4; counters +0x42 / +0x19 start equal or not."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4377e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    W = rnd(c, 0x1400)
    key = r.choice([0, 1, 2, 3, 5])
    cnt = r.choice([key, key + 1, key + 2, 0, 0xffffffff, 7])
    _w(c, W + 0x1210, cnt)
    tbl = e.alloc(0x80, 4)
    e.wbytes(tbl, bytes(r.getrandbits(8) for _ in range(0x80)))
    _w(c, W + 0x1344, tbl)
    X = rnd(c, 0x30)
    _w(c, X + 0x11, W)
    if r.random() < 0.5:
        link = X + 4
        _w(c, link, 3)
    else:
        link = rnd(c, 0x20)
        _w(c, link, 1)
        _w(c, link + 8, X + 4)
    pool = [rnd(c, 0x20) for _ in range(2)]
    hook_rec(c, 0x4382e0, 1, pop=0, ret=lambda em, k: pool[k % 2]) if False else None
    hook_rec(c, 0x4382e0, 0, this=True, ret=lambda em, k: pool[k % 2])
    flag = r.choice([0, 1, 7, 0x107])
    _w(c, tbl + 10 * key + 8, r.choice([flag & 0xff, 0, 1, 9]), 1)
    me = obj(c, 0x60, {})
    _w(c, me + 0xc, link)
    lst = obj(c, 0x20, {0x4: pystub(c, 1, this=True)})
    _w(c, me + 0x15, lst)
    a = r.choice([0, 1, 5])
    _w(c, me + 0x19, a)
    _w(c, me + 0x42, r.choice([a, a, a - 1 if a else 0, 3]))
    _w(c, me + 0x32, r.getrandbits(8), 1)
    return [me, key, flag]


S(0x4377e0, 'GUESS register_in_bucket', 'thiscall', None, ret=None, gen=_g4377e0, note='batch67505')
