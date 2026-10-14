"""specs_s37026.py - cascade s6 batch 37026: 0x6302f0 (zlib build_tree). 0x630ce0 (pqdownheap) runs as original code on real heap data; 0x6309a0 and 0x630bb0 are recording
hooks. Frequencies random with zeros, tree sized 2*elems+2 entries, static tree optional."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g6302f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x6309a0, 2, pop=0)
    hook_rec(c, 0x630bb0, 3, pop=0)
    elems = r.choice([1, 2, 3, 5, 8, 12])
    tree = e.alloc(4 * (2 * elems + 4), 4)
    for i in range(2 * elems + 4):
        fr = 0 if (i >= elems or r.random() < 0.35) else r.choice([1, 2, 3, 7, 100, 0xffff, r.getrandbits(16)])
        e.wbytes(tree + 4 * i, fr.to_bytes(2, 'little') + r.getrandbits(16).to_bytes(2, 'little'))
    if r.random() < 0.5:
        st = e.alloc(4 * (elems + 2), 4)
        for i in range(elems + 2):
            e.wbytes(st + 4 * i, bytes(r.getrandbits(8) for _ in range(4)))
    else:
        st = 0
    sd = rnd(c, 0x20)
    e.w32(sd, st)
    e.w32(sd + 0xc, elems)
    desc = rnd(c, 0x10)
    e.w32(desc, tree)
    e.w32(desc + 8, sd)
    s = rnd(c, 0x1700)
    return [s, desc]


S(0x6302f0, 'GUESS zlib build_tree', 'cdecl', None, ret=None, gen=_g6302f0, note='batch37026')
