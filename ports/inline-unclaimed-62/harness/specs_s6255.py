"""specs_s6255.py - ragdoll side (claim 48): 0x6452f0 ZBoneModifyBase::ActivateRagdoll (thiscall, four stack arguments: lnk pointer and three bytes; ret 0x10;
returns al). The object's vtable (slots 0x34 returning a bit, 0x58 returning a word) is logged; the lnk object's slot 0x334 is logged and its +8 pointer
gives an object whose word at +0x5a is set or not; the engine's +0x190f object has slot 0x20 returning obj2, whose slot 0x5c (two arguments) is logged.
The helpers 0x641b60, 0x642140, 0x644630, 0x640fe0 and 0x641c50 are recording stubs by address (GUESS). Debug report (line 0x50f) is the logged stub with the
assert hook installed for the over-range case (this+0x11 > 0x60). No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _rep(c):
    e = c.emu
    rep = e.alloc(16)

    def log(em, rr):
        em.calllog.append(('report',) + tuple(em.arg32(k) for k in range(2)))
        em.ret(argbytes=0)
    e.w32(rep, e.fake_vtable('rep6255', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6255', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6255', hook))


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    stubs = {
        0x641b60: ('641b60', 4, 1),
        0x642140: ('642140', 4, 1),
        0x644630: ('644630', 4, 1),
        0x640fe0: ('640fe0', 0, 0),
        0x641c50: ('641c50', 4, 1),
    }
    for addr, (name, nb, na) in stubs.items():
        def mk(name=name, nb=nb, na=na, addr=addr):
            def h(em, rr):
                em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(k) for k in range(na)))
                if addr == 0x642140:
                    em.ret(eax=r.choice([0, 0x123400 + r.getrandbits(8) * 8]), argbytes=nb)
                else:
                    em.ret(argbytes=nb)
            return h
        e.hook(addr, mk())

    # the ZBoneModifyBase object: its first dword is its vtable (slots 0x34, 0x58)
    rec = rnd(c, 0x300)
    t34 = r.choice([0, 1])
    obj58 = r.getrandbits(32)
    e.w32(rec, vtable(c, 'zbm6452', 0x100, impl={0x34: lambda em, a: t34, 0x58: lambda em, a: obj58},
                      argwords={0x34: 0, 0x58: 1}))
    e.w32(rec + 0x11, r.choice([0x10, 0x60, 0x61, 0x80]))
    cont = rnd(c, 0x80)
    e.w32(rec + 0x28d, cont)
    e.w32(rec + 0x291, 0 if r.random() < 0.4 else rnd(c, 0x100))
    e.w8(rec + 0x295, r.choice([0, 1]))

    # the lnk object: its vtable slot 0x334 is logged; its +8 pointer has a word at +0x5a
    lnk = rnd(c, 0x100)
    e.w32(lnk, vtable(c, 'lnk6452', 0x400, impl={0x334: lambda em, a: 0}, argwords={0x334: 0}))
    o8 = rnd(c, 0x100)
    e.w32(o8 + 0x5a, r.choice([0, 1]))
    e.w32(lnk + 8, o8)

    # the engine's +0x190f object: slot 0x20 returns obj2, whose slot 0x5c (two arguments) is logged
    obj2 = rnd(c, 0x100)
    e.w32(obj2, vtable(c, 'obj2_6452', 0x400, impl={0x5c: lambda em, a: 0}, argwords={0x5c: 2}))
    obj190 = rnd(c, 0x100)
    e.w32(obj190, vtable(c, 'o190_6452', 0x100, impl={0x20: lambda em, a: obj2}, argwords={0x20: 0}))
    eng = e.alloc(0x2000)
    e.w32(eng + 0x190f, obj190)
    e.w32(0x70039c, eng)

    a2 = r.choice([0, 0, 1])
    return [rec, lnk, a2, r.choice([0, 1]), r.choice([0, 1])]


S(0x6452f0, 'unnamed 0x6452f0', 'thiscall', None, ret='al', gen=_x, n=1000)
