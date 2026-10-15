"""specs_s67531.py - cascade s6 batch 67531 (0x54e450, thiscall() plain ret, returns al). The object (0x100 bytes, vtable slot 0xc = ready check, bool) holds small counters at the odd
offsets +0x14 / 0x18 / 0x33 / 0x37 / 0x3b / 0x3f / 0x43 / 0x47 / 0x5f / 0x67 and flag bytes +0x57 / 0x5a; the source object at +0x4b has slot 0xc (4 args, returns the byte count: small non-negative,
sometimes negative which fires the assert hook 0x7003b0)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g54e450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nr = [r.choice([0, 1, 2, 5, 9, 20, 40, -1, -5]) for _ in range(2)]
    src = obj(c, 0x1d0, {0xc: pystub(c, 4, this=True, ret=lambda em, k: nr[k % 2] & 0xffffffff)})
    t = obj(c, 0x100, {0xc: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100, 0x101]))})
    for off, v in ((0x14, r.randrange(0, 6)), (0x18, r.randrange(0, 6)), (0x33, r.randrange(0, 8)), (0x37, r.randrange(0, 8)), (0x3b, r.randrange(0, 4)),
                   (0x3f, r.randrange(0, 30)), (0x43, r.randrange(0, 20)), (0x47, r.randrange(0, 6)), (0x5f, r.randrange(0, 4)), (0x67, r.randrange(0, 20)), (0x4b, src), (0x4, r.getrandbits(32))):
        _w(c, t + off, v)
    _w(c, t + 0x57, r.choice([0, 0, 1]), 1)
    return [t]


S(0x54e450, 'GUESS ring_reader_step', 'thiscall', None, ret='al', gen=_g54e450, note='batch67531')
