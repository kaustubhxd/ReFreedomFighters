"""specs_s36070.py - cascade s4 batch 36070: 0x438b10 (find an entry by name), 0x42b1e0 (byte-range search)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _g438b10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    names = [b'', b'a', b'ab', b'abc', b'abd', b'b']

    def cstr(t):
        a = e.alloc(8, 4)
        e.wbytes(a, t + b'\0' + bytes(8 - len(t) - 1))
        return a
    elems = []
    empty = r.random() < 0.3
    for i in range(r.choice([0, 1, 2, 3])):
        el = rnd(c, 0x10)
        e.w32(el + 4, 0 if (r.random() < 0.2 or (empty and i == 0)) else cstr(r.choice(names)))
        if r.random() < 0.2:
            e.w32(el + 8, 0)
        elems.append(el)
    lst = reftab(c, elems)
    s = rnd(c, 0x40)
    e.w32(s + 0x19, 0 if r.random() < 0.1 else lst)
    return [s, 0 if r.random() < 0.1 else cstr(b'' if empty else r.choice(names))]


def _g42b1e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, 12])
    m = r.choice([0, 1, 1, 2, 2, 3])
    alpha = r.choice([b'ab', b'abc', b'a'])
    hay = e.alloc(16, 4)
    e.wbytes(hay, bytes(r.choice(alpha) for _ in range(12)) + bytes(4))
    pat = e.alloc(8, 4)
    e.wbytes(pat, bytes(r.choice(alpha) for _ in range(4)) + bytes(4))
    if n > 0 and m > 0 and r.random() < 0.5:
        k = r.randint(0, max(0, n - m))
        e.wbytes(hay + k, bytes(e.rbytes(pat, m)))
    return [hay, hay + n, pat, pat + m, r.getrandbits(32)]


S(0x438b10, 'GUESS find an entry by name', 'thiscall', None, ret='eax', gen=_g438b10, note='batch36070')
S(0x42b1e0, 'GUESS byte-range search', 'fastcall', None, ret='eax', gen=_g42b1e0, note='batch36070')
