"""specs_u69_55.py - area 69, group 55 (slice 8): 0x4cc500, a UTF-8 style decoder (no callees). The first byte is drawn from each lead-byte class,
so the one-byte, two-byte ... and seven-or-more-ones paths are all reached; the object holds the char* (its position)."""
from pilot import S
from ckit import rnd


def _dec(c):
    r = c.rng
    o = rnd(c, 0x10)
    buf = rnd(c, 0x20)
    cls = r.choice(['zero', 'ascii', 'cont', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight'])
    lead = {'zero': 0x00, 'ascii': r.randrange(1, 0x80), 'cont': r.randrange(0x80, 0xc0),
            'two': r.randrange(0xc0, 0xe0), 'three': r.randrange(0xe0, 0xf0), 'four': r.randrange(0xf0, 0xf8),
            'five': r.randrange(0xf8, 0xfc), 'six': r.randrange(0xfc, 0xfe), 'seven': 0xfe, 'eight': 0xff}[cls]
    c.emu.wbytes(buf, bytes([lead]) + bytes(r.getrandbits(8) for _ in range(0x1f)))
    c.emu.w32(o, buf)
    return [o]


S(0x4cc500, 'nextUtf4cc500 (GetNextUTC4Char, thiscall, no args, returns the value)', 'thiscall', None, ret='eax', gen=_dec, note='u69 group 55; no callees')
