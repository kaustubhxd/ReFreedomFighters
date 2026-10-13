"""specs_s301.py - unclaimed-43 batch 301: ZMoveOnSpline::GetAimPoint(float *out, ZGEOM *g) (0x512ea0), stdcall, ret 8.
g is a logging vtable: slot 0x1e0 is the class test (random true/false), slots 0x84 write three floats through their
pointer argument, 0x3a0 and 0x3a8 return random words, 0x398 takes one word. Values are drawn in gen, so the original and
the port see the same writes. g may be NULL (the early return).
Stack-pointer arguments (the local tmp) are logged as 'stack': the original and the port lay their frames out differently
(same rule as ladder_kit.nostack)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS = 0x3ac // 4          # slots up to 0x3a8


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _gen(c):
    r = c.rng
    out = c.bytes_(16)
    if r.random() < 0.05:
        return [out, 0]
    cls = 1 if r.random() < 0.8 else 0
    v84 = [c.fv(-10.0, 10.0) for _ in range(3)]
    x = r.getrandbits(32)
    y = r.getrandbits(32)

    def w84(e, a):
        for k, v in enumerate(v84):
            e.wf32(a[0] + 4 * k, v)
        return (None, None)

    impl = {
        0x1e0: lambda e, a: (cls, None),
        0x84: w84,
        0x3a0: lambda e, a: (x, None),
        0x3a8: lambda e, a: (y, None),
    }
    argwords = {0x1e0: 1, 0x84: 1, 0x398: 1, 0x3a0: 1, 0x3a8: 1}
    g = E.zero_obj(c, 0x400)
    c.emu.w32(g, _vtable(c, 'ZGEOM', NSLOTS, impl, argwords))
    c.emu.mu.ctl_flush_tb()
    return [out, g]


S(0x512ea0, 'ZMoveOnSpline::GetAimPoint(float*, ZGEOM*)', 'stdcall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 301; vscalar (0x4e0d00) and PSVECAdd (0x441940) are original exe code')
