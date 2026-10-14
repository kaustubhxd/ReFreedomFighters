"""specs_s37098.py - cascade s6 batch 37098 (0x62fc30, cdecl(s), zlib _tr_align). Bit buffer (+0x16b0 u16, +0x16b4 valid 0..16), pending buffer at +8 / +0x14 and last_eob_len
(+0x16ac). bi_flush (0x630120) is a hook that really flushes (whole short at 16 bits, a byte at >= 8), so the second-block condition sees realistic bit counts."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g62fc30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x16c0)
    pb = e.alloc(0x100, 4)
    e.wbytes(pb, bytes(r.getrandbits(8) for _ in range(0x100)))
    _w(c, s + 8, pb)
    _w(c, s + 0x14, r.randrange(0, 0x30))
    valid = r.choice([0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, r.randrange(0, 17)])
    _w(c, s + 0x16b4, valid)
    _w(c, s + 0x16b0, r.getrandbits(16), 2)
    _w(c, s + 0x16ac, r.choice([-5, -1, 0, 1, 2, 5, 6, 7, 8, 9, 10, 11, 12, 16, r.randrange(-3, 20)]))

    def flush(em, k):
        sp = em.arg32(0)
        v = int.from_bytes(em.rbytes(sp + 0x16b4, 4), 'little', signed=True)
        bf = int.from_bytes(em.rbytes(sp + 0x16b0, 2), 'little')
        pend = int.from_bytes(em.rbytes(sp + 0x14, 4), 'little')
        buf = int.from_bytes(em.rbytes(sp + 8, 4), 'little')
        if v == 16:
            em.wbytes(buf + pend, bytes([bf & 0xff, bf >> 8]))
            _w(c, sp + 0x14, pend + 2)
            _w(c, sp + 0x16b0, 0, 2)
            _w(c, sp + 0x16b4, 0)
        elif v >= 8:
            em.wbytes(buf + pend, bytes([bf & 0xff]))
            _w(c, sp + 0x14, pend + 1)
            _w(c, sp + 0x16b0, bf >> 8, 2)
            _w(c, sp + 0x16b4, v - 8)
    hook_rec(c, 0x630120, 1, pop=0, side=flush)
    return [s]


S(0x62fc30, 'GUESS tr_align', 'cdecl', None, ret=None, gen=_g62fc30, note='batch37098')
