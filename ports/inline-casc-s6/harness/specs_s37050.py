"""specs_s37050.py - cascade s6 batch 37050 (0x472280). Table slots 0x58 (id -> object) and 0x4c (3 args), table+0xadc a pointer; b has slots 0x290 (4 args, the last
a stack pointer for kind 0x11), 0x294, 0x128; objects have slot 0x2f0 and +8; 0x4dcbb0 and 0x474eb0 hooked; logger at 0x700390."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g472280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    hook_rec(c, 0x4dcbb0, 1, this=True)
    hook_rec(c, 0x474eb0, 2, this=True, pop=8)
    ids = [r.randint(1, 0xffff) for _ in range(3)]

    def mkobj():
        o = obj(c, 0x20, {0x2f0: pystub(c, 1, this=True)})
        e.w32(o + 8, rnd(c, 0x20))
        return o
    table = {i: (mkobj() if r.random() < 0.8 else 0) for i in ids}
    if r.random() < 0.4:
        table[0] = mkobj()
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0)),
                                0x4c: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, r.getrandbits(32))
    b = obj(c, 0x40, {0x290: pystub(c, 4, this=True, stackmark=(3,), side=lambda em, k: em.calllog.append(('v', tuple(em.r32(em.arg32(3) + 4 * i) for i in range(3))) if em.arg32(3) else ('v', None))), 0x294: pystub(c, 2, this=True),
                      0x128: pystub(c, 3, this=True)})
    me = rnd(c, 0x80)
    cur = r.choice(ids + [0])
    _w(c, me + 0x51, cur)
    _w(c, me + 0x56, r.choice([0x11, 0x11, 5, 0x20]))
    _w(c, me + 0x66, r.getrandbits(16), 2)
    _w(c, me + 0x55, r.choice([0, 1]), 1)
    nid = r.choice(ids + [0, cur, cur])
    return [me, b, nid]


S(0x472280, 'GUESS rebind object of entity', 'thiscall', None, ret='eax', gen=_g472280, note='batch37050')
