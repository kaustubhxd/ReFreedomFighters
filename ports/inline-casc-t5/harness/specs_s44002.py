"""specs_s44002.py - t5 () batch 44002: 0x4f1140."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def g4f1140(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    vals = [r.choice([0, 0x3f800000, 0x40000000, NAN, 0x80000000, r.getrandbits(32)]) for _ in range(3)]
    ent = rnd(c, 0x60)
    for i in range(3):
        e.w32(ent + 0x24 + 4 * i, vals[i])
    p = rnd(c, 0x10)
    same = r.random() < 0.35
    for i in range(3):
        e.w32(p + 4 * i, vals[i] if same or r.random() < 0.6 else r.choice([0, 0x3f800000, NAN, 0x80000000, r.getrandbits(32)]))
    hook_rec(c, 0x45fd20, 1, this=True, pop=4, deref={0: 3})
    # the list: this[8] and the slot-0x50 stub walks a chain of nodes
    nodes = []
    for k in range(r.choice([1, 1, 2, 3, 4])):
        nd = ent if k == 0 else rnd(c, 0x60)
        sub = rnd(c, 0x98)
        e.w32(nd + 0x54, r.choice([sub, sub, 0]))
        nodes.append((nd, sub))
    nn = len(nodes)
    flags = [r.choice([0, 1, 1, 0xffffff01, 0x100]) for _ in range(5)]
    cnt = [0]

    def has(em, rr):
        em.calllog.append(('4db9a0', em.reg('ecx') in [n[0] for n in nodes], em.arg32(0)))
        k = cnt[0]
        cnt[0] += 1
        em.ret(eax=flags[k % 5], argbytes=4)
    e.hook(0x4db9a0, has)

    def nxt(em, rr):
        a = em.arg32(0)
        cur = em.r32(a)
        idx = [n[0] for n in nodes].index(cur)
        nv = nodes[idx + 1][0] if idx + 1 < nn else 0
        em.calllog.append(('slot50', idx))
        em.w32(a, nv)
        em.ret(eax=0, argbytes=4)
    me = obj(c, 0x20, {0x50: pystub(c, 1, this=True)}, nslots=0x54 // 4)
    vt = e.r32(me)
    e.w32(vt + 0x50, e.stub_fn('slot50', nxt))
    e.w32(me + 8, r.choice([ent, ent, ent, 0]))
    return [me, p]


S(0x4f1140, 'GUESS sync position and flag list', 'thiscall', None, ret=None, gen=g4f1140, nan_heap=True, note='batch44002')
