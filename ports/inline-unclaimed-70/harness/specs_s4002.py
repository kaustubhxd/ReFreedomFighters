"""specs_s4002.py - area 70 batch 4002: wrappers 0x463010 and 0x481510. Virtual targets are stubs (classes GUESS).
The slot-0x58 stub takes one stack argument (the object pointer the wrapper pushes) and logs its value; the slot-0x1c
stub takes no arguments and logs that it was called."""
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


def _w58(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    sub = e.alloc(0x40, 4)
    e.w32(sub, _vt(c, 'sub58', {0x58: (1, lambda em, a: (r.getrandbits(32), (a[0] == self_,)))}, 0x5c // 4))
    e.w32(self_ + 0x6c, sub)
    return [self_]


def _w1c(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x500, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x500)))
    sub = e.alloc(0x40, 4)
    e.w32(sub, _vt(c, 'sub1c', {0x1c: (0, lambda em, a: (0, ()))}, 0x20 // 4))
    e.w32(self_ + 0x455, sub)
    return [self_, r.getrandbits(32), r.getrandbits(32) | (0x1000 if r.random() < 0.5 else 0)]


S(0x463010, 'wrapper: slot 0x58 of +0x6c with this pushed (area 70)', 'thiscall', None, ret='eax', gen=_w58, note='batch4002')
S(0x481510, 'wrapper: slot 0x1c of +0x455 when flag 0x1000 (area 70)', 'thiscall', None, gen=_w1c, note='batch4002')
