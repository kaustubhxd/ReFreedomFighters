"""specs_s5758.py - unclaimed-57, band batch 58 (GUESS): 0x5c4580, the destructor shape with an SEH frame (tagged: the fs:[0] frame and the cookie are
not reproduced; the harness raises no exception). Hook: 0x41e2c0 (cdecl, one argument, logged). Stub: the engine object's slot +0x34 (one argument)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dt(c):
    def h(em, r):
        em.calllog.append(('41e2c0', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x41e2c0, h)
    vt = c.emu.logging_vtable('band5c4580_eng', 16, argwords={0x34: 1})
    eo = _rnd(c, 0x40)
    c.emu.w32(eo, vt)
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x9b, eo)
    c.emu.w32(0x70039c, eng)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x4c, c.rng.getrandbits(32))
    return [obj]


S(0x5c4580, 'unnamed_5c4580 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_dt,
  note='unclaimed-57 band batch 58; SEH-TAG (fs:[0] frame not reproduced); 0x41e2c0 hooked (logged); engine slot +0x34 stubbed')
