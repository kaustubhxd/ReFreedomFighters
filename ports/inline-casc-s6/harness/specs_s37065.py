"""specs_s37065.py - cascade s6 batch 37065 (0x430fc0, find-or-insert in a tree keyed by byte ranges). The tree is a random binary search tree of spec nodes ordered by the
range compare (tiny alphabet so prefix/length ties occur), with parent/left/right links; the header node's left is the leftmost, its right the rightmost. The insert callee 0x4300c0 is a recording hook."""
import functools
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _cmp(a, b):
    n = min(len(a), len(b))
    for i in range(n):
        if a[i] != b[i]:
            return -1 if a[i] < b[i] else 1
    return -1 if len(a) < len(b) else (1 if len(a) > len(b) else 0)


def _g430fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    alpha = r.choice([1, 2, 3, 256])
    keys = []
    for _ in range(r.choice([0, 0, 1, 2, 3, 5, 8, 12])):
        k = bytes(r.randrange(alpha) for _ in range(r.choice([0, 1, 2, 3, 4, 5, 6, 8, 9])))
        if k not in keys:
            keys.append(k)
    keys.sort(key=functools.cmp_to_key(_cmp))
    pool = e.alloc(0x200, 4)
    pos = [0]

    def blob(b):
        a = pool + pos[0]
        e.wbytes(a, b + bytes(r.getrandbits(8) for _ in range(3)))
        pos[0] += len(b) + 4
        return a
    hdr = e.alloc(0x20, 4)
    e.wbytes(hdr, bytes(r.getrandbits(8) for _ in range(0x20)))
    nodes = [e.alloc(0x20, 4) for _ in keys]
    for n_ in nodes:
        e.wbytes(n_, bytes(r.getrandbits(8) for _ in range(0x20)))
    ba = [blob(k) for k in keys]

    def build(lo, hi, parent):
        if lo >= hi:
            return 0
        m = r.randrange(lo, hi)
        n_ = nodes[m]
        e.wbytes(n_, b'\x01' if r.random() < 0.5 else b'\x00')
        _w(c, n_ + 1, parent)
        _w(c, n_ + 0xd, ba[m])
        _w(c, n_ + 0x11, ba[m] + len(keys[m]))
        _w(c, n_ + 5, build(lo, m, n_))
        _w(c, n_ + 9, build(m + 1, hi, n_))
        return n_
    root = build(0, len(keys), hdr)
    e.wbytes(hdr, b'\x00')
    _w(c, hdr + 1, root)
    _w(c, hdr + 5, nodes[0] if keys else hdr)
    _w(c, hdr + 9, nodes[-1] if keys else hdr)
    self_ = e.alloc(0x10, 4)
    _w(c, self_, hdr)
    out = e.alloc(0x10, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x10)))
    mode = r.random()
    if keys and mode < 0.45:
        k = r.choice(keys)
    elif keys and mode < 0.7:
        k = r.choice(keys)
        k = k[:r.randrange(len(k) + 1)] + bytes(r.randrange(alpha) for _ in range(r.choice([0, 1, 2])))
    else:
        k = bytes(r.randrange(alpha) for _ in range(r.choice([0, 1, 2, 3, 4, 5, 6, 8, 9, 12])))
    kb = blob(k)
    pair = e.alloc(0x10, 4)
    _w(c, pair, kb)
    _w(c, pair + 4, kb + len(k))
    newit = e.alloc(0x10, 4)

    nv = r.getrandbits(32)
    _w(c, newit, nv)

    def ins(em, n):
        em.calllog.append(('ins', em.rbytes(em.arg32(0), 4)))
    hook_rec(c, 0x4300c0, 4, pop=16, this=True, nullflag=(0,), ret=newit, side=ins)
    return [self_, out, pair]


S(0x430fc0, 'GUESS tree find_or_insert', 'thiscall', None, ret=None, gen=_g430fc0, note='batch37065')
