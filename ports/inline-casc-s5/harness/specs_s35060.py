"""specs_s35060.py - 0x438e30 (thiscall, no args, ret='al'). [this+0xd] (unaligned) = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out param; first dword zeroed after 0..4 calls, non-zero at the start in 4/5)); 0x438c30 hooked
(thiscall) returning an object whose slot 0x28 (1 arg, e recorded) returns, per call, AL values including negative bytes (0x80..0xff) and positives."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g438e30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [(r.getrandbits(24) << 8) | r.choice([0, 1, 5, 0x7f, 0x80, 0x81, 0xff, r.getrandbits(8)]) for _ in range(6)]
    o = obj(c, 0x20, {0x28: pystub(c, 1, this=True, ret=lambda em, k: vals[min(k, 5)])}, nslots=0xc)
    hook_rec(c, 0x438c30, 0, this=True, ret=o)
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3, 4])
    seq = [r.getrandbits(32) for _ in range(6)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)], side=s5c)}, nslots=0x20)
    me = rnd(c, 0x40)
    e.wbytes(me + 0xd, L.to_bytes(4, 'little'))
    return [me]


S(0x438e30, 'GUESS signed byte maximum over list', 'thiscall', None, ret='al', gen=_g438e30, note='batch35060')
