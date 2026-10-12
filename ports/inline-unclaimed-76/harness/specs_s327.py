"""specs_s327.py - gap band, batch 327: 0x6079d0 (stdcall, two arguments). The helper 0x64fec0 is hooked (recorded). The engine global's
+0x190f object has a vtable: slot 0x290 (thiscall, no arguments) returns a second object whose vtable slot 8 (thiscall, one argument)
returns a per-run value and logs its argument."""
from pilot import S


def _rec(em, r):
    # 0x64fec0 (stdcall, two arguments): recorded by address; the callee pops
    em.calllog.append(('h64fec0', 0, None, (em.arg32(0), em.arg32(1))))
    em.ret(eax=0, argbytes=8)


def _gen(c):
    e = c.emu
    rng = c.rng
    e.hook(0x64fec0, _rec)
    rv = rng.getrandbits(32)

    def slot8(em, r):
        em.calllog.append(('slot8', 8, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    def slot290(em, r):
        em.calllog.append(('slot290', 0x290, em.reg('ecx'), ()))
        em.ret(eax=robj, argbytes=0)

    robj = e.alloc(0x40, 4)
    e.w32(robj, e.fake_vtable('robj327', 0x40, {8: slot8}))
    obj = e.alloc(0x400, 4)
    e.w32(obj, e.fake_vtable('obj327', 0x400, {0x290: slot290}))
    eng = e.alloc(0x2000, 4)
    e.wbytes(eng, bytes(rng.getrandbits(8) for _ in range(0x2000)))
    e.w32(eng + 0x190f, obj)
    e.w32(0x70039c, eng)
    return [rng.getrandbits(32), rng.getrandbits(32)]


S(0x6079d0, 'run6079d0 (GUESS)', 'stdcall', None, ret='eax', gen=_gen, note='batch327; ret 8; helper 0x64fec0 hooked')
