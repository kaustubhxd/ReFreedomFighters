"""specs_s38073.py - cascade s8 batch 38073. thiscall(this) void; this = 0x70-byte random block whose owned pointers (+0x14 / 0x1c / 0x18 records {object +0, buffer +4, object +0x10}, +8 / +0x2c objects, +0xc / 0x30 / 0x40 / 0x44 /
0x51 / 0x55 / 0x5d buffers, +4 a list object with begin / next stubs) are each null or valid with probability ~0.7. 0x634273 (free(ptr, size)) is a custom hook logging every call; the objects' slot 0 (deleting destructor)
logs its this and argument; the global object at 0x70038c has slot 0xdc; the list's next stub is stateful (it[0] = valid, it[1] = index) and logs no stack address."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g496db0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def freeh(em, res_):
        em.calllog.append(('free', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, freeh)

    def dtor(name):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0)))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn(name, h)

    def mkobj():
        return obj(c, 0x20, {0: dtor('dtor')})

    def maybe(f):
        return f() if r.random() < 0.7 else 0

    def buf():
        return rnd(c, 0x20)

    def record():
        rec = rnd(c, 0x14)
        e.w32(rec, maybe(mkobj))
        e.w32(rec + 4, maybe(buf))
        e.w32(rec + 0x10, maybe(mkobj))
        return rec
    e.w32(0x70038c, obj(c, 0x20, {0xdc: e.stub_fn('s-dc', lambda em, res_: (em.calllog.append(('dc', em.reg('ecx'))), em.ret(eax=0)))}))
    ids = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3, 5]))]

    def begin(em, res_):
        p = em.arg32(0)
        em.w32(p, 0)
        em.w32(p + 4, 0)
        em.calllog.append(('begin', em.reg('ecx')))
        em.ret(eax=0, argbytes=4)

    def nxt(em, res_):
        p = em.arg32(0)
        i = em.r32(p + 4)
        ok = i < len(ids)
        em.w32(p, 1 if ok else 0)
        em.w32(p + 4, i + 1)
        em.calllog.append(('next', em.reg('ecx'), i, ok))
        em.ret(eax=(ids[i] if ok else 0), argbytes=4)
    lst = obj(c, 0x20, {0: dtor('dtor-list'), 0x4c: e.stub_fn('begin', begin), 0x5c: e.stub_fn('next', nxt)})
    this = rnd(c, 0x70)
    for off, v in ((0x14, maybe(record)), (0x1c, maybe(record)), (0x18, maybe(record)), (8, maybe(mkobj)), (0x2c, maybe(mkobj)),
                   (0xc, maybe(buf)), (0x30, maybe(buf)), (0x40, maybe(buf)), (0x44, maybe(buf)), (0x51, maybe(buf)), (0x55, maybe(buf)), (0x5d, maybe(buf)),
                   (4, lst if r.random() < 0.8 else 0)):
        e.wbytes(this + off, struct.pack('<I', v))
    return [this]


S(0x496db0, 'GUESS release owned objects and buffers', 'thiscall', None, ret=None, gen=_g496db0, note='batch38073')
