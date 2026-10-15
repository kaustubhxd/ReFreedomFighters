"""specs_s66062.py - cascade s4 batch 66062: 0x4e3f60 (descend a 4-way tree by occupancy masks and link a node into the leaf list)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, logger


def _g4e3f60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2, 0x30)
    pool = e.alloc(0x40, 8)
    stride = 0x20
    base = e.alloc(stride * 0x140, 8)
    e.w32(pool, base)
    e.w32(pool + 0xc, stride)
    full = r.random() < 0.15
    e.w32(pool + 8, 5)
    e.w32(pool + 0x10, 5 if full else r.choice([0, 1, 3]))
    seq = [r.getrandbits(5) + 1 for _ in range(8)]
    st = {'i': 0}

    def p6b80(em, rr):                    # 0x4e6b80 (ecx = pool, &tmp) ret 4
        k = st['i']
        st['i'] += 1
        em.calllog.append(('h4e6b80', em.reg('ecx')))
        em.w32(em.arg32(0), seq[k % 8] | (r.getrandbits(8) << 16 if False else 0))
        em.ret(eax=rnd(c, 8), argbytes=4)
    rv = rnd(c, 8)

    def p6b80b(em, rr):
        k = st['i']
        st['i'] += 1
        em.calllog.append(('h4e6b80', em.reg('ecx')))
        em.w32(em.arg32(0), seq[k % 8] | (0x10100 if k % 2 else 0x10000))
        em.ret(eax=rv, argbytes=4)
    e.hook(0x4e6b80, p6b80b)
    hook_rec(c, 0x4e4a50, 2, this=True)
    s = e.alloc(0x40, 8)
    e.wbytes(s, bytes(r.getrandbits(8) for _ in range(0x40)))
    for i in range(4):
        e.wbytes(s + 2 * i, r.choice([0, 0, 1, 2, 3]).to_bytes(2, 'little'))
    e.w32(s + 0xc, r.choice([0, rnd(c, 0x20)]))
    a = e.alloc(0x40, 8)
    e.w32(a, pool)
    node = e.alloc(0x40, 8)
    e.wbytes(node, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(a + 4, node)
    lvl = r.choice([0, 1, 3, 5])
    e.w32(a + 8, lvl)
    e.w32(a + 0xc, r.choice([lvl, lvl + 1, lvl + 2, lvl + 4]))
    e.w32(a + 0x10, r.getrandbits(16))
    e.w32(a + 0x18, r.getrandbits(16))
    return [s, a]


S(0x4e3f60, 'GUESS descend a 4-way tree by masks and link a node into the leaf list', 'thiscall', None, ret=None, gen=_g4e3f60, note='batch66062')
