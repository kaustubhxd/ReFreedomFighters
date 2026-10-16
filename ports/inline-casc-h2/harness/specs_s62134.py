from pilot import S
from recruits_util import rnd, clear_hooks, pystub

def chain(c, n):
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for i, node in enumerate(nodes):
        c.emu.w32(node, nodes[i + 1] if i + 1 < len(nodes) else 0)
    return nodes[0] if nodes else 0

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    calls = pystub(c, 1, pop=0)
    callback_table = rnd(c, 0x20)
    e.w32(callback_table + 8, calls)
    state = rnd(c, 0x30)
    e.w32(state, chain(c, r.randrange(4)))
    e.w32(state + 4, chain(c, r.randrange(4)))
    for off in (8, 0xc, 0x10):
        e.w32(state + off, r.getrandbits(32))
    e.w32(state + 0x14, callback_table)
    return [state]

S(0x620670, 'GUESS visit_two_linked_lists_and_clear', 'cdecl', None, ret=None, gen=gen, note='batch62134')
