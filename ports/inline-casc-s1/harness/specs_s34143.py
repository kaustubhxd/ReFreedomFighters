"""specs_s34143.py - 0x5f90a0: as specs_s34142 (_g5f9010) with the setup word at +0x82.
0x5fbf90: a random binary search tree of 0..6 nodes (unaligned parent +1, left +5, right +9, payload pointer +0x19; header with root at +1, leftmost +5, rightmost +9, children zero when absent); payload objects with a value at +0x172; key = payload+0x3c of a random node, or a random value (assert hook path); assert hook word a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
import specs_s34142 as m


def _g5f90a0(c):
    args = m._g5f9010(c)
    me = args[0]
    c.emu.wbytes(me + 0x82, c.rng.getrandbits(32).to_bytes(4, 'little'))
    return args


def _g5fbf90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def w(a, v):
        e.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    n = r.choice([0, 1, 2, 3, 4, 5, 6])
    hdr = rnd(c, 0x20)
    nodes = [rnd(c, 0x30) for _ in range(n)]
    pls = [rnd(c, 0x180) for _ in range(n)]
    left = {}
    right = {}
    parent = {}
    root = None
    # in-order position = key order; insert indices of a random permutation into a BST by rank
    order = list(range(n))
    r.shuffle(order)
    rank = {i: order[i] for i in range(n)}

    def ins(root, i):
        if root is None:
            return i
        cur = root
        while True:
            if rank[i] < rank[cur]:
                if cur in left:
                    cur = left[cur]
                else:
                    left[cur] = i
                    parent[i] = cur
                    return root
            else:
                if cur in right:
                    cur = right[cur]
                else:
                    right[cur] = i
                    parent[i] = cur
                    return root
    for i in range(n):
        root = ins(root, i)
    for i in range(n):
        w(nodes[i] + 1, nodes[parent[i]] if i in parent else hdr)
        w(nodes[i] + 5, nodes[left[i]] if i in left else 0)
        w(nodes[i] + 9, nodes[right[i]] if i in right else 0)
        w(nodes[i] + 0x19, pls[i])
        w(pls[i] + 0x172, r.getrandbits(32))
    if n:
        mn = min(range(n), key=lambda i: rank[i])
        mx = max(range(n), key=lambda i: rank[i])
        w(hdr + 1, nodes[root])
        w(hdr + 5, nodes[mn])
        w(hdr + 9, nodes[mx])
    else:
        w(hdr + 1, hdr)
        w(hdr + 5, hdr)
        w(hdr + 9, hdr)
    me = rnd(c, 0x10)
    w(me + 1, hdr)
    key = pls[r.randrange(n)] + 0x3c if n and r.random() < 0.85 else r.getrandbits(32)
    return [me, key]


S(0x5f90a0, 'GUESS push a ref-counted record B', 'thiscall', None, ret='eax', gen=_g5f90a0, note='batch34143')
S(0x5fbf90, 'GUESS find value in tree by key address', 'thiscall', None, ret='eax', gen=_g5fbf90, note='batch34143')
