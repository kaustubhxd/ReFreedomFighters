"""specs_s67564.py - cascade s6 batch 67564 (0x575bd0, thiscall() plain ret, return value unused). Five entries at this+0x240 (stride 0x24): flag dword +0 (pointing at a name holder when set), source object +4
with slot 0x84 (fills the stack record: stack-marked pointer, writes 12 bytes); this[0x94] is a heap block; the manager at sys[0x9b][0xae4] has slot 0 (2 args); the slot objects (array at this+0x190, count limit
this[0x1fe]) have slots 0x284 / 0xbc / 0x260; 0x5b1000 (bool, high bits garbage) is a hook; 0x574af0 is a custom stub logging the record contents, the flag byte and the slot object."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g575bd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    mgr = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=lambda em, k: 0x4000 + k)})
    so = sysobj(c, table_slots={}, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 0xae4, mgr)
    hook_rec(c, 0x5b1000, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x101, 0xff00, 0xff01]))

    def s84(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))

    def stub574(em, res_):
        rec = em.arg32(1)
        em.calllog.append(('574af0', em.reg('ecx'), em.arg32(0), em.rbytes(rec, 12), em.arg32(2) & 0xff, em.arg32(3), em.arg32(4)))
        em.ret(eax=0, argbytes=20)
    e.hook(0x574af0, stub574)
    t = rnd(c, 0x600)
    _w(c, t + 0x94, rnd(c, 0x600))
    lim = r.choice([0, 1, 2, 3, 5])
    _w(c, t + 0x1fe, lim)
    for i in range(5):
        s = obj(c, 0x20, {0x284: pystub(c, 1, this=True), 0xbc: pystub(c, 1, this=True), 0x260: pystub(c, 1, this=True)})
        _w(c, t + 0x190 + 4 * i, s)
        base = t + 0x240 + 0x24 * i
        if r.random() < 0.8:
            nh = rnd(c, 0x10)
            _w(c, nh + 4, r.choice([0, rnd(c, 8)]))
            _w(c, base, nh)
        else:
            _w(c, base, 0)
        if r.random() < 0.85:
            src = obj(c, 0x20, {0x84: pystub(c, 1, this=True, stackmark=(0,), side=s84)})
            _w(c, base + 4, src)
        else:
            _w(c, base + 4, 0)
    return [t]


S(0x575bd0, 'GUESS refresh_entries', 'thiscall', None, ret=None, gen=_g575bd0, note='batch67564')
