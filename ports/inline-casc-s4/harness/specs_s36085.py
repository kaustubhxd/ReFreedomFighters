"""specs_s36085.py - cascade s4 batch 36085: 0x4bd190 (read a record from a stream), 0x4d21b0 (move a node into a doubly linked list)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g4bd190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {0x48: [0], 0x50: [0]}

    def mk(slot):
        def h(em, rr):
            p = em.arg32(0)
            k = cnt[slot][0]
            cnt[slot][0] += 1
            v = (slot << 20) | (k << 8) | r.getrandbits(8)
            em.calllog.append(('slot', slot, k, p if 0x20000000 <= p < 0x30000000 else 0))
            em.w32(p, v)
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('s%x' % slot, h)
    s = obj(c, 0x80, {0x48: mk(0x48), 0x50: mk(0x50)})
    t = e.alloc(0x90, 4)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x90)))
    return [t, s]


def _g4d21b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mklist(k):
        L = e.alloc(0x40, 8)
        nodes = [e.alloc(0x40, 8) for _ in range(k)]
        for i, n in enumerate(nodes):
            e.w32(n + 0x2c, L)
            e.w32(n + 0x30, nodes[i + 1] if i + 1 < k else 0)
            e.w32(n + 0x34, nodes[i - 1] if i > 0 else 0)
        e.w32(L + 0x24, nodes[0] if k else 0)
        e.w32(L + 0x28, nodes[-1] if k else 0)
        return L, nodes
    A, na = mklist(r.choice([0, 1, 2, 3, 4]))
    B, nb = mklist(r.choice([0, 1, 2, 3]))
    mode = r.random()
    if mode < 0.3 or not na:
        n = e.alloc(0x40, 8)
        e.w32(n + 0x2c, 0)
        for off in (0x30, 0x34):
            e.w32(n + off, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    else:
        n = r.choice(na)
    target = r.choice([A, A, B, 0, B])
    idx = r.choice([0, 0, 1, 2, 3, 5, 0xffffffff, 1])
    return [n, target, idx]


S(0x4bd190, 'GUESS read a record from a stream', 'thiscall', None, ret='al', gen=_g4bd190, note='batch36085')
S(0x4d21b0, 'GUESS move a node into a doubly linked list', 'thiscall', None, ret=None, gen=_g4d21b0, note='batch36085')
