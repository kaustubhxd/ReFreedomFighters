"""specs_s4004.py - area 70 batch 4004: 0x59e650 (pure countdown scan over 16-byte entries) and 0x5a8510 (byte stores,
then a tail jump to slot 0x14 of the object at +0x634; the callee is a GUESS stub that logs its two arguments)."""
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


def _scan(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x900, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x900)))
    count = r.choice([0, 1, 2, 3, 7, 0x20])
    e.w32(self_ + 0x7ce, count)
    # keys are small signed numbers so the signed compare goes both ways
    for k in range(0, 0x21):
        e.w32(self_ + 0x7c2 + 16 * k, (r.randint(-40, 40) & 0xffffffff))
    arg = r.randint(-40, 40) & 0xffffffff
    return [self_, arg]


def _tail(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x800, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x800)))
    o = e.alloc(0x100, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    def s14(em, a):
        em.calllog.append(('s14', a[0], a[1] & 0xffffffff))
        return 0, ()
    e.w32(o, _vt(c, 'obj14', {0x14: (2, s14)}, 0x18 // 4))
    e.w32(self_ + 0x634, o)
    a1 = r.getrandbits(32) if r.random() < 0.8 else 0
    return [self_, a1, r.getrandbits(32)]


S(0x59e650, 'countdown scan (name GUESS)', 'thiscall', None, gen=_scan, note='batch4004')
S(0x5a8510, 'byte stores then tail jump slot 0x14 (name GUESS)', 'thiscall', None, gen=_tail, note='batch4004')
