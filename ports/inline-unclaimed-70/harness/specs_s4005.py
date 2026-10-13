"""specs_s4005.py - area 70 batch 4005: 0x5083d0 and 0x508290. The argument a has +4 = a 'this' for the exe 0x5003d0,
which has inner = [this] (size +8 = 0x1000) and base = [this+4]: it returns inner + base*8 (the exe runs as code).
The object at this+0x18 is a fake with a slot 0x5fc (one float arg) stub for 0x5083d0 and a plain dword at +0x678."""
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


def _case(c, fv):
    e, r = c.emu, c.rng
    # inner: +0 = a data block pointer (the exe returns [inner] + base*8), +8 = size 0x1000
    data = e.alloc(0x1000 * 8 + 0x100, 8)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x1000 * 8 + 0x100)))
    inner = e.alloc(0x20, 4)
    e.w32(inner, data)
    e.w32(inner + 8, 0x1000)
    t = e.alloc(0x20, 4)
    e.w32(t, inner)
    e.w32(t + 4, r.randint(0, 0x100))
    e.w32(t + 8, r.randint(1, 0x10))
    a = e.alloc(0x20, 4)
    e.w32(a + 4, t)
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    obj = e.alloc(0x800, 4)
    e.wbytes(obj, bytes(r.getrandbits(8) for _ in range(0x800)))
    def s5fc(em, a2):
        em.calllog.append(('s5fc', round(em.rf32(0), 6) if False else a2[0] & 0xffffffff))
        return 0, ()
    e.w32(obj, _vt(c, 'obj5fc', {0x5fc: (1, s5fc)}, 0x600 // 4))
    e.w32(self_ + 0x18, obj)
    return [self_, a]


def _scale(c):
    return _case(c, True)


def _store(c):
    return _case(c, False)


S(0x5083d0, 'read via 0x5003d0, scale by 100, slot 0x5fc (name GUESS)', 'thiscall', None, gen=_scale, note='batch4005')
S(0x508290, 'read via 0x5003d0, store dword at +0x678 (name GUESS)', 'thiscall', None, gen=_store, note='batch4005')
