"""specs_s210056.py - Sonnet-w3a: 0x603110. Random BST of 0..7 nodes with packed (unaligned) links: head+1 root, head+5 leftmost, head+9 rightmost; node +1 parent, +5 left, +9 right, +0x19 value; each value has optional sub-objects (slot 8 stub, a 0x2c-byte counter block)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g603110(c):
    clear_hooks(c)
    e = c.emu
    head = rnd(c, 0x20)
    n = c.rng.choice([0, 1, 2, 3, 4, 5, 7])
    ret8 = lambda emu, k: (emu.arg32(0) * 3 + 1) & 0xffff
    sub = obj(c, 0x40, {8: pystub(c, 1, ret=ret8, this=True)}, nslots=4)
    sub2 = obj(c, 0x40, {8: pystub(c, 1, ret=_r(c) & 0xffff, this=True)}, nslots=4)
    nodes = [rnd(c, 0x30) for _ in range(n)]
    L = {}; R = {}; P = {}
    root = None

    def insert(key, nd):
        nonlocal root
        if root is None:
            root = nd; P[nd] = head; return
        cur = root
        while True:
            if key < keys[cur]:
                if L.get(cur): cur = L[cur]
                else: L[cur] = nd; P[nd] = cur; return
            else:
                if R.get(cur): cur = R[cur]
                else: R[cur] = nd; P[nd] = cur; return
    keys = {nd: i + c.rng.random() for i, nd in enumerate(nodes)}
    for nd in sorted(nodes, key=lambda x: c.rng.random()):
        insert(keys[nd], nd)
    for nd in nodes:
        val = rnd(c, 0x30)
        _ub(c, val + 4, _r(c) & 0xffff); _ub(c, val + 8, _r(c) & 0xffffff)
        _ub(c, val + 0x1c, c.rng.choice([0, sub, sub2]))
        if c.rng.random() < 0.5:
            blk = rnd(c, 0x30); _ub(c, val + 0x24, blk)
        else:
            _ub(c, val + 0x24, 0)
        _ub(c, nd + 0x19, val)
        _ub(c, nd + 1, P[nd]); _ub(c, nd + 5, L.get(nd, 0)); _ub(c, nd + 9, R.get(nd, 0))
    if n:
        lm = root
        while L.get(lm): lm = L[lm]
        rm = root
        while R.get(rm): rm = R[rm]
        _ub(c, head + 1, root); _ub(c, head + 5, lm); _ub(c, head + 9, rm)
    else:
        _ub(c, head + 1, 0); _ub(c, head + 5, head); _ub(c, head + 9, head)
    s = rnd(c, 0x20); _ub(c, s + 1, head)
    return [s]


S(0x603110, 'tree_serialized_size', 'thiscall', None, ret='eax', gen=g603110, note='batch210056')
