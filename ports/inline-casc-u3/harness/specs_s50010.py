"""specs_s50010.py - u3 batch 50010 (Haiku slot, run by Sonnet 5.5), tier H. 0x5ee970: stream object s with recorder slots 0x3c / 0x44 / 0x4c (float bits); [this+0x15] object slot 0x10; 0x49b3a0 hooked (8 args);
unaligned this fields random-filled; the pointer range [+5, +9) holds 0-4 entries whose [[e]] object has slot 0x10 and a word at +4."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5ee970(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x49b3a0, 8, this=True, pop=0x20, ret=r.getrandbits(32))
    def log(em, k):   # the recorder keeps only 8 rows, so every written value also goes into the call log
        em.calllog.append(('w', em.arg32(0)))
    s = obj(c, 0x20, {0x3c: pystub(c, 1, this=True, side=log), 0x44: pystub(c, 1, this=True, side=log), 0x4c: pystub(c, 1, this=True, side=log)}, nslots=0x50 // 4)
    me = rnd(c, 0x90)
    e.wbytes(me + 0x15, obj(c, 0x20, {0x10: pystub(c, 1, this=True)}, nslots=0x14 // 4).to_bytes(4, 'little'))
    n = r.choice([0, 0, 1, 2, 3, 5])
    arr = rnd(c, 4 * n + 8)
    for i in range(n):
        inner = obj(c, 0x20, {0x10: pystub(c, 1, this=True)}, nslots=0x14 // 4)
        el = rnd(c, 0x10)
        e.w32(el, inner)
        e.w32(arr + 4 * i, el)
    e.wbytes(me + 5, arr.to_bytes(4, 'little'))
    e.wbytes(me + 9, (arr + 4 * n).to_bytes(4, 'little'))
    return [me, s]


S(0x5ee970, 'GUESS serialise object fields to stream', 'thiscall', None, ret=None, gen=_g5ee970, note='batch50010')
