"""specs_s4007.py - area 70 batch 4007: 0x4dcb90 (36-byte copy and flag) and 0x5f0450 (vtable store and two slot-0x14
calls on a GUESS stub object that logs its constant argument and returns a value)."""
from pilot import S, F


def _vt(c, name, slots, nslots):
    e = c.emu
    hs = {}
    for off, (nargs, fn) in slots.items():
        def h(em, rr, off=off, nargs=nargs, fn=fn):
            args = [em.arg32(k) for k in range(nargs)]
            eax, logged = fn(em, args)
            em.calllog.append((name, off, em.reg('ecx'), logged))
            em.ret(eax=eax, argbytes=4 * nargs)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def _copy(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x80, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x80)))
    src = e.alloc(0x40, 4)
    e.wbytes(src, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [self_, src]


def _vt5f(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    obj = e.alloc(0x40, 4)
    def s14(em, a):
        em.calllog.append(('s14', a[0]))
        return r.getrandbits(32), ()
    e.w32(obj, _vt(c, 'obj14', {0x14: (1, s14)}, 0x18 // 4))
    return [self_, obj]


S(0x4dcb90, 'copy 36 bytes and set flag 0x100000 (name GUESS)', 'thiscall', None, gen=_copy, note='batch4007')
S(0x5f0450, 'vtable store, two slot-0x14 lookups (name GUESS)', 'thiscall', None, ret='eax', gen=_vt5f, note='batch4007')
