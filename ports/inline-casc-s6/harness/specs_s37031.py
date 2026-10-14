"""specs_s37031.py - cascade s6 batch 37031: 0x548f40. Table slots 0x58 (id -> list object) and 0x114 (4 args); list objects have slot 0xbc (reset) and 0x50 (advance:
scripted next node written through the pointer); nodes carry an object at +0x54 with slot 0x128 (3 args); 0x4db860 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g548f40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x4db860, 1, this=True)
    nxt = {}

    def mklist():
        nodes = []
        for _ in range(r.choice([0, 1, 2, 3])):
            nd = rnd(c, 0x60)
            if r.random() < 0.8:
                tgt = obj(c, 0x20, {0x128: pystub(c, 3, this=True)})
            else:
                tgt = 0
            e.w32(nd + 0x54, tgt)
            nodes.append(nd)
        for x, y in zip(nodes, nodes[1:] + [0]):
            nxt[x] = y
        L = obj(c, 0x20, {0xbc: pystub(c, 1, this=True),
                          0x50: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), nxt.get(em.r32(em.arg32(0)), 0)))})
        e.w32(L + 8, nodes[0] if nodes else 0)
        return L
    la = mklist() if r.random() < 0.85 else 0
    lb = mklist() if r.random() < 0.85 else 0
    ida, idb = r.randint(1, 0xffff), r.randint(1, 0xffff)
    table = {ida: la, idb: lb}
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0)),
                                0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)
    me = obj(c, 0x80, {0x28: pystub(c, 0, this=True)})
    fin = obj(c, 0x20, {0x28: pystub(c, 0, this=True)})
    e.w32(me + 0x44, fin)
    e.w32(me + 0x4c, ida)
    e.w32(me + 0x50, idb)
    a = rnd(c, 0x20) if r.random() < 0.6 else 0
    return [me, a]


S(0x548f40, 'GUESS reset two lists and notify nodes', 'thiscall', None, ret=None, gen=_g548f40, note='batch37031')
