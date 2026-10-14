"""specs_s38026.py - cascade s8 batch 38026. Node chain (1..4 nodes, +0x54 target object whose flag dword is at [[t+0xc]+0x23], +0x60 next; bit 0x100000 set 90% of the time) with 0x4db9a0 a custom
per-(node, flag) hook (random but fixed per case, so the 0x1007d3 / 0x1007d4 / 0x100001 branches all run); list object embedded at this+0x11a (unaligned vtable pointer) with slots 0x4c / 0x5c
(cursor dword set for the first 0..3 reads, ids from a pool); table slot 0x58 maps ids to objects (slot 0x1e0 flag test, slot 0x2e8 returns the target of the chain node about half of the time),
slot 0x4c a random handle; 0x4acf30 hooked; this slot 0x8c recorded; targets' slot 0x340 returns a value taken from the same pool of objects so the second match test can succeed."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4ac120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nn = r.choice([0, 1, 2, 3, 4])
    targets = []
    nodes = []
    for _ in range(nn):
        blk = rnd(c, 0x40)
        fl = (0x100000 | r.getrandbits(32)) if r.random() < 0.9 else (r.getrandbits(32) & ~0x100000)
        e.wbytes(blk + 0x23, struct.pack('<I', fl & 0xffffffff))
        u = rnd(c, 0x20)
        t = obj(c, 0x60, {0x340: pystub(c, 1, this=True, ret=u)})
        e.w32(t + 0xc, blk)
        node = rnd(c, 0x70)
        e.w32(node + 0x54, t if r.random() > 0.05 else 0)
        targets.append((t, u))
        nodes.append(node)
    for a, b in zip(nodes, nodes[1:]):
        e.w32(a + 0x60, b)
    if nodes:
        e.w32(nodes[-1] + 0x60, 0)
    owner = rnd(c, 0x80)
    e.w32(owner + 0x50, nodes[0] if nodes else 0)
    cfg = {}

    def h9a0(em, res_):
        k = (em.reg('ecx'), em.arg32(0))
        if k not in cfg:
            cfg[k] = r.random() < 0.6
        em.calllog.append(('h9a0', k[0], k[1]))
        em.ret(eax=(r.getrandbits(24) << 8) | (1 if cfg[k] else 0), argbytes=4)
    e.hook(0x4db9a0, h9a0)
    pool = list(range(1, 9))
    objs = {}
    for i in pool:
        if r.random() < 0.2:
            continue
        ty = r.choice(targets)[r.randrange(2)] if targets and r.random() < 0.5 else rnd(c, 0x20)
        objs[i] = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([1, 1, 0x100, 0])),
                                0x2e8: pystub(c, 0, this=True, ret=ty)})
    ncur = r.randrange(0, 4)
    seq = [r.choice(pool) for _ in range(8)]

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        em.ret(eax=objs.get(a, 0), argbytes=4)
    sysobj(c, {}, table_slots={0x58: e.stub_fn('s58', s58), 0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    lvt = e.alloc(0x80, 4)
    e.w32(lvt + 0x4c, pystub(c, 1, this=True, stackmark=(0,)))
    e.w32(lvt + 0x5c, pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[k % 8],
                             side=lambda em, k: em.w32(em.arg32(0), 1 if (k % 4) < ncur else 0)))
    me = obj(c, 0x200, {0x8c: pystub(c, 1, this=True)})
    e.wbytes(me + 0x11a, struct.pack('<I', lvt))
    hook_rec(c, 0x4acf30, 1, this=True, pop=4)
    return [me, owner]


S(0x4ac120, 'GUESS register matching objects of node chain', 'thiscall', None, ret=None, gen=_g4ac120, note='batch38026')
