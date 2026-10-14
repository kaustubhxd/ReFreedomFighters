"""specs_s36051.py - cascade s4 batch 36051: 0x6402b0 (gather children of an owner and refresh), 0x464d00 (refresh entries and drop finished ones)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _g6402b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    def h65(em, rr):
        base = em.reg('ecx') - 0x8270
        em.calllog.append(('65f2f0', em.reg('ecx'), bytes(em.rbytes(base + 5, 3))))
        em.ret(0, 0)
    e.hook(0x65f2f0, h65)
    hook_rec(c, 0x640590, 0, this=True)

    def h63(em, rr):
        arr, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('63d4a0', em.reg('ecx'), n, tuple(em.r32(arr + 4 * i) for i in range(n))))
        em.ret(0, 8)
    e.hook(0x63d4a0, h63)
    a = rnd(c, 0x110)
    for off in (0xfd, 0x101):
        if r.random() < 0.4:
            e.w32(a + off, 0)
    n = r.choice([0, 1, 2, 3, 6])
    s = obj(c, 0x8300, {0xcc: pystub(c, 0, this=True), 0xb8: pystub(c, 0, this=True)})
    e.wbytes(s + 5, bytes([r.choice([0, 1, 1, 1, 0x80])]))
    e.w32(s + 0xec, n)
    other = rnd(c, 0x20)
    for i in range(n):
        vt = e.alloc(0x10, 4)
        e.w32(vt, pystub(c, 0, this=True))
        e.w32(vt + 4, pystub(c, 0, this=True))
        ch = e.alloc(0x10060, 16)
        e.w32(ch, vt)
        e.w32(ch + 0x10051, a if r.random() < 0.5 else other)
        e.w32(s + 0xf0 + 4 * i, ch)
    return [s, a]


def _g464d00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x462510, 1, this=True)
    n = r.choice([0, 1, 2, 3])
    arr = e.alloc(0x18 * 4, 4)
    e.wbytes(arr, bytes([0x55]) * (0x18 * 4))
    def mkx():
        x = rnd(c, 0x80)
        q = rnd(c, 0x90)
        e.wbytes(q + 0x7c, bytes([r.choice([0, 0x10, 0x20, 0x30, 0x40, 0x01, 0x4f])]))
        e.w32(x + 0x70, q)
        return x
    for i in range(n):
        e.wbytes(arr + 0x18 * i + 4, bytes([r.choice([0, 1, 1, 3, 2])]))
        e.w32(arr + 0x18 * i + 0x14, mkx())
    elems = []
    for _ in range(r.choice([0, 1, 2, 3])):
        el = rnd(c, 0x80)
        q = rnd(c, 0x90)
        e.wbytes(q + 0x7c, bytes([r.choice([0, 0x10, 0x20, 0x30, 0x40, 0x01, 0x4f])]))
        e.w32(el + 4 + 0x70, q)
        elems.append(el)
    lst = reftab(c, elems)
    s = obj(c, 0x40, {0x274: pystub(c, 0, this=True), 0x340: pystub(c, 2, this=True)})
    e.w32(s + 0x18, 0 if r.random() < 0.1 else lst)
    e.w32(s + 0x1c, arr)
    e.w32(s + 0x20, n)
    return [s, r.choice([0, 0, 1, 0x100, 0x2, 0xff])]


S(0x6402b0, 'GUESS gather children of an owner and refresh', 'thiscall', None, ret=None, gen=_g6402b0, note='batch36051')
S(0x464d00, 'GUESS refresh entries and drop finished ones', 'thiscall', None, ret=None, gen=_g464d00, note='batch36051')
