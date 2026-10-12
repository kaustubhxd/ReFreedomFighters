"""specs_s804.py - unclaimed-08 batch 804 (docs/20-unclaimed-08.md): ZItemAmmo::CopyData(const ZGEOM*), thiscall, ret 4.

The destination and the source are 0x100 random bytes. The source's vtable +0x1e0 is a logging stub returning a random
bool for each of the two flags. The base copy 0x43f8c0 runs the original code; its stores land inside both objects."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl, pop=True):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs if pop else 0, st0=st0)
    return h


def _copy(c):
    dst = _rnd(c, 0x100)
    src = _rnd(c, 0x100)
    # 0x43f8c0 ends with a virtual tail call through the destination's vtable +0x48 (stub: unverified callee, logs
    # its argument, returns 0).
    dvt = c.emu.fake_vtable('ZItemAmmo dst', 0x50 // 4 + 1, slots={
        0x48: _slot('ZItemAmmo dst base copy (stub)', 0x48, 1, lambda e, a: (0, None))})
    c.emu.w32(dst, dvt)
    vt = c.emu.fake_vtable('ZGEOM src', 0x1e0 // 4 + 1, slots={
        0x1e0: _slot('ZGEOM src', 0x1e0, 1, lambda e, a: (c.rng.randint(0, 1), None))})
    c.emu.w32(src, vt)
    return [dst, src]


S(0x46c9b0, 'ZItemAmmo::CopyData (unknown)', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-08 batch 4; base copy 0x43f8c0 original; flags 0x1007d1 / 0x1007d8 stubbed')
