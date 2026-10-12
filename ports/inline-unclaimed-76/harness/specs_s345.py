"""specs_s345.py - gap band, batch 345: 0x606ea0 (stdcall: a char* cell and a nonzero modulus) and 0x6204a0 (cdecl: a list head object).
The string holds letters (both cases), digits and high bytes. 0x6204a0's list nodes are random blocks whose first dword is the link."""
from pilot import S


def _hash_gen(c):
    e = c.emu
    rng = c.rng
    chars = bytes(rng.choice(b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_~\x80\xff') for _ in range(rng.randrange(0, 20)))
    s = e.alloc(len(chars) + 8, 4)
    e.wbytes(s, chars + b'\0' + rng.randbytes(7))
    cell = e.alloc(4, 4)
    e.w32(cell, s)
    return [cell, rng.randrange(1, 0x10000)]


def _rev_gen(c):
    e = c.emu
    rng = c.rng
    nodes = []
    for _ in range(rng.randrange(0, 4)):
        nodes.append(e.alloc(0x20, 4))
    for i, nd in enumerate(nodes):
        e.w32(nd, nodes[i + 1] if i + 1 < len(nodes) else 0)
    p = e.alloc(0x20, 4)
    e.wbytes(p, rng.randbytes(0x20))
    e.w32(p, nodes[0] if nodes else 0)
    e.w32(p + 4, nodes[rng.randrange(len(nodes))] if nodes and rng.random() < 0.3 else (0 if rng.random() < 0.5 else rng.getrandbits(32) & 0xfffffff0))
    return [p]


S(0x606ea0, 'hash606ea0 (GUESS)', 'stdcall', None, ret='eax', gen=_hash_gen, note='batch345; ret 8')
S(0x6204a0, 'reverse6204a0 (GUESS)', 'cdecl', None, ret=None, gen=_rev_gen, note='batch345; plain ret')
