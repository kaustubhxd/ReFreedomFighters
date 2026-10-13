"""specs_s4003.py - area 70 batch 4003: 0x469550 (store routine), 0x45c850 and 0x4cf210 (single-virtual members; the
virtual targets are GUESS stubs). The stubs return null or a heap block; the block's first dwords are random so the
loaded value (0x4cf210) and the bit-set (0x45c850) are both visible."""
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


def _store(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x80, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x80)))
    a = e.alloc(0x40, 4)
    e.wbytes(a, bytes(r.getrandbits(8) for _ in range(0x40)))
    b = -1 if r.random() < 0.4 else r.getrandbits(32)
    return [self_, a, b & 0xffffffff]


def _slot108(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    blk = e.alloc(0x20, 4)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x20)))
    ret_blk = blk if r.random() < 0.7 else 0
    def s108(em, a):
        em.calllog.append(('s108', a[0] & 0xffff, a[1]))
        return ret_blk, ()
    e.w32(self_, _vt(c, 'self108', {0x108: (2, s108)}, 0x10c // 4))
    a = e.alloc(0x20, 4)
    return [self_, a, r.getrandbits(32)]


def _slot60(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x40, 4)
    blk = e.alloc(0x10, 4)
    e.w32(blk, r.getrandbits(32))
    ret_blk = blk if r.random() < 0.7 else 0
    def s60(em, a):
        em.calllog.append(('s60', a[0]))
        return ret_blk, ()
    e.w32(self_, _vt(c, 'self60', {0x60: (1, s60)}, 0x64 // 4))
    return [self_, r.getrandbits(32)]


S(0x469550, 'store routine (name GUESS)', 'thiscall', None, gen=_store, note='batch4003')
S(0x45c850, 'slot 0x108 member, bit 2 set (name GUESS)', 'thiscall', None, gen=_slot108, note='batch4003')
S(0x4cf210, 'slot 0x60 member, load (name GUESS)', 'thiscall', None, ret='eax', gen=_slot60, note='batch4003')
