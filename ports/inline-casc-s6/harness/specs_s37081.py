"""specs_s37081.py - cascade s6 batch 37081 (0x58eb50, thiscall(a) ret 4). Slot 0x4c of the table object takes 1 argument at the first site and 3 (this, 0, 1) at two others; its
stub pops 4 and logs the extra two arguments when the first one is the owner. All other callees are vtable stubs on spec objects; 0x473000 is a recording hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g58eb50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x473000, 1, this=True)
    vals = [0, 1, 0x40, r.getrandbits(32)]
    Tbox = []

    def t4c(em, res_):
        a0 = em.arg32(0)
        if Tbox and a0 == Tbox[0]:
            em.calllog.append(('4c3', a0, em.arg32(1), em.arg32(2), em.reg('ecx')))
            em.ret(eax=r.choice(vals), argbytes=12)
        else:
            em.calllog.append(('4c1', a0, em.reg('ecx')))
            em.ret(eax=r.choice(vals), argbytes=4)
    so = sysobj(c, table_slots={0x4c: e.stub_fn('4c', t4c)}, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 0xadc, r.getrandbits(32))

    def mk3():
        return obj(c, 0x40, {0x2f0: pystub(c, 1, this=True), 0x320: pystub(c, 0, this=True, ret=r.choice([0, 3, 0xfffffffe])),
                             0x324: pystub(c, 1, this=True), 0x2d0: pystub(c, 2, this=True)})
    B = mk3()
    r2 = mk3()
    found = mk3()
    q = obj(c, 0x40, {0x2c4: pystub(c, 1, this=True, ret=r2)})
    types = [r.choice([0xc, 0xb, 0, 5, 0xc]) for _ in range(2)]
    o = obj(c, 0x40, {0x330: pystub(c, 0, this=True, ret=lambda em, k: types[min(k, 1)]),
                      0x2c4: pystub(c, 2, this=True, ret=B)})
    cnt = r.choice([0, 1, 2, 3, 0xffffffff])
    A = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101])),
                      0x2e8: pystub(c, 0, this=True, ret=o), 0x35c: pystub(c, 0, this=True, ret=cnt),
                      0x328: pystub(c, 0, this=True, ret=q), 0x360: pystub(c, 1, this=True)})
    fnd = found if r.random() < 0.5 else 0
    T = obj(c, 0x900, {0x20: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0x55c: pystub(c, 1, this=True, ret=fnd)})
    Tbox.append(T)
    return [T, A]


S(0x58eb50, 'GUESS attach_entity', 'thiscall', None, ret=None, gen=_g58eb50, note='batch37081')
