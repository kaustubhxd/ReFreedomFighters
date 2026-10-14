"""specs_s38017.py - cascade s8 batch 38017: 0x5a0be0. The stream object has recording read slots (0x50, 0x40, 0x68, 0x48, 0x4c, 0x6c) that write a random value of their width
through the destination pointer (the stack locals are stackmarked, the heap destinations recorded as pointers), slot 0x18 (2 args) fills 0x10 bytes; 0x479190 / 0x5a0b80 / 0x59d3a0 are
recording hooks; the engine table's +0x44 clock is random. Return is bool (AL)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5a0be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def wr(nbytes):
        def side(em, k):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(nbytes)))
        return side

    def fill16(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(16)))
    slots = {0x50: pystub(c, 1, this=True, stackmark=(0,), side=wr(1)),
             0x40: pystub(c, 1, this=True, stackmark=(0,), side=wr(4)),
             0x68: pystub(c, 1, this=True, stackmark=(0,), side=wr(1)),
             0x48: pystub(c, 1, this=True, stackmark=(0,), side=wr(2)),
             0x4c: pystub(c, 1, this=True, stackmark=(0,), side=wr(2)),
             0x6c: pystub(c, 1, this=True, stackmark=(0,), side=wr(2)),
             0x18: pystub(c, 2, this=True, stackmark=(0,), side=fill16)}
    stream = obj(c, 0x20, slots)
    so = sysobj(c, {})
    tb = e.r32(so + 0x9b)
    e.w32(tb + 0x44, r.getrandbits(32))
    me = rnd(c, 0x980)
    e.w32(me + 0x54, rnd(c, 0x20))
    hook_rec(c, 0x479190, 1, this=True, pop=4)
    hook_rec(c, 0x5a0b80, 1, this=True, pop=4)
    hook_rec(c, 0x59d3a0, 1, this=True, pop=4)
    return [me, stream]


S(0x5a0be0, 'GUESS load fields from stream', 'thiscall', None, ret='al', gen=_g5a0be0, note='batch38017')
