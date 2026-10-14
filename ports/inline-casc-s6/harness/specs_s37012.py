"""specs_s37012.py - cascade s6 batch 37012: 0x61c3d0 (context teardown, cdecl(ctx)). ctx+0x14 is a recording free stub (cdecl, 1 arg); lists/nodes are random-filled
heap objects linked through +0 / +4; 0x620670 and 0x61f0d0 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g61c3d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x620670, 1, pop=0)
    hook_rec(c, 0x61f0d0, 2, pop=0)
    ctx = rnd(c, 0x290)

    def sub_list(n):
        head = 0
        for _ in range(n):
            el = rnd(c, 0x20)
            e.w32(el + 4, head)
            head = el
        return head

    def node_chain(n):
        head = 0
        for _ in range(n):
            nd = rnd(c, 0x30)
            e.w32(nd, head)
            e.w32(nd + 0x20, sub_list(r.choice([0, 0, 1, 2, 3])))
            head = nd
        return head
    a = node_chain(r.choice([0, 0, 1, 2, 3]))
    b = node_chain(r.choice([0, 0, 1, 2]))
    e.w32(ctx + 0x204, a)
    e.w32(ctx + 0x208, b)
    e.w32(ctx + 0x210, sub_list(r.choice([0, 1, 2, 3])))
    e.w32(ctx + 0x20c, sub_list(r.choice([0, 1, 2])))
    e.w32(ctx + 0x14, pystub(c, 1, pop=0))
    e.w32(ctx + 0x270, rnd(c, 0x290) if r.random() < 0.7 else 0)
    if r.random() < 0.3:
        e.w32(ctx + 0x264, 0)
    for off in (0x25c, 0x8, 0xf0):
        if r.random() < 0.3:
            e.w32(ctx + off, 0)
    e.w32(ctx + 0xfc, pystub(c, 1, pop=0) if r.random() < 0.6 else 0)
    return [ctx]


S(0x61c3d0, 'GUESS context teardown', 'cdecl', None, ret=None, gen=_g61c3d0, note='batch37012')
