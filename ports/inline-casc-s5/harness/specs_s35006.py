"""specs_s35006.py - 0x4d1790. Record (size +8 and data +0xc random, children list +0x24 (next +0x30, slot 0xc(cursor ptr) that advances the cursor), item list +0x18 (next +8, data +0xc, size +0x10 in 0..9));
0x634d22 / 0x634d10 cdecl recorders (3 args). The cursor is a heap dword."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d1790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x634d10, 3, pop=0)
    cur = rnd(c, 4)
    e.w32(cur, 0x20000000 + r.randrange(0x1000) * 4)
    me = rnd(c, 0x40)
    e.w32(me + 8, r.choice([0, 1, 3, 4, r.randint(0, 40)]))

    def adv(em, kk):
        p = em.arg32(0)
        em.w32(p, (em.r32(p) + r.randint(1, 16)) & 0xffffffff)
    prev = 0
    for _ in range(r.choice([0, 1, 2, 3])):
        ch = obj(c, 0x40, {0xc: pystub(c, 1, this=True, side=adv)})
        e.w32(ch + 0x30, prev)
        prev = ch
    e.w32(me + 0x24, prev)
    prev = 0
    for _ in range(r.choice([0, 1, 2, 3])):
        it = rnd(c, 0x20)
        e.w32(it + 8, prev)
        e.w32(it + 0x10, r.randint(0, 9))
        prev = it
    e.w32(me + 0x18, prev)
    return [me, cur]


S(0x4d1790, 'GUESS serialize record into cursor', 'thiscall', None, ret=None, gen=_g4d1790, note='batch35006')
