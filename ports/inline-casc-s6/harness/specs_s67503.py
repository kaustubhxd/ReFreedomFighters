"""specs_s67503.py - cascade s6 batch 67503 (0x6316e0, stdcall(adler, buf, len) ret 0xc, zlib adler32). Pure memory function: random buffers with lengths around the 16-byte unroll
and the 5552-byte block limit (0, 1, 15, 16, 17, 31, 5551, 5552, 5553, 11104, 11105) and random ones, null buffers, random starting checksums (halves up to 0xffff) and values near
the modulus; bytes include 0xff runs."""
from pilot import S


def _g6316e0(c):
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 15, 16, 17, 31, 32, 100, 5551, 5552, 5553, 11104, 11105, r.randrange(0, 300), r.randrange(0, 6000)])
    buf = e.alloc(n + 16, 1)
    mode = r.random()
    if mode < 0.2:
        data = bytes([0xff]) * (n + 16)
    else:
        data = bytes(r.getrandbits(8) for _ in range(n + 16))
    e.wbytes(buf, data)
    ad = r.choice([1, 0, 0xffffffff, 0xfff0fff0, 0x0001fff1, r.getrandbits(32) & 0xffffffff])
    if r.random() < 0.5:
        ad = (r.randrange(0, 65521) << 16) | r.randrange(0, 65521)
    return [ad, 0 if r.random() < 0.08 else buf, n]


S(0x6316e0, 'GUESS adler32', 'stdcall', None, ret='eax', gen=_g6316e0, note='batch67503')
