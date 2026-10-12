"""specs_s6560.py - unclaimed-68 batch 56 (claim 57): 0x5124c0 ZMoveOnSpline::ClassInit2 (residue name, medium), thiscall, no args, plain ret.
Calls the exe 0x45d3a0 first, then the body: slot +0x110(0x10, 0), slot +0x2c8([this+0xce], 0), exe 0x513d10, and if [this+0x134] is set:
its slot +0x28, exe 0x4de7a0 on a 9-dword local, then slot +0x1bc(mgr+0xadc, &local34, &local10, 0, 0, 0, 1) stored at this+0x134 and its slot +0x28.
Finally slot +0x2e4 on this. The object's vtable logs all of them."""
from pilot import S
from pe_emu import STACK_TOP
from engine_stubs import zero_obj, set_global


def _is_stk(v):
    return STACK_TOP - 0x20000 <= v < STACK_TOP


def _masked_vt(c, name, nslots, impl, argwords):
    """logging vtable whose stack-frame pointers are logged as '&stk' (the port's locals sit at other addresses)."""
    fake = {}
    for off, n in argwords.items():
        f = impl.get(off, lambda e, a: (None, None))

        def h(e, r, off=off, n=n, f=f):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple('&stk' if _is_stk(a) else a for a in args)))
            eax, st0 = f(e, args)
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        fake[off] = h
    return c.emu.fake_vtable(name, nslots, fake)


def _setup(c):
    # 0x513d10 is not ported here: stubbed by address and logged (GUESS; its effects are not modelled, as for 0x4a1270)
    c.emu.hook(0x513d10, lambda em, r: (em.calllog.append(('stub513d10',)), em.ret(eax=None, argbytes=0)))


def _gen(c):
    o_self = zero_obj(c, 0x400)
    eng = zero_obj(c, 0x400)
    mgr = zero_obj(c, 0x1000)
    set_global(c, 0x70039c, eng)
    c.emu.w32(eng + 0x9b, mgr)
    c.emu.w32(mgr + 0xadc, c.rng.getrandbits(32))
    c.emu.w32(o_self + 0xce, c.rng.getrandbits(32))

    res_vt = c.emu.logging_vtable('ZMoveSplineRes', 0x80, impl={0x28: lambda e, a: (None, None)}, argwords={0x28: 0})
    res = zero_obj(c, 0x200)
    c.emu.w32(res, res_vt)
    o_vt = _masked_vt(c, 'ZMoveSplineSub', 0x80,
                      impl={0x28: lambda e, a: (None, None),
                            0x1bc: (lambda r: (lambda e, a: (r, None)))(res)},
                      argwords={0x28: 0, 0x1bc: 7})
    o = zero_obj(c, 0x200)
    c.emu.w32(o, o_vt)
    if c.rng.random() < 0.7:
        c.emu.w32(o_self + 0x134, o)
    else:
        c.emu.w32(o_self + 0x134, 0)

    self_vt = _masked_vt(c, 'ZMoveOnSpline', 0x400, impl={}, argwords={0x110: 2, 0x2c8: 2, 0x2e4: 0})
    c.emu.w32(o_self, self_vt)
    return [o_self]


S(0x5124c0, 'ZMoveOnSpline::ClassInit2 (residue name) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 56; calls exe 0x45d3a0, 0x513d10 and 0x4de7a0; slots 0x110, 0x2c8, 0x2e4 on this')
