"""specs_s67509.py - cascade s6 batch 67509 (0x63a1a0, fastcall(flag, comp, lo, hi, pixels, out) ret 0x10). Endpoints lo / hi are signed ints (including negatives and large values,
so the arithmetic shifts matter); the palette builder 0x6383a0 (fastcall flag, palette pointer + two stack pointers, ret 8) is a hook that logs both expanded endpoints by content and writes
a random 16-dword palette (some entries huge so squared distances overflow); pixels are 16 x 0x10 bytes with random components and a zero / non-zero word at +0xc."""
from pilot import S
from recruits_util import clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g63a1a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    big = r.random() < 0.3

    def val():
        if big and r.random() < 0.4:
            return r.choice([0x7fffffff, 0x80000000, 0x10000, 0x20000, 0xffff0000, r.getrandbits(32)])
        return r.choice([0, 1, 31, 32, 255, 0xfffffff0, r.randrange(0, 256), r.randrange(-300, 300) & 0xffffffff])
    pal = [val() for _ in range(16)]

    def h(em, res_):
        x, y = em.arg32(0), em.arg32(1)
        em.calllog.append(('6383a0', em.reg('ecx'), em.rbytes(x, 12), em.rbytes(y, 12)))
        em.wbytes(em.reg('edx'), b''.join((v & 0xffffffff).to_bytes(4, 'little') for v in pal))
        em.ret(eax=0, argbytes=8)
    e.hook(0x6383a0, h)
    lo = e.alloc(0x10, 4)
    hi = e.alloc(0x10, 4)
    for p in (lo, hi):
        for i in range(3):
            _w(c, p + 4 * i, val())
    pix = e.alloc(0x100, 4)
    for i in range(16):
        for k in range(3):
            _w(c, pix + 0x10 * i + 4 * k, val())
        _w(c, pix + 0x10 * i + 0xc, r.choice([0, 1, 1, 0xff]))
    out = e.alloc(0x40, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [r.choice([0, 1, 2]), r.choice([0, 1, 2]), lo, hi, pix, out]


S(0x63a1a0, 'GUESS select_indices', 'fastcall', None, ret=None, gen=_g63a1a0, note='batch67509')
