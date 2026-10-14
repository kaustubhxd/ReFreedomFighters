"""specs_s37095.py - cascade s6 batch 37095 (0x5c7570, thiscall(a) ret 4). 0x4db2f0 is a hook returning an object whose slot 0x25c (2 args, the local string buffer logged by
content) returns a handle or 0; table slot 0x4c, the a+0x10 object (slot 4), this+0x44 (slots 0x12c / 0x130) and the logger (slot 0x2c cdecl) are recorded."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5c7570(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = 0
    s = e.rbytes(0x6b4718, 0x80)
    n = s.index(0) + 1
    e.w32(0x700390, 0)

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    hit = r.random() < 0.6
    w = obj(c, 0x30, {0x25c: pystub(c, 2, this=True, deref={0: -n}, ret=r.getrandbits(32) | 1 if hit else 0)})
    hook_rec(c, 0x4db2f0, 1, this=True, ret=w)
    owner = rnd(c, 0x20)
    own = rnd(c, 0x20)
    e.w32(own + 8, owner)
    e.w32(own + 4, rnd(c, 0x10) if r.random() < 0.7 else 0)
    a = rnd(c, 0x40)
    e.w32(a + 0x1c, own)
    e.w32(a + 0x10, obj(c, 0x20, {0x4: pystub(c, 1, this=True)}))
    this = rnd(c, 0x60)
    e.w32(this + 0x44, obj(c, 0x20, {0x12c: pystub(c, 3, this=True), 0x130: pystub(c, 3, this=True)}))
    e.wbytes(0x714348, r.getrandbits(16).to_bytes(2, 'little'))
    return [this, a]


S(0x5c7570, 'GUESS lookup_register_name', 'thiscall', None, ret=None, gen=_g5c7570, note='batch37095')
