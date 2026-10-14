"""specs_s35005.py - 0x4d8e60. [this] = list object (vtable slot 4 recorded; its side effect advances list[1] to the next node, finally to the end marker list[2], or to null);
nodes carry an unaligned dword at +0x11 (null in 1/5) = sub-object with slots 0x4c (out param), 0x64 (returns 0..3 pointers to a word, then 0) and 0 (delete, flag 1);
byte [this+4] zero in 3/4; 0x634273 cdecl recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d8e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    k = r.choice([0, 1, 2, 3, 3])
    nodes = []
    for _ in range(k):
        nd = rnd(c, 0x30)
        if r.random() < 0.2:
            s = 0
        else:
            m = r.choice([0, 1, 2, 3])
            blocks = [rnd(c, 8) for _ in range(m)]
            slots = {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                     0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, kk, b=blocks: b[kk] if kk < len(b) else 0),
                     0: pystub(c, 1, this=True)}
            s = obj(c, 0x20, slots)
        e.wbytes(nd + 0x11, s.to_bytes(4, 'little'))
        nodes.append(nd)
    end = rnd(c, 0x10)
    ends = [0] if r.random() < 0.3 else [end]

    def adv(em, kk):
        lst = em.arg32(0) if False else em.reg('ecx')
        em.w32(lst + 4, nodes[kk + 1] if kk + 1 < len(nodes) else (ends[0]))
    lst = obj(c, 0x10, {4: pystub(c, 1, this=True, side=adv)}, nslots=2)
    e.w32(lst + 4, nodes[0] if nodes else end)
    e.w32(lst + 8, end)
    me = rnd(c, 0x10)
    e.w32(me, lst)
    if r.random() < 0.75:
        e.wbytes(me + 4, bytes([0]))
    return [me]


S(0x4d8e60, 'GUESS drain list nodes', 'thiscall', None, ret=None, gen=_g4d8e60, note='batch35005')
