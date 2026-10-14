"""specs_s35017.py - 0x570930 (ret='al'). 0x5626d0 hooked (thiscall, 1 arg, AL true in 3/4); stream object slots 0x68 (writes a random byte through its argument) and 0x40 (writes a random dword);
both record the destination as a small offset of the object (this + k) via the written value being compared in memory."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g570930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5626d0, 1, this=True, ret=(r.getrandbits(32) | 1) if r.random() < 0.75 else (r.getrandbits(32) & ~0xff))
    n = [0]

    def wb(em, k):
        em.wbytes(em.arg32(0), bytes([k + 1 + r.getrandbits(7)]))

    def wd(em, k):
        em.w32(em.arg32(0), (k + 1) * 0x01010101 ^ r.getrandbits(32))
    me = rnd(c, 0x200)
    s = obj(c, 0x20, {0x68: pystub(c, 1, nullflag=(0,), this=True, side=wb), 0x40: pystub(c, 1, nullflag=(0,), this=True, side=wd)}, nslots=0x1c)
    return [me, s]


S(0x570930, 'GUESS read record fields from stream', 'thiscall', None, ret='al', gen=_g570930, note='batch35017')
