"""specs_s37059.py - cascade s6 batch 37059 (0x464f50). Helper calls are custom handlers that log their register / stack arguments (stack pointers as markers) and write random
data into the stack records they fill (0x4db2c0 -> 36 + 12 bytes, 0x441970 -> 12, 0x4de480 -> 36, 0x441940 -> 12), so the data flow is compared through the final slot 0x7c stub
(logs both records). Table slot 0x58 maps ids to objects."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, HEAP_LO, HEAP_HI


def _mk(p):
    return p if HEAP_LO <= p < HEAP_HI else 0x57ac0000


def _g464f50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def fillr(em, p, n):
        em.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))

    def h4db2c0(em, res_):
        v34, v10 = em.arg32(0), em.arg32(1)
        em.calllog.append(('4db2c0', _mk(em.reg('ecx'))))
        fillr(em, v34, 0x24)
        fillr(em, v10, 12)
        em.ret(eax=0, argbytes=8)

    def h441970(em, res_):
        em.calllog.append(('441970', _mk(em.reg('edx')), tuple(em.rbytes(em.reg('edx'), 12)), tuple(em.rbytes(em.arg32(0), 0x24))))
        fillr(em, em.reg('ecx'), 12)
        em.ret(eax=0, argbytes=4)

    def h4de480(em, res_):
        em.calllog.append(('4de480', _mk(em.reg('edx')), tuple(em.rbytes(em.reg('edx'), 12))))
        fillr(em, em.reg('ecx'), 0x24)
        em.ret(eax=0, argbytes=0)

    def h441940(em, res_):
        em.calllog.append(('441940', tuple(em.rbytes(em.reg('edx'), 12))))
        fillr(em, em.reg('ecx'), 12)
        em.ret(eax=0, argbytes=0)
    e.hook(0x4db2c0, h4db2c0)
    e.hook(0x441970, h441970)
    e.hook(0x4de480, h4de480)
    e.hook(0x441940, h441940)

    def mkobj():
        def side(em, k):
            em.calllog.append(('o7c', tuple(em.rbytes(em.arg32(0), 0x24)), tuple(em.rbytes(em.arg32(1), 12))))
        return obj(c, 0x40, {0x7c: pystub(c, 2, this=True, stackmark=(0, 1), side=side)})
    ids = [r.randint(1, 0xffff) for _ in range(3)]
    table = {i: (mkobj() if r.random() < 0.75 else 0) for i in ids}
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0))}, table_size=0x20)
    owner = rnd(c, 0x20)
    e.w32(owner + 8, rnd(c, 0x20))
    me = obj(c, 0x140, {0x20: pystub(c, 0, this=True, ret=owner)})
    for off, i in zip((0x12a, 0x12e, 0x132), ids):
        e.wbytes(me + off, (i if r.random() < 0.85 else 0).to_bytes(4, 'little'))
    return [me]


S(0x464f50, 'GUESS refresh three attached objects', 'thiscall', None, ret=None, gen=_g464f50, note='batch37059')
