"""specs_s1016.py - unclaimed-10, batch 12: ZRepositionCharacter destructor (0x5c3f90). Thiscall, one argument (flags), ret 4,
returns this. Stubs: the child at +0x48 (half the cases; vtable slot 0 with one argument), and the engine object at the global
0x70039c (its field +0x9b is the object whose slot +0x34 takes this). Operator delete paths: 0x4690b0 (sized free, cdecl,
(ptr, size)) and 0x634273 are hooked to log only. The assert hook at 0x7003b0 is a logging stub (called when bit 2 is clear)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    e = c.emu

    def log_free(em, r):
        em.calllog.append(('free', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x4690b0, log_free)
    e.hook(0x634273, log_free)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    vt_child = e.logging_vtable('child', 8, argwords={0: 1})
    vt_eng_obj = e.logging_vtable('engobj', 16, argwords={0x34: 1})
    obj = _rnd(c, 0x800)
    if c.rng.random() < 0.5:
        child = _rnd(c, 0x40)
        e.w32(child, vt_child)
        e.w32(obj + 0x48, child)
    else:
        e.w32(obj + 0x48, 0)
    eng_obj = _rnd(c, 0x40)
    e.w32(eng_obj, vt_eng_obj)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, eng_obj)
    e.w32(0x70039c, eng)
    return [obj, c.rng.getrandbits(32)]


S(0x5c3f90, 'ZRepositionCharacter::~ZRepositionCharacter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-10 batch 12; child slot 0 and engine slot +0x34 stubbed; 0x4690b0 and 0x634273 logged')
