"""specs_s35064.py - 0x6578b0 (thiscall(a, out, max) ret 0xc, ret='eax'). this vtable slot 0xc (1 arg recorded) returns, by call index, rec (block with +0x14 and +0x3c), the record array A (8 records of 36 bytes) and the
index block C (word count 0..6 at +2, word indices 0..7 from +4); out = 0x60 random bytes; max 0..8 (0 and above-count included)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g6578b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x48)
    A = rnd(c, 36 * 8)
    C = rnd(c, 0x20)
    e.wbytes(C + 2, r.randint(0, 6).to_bytes(2, 'little'))
    for i in range(8):
        e.wbytes(C + 4 + 2 * i, r.randint(0, 7).to_bytes(2, 'little'))
    seq = [rec, A, C]
    me = obj(c, 0x20, {0xc: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 2)])}, nslots=4)
    return [me, r.getrandbits(32), rnd(c, 0x60), r.choice([0, 1, 2, 3, 5, 8, r.randint(0, 8)])]


S(0x6578b0, 'GUESS copy indexed record heads into array', 'thiscall', None, ret='eax', gen=_g6578b0, note='batch35064')
