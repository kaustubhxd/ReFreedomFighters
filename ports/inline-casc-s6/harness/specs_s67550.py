"""specs_s67550.py - cascade s6 batch 67550 (0x401220, cdecl(vi, vc, op), returns eax). The packet {data ptr, byte count, b_o_s at +8} holds a type byte (1 / 3 / 5 / other) followed by "vorbis"
(sometimes corrupted) and padding, sometimes truncated to a few bytes (the real bit reader 0x410bc0 / 0x410de0 / 0x401320 runs unhooked); 0x401350 / 0x401430 / 0x401510 (cdecl, 2 args) are hooks that
log the reader state; vi[8] (rate) and vc[0xc] (vendor) are zero or not; op may be null."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g401220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x401350, 0x401430, 0x401510):
        hook_rec(c, a, 2, pop=0, ret=lambda em, k: r.choice([0, 0, 7, 0xfffffff0]), stackmark=(1,))
    vi = rnd(c, 0x40)
    _w(c, vi + 8, r.choice([0, 0, 44100, 1]))
    vc = rnd(c, 0x40)
    _w(c, vc + 0xc, r.choice([0, rnd(c, 0x10)]))
    typ = r.choice([1, 1, 3, 3, 5, 5, 7, 0, 0x81])
    magic = b'vorbis'
    if r.random() < 0.15:
        b = bytearray(magic)
        b[r.randrange(6)] ^= 0x20
        magic = bytes(b)
    data = bytes([typ]) + magic + bytes(r.getrandbits(8) for _ in range(9))
    ln = r.choice([len(data), len(data), 7, 5, 0, 3])
    buf = e.alloc(0x20, 4)
    e.wbytes(buf, data + bytes(0x20 - len(data)))
    op = rnd(c, 0x20)
    _w(c, op, buf)
    _w(c, op + 4, ln)
    _w(c, op + 8, r.choice([0, 1, 1]))
    return [vi, vc, op if r.random() < 0.93 else 0]


S(0x401220, 'GUESS vorbis_synthesis_headerin', 'cdecl', None, ret='eax', gen=_g401220, note='batch67550')
