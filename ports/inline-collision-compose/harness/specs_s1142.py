"""specs_s1142.py - collision thread batch 1142 (GUESS name): 0x463030, a table lookup. The table is a block of 0x400 bytes: [+4]
is negative in most cases (bit 0x40000000 half of those), [+0xc] is the count 0..6, the entries are 0x20 bytes apart and each has
a key, a flags dword (the top two bits pick the value and the offset; the low 30 bits are the stride 0x20), and three data
dwords. The key is one of the entry keys or a value that is not present. The out pointer is null in a quarter of the cases."""
from pilot import S, F


def _look(c):
    e, r = c.emu, c.rng
    T = e.alloc(0x400, 16)
    e.wbytes(T, bytes(r.getrandbits(8) for _ in range(0x400)))
    f = r.getrandbits(31) | 0x80000000                        # negative
    if r.random() < 0.5:
        f |= 0x40000000
    else:
        f &= ~0x40000000
    if r.random() < 0.1:
        f = 0 if r.random() < 0.5 else r.getrandbits(31)      # non-negative (zero half of them): the lookup returns 0 at once
    e.w32(T + 4, f & 0xffffffff)
    v = r.randrange(0, 8)
    e.w32(T + 0x10, v)                                        # the block-length word (used when bit 0x40000000 is set)
    n = r.randrange(0, 7)
    e.w32(T + 0xc, n)
    keys = [r.randrange(1, 40) for _ in range(n)]
    base = T + ((v + 5) * 4 if (f & 0x40000000) else 0x10)    # the same base the callee computes
    for i in range(n):
        ent = base + 0x20 * i
        e.w32(ent, keys[i])
        fl = (r.getrandbits(2) << 30) | 0x20
        e.w32(ent + 4, fl)
        e.w32(ent + 8, r.getrandbits(32))
        e.w32(ent + 0xc, r.getrandbits(32))
        e.w32(ent + 0x10, r.getrandbits(32))
    key = r.choice(keys) if keys and r.random() < 0.7 else r.randrange(40, 80)
    out = e.alloc(8, 4) if r.random() < 0.75 else 0
    return [T, key, out]


S(0x463030, 'table lookup: key match returns entry + offset and writes a value to out (name GUESS)', 'thiscall', None,
  ret='eax', gen=_look, note='batch1142')
