"""specs_s66047.py - cascade s4 batch 66047: 0x431110 (lower-bound search in a binary tree keyed by byte strings)."""
from pilot import S
from recruits_util import clear_hooks


def _g431110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [b'', b'a', b'ab', b'abc', b'abcd', b'abcde', b'abce', b'b', b'abcdefgh', b'abcdefgi', b'\xff', b'\x80a', b'abd', b'a\0', b'a\0b', b'\0', b'ab\0', b'ab\0\0']
    pool = e.alloc(0x200, 8)
    off = [0]
    strs = {}

    def put(w):
        if w in strs:
            return strs[w]
        a = pool + off[0]
        e.wbytes(a, w + b'\xfe\x01\xfe\x01\xfe\x01\xfe\x01')
        off[0] += (len(w) + 8) & ~3
        strs[w] = (a, a + len(w))
        return strs[w]
    keys = sorted(set(r.sample(words, r.choice([0, 1, 2, 3, 5, 8]))))
    # build a balanced-ish BST from the sorted keys
    head = e.alloc(0x30, 8)

    def node(lo, hi):
        if lo >= hi:
            return 0
        mid = (lo + hi) // 2
        n = e.alloc(0x30, 8)
        b, en = put(keys[mid])
        e.w32(n + 0xd, b)
        e.w32(n + 0x11, en)
        e.w32(n + 5, node(lo, mid))
        e.w32(n + 9, node(mid + 1, hi))
        return n
    e.w32(head + 1, node(0, len(keys)))
    tp = e.alloc(8, 8)
    e.w32(tp, head)
    kw = r.choice(words + keys) if keys or True else b''
    kb, ke = put(kw)
    key = e.alloc(8, 8)
    e.w32(key, kb)
    e.w32(key + 4, ke)
    out = e.alloc(8, 8)
    e.w32(out, 0xdead)
    return [tp, out, key]


S(0x431110, 'GUESS lower-bound search in a byte-string tree', 'thiscall', None, ret=None, gen=_g431110, note='batch66047')
