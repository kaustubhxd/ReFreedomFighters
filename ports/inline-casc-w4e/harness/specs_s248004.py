"""specs_s248004.py - Sonnet-w4e hand specs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain

def g4fc460(c):
    clear_hooks(c)
    r = c.rng; em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    T = rnd(c, 0x100)
    n = r.choice([0, 1, 1, 2, 3, 4])
    nodes = [rnd(c, 0x40) for _ in range(n)]
    for i, nd in enumerate(nodes):
        em.w32(nd + 0x10, T)
        em.w32(nd + 8, nodes[i - 1] if i > 0 else 0)
        em.w32(nd + 0xc, nodes[i + 1] if i + 1 < n else 0)
    em.w32(T + 0x48, nodes[0] if n else 0)
    em.w32(T + 0x4c, r.choice([nodes[-1] if n else 0, nodes[-1] if n else 0, 0, r.getrandbits(32)]))
    em.w32(T + 0x50, r.choice(nodes + [0, nodes[0] if n else 0, r.getrandbits(32)]))
    def side(emu, k):
        nd = emu.arg32(0)
        emu.calllog.append(('free', nd, emu.arg32(1), emu.r32(T + 0x48), emu.r32(T + 0x4c), emu.r32(T + 0x50)))
    hook_rec(c, 0x634273, 2, ret=R, pop=0, this=False, side=side)
    return [T]

S(0x4fc460, 'list teardown 0x4fc460', 'thiscall', None, ret=None, gen=g4fc460, note='batch248004')
