"""specs_s35111.py - 0x57d780 (thiscall, no args). this: random 0x340 bytes with vtable slot 0x84 (0 args; returns o1 then o2: o1 has slot 0x350 (3 args), o2 slot 0x30c (1 arg)); [+0x18c] object with slot 0xbc (1 arg); [+0x310] = L ([L+8] first node, null in 1/4; slot 0x50 (1 arg, out pointer
flag-recorded) writes the next node: 0..3 nodes); nodes: [+0x54] object with slot 0x250 (1 arg); 0x4db9a0 hooked (thiscall, 1 arg, AL true in half)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g57d780(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    al = lambda: ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < 0.5 else (r.getrandbits(24) << 8)
    vals = [al() for _ in range(4)]
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: vals[min(k, 3)])
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        nd = rnd(c, 0x60)
        e.w32(nd + 0x54, obj(c, 0x20, {0x250: pystub(c, 1, this=True)}, nslots=0x95))
        nodes.append(nd)
    L = obj(c, 0x20, {0x50: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), nodes[k + 1] if k + 1 < len(nodes) else 0))}, nslots=0x15)
    e.w32(L + 8, nodes[0] if nodes else 0)
    o1 = obj(c, 0x20, {0x350: pystub(c, 3, this=True)}, nslots=0xd5)
    o2 = obj(c, 0x20, {0x30c: pystub(c, 1, this=True)}, nslots=0xc4)
    X = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0x30)
    me = obj(c, 0x340, {0x84: pystub(c, 0, this=True, ret=lambda em, k: (o1, o2)[min(k, 1)])}, nslots=0x22)
    e.w32(me + 0x18c, X)
    e.w32(me + 0x310, L)
    return [me]


S(0x57d780, 'GUESS reset panel and fade matching children', 'thiscall', None, ret=None, gen=_g57d780, note='batch35111')
