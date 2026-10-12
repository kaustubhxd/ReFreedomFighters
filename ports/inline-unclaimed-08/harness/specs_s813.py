"""specs_s813.py - unclaimed-08 batch 813 (docs/20-unclaimed-08.md): ZMovementGuide::ClassInit2 (thiscall, no args) and
ZFFMortar::PlayAnimation(ZIKLNKOBJ*, char*) (stdcall, ret 8). Their engine and object vtable calls are logging stubs.
The ZFFMortar call with five arguments pops 0x14 bytes (the stub does the same)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _cig2(c):
    self = _rnd(c, 0x400)
    ref = c.emu.fake_object('ref 0xadc', 0x40, vtable=c.emu.fake_vtable('ref 0xadc', 0x25c // 4 + 1, slots={
        0x25c: _slot('ref 0xadc (stub)', 0x25c, 2, lambda e, a: (c.rng.getrandbits(32), None))}))
    db = _rnd(c, 0xb00)
    c.emu.w32(db + 0xadc, ref)
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    return [self]


def _pa(c):
    obj = _rnd(c, 0x400)
    name = c.emu.alloc(0x20)
    vt = c.emu.fake_vtable('ZIKLNKOBJ', 0x228 // 4 + 1, slots={
        0x21c: _slot('ZIKLNKOBJ name (stub)', 0x21c, 1, lambda e, a: (c.rng.getrandbits(32), None)),
        0x228: _slot('ZIKLNKOBJ play (stub)', 0x228, 5, lambda e, a: (0, None))})
    c.emu.w32(obj, vt)
    return [obj, name]


S(0x488430, 'ZMovementGuide::ClassInit2 (unknown)', 'thiscall', None, ret=None, gen=_cig2,
  note='unclaimed-08 batch 13; engine ref +0xadc vtable +0x25c(0x68d404, 0) stubbed; result to +0x375')
S(0x5dd470, 'ZFFMortar::PlayAnimation (unknown)', 'stdcall', None, ret=None, gen=_pa,
  note='unclaimed-08 batch 13; vtable +0x21c (name) and +0x228 (r, 1, 0, -1, 1) stubbed')
