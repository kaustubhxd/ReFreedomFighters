"""specs_s37022.py - cascade s6 batch 37022: 0x4ed1d0. A forest of objects (slot 0x260 = depth, slot 0x20 = parent); this slots 0x18 (4 args) / 0x14 (6 args) return the
entry count (at most 6) over an 8-entry pointer array."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4ed1d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    # forest
    nodes = []
    info = []
    for i in range(r.choice([4, 6, 9])):
        if nodes and r.random() < 0.75:
            pi = r.randrange(len(nodes))
            par = nodes[pi]
            dep = info[pi] + 1
        else:
            par, dep = 0, 0
        nd = obj(c, 0x20, {0x260: pystub(c, 0, this=True, ret=dep), 0x20: pystub(c, 0, this=True, ret=par)})
        nodes.append(nd)
        info.append(dep)
    arr = e.alloc(0x40, 4)
    n = r.choice([0, 1, 2, 3, 4, 5, 6, 6])
    for i in range(8):
        e.w32(arr + 4 * i, 0 if (i >= n or r.random() < 0.1) else r.choice(nodes))
    cnt1 = r.choice([n, n, 0, 1, 2])
    cnt2 = r.choice([n, 0, 1, 3])
    me = obj(c, 0x200, {0x18: pystub(c, 4, this=True, ret=min(cnt1, 6)), 0x14: pystub(c, 6, this=True, ret=min(cnt2, 6))})
    e.wbytes(me + 0x1a1, (0 if r.random() < 0.08 else rnd(c, 0x10)).to_bytes(4, 'little'))
    end = (arr + 4 * 8) if r.random() < 0.9 else r.choice([arr, arr - 4])
    return [me, arr, end, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4ed1d0, 'GUESS prune descendants from entry array', 'thiscall', None, ret='eax', gen=_g4ed1d0, note='batch37022')
