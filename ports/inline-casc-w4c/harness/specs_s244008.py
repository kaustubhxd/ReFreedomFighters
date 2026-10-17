"""specs_s244008.py - Sonnet-w4c batch 244008: two free-list block initialisers (stride 0x138 / 0x20)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _gen(stride):
    def g(c):
        clear_hooks(c)
        r = c.rng
        em = c.emu
        blk = rnd(c, 0x10 + 7 * stride + 0x40) if r.random() < 0.85 else 0
        n = r.choice([1, 2, 3, 4, 6])
        me = obj(c, 0x40, {0x30: pystub(c, 0, ret=blk, this=True), 0x28: pystub(c, 0, ret=n, this=True)})
        em.wbytes(me + 0x10, bytes([r.getrandbits(8)]))
        if r.random() < 0.6:
            ex = rnd(c, 0x20)
            other = ex if r.random() < 0.3 else rnd(c, 0x20)
            em.w32(ex + 0xc, other)
            em.w32(me + 8, ex)
        else:
            em.w32(me + 8, 0)
        return [me]
    return g


S(0x6155d0, 'GUESS init block (stride 0x138) and link into ring', 'thiscall', None, ret='al', gen=_gen(0x138), note='batch244008')
S(0x648d50, 'GUESS init block (stride 0x20) and link into ring', 'thiscall', None, ret='al', gen=_gen(0x20), note='batch244008')
