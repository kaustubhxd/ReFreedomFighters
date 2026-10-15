"""specs_s67534.py - cascade s6 batch 67534 (0x430b70, thiscall(out, key) ret 8, returns out in eax). this points at a head node whose +1 dword is the root of a binary tree of string keys
(node +5 left, +9 right, +0xd begin, +0x11 end; unaligned dwords written byte-wise). The tree is a sorted BST over short strings (alphabet with high bytes, lengths 0..9 so both the dword and
byte compare paths run); the search key is an existing key, a perturbed one, a prefix / extension, or random. 0x42feb0 runs unhooked in both."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g430b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    alpha = bytes([0x61, 0x62, 0x63, 0x80, 0xff, 0x00, 0x41])
    keys = []
    for _ in range(r.choice([0, 1, 2, 3, 5, 8])):
        keys.append(bytes(r.choice(alpha) for _ in range(r.choice([0, 1, 2, 3, 4, 5, 6, 8, 9]))))
    sk = sorted(set(keys))
    if r.random() < 0.2:
        r.shuffle(sk)

    def mkstr(b):
        a = e.alloc(len(b) + 8, 1)
        e.wbytes(a, b + bytes(r.choice(alpha) for _ in range(8)))
        return a

    def build(lst):
        if not lst:
            return 0
        mid = r.randrange(len(lst)) if r.random() < 0.3 else len(lst) // 2
        n = rnd(c, 0x20)
        s = mkstr(lst[mid])
        _w(c, n + 0xd, s)
        _w(c, n + 0x11, s + len(lst[mid]))
        _w(c, n + 5, build(lst[:mid]))
        _w(c, n + 9, build(lst[mid + 1:]))
        return n
    root = build(sk)
    head = rnd(c, 0x20)
    _w(c, head + 1, root)
    cell = e.alloc(4, 4)
    e.w32(cell, head)
    pick = r.random()
    if sk and pick < 0.4:
        kb = r.choice(sk)
    elif sk and pick < 0.6:
        kb = r.choice(sk) + bytes([r.choice(alpha)])
    elif sk and pick < 0.8:
        b = r.choice(sk)
        kb = b[:max(0, len(b) - 1)]
    else:
        kb = bytes(r.choice(alpha) for _ in range(r.choice([0, 1, 3, 4, 5, 7])))
    ks = mkstr(kb)
    key = e.alloc(8, 4)
    e.w32(key, ks)
    e.w32(key + 4, ks + len(kb))
    out = e.alloc(4, 4)
    e.w32(out, 0)
    return [cell, out, key]


S(0x430b70, 'GUESS string_map_find', 'thiscall', None, ret='eax', gen=_g430b70, note='batch67534')
