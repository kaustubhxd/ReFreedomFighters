"""specs_s37009.py - cascade s6 batch 37009: 0x613690 (luminance difference image, fastcall(dst, src, w, h, fmt) ret 0xc). Source and destination random-filled."""
from pilot import S
from recruits_util import rnd


def _g613690(c):
    r = c.rng
    e = c.emu
    w = r.choice([0, 1, 2, 3, 4, 5, 7, 9])
    h = r.choice([0, 1, 2, 3, 4, 6])
    fmt = r.choice([0x3c, 0x3d, 0x3e, 0x3e, 0x3c, 0x3d, 0x3b, 0x3f, 0, 0x40])
    src = rnd(c, 4 * w * h + 8)
    if r.random() < 0.3:
        for i in range(w * h):
            e.wbytes(src + 4 * i + r.randrange(4), bytes([r.choice([0, 0xff, 0x80])]))
    dst = rnd(c, 4 * w * h + 16)
    return [dst, src, w, h, fmt]


S(0x613690, 'GUESS luminance difference image', 'fastcall', None, ret=None, gen=_g613690, note='batch37009')
