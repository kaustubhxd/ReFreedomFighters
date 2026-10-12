"""specs_s805.py - unclaimed-08 batch 805 (docs/20-unclaimed-08.md): ZItemTemplateAmmo::CopyData(const ZGEOM*), thiscall, ret 4.

As batch 804: the destination and source are 0x100 random bytes, the destination's vtable +0x48 is a logging stub (the
virtual tail call of the base copy, unverified), the source's vtable +0x1e0 is a logging stub returning a random bool.
The base copy 0x43f8c0 runs the original code."""
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
    dvt = c.emu.fake_vtable('ZItemTemplateAmmo dst', 0x50 // 4 + 1, slots={
        0x48: _slot('ZItemTemplateAmmo dst base copy (stub)', 0x48, 1, lambda e, a: (0, None))})
    c.emu.w32(dst, dvt)
    svt = c.emu.fake_vtable('ZGEOM src', 0x1e0 // 4 + 1, slots={
        0x1e0: _slot('ZGEOM src', 0x1e0, 1, lambda e, a: (c.rng.randint(0, 1), None))})
    c.emu.w32(src, svt)
    return [dst, src]


S(0x46caf0, 'ZItemTemplateAmmo::CopyData (unknown)', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-08 batch 5; base copy 0x43f8c0 original; flag 0x1007d5 stubbed; +0x7c..+0x94 copied')
