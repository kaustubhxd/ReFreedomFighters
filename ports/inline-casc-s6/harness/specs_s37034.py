"""specs_s37034.py - cascade s6 batch 37034: 0x573000. List object at this+0x44 (slot 0x50 scripted next-node writer); nodes carry objects (+0x54) with a name pointer at +4 and
slot 0x1e0; names include the exact string at 0x6a8c14, prefixes and extensions of it; matching objects have slots 0x318 (1 arg, returns children by index 3/4 or 0) and 0x31c
(2 args), 0xbc (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _cs(c, b):
    p = c.emu.alloc(len(b) + 1, 1)
    c.emu.wbytes(p, b + b'\0')
    return p


def _g573000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    tgt = b''
    p = 0x6a8c14
    while True:
        b = e.rbytes(p, 1)
        if b == b'\0' or len(tgt) > 40:
            break
        tgt += b
        p += 1
    names = [_cs(c, tgt), _cs(c, tgt), _cs(c, tgt + b'x'), _cs(c, tgt[:-1]), _cs(c, b''), _cs(c, b'other'), 0]

    def mkchild(depth):
        kids = {}
        if depth > 0:
            for k in (3, 4):
                kids[k] = mkchild(depth - 1)
        return obj(c, 0x20, {0x318: pystub(c, 1, this=True, ret=lambda em, k, kids=kids: kids.get(em.arg32(0), 0)),
                             0x31c: pystub(c, 2, this=True)})

    def mkobj(name):
        kids = {3: mkchild(2), 4: mkchild(2) if r.random() < 0.8 else 0}
        o = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100, 0x1ff])),
                          0x318: pystub(c, 1, this=True, ret=lambda em, k, kids=kids: kids.get(em.arg32(0), 0)),
                          0x31c: pystub(c, 2, this=True),
                          0xbc: pystub(c, 1, this=True)})
        e.w32(o + 4, name)
        return o
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        nd = rnd(c, 0x60)
        e.w32(nd + 0x54, mkobj(r.choice(names)))
        nodes.append(nd)
    nxt = {x: y for x, y in zip(nodes, nodes[1:] + [0])}
    L = obj(c, 0x20, {0x50: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), nxt.get(em.r32(em.arg32(0)), 0)))})
    e.w32(L + 8, nodes[0] if nodes else 0)
    me = rnd(c, 0x190)
    e.w32(me + 0x44, L)
    return [me, r.choice([0, 1, 1, 7, 0x100, 0x101])]


S(0x573000, 'GUESS link children of matching object', 'thiscall', None, ret=None, gen=_g573000, note='batch37034')
