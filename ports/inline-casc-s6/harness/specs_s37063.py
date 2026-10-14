"""specs_s37063.py - cascade s6 batch 37063 (0x461d60). Same technique as batch 37059: the x87 helpers (0x4db2c0, 0x4419f0, 0x4de480, 0x441940) are custom handlers that log their
register arguments and fill stack records with random data; 0x4de7a0 runs as original code; the slot 0x74 stubs log both records. this/owner/manager objects are spec blocks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, HEAP_LO, HEAP_HI


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _mk(p):
    return p if HEAP_LO <= p < HEAP_HI else 0x57ac0000


def _g461d60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def fillr(em, p, n):
        em.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))

    def h4db2c0(em, res_):
        em.calllog.append(('4db2c0', _mk(em.reg('ecx'))))
        fillr(em, em.arg32(0), 0x24)
        fillr(em, em.arg32(1), 12)
        em.ret(eax=0, argbytes=8)

    def h4419f0(em, res_):
        em.calllog.append(('4419f0', tuple(em.rbytes(em.reg('edx'), 0x24)), tuple(em.rbytes(em.reg('ecx'), 12))))
        fillr(em, em.reg('ecx'), 12)
        em.ret(eax=0, argbytes=0)

    def h4de480(em, res_):
        em.calllog.append(('4de480', tuple(em.rbytes(em.reg('edx'), 0x24)), tuple(em.rbytes(em.reg('ecx'), 0x24))))
        fillr(em, em.reg('ecx'), 0x24)
        em.ret(eax=0, argbytes=0)

    def h441940(em, res_):
        em.calllog.append(('441940', tuple(em.rbytes(em.reg('edx'), 12)), tuple(em.rbytes(em.reg('ecx'), 12))))
        fillr(em, em.reg('ecx'), 12)
        em.ret(eax=0, argbytes=0)
    e.hook(0x4db2c0, h4db2c0)
    e.hook(0x4419f0, h4419f0)
    e.hook(0x4de480, h4de480)
    e.hook(0x441940, h441940)
    hook_rec(c, 0x4dc440, 1, this=True, pop=4)

    def lg74(em, k):
        em.calllog.append(('s74', tuple(em.rbytes(em.arg32(0), 0x24)), tuple(em.rbytes(em.arg32(1), 12))))
    F = rnd(c, 0x80)
    _w(c, F + 0x3c, r.choice([0, 0x4000, 0x40000, 0x44000, r.getrandbits(32)]))
    O = obj(c, 0x40, {0x74: pystub(c, 2, this=True, stackmark=(0, 1), side=lg74)})
    _w(c, O + 8, F)
    _w(c, O + 4, r.choice([0, rnd(c, 0x10)]))
    G = rnd(c, 0x80)
    M = obj(c, 0x20, {0xc: pystub(c, 1, this=True)})
    holder = rnd(c, 0x40)
    _w(c, holder + 0x18, M)
    T2 = obj(c, 0x100, {0x0: pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('d0', em.rbytes(em.reg('ecx') + 0xd0, 1))))})
    _w(c, T2 + 0xd0, r.getrandbits(8), 1)
    so = sysobj(c, table_size=0x5e00)
    tab = e.r32(so + 0x9b)
    _w(c, so + 0x1aa3, holder)
    _w(c, tab + 0x5d31, T2)
    Tt = rnd(c, 0x40)
    _w(c, Tt + 0x23, r.choice([0x200027, 0x200027, 0x100, r.getrandbits(32)]))
    me = obj(c, 0x100, {0x20: pystub(c, 0, this=True, ret=O),
                        0x74: pystub(c, 2, this=True, stackmark=(0, 1), side=lg74),
                        0x110: pystub(c, 2, this=True), 0x214: pystub(c, 0, this=True), 0x260: pystub(c, 0, this=True)})
    _w(c, me + 8, G)
    _w(c, me + 0xc, Tt)
    return [me]


S(0x461d60, 'GUESS rebind transform to owner', 'thiscall', None, ret=None, gen=_g461d60, note='batch37063')
