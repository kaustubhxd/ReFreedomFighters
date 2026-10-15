"""specs_s5705.py - unclaimed-57, batch 5: ZStartAnim scalar deleting destructor (0x485900). Thiscall, one argument (flags), returns
this. Stubs: the engine object (global 0x70039c, +0x9b) has a logging vtable with slot +0x34 (one argument); the sized free 0x4690b0
and operator delete 0x634273 are hooked to log (ptr, size); the assert hook 0x7003b0 is a logging stub (always set: with the
default int3 the original faults on the non-sized-free path)."""
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
    vt_eng = e.logging_vtable('startanim_eng', 16, argwords={0x34: 1})
    eo = _rnd(c, 0x40)
    e.w32(eo, vt_eng)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, eo)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x485900, 'ZStartAnim::~ZStartAnim (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-57 batch 5; engine slot +0x34 stubbed; 0x4690b0 (size 0xcc) and 0x634273 logged; assert hook a logging stub')
