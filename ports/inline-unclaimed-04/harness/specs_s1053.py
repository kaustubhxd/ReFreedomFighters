"""specs_s1053.py - unclaimed-04 batch 53 (docs/20-unclaimed-04.md): 0x62a870 (cdecl, four arguments, returns 0 or 1).
GUESS: expat checkPiTarget. The three bytes come mostly from x/X, m/M, l/L (with some other letters); the span is 3 in most
cases and sometimes 0 to 6 or negative. The token cell is pre-filled with a random dword."""
from pilot import S


def _args(c):
    e = c.emu
    e.alloc(0x10, 4)
    b = bytearray()
    for lo in b'xml':
        r = c.rng.random()
        if r < 0.45:
            b.append(lo)
        elif r < 0.85:
            b.append(lo - 0x20)
        else:
            b.append(c.rng.choice([c.rng.randrange(0, 256), lo + 1, lo ^ 0x20 ^ 1]))
    b += bytes(c.rng.getrandbits(8) for _ in range(5))
    ptr = e.alloc(0x10, 4)
    e.wbytes(ptr, bytes(b))
    span = 3 if c.rng.random() < 0.75 else c.rng.choice([0, 1, 2, 4, 5, 6, -1, -3, 0x103])
    cell = e.alloc(0x10, 4)
    e.w32(cell, c.rng.getrandbits(32))
    return [c.rng.getrandbits(32), ptr, (ptr + span) & 0xffffffff, cell]


S(0x62a870, 'unknown::expat_checkPiTarget (GUESS) cdecl', 'cdecl', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 53; expat checkPiTarget, one-byte encoding (GUESS)')
