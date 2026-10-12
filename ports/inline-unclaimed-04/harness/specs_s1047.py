"""specs_s1047.py - unclaimed-04 batch 47 (docs/20-unclaimed-04.md): 0x625c30 (cdecl, table (edx) and string (eax), returns a pointer).
Pairs (c, 0) advance by two while the class table[c + 0x4c] is 9, 10 or 21; a non-zero second byte or another class returns the
current pair. The table is a 0x200-byte block with random classes (the values 9, 10 and 21 come up often); strings are built from
pairs, sometimes with a broken pair."""
from pilot import S


def _args(c):
    tab = c.emu.alloc(0x200, 4)
    tb = bytes(c.rng.choice([0, 9, 10, 21, c.rng.randrange(0, 256)]) for _ in range(0x200))
    c.emu.wbytes(tab, tb)
    n = c.rng.randrange(0, 8)
    s = bytearray()
    for _ in range(n):
        ch = c.rng.randrange(0, 0xb4)
        s += bytes([ch, 0])
    if c.rng.random() < 0.4:
        s += bytes([c.rng.randrange(1, 256), c.rng.randrange(1, 256)])
    s += bytes([1, 1])  # a non-zero pair ends the scan inside the buffer
    sb = c.emu.alloc(len(s) + 4, 4)
    c.emu.wbytes(sb, bytes(s))
    return [tab, sb]


S(0x625c30, 'unknown::pair_scanner_class_table (unknown) cdecl', 'cdecl', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 47; re-attempt of the parked row; table data read from the image (GUESS on the class meanings)')
