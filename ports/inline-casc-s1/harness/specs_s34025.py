"""specs_s34025.py - cascade tier E, batch 34025.
0x57aff0 / 0x57b060: the child list is a chain of up to 4 nodes ([[this+0x54]+8] first node, slot 0x50 of the list object writes the next node or 0 through its stack pointer
argument); hooked 0x4db9a0 returns 0/1; each node has [node+0x54] = a child object whose slots 0x368 (random value), 0x310 (index 0..30) and 0x36c are recorders.
0x57bee0: [[this+0x94]+0x1044] is 3 in 60% of the cases; the slot 0x25c chain returns three objects (call 0 and 2 on the root's child, call 1 ...) whose slots are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _list(c, n_nodes, mk_child):
    r = c.rng
    nodes = [rnd(c, 0x60) for _ in range(n_nodes)]
    for nd in nodes:
        c.emu.w32(nd + 0x54, mk_child())
    seq = nodes + [0]
    state = {'i': 0}

    def nxt(em, k):
        state['i'] += 1
        em.w32(em.arg32(0), seq[min(state['i'], len(seq) - 1)] if state['i'] < len(seq) else 0)
    lst = obj(c, 0x20, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x40)
    first = nodes[0] if nodes else 0
    return lst, first, state


def _gen(kind):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, 0x4db9a0, 1, ret=lambda em, k: r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)
        idx = lambda em, k: r.randrange(0, 31)

        def mk_child():
            if kind == 'save':
                return obj(c, 0x20, {0x368: pystub(c, 0, ret=lambda em, k: r.getrandbits(32), this=True),
                                     0x310: pystub(c, 0, ret=idx, this=True)}, nslots=0x400 // 4)
            return obj(c, 0x20, {0x36c: pystub(c, 2, this=True), 0x310: pystub(c, 0, ret=idx, this=True)}, nslots=0x400 // 4)
        n = r.choice([0, 1, 2, 3, 4])
        lst, first, state = _list(c, n, mk_child)
        c.emu.w32(lst + 8, first)
        me = rnd(c, 0x180 + 31 * 4 + 0x20)
        c.emu.w32(me + 0x54, lst)
        return [me]
    return g


def _g57bee0(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x1050)
    c.emu.w32(blk + 0x1044, 3 if r.random() < 0.6 else r.getrandbits(32))
    b = obj(c, 0x20, {0x2dc: pystub(c, 0, this=True), 0x28: pystub(c, 0, this=True)}, nslots=0x300 // 4)
    cc = obj(c, 0x20, {0x31c: pystub(c, 2, this=True)}, nslots=0x340 // 4)
    a = obj(c, 0x20, {0x25c: pystub(c, 2, ret=lambda em, k: b if k == 0 else cc, this=True)}, nslots=0x280 // 4)
    p = obj(c, 0x20, {0x25c: pystub(c, 2, ret=a, this=True)}, nslots=0x280 // 4)
    me = rnd(c, 0xa0)
    c.emu.w32(me + 0x54, p)
    c.emu.w32(me + 0x94, blk)
    return [me]


S(0x57aff0, 'GUESS save per-slot value of matching children', 'thiscall', None, ret=None, gen=_gen('save'), note='batch34025')
S(0x57b060, 'GUESS restore per-slot value of matching children', 'thiscall', None, ret=None, gen=_gen('restore'), note='batch34025')
S(0x57bee0, 'GUESS fetch three named children and prod them', 'thiscall', None, ret=None, gen=_g57bee0, note='batch34025')
