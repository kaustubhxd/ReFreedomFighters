from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    count = r.randrange(0, 5)
    start_null = r.random() < 0.15
    links = r.randrange(0, count + 1) if count else 0
    nodes = [rnd(c, 0x10) for _ in range(count + 1)]
    wrappers = [rnd(c, 0x10) for _ in range(count + 1)]
    for i, wrapper in enumerate(wrappers):
        nxt = nodes[i + 1] if i < links else 0
        e.w32(wrapper + 8, nxt)
    returns = [wrappers[min(i, len(wrappers)-1)] for i in range(count + 1)]
    cb = pystub(c, 1, this=True, pop=4,
                ret=lambda emu, k: returns[min(k, len(returns)-1)])
    self = obj(c, 0x20, {0xc: cb})
    node = 0 if start_null else nodes[0]
    return [self, node, count]


S(0x6567e0, 'GUESS walk linked nodes for bounded count', 'thiscall', None,
  ret='eax', gen=gen, note='batch62097')
