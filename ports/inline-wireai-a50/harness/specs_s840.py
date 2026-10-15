"""specs_s840.py - area 50, batch 840: 0x55ad10. The slot accessor (0x5003d0) is hooked: it returns records from a table
per (object, index). The vector virtual (vt +0x84) fills the vector; the logger and the assert hook are logged."""
import struct
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _gen(c):
    e, r = c.emu, c.rng
    recs = {}

    def slot_get(e, res):
        obj, idx = e.reg('ecx'), e.arg32(0)
        rec = recs.get((obj, idx))
        if rec is None:
            rec = rnd(c, 0x10)
            e.wf32(rec, c.fv(-50, 50))
            e.w8(rec + 4, r.choice([0, 2, 0, 2, 1, 3]))
            recs[(obj, idx)] = rec
        e.calllog.append(('slot.get', idx))
        e.ret(eax=rec, argbytes=4)

    def printf_(e, res):
        fmt, msg = e.arg32(1), e.arg32(2)
        e.calllog.append(('log.printf', e.cstr_read(fmt) if False else e.rbytes(fmt, 20).split(b'\0')[0],
                          e.rbytes(msg, 16).split(b'\0')[0]))
        e.ret(eax=0, argbytes=0)

    def where(e, res):
        e.calllog.append(('log.where', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    only_hooks(c, {0x5003d0: slot_get})
    sink = e.fake_object('sink', 0x10, nslots=12, slots={0x2c: printf_})
    lg = e.fake_object('logger', 0x10, nslots=9, slots={0x20: where})
    e.w32(0x700390, lg)
    hk = e.stub_fn('assert_hook', lambda e, res: (e.calllog.append(('assert',)), e.ret(eax=0, argbytes=0)))
    e.w32(0x7003b0, hk)

    src = rnd(c, 0x20)
    dst = rnd(c, 0x20)
    srcobj = rnd(c, 0x20)
    dstobj = rnd(c, 0x20)
    e.w32(src + 4, srcobj)
    e.w32(dst + 8, dstobj)
    e.w32(src + 4, srcobj)
    def vec_get(e, res):
        p = e.arg32(0)   # a local: write the values and log their content, not the address
        for i in range(3):
            e.wf32(p + 4 * i, [1.25, -2.5, 3.75][i])
        e.calllog.append(('vec.Get', struct.unpack('<3I', e.rbytes(p, 12))))
        e.ret(eax=0, argbytes=4)
    self = vt_object(c, 0x40, {0x84: vslot('owner.GetVec3', 1)}, nslots=0x40, name='owner')
    e.w32(self + 0x1c, vt_object(c, 0x40, {0x84: vec_get}, nslots=0x40, name='vecobj'))
    # the argument a: [a+4] = source record object, [a+8] = destination record object
    a = rnd(c, 0x20)
    e.w32(a + 4, srcobj)
    e.w32(a + 8, dstobj)
    return [self, a]


S(0x55ad10, 'area50 0x55ad10 (no GC name)', 'thiscall', None, gen=_gen, note='area50 batch840')
