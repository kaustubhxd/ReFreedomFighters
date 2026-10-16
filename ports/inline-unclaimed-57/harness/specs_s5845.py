"""specs_s5845.py - 0x5c3f90 (FUN_005c3f90, scalar deleting destructor with an SEH frame): thiscall, one stack argument (flags), ret 4, returns this. The member m at
this+0x48 (non-null in about 70% of the cases) has slot 0 (one arg: logs). The sub-object (engine +0x9b) has slot +0x34 (one arg: logs the pointer as an offset from
this). The sized free 0x4690b0 (cdecl, two args) and the assert hook 0x7003b0 (non-null) are logging stubs. flags is random (bit 0 and bit 2 both occur)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d3f90(c):
    e = c.emu
    rnd = c.rng
    self_obj = _rnd(c, 0x100)

    def rel(p):
        return ('self', p - self_obj) if self_obj <= p < self_obj + 0x100 else ('other', p)

    def hm0(em, r):
        em.calllog.append(('m0', rel(em.arg32(0)), None, ()))  # one argument (the value 1)
        em.ret(eax=0, argbytes=4)

    def hsub(em, r):
        em.calllog.append(('sub34', rel(em.arg32(0)), None, ()))
        em.ret(eax=0, argbytes=4)

    def hfree(em, r):
        em.calllog.append(('free', 'self' if em.arg32(0) == self_obj else 'other', em.arg32(1), ()))
        em.ret(eax=0, argbytes=0)

    def hassert(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x4690b0, hfree)
    e.w32(0x7003b0, e.stub_fn('assert', hassert))
    vt_m = e.fake_vtable('d3f90_m', 200, {0x0: hm0})
    vt_sub = e.fake_vtable('d3f90_sub', 200, {0x34: hsub})
    m_obj = _rnd(c, 0x40)
    e.w32(m_obj, vt_m)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    e.w32(self_obj + 0x48, m_obj if rnd.random() < 0.7 else 0)
    e.w32(self_obj + 0x44, rnd.getrandbits(32))
    e.w32(self_obj + 0x30, rnd.getrandbits(32))
    flags = rnd.choice([0, 1, 2, 3, 4, 5, 6, 7, rnd.getrandbits(32)])
    return [self_obj, flags]


S(0x5c3f90, 'FUN_005c3f90 (SEH scalar deleting dtor) thiscall', 'thiscall', None, ret='eax', gen=_d3f90,
  note='fresh-12 family: naked SEH frame; member slot 0, sub slot +0x34, free 0x4690b0 and assert hook 0x7003b0 (non-null) logged')
