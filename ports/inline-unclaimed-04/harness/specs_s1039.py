"""specs_s1039.py - unclaimed-04 batch 39 (docs/20-unclaimed-04.md): 0x64b430 (thiscall, one stack argument key, ret 4).
For i < count (dword +0x10089), the entry E = array[i] (array at +0x1008d) leads to node2 = (E+0xc)+0xc; the match is
node2+8 == key, which returns this+0x10075; otherwise 0. Each chain is built per case; the key matches one of them about half
the time."""
from pilot import S


def _args(c):
    o = c.emu.alloc(0x10100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x10100)))
    n = c.rng.randrange(0, 5)
    c.emu.w32(o + 0x10089, n)
    vals = []
    for i in range(n):
        E = c.emu.alloc(0x20, 4)
        N = c.emu.alloc(0x20, 4)
        M = c.emu.alloc(0x20, 4)
        v = c.rng.getrandbits(32)
        vals.append(v)
        c.emu.w32(E + 0xc, N)
        c.emu.w32(N + 0xc, M)
        c.emu.w32(M + 8, v)
        c.emu.w32(o + 0x1008d + 4 * i, E)
    if vals and c.rng.random() < 0.5:
        key = c.rng.choice(vals)
    else:
        key = c.rng.getrandbits(32)
    return [o, key]


S(0x64b430, 'unknown::find_chain_key (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 39; pure leaf over a pointer array (GUESS)')
