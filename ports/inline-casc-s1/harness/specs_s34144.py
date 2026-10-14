"""specs_s34144.py - 0x5fcc40: header h (this points to a cell holding h), root at the unaligned h+1 (0 in a tenth), a random binary tree of 1..6 nodes (left +5, right +9, string begin +0xd, end +0x11, all unaligned) with short strings over a small alphabet in mixed case; key {begin, end} of the same kind; _strnicmp import stubbed in Python (case-insensitive compare of at most n bytes, logs the strings and n)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def w(a, v):
        e.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))

    def mkstr():
        s = bytes(r.choice(b'abAB') for _ in range(r.choice([0, 1, 2, 3, 4])))
        p = rnd(c, 0x10)
        e.wbytes(p, s + b'\0')
        return p, p + len(s)
    n = 0 if r.random() < 0.1 else r.randrange(1, 7)
    hdr = rnd(c, 0x20)
    nodes = [rnd(c, 0x30) for _ in range(n)]
    left, right = {}, {}
    for i in range(1, n):
        cur = 0
        while True:
            d = left if r.random() < 0.5 else right
            if cur in d:
                cur = d[cur]
            else:
                d[cur] = i
                break
    for i in range(n):
        b, en = mkstr()
        w(nodes[i] + 5, nodes[left[i]] if i in left else 0)
        w(nodes[i] + 9, nodes[right[i]] if i in right else 0)
        w(nodes[i] + 0xd, b)
        w(nodes[i] + 0x11, en)
    w(hdr + 1, nodes[0] if n else 0)
    this = rnd(c, 0x10)
    e.w32(this, hdr)
    kb, ke = mkstr()
    key = rnd(c, 0x10)
    e.w32(key, kb)
    e.w32(key + 4, ke)
    out = rnd(c, 0x10)

    def sti(em, res_):
        a, b, k = em.arg32(0), em.arg32(1), em.arg32(2)
        sa = bytes(em.rbytes(a, k)) if k else b''
        sb = bytes(em.rbytes(b, k)) if k else b''
        em.calllog.append(('_strnicmp', sa, sb, k))
        la, lb = sa.lower(), sb.lower()
        res = 0 if la == lb else (0xffffffff if la < lb else 1)
        em.ret(eax=res, argbytes=0)
    e.stub_import('_strnicmp', sti)
    return [this, out, key]


S(0x5fcc40, 'GUESS lower bound in a string tree', 'thiscall', None, ret='eax', gen=_g, note='batch34144')
