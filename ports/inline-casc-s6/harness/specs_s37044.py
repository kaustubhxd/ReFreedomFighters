"""specs_s37044.py - cascade s6 batch 37044. Engine slots 0x14 / 0x28 / 0xc8 / 0x10, manager at [[eng+0x1aa3]+0x1c] (slot 0x10), object at [[eng+0x9b]+0x5d31] (slot 8), chain at
[eng+0x190f] (slots 0x94 / 0x3c, next at +8), allocator object 0x70038c (slot 0x38) and 0x7003b4 (slot 4); this has 0 virtuals and packed pointer fields; 0x634273 and
0x49b680 are recording hooks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g48fae0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x49b680, 0, this=True)
    so = sysobj(c, slots={0x14: pystub(c, 0, this=True), 0x28: pystub(c, 0, this=True),
                          0xc8: pystub(c, 0, this=True), 0x10: pystub(c, 0, this=True)}, table_size=0x5e00)
    tab = e.r32(so + 0x9b)
    _w(c, tab + 0x5d31, obj(c, 0x20, {0x8: pystub(c, 0, this=True)}))
    holder = rnd(c, 0x30)
    e.w32(holder + 0x1c, obj(c, 0x20, {0x10: pystub(c, 0, this=True)}) if r.random() < 0.7 else 0)
    _w(c, so + 0x1aa3, holder)
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n = obj(c, 0x20, {0x94: pystub(c, 0, this=True), 0x3c: pystub(c, 0, this=True)})
        nodes.append(n)
    for a, b in zip(nodes, nodes[1:] + [0]):
        e.w32(a + 8, b)
    _w(c, so + 0x190f, nodes[0] if nodes else 0)
    e.w32(0x70038c, obj(c, 0x20, {0x38: pystub(c, 0, this=True)}) if r.random() < 0.7 else 0)
    e.w32(0x7003b4, obj(c, 0x20, {0x4: pystub(c, 0, this=True)}) if r.random() < 0.7 else 0)
    me = e.alloc(0x5e00, 4)
    vt = e.alloc(0x200, 4)
    for off in (0x198, 0xe8, 0xdc, 0x194, 0x6c, 0x48, 0x3c):
        e.w32(vt + off, pystub(c, 0, this=True))
    e.w32(me, vt)

    def ptr(off, n=0x20):
        _w(c, me + off, rnd(c, n) if r.random() < 0.7 else 0)
    for off in (0xbb7, 0xbbb, 0xaf4, 0x5d35, 0x1c5d, 0x44):
        ptr(off)
    lvt = e.alloc(0x40, 4)
    e.w32(lvt + 0xc, pystub(c, 0, this=True))
    _w(c, me + 0x1c61, lvt)
    dobj = obj(c, 0x20, {0x0: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0
    _w(c, me + 0xc, dobj)
    return [me]


S(0x48fae0, 'GUESS shutdown game state', 'thiscall', None, ret=None, gen=_g48fae0, note='batch37044')
