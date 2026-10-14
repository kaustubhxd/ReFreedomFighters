"""specs_s853.py - area 50, batch 853: 0x4e5a10 (name GUESS "FindNamedField"), thiscall, four stack args (ret 0x10), bool.
Nothing is stood in: the child lookup 0x45e420, the node data start 0x4e5140 and the name match 0x4cc780 run as exe code on
a zero-filled node that the spec lays out (children with a key at +0, a size at +4 (flag kind in the top two bits) and a
name or an element array at the field offset). The engine logger (0x700390) is installed for the failed element search.
Children: keys 4,5,6,7,8,0xb,0xd,0xf and mostly 0xe (its element array holds a skip count, a key and a value), 0xa entries
(the marked ones), and a few other keys. Every element skip count is at most the number of 0xa entries, so the list walk
ends."""
from pilot import S
from anim_common import only_hooks, install_logger, install_crt_str, rnd


def _zero(c, n):
    a = c.emu.alloc(n, 8)
    c.emu.wbytes(a, bytes(n))
    return a


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_logger(c, nargs=2)
    install_crt_str(c)

    key = r.choice([0x12345678, 0x9, 0xa, 0x4, 0x2b, 0x1e])     # the key argument (an element's +4 may match it)
    alpha = 'ab'
    pat = ''.join(r.choice(['a', 'b', '*', 'ab', '*a', 'b*']) for _ in range(r.randint(1, 2)))
    patb = pat.encode() + b'\x00'
    pattern = _zero(c, 32)
    e.wbytes(pattern, patb)

    node = _zero(c, 0x400)
    if r.random() < 0.5:
        e.w32(node + 4, 0x80000000)                        # negative flags, no 0x40000000: children at +0x10
        base = node + 0x10
    else:
        e.w32(node + 4, 0xc0000000)                        # the 0x40000000 form: children at node + ([node+0x10]+5)*4
        e.w32(node + 0x10, 0)                              # which is node + 0x14 for a zero count word
        base = node + 0x14
    keys_fixed = [4, 5, 6, 7, 8, 0xb, 0xd]
    keys = list(keys_fixed)
    if r.random() < 0.8:
        keys.append(0xf)
    have_e = r.random() < 0.85
    if have_e:
        keys.append(0xe)
    n_a = r.randint(1, 3)
    keys += [0xa] * n_a
    extra = [k for k in (0x1, 0x2, 0x3, 0x9, 0x10, 0x11) if r.random() < 0.5]
    keys += extra
    r.shuffle(keys)
    N = len(keys)
    e.w32(node + 0xc, N)

    def name(a, text):
        e.wbytes(a, text.encode()[:0x0f] + b'\x00')

    ea = []                                                 # element arrays to fill
    cur = base                                              # the children, one after another
    for idx, k in enumerate(keys):
        e.w32(cur, k)
        if k == 0xe:
            cnt = r.randint(0, 4)
            kind = r.choice([0x0, 0x40000000, 0x80000000, 0xc0000000])
            if kind == 0:
                size = 16 + 12 * cnt                        # the element array starts at +8; the count is (size-8)/12 = cnt
                e.w32(cur + 4, size)
                ea.append((cur, cnt, 8))
            else:
                size = 0x10 + 12 * cnt                      # the element array starts at +0x10 (the offset word)
                e.w32(cur + 4, kind | size)
                e.w32(cur + 8, 0x10)
                ea.append((cur, cnt, 0x10))
        else:
            size = 0x20
            kind = r.choice([0x0, 0x40000000, 0x80000000, 0xc0000000])
            e.w32(cur + 4, kind | size)
            if kind == 0:
                name(cur + 8, ''.join(r.choice(alpha) for _ in range(r.randint(1, 4))))
            else:
                e.w32(cur + 8, 0x10)
                name(cur + 0x10, ''.join(r.choice(alpha) for _ in range(r.randint(1, 4))))
        cur += size
    # the element arrays of the 0xe entries: skip counts (0..min(2, n_a)), keys, values
    for base, cnt, eoff in ea:
        for j in range(cnt):
            el = base + eoff + 12 * j
            e.w32(el, r.randint(0, min(2, n_a)))
            e.w32(el + 4, key if r.random() < 0.5 else r.getrandbits(32) | 0x1000)
            e.w32(el + 8, r.randint(0, 9))
        if eoff == 8:                                        # slack after the last element (the entry is 8 bytes longer)
            e.w32(base + 8 + 12 * cnt + 4, key if r.random() < 0.5 else 0x1000)
    out = rnd(c, 8)
    self = rnd(c, 0x40)
    return [self, out, pattern, key, node]


S(0x4e5a10, 'FindNamedField (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch853')
