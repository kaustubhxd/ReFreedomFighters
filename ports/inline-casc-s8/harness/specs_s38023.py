"""specs_s38023.py - cascade s8 batch 38023: 0x5c9f80. Stream object with recording read slots 0x40 / 0x48 / 0x50 / 0x68 / 0x6c / 0x74 that write a random value of a slot-specific width
(4, 4, 4, 1, 12, 24 bytes) through the destination pointer; the header check 0x4fb360 hooked (fails about 15% of the time, low byte only). Return is bool (AL)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5c9f80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    widths = {0x40: 4, 0x48: 4, 0x50: 4, 0x68: 1, 0x6c: 12, 0x74: 24}

    def wr(n):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(n)))
        return side
    stream = obj(c, 0x20, {off: pystub(c, 1, this=True, side=wr(n)) for off, n in widths.items()})
    me = rnd(c, 0x480)
    hook_rec(c, 0x4fb360, 1, this=True, pop=4, ret=lambda em, k: 0 if r.random() < 0.15 else r.choice([1, 0x101, 0xff01]))
    return [me, stream]


S(0x5c9f80, 'GUESS load settings block from stream', 'thiscall', None, ret='al', gen=_g5c9f80, note='batch38023')
