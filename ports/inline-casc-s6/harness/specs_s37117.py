"""specs_s37117.py - cascade s6 batch 37117 (0x571720, thiscall(a, b, c) ret 0xc). The widget array at +0x1cc (cursor +0x230, limit +0x22c, some entries null) holds objects whose
slots 0x260 / 0x70 / 0xbc / 0x284 are recorders; slot 0x70 gets a stack vector whose content (12 bytes) is logged; the skip flag +0x1a3 and zero arguments are mixed in."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g571720(c):
    clear_hooks(c)
    r = c.rng

    def vec(em, k):
        em.calllog.append(('vec', em.rbytes(em.arg32(0), 12)))

    def mkw():
        return obj(c, 0x20, {0x260: pystub(c, 1, this=True), 0x70: pystub(c, 1, this=True, stackmark=(0,), side=vec),
                             0xbc: pystub(c, 1, this=True), 0x284: pystub(c, 1, this=True)})
    t = rnd(c, 0x240)
    _w(c, t + 0x1a3, r.choice([0, 0, 0, 1]), 1)
    limit = r.choice([0, 1, 2, 3, 4])
    _w(c, t + 0x22c, limit)
    _w(c, t + 0x230, r.choice([0, 0, 1, 2, 3]))
    for i in range(6):
        _w(c, t + 0x1cc + 4 * i, mkw() if r.random() < 0.8 else 0)
    args = [r.choice([0, r.getrandbits(32) | 1]) for _ in range(3)]
    return [t] + args


S(0x571720, 'GUESS place_widgets', 'thiscall', None, ret=None, gen=_g571720, note='batch37117')
