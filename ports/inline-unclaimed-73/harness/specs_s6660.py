"""specs_s6660.py - area 73 batch 66 (gap band, GUESS name). FUN_4e8770(A) (ret 4): T = [this+8], X = [A+8]. If X != T, returns
vtable +0x10 on this with X (logging stub, one argument). Otherwise e = [A]; while e != T and [e+8] == the previous node,
step to e's next (the walk ends when e == T or the back-link breaks); returns the final e. Chains are built per case with
back-links to A so both the walk and the break are reached."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    T = c.rng.getrandbits(32)
    o = _rnd(c, 0x40)
    e.w32(o + 8, T)
    r = c.rng.getrandbits(32)
    e.w32(o, e.logging_vtable('f8770', 0x40 // 4, impl={0x10: (lambda v: (lambda em, a: (v, None)))(r)},
                              argwords={0x10: 1}))
    A = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        e.w32(A + 8, T)
        k = c.rng.randint(0, 3)
        nodes = [_rnd(c, 0x40) for _ in range(k)]
        for i, nd in enumerate(nodes):
            e.w32(nd, nodes[i + 1] if i + 1 < k else T)
            e.w32(nd + 8, A if c.rng.random() < 0.6 else c.rng.getrandbits(32))
        e.w32(A, nodes[0] if k else T)
    else:
        e.w32(A + 8, c.rng.getrandbits(32))
        e.w32(A, c.rng.getrandbits(32))
    return [o, A]


S(0x4e8770, 'GUESS FUN_4e8770 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 66; X=[A+8] != [this+8] -> vt+0x10(X); else walk the chain from [A] while back-linked')
