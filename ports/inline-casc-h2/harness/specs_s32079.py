"""specs_s32079.py - h2 () batch 32079: 0x63af20. 0x63b440 is a recorder (this recorded) that sometimes installs a fresh head block and returns al."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _node(c, full):
    n = rnd(c, 0x200)
    c.emu.wbytes(n + 2, (0xffff if full else c.rng.choice([0, 1, 2, 3])).to_bytes(2, 'little'))
    c.emu.w32(n + 8, 0)
    return n


def g63af20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x40)
    k = r.choice([0, 1, 2, 3, 4])
    nodes = [_node(c, r.random() < 0.65) for _ in range(k)]
    for a, b in zip(nodes, nodes[1:]):
        e.w32(a + 8, b)
    if k and r.random() < 0.15:
        e.w32(nodes[-1] + 8, nodes[0])
    e.w32(me + 8, nodes[0] if nodes else 0)
    fresh = _node(c, r.random() < 0.3)
    ok = r.random() < 0.75

    def side(emu, kk):
        emu.w32(emu.reg('ecx') + 8, fresh)
    hook_rec(c, 0x63b440, 0, this=True, pop=0, ret=(1 if ok else 0), side=side)
    return [me]


S(0x63af20, 'GUESS take a free entry from block pool', 'thiscall', None, ret='eax', gen=g63af20, note='batch32079')
