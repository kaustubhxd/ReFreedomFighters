"""specs_s252018.py - hand specs (Sonnet-w4f)."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g65f070(c):
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    O = rnd(c, 0x200); n = r.choice([0, 1, 2, 3, 4, 5])
    em.w32(O + 0x44, n)
    G = rnd(c, 0x2000); em.w32(0x70039c, G)
    C1 = rnd(c, 0x40); V1 = rnd(c, 0x100); em.w32(C1, V1); em.w32(G + 0x9b, C1)
    C2 = rnd(c, 0x40); V2 = rnd(c, 0x100); em.w32(C2, V2); em.w32(G + 0x190f, C2)
    X = rnd(c, 0x40)
    em.w32(V1 + 0x54, pystub(c, 1, this=True, ret=lambda emu, k: r.choice([0, 0, 0x1234, r.getrandbits(32)]), side=lambda emu, k: emu.calllog.append(('s54', emu.arg32(0)))))
    em.w32(V2 + 0x20, pystub(c, 0, this=True, ret=X, side=lambda emu, k: emu.calllog.append(('s20',))))
    hook_rec(c, 0x63d2f0, 2, ret=R32, pop=8, this=True)
    return [O]


S(0x65f070, 'GUESS hand port 0x65f070', 'stdcall', None, ret=None, gen=g65f070, note='batch252018')
