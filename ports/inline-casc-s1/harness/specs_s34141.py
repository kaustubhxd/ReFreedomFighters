"""specs_s34141.py - 0x5f29e0: m=[this+0xc] with +4 child, +0x14 string pointer, +0x98 count (0..8); hooked 0x5fd6f0 and 0x4cc5f0 (plain, ecx recorded; length 0 in half); this slot 0x8c (1 arg, small result); engine [0x70039c] slot 0x190 -> object whose slot 0x184 is a 4-arg cdecl recorder.
0x5f48c0: a with slot 0x5c (writes a count 0..3 to its pointer argument, a stack slot, marked); c = vector {data, cap, size} with size around cap; hooked 0x5f55e0, 0x42ab62 (cdecl), 0x605940 (3 args); assert hook word at 0x7003b0 a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5f29e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5fd6f0, 0, this=True, pop=0)
    hook_rec(c, 0x4cc5f0, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 0, 3, 9]))
    o = obj(c, 0x20, {0x184: pystub(c, 4, pop=0)}, nslots=0x188 // 4)
    eng = obj(c, 0x20, {0x190: pystub(c, 0, ret=o, this=True)}, nslots=0x194 // 4)
    e.w32(0x70039c, eng)
    m = rnd(c, 0xa0)
    e.w32(m + 0x98, r.randrange(9))
    e.w32(m + 4, rnd(c, 0x10))
    me = obj(c, 0x20, {0x8c: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 2, 3, 5, 7, 9]))}, nslots=0x90 // 4)
    e.w32(me + 0xc, m)
    return [me]


def _g5f48c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x5f55e0, 0, this=True, pop=0)
    hook_rec(c, 0x42ab62, 1, pop=0)
    hook_rec(c, 0x605940, 3, this=True, ret=r.getrandbits(32))
    n = r.choice([0, 1, 2, 3])

    def cnt(em, k):
        em.w32(em.arg32(0), n)
    a = obj(c, 0x20, {0x5c: pystub(c, 1, this=True, side=cnt, stackmark=(0,))}, nslots=0x60 // 4)
    cap = r.choice([1, 2, 3, 4])
    size = r.choice([0, 1, 2, 3, cap, cap - 1 if cap else 0, cap + 1])
    data = rnd(c, 0x80)
    vec = rnd(c, 0x10)
    e.w32(vec, data)
    e.w32(vec + 4, cap)
    e.w32(vec + 8, min(size, 6))
    return [rnd(c, 0x10), a, r.getrandbits(32), vec]


S(0x5f29e0, 'GUESS trim a history list', 'thiscall', None, ret=None, gen=_g5f29e0, note='batch34141')
S(0x5f48c0, 'GUESS append records to a vector', 'thiscall', None, ret=None, gen=_g5f48c0, note='batch34141')
