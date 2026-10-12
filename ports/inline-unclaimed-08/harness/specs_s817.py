"""specs_s817.py - unclaimed-08 batch 817 (residue 7): CRigidBody::InitCentroid(), thiscall, no arguments.

The body is 0x200 random bytes. Its rigid-body object rb (+0x44) is a fake: vtable +0x1e0 returns a random bool (the
two tests); +0x2bc writes three random floats through its first argument (the accumulator, a heap address) and is logged
without its second argument (a stack address that differs between builds); +0x84 is a logging stub. rb+0xc is an object
with a random dword at +0x23; rb+8 is an object with three random floats at +0x30. The element array at +0x14e holds up to
3 vectors of random floats; the count at +0x152 is -1..3. The helper 0x441940 (vector add) runs the original code."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]


def _init(c):
    self = _rnd(c, 0x200)
    rb_vt = c.emu.alloc(0x2bc // 4 * 4 + 16, 4)
    def slot(name, off, nargs, impl, mask=()):
        def h(e, r):
            args = [e.arg32(k) for k in range(nargs)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(None if i in mask else a for i, a in enumerate(args))))
            eax, st0 = impl(e, args)
            e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
        return h
    def w_acc(e, a):
        e.w32(a[0] + 0, _f(c)); e.w32(a[0] + 4, _f(c)); e.w32(a[0] + 8, _f(c))
        return (0, None)
    vt = c.emu.fake_vtable('rigid body', 0x2bc // 4 + 2, slots={
        0x1e0: slot('rigid body flag (stub)', 0x1e0, 1, lambda e, a: (c.rng.randint(0, 1), None)),
        0x2bc: slot('rigid body fill (stub)', 0x2bc, 3, w_acc, mask=(1,)),
        0x84: slot('rigid body set (stub)', 0x84, 1, lambda e, a: (0, None))})
    rb = c.emu.fake_object('rigid body', 0x40, vtable=vt)
    cc = _rnd(c, 0x40)
    c.emu.w32(cc + 0x23, c.rng.getrandbits(32))
    c.emu.w32(rb + 0xc, cc)
    o8 = _rnd(c, 0x40)
    c.emu.w32(rb + 8, o8)
    c.emu.w32(self + 0x44, rb)
    n = c.rng.randint(-1, 3)
    arr = _rnd(c, 12 * 4 + 16)
    c.emu.w32(self + 0x14e, arr)
    c.emu.w32(self + 0x152, n & 0xffffffff)
    return [self]


S(0x53f630, 'CRigidBody::InitCentroid (unknown)', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-08 batch 17 (residue 7, ragdoll); rigid body vtable stubbed; 0x441940 original; 1.0f/count')
