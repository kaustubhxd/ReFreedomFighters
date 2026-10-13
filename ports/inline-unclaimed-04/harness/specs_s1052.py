"""specs_s1052.py - unclaimed-04 batch 52 (docs/20-unclaimed-04.md): 0x622cb0 (cdecl, five arguments, leaves &to in eax).
The source is a 0x80-byte block heavy in UTF-8 continuation bytes (0x80-0xbf); the destination span is often shorter than the
source span so the cut-back loop runs. Some cases have reversed spans (end before start) or overlapping buffers."""
from pilot import S


def _rbytes(c, n):
    out = bytearray()
    for _ in range(n):
        r = c.rng.random()
        if r < 0.5:
            out.append(c.rng.randrange(0x80, 0xc0))       # continuation byte
        elif r < 0.7:
            out.append(c.rng.randrange(0xc0, 0x100))      # lead byte
        else:
            out.append(c.rng.randrange(0, 0x80))          # ASCII
    return bytes(out)


def _args(c):
    e = c.emu
    e.alloc(0x40, 4)
    src = e.alloc(0x100, 4)
    e.wbytes(src, _rbytes(c, 0x100))
    e.alloc(0x40, 4)
    dst = e.alloc(0x100, 4)
    e.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    e.alloc(0x40, 4)
    from_ = src + c.rng.randrange(0, 0x40)
    flen = c.rng.choice([c.rng.randrange(0, 0x40), c.rng.randrange(0, 8), -c.rng.randrange(1, 0x20)])
    if c.rng.random() < 0.1:
        to = from_ + c.rng.randrange(-8, 9)                 # overlapping source and destination
    else:
        to = dst + c.rng.randrange(0, 0x40)
    tlen = c.rng.choice([c.rng.randrange(0, 0x40), max(flen - c.rng.randrange(0, 6), 0), -c.rng.randrange(1, 0x20)])
    cell = e.alloc(0x10, 4)
    e.w32(cell, from_)
    e.w32(cell + 8, to)
    return [c.rng.getrandbits(32), cell, (from_ + flen) & 0xffffffff, cell + 8, (to + tlen) & 0xffffffff]


S(0x622cb0, 'unknown::utf8_passthrough_copy (unknown) cdecl', 'cdecl', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 52; UTF-8 codecvt-style copy (GUESS)')
