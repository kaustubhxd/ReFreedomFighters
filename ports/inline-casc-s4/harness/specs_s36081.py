"""specs_s36081.py - cascade s4 batch 36081: 0x630dd0 (run-length statistics over a symbol array)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g630dd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([-1, 0, 1, 2, 3, 5, 8, 12, 20, 40, 129, 137, 142, 150])
    pal = r.choice([[0, 1], [0, 3, 7], [0, 1, 2, 3, 4, 5], [2, 3], [0], [5]])
    stay = r.choice([0.3, 0.7, 0.9, 0.97]) if n < 100 else 1.0
    mode = r.random() < 0.3
    if mode:
        k = r.choice([9, 10, 11, 137, 138, 139])
        n = k + r.choice([1, 1, 2, 5])
    cnt = max(n + 2, 2)
    p = e.alloc(4 * cnt + 8, 4)
    syms = []
    cur = r.choice(pal)
    for i in range(cnt):
        if mode:
            cur = 3 if i == 0 or i > k else 0
        elif r.random() > stay:
            cur = r.choice(pal)
        syms.append(cur)
        e.wbytes(p + 4 * i, bytes(r.getrandbits(8) for _ in range(2)) + cur.to_bytes(2, 'little'))
    a = e.alloc(0xc00, 4)
    e.wbytes(a, bytes(r.getrandbits(8) for _ in range(0xc00)))
    return [a, p, n & 0xffffffff]


S(0x630dd0, 'GUESS run-length statistics over a symbol array', 'cdecl', None, ret=None, gen=_g630dd0, note='batch36081')
