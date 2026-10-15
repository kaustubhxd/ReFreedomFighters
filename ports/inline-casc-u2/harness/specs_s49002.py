"""specs_s49002.py - cascade u2 batch 49002: 0x41e340. this+0x20 is an iterator object (null 8%) whose slot 0x4c (init, 1 arg) and slot 0x64 (next, returns the next entry, 0 at the end) are
stubs; _stricmp (IAT 0x676414) is a stub that matches (returns 0) at a random call. Entries: name ptr, total at +8, bins array at +0xc (random contents, room for every index), bin size at +0x10 (1..16)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, stub_seq


def _g41e340(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 1, 2, 3])
    ents = []
    for _ in range(n):
        ent = rnd(c, 0x20)
        arr = rnd(c, 4 * 700)
        e.w32(ent, rnd(c, 8))
        e.w32(ent + 0xc, arr)
        e.w32(ent + 0x10, r.choice([1, 2, 3, 4, 5, 8, 16, r.randrange(1, 40)]))
        ents.append(ent)
    seq = ents + [0]
    k = r.randrange(0, n + 1) if r.random() < 0.9 else n
    cmpret = [1] * k + [0]
    e.w32(0x676414, pystub(c, 2, ret=lambda em, i: cmpret[min(i, len(cmpret) - 1)], pop=0))
    it = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,)), 0x64: pystub(c, 1, this=True, nullflag=(0,), ret=lambda em, i: seq[min(i, len(seq) - 1)])}, nslots=0x20)
    me = rnd(c, 0x40)
    e.w32(me + 0x20, 0 if r.random() < 0.08 else it)
    b = r.choice([0, r.randrange(0, 60), r.randrange(0, 300), r.randrange(0, 20)])
    cc = r.choice([0, r.randrange(0, 40), r.randrange(0, 300), r.randrange(0, 100)])
    return [me, rnd(c, 8), b, cc]


S(0x41e340, 'GUESS add count to named entry histogram', 'thiscall', None, ret=None, gen=_g41e340, note='batch49002')
