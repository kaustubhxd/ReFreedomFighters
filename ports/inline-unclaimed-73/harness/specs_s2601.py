"""specs_s2601.py - area 73 batch 1 (residue 12): GUESS FUN_481180 (0x481180) and GUESS FUN_5eaf80 (0x5eaf80).
Helpers 0x480ff0 (thiscall, no args) and 0x45c510 (cdecl, one arg) and 0x4690b0 (bare ret, cdecl, two args) are hooked to
logging stubs. For 0x5eaf80: the object at this+8 has logging slots +0x704 (one arg) and +0x128 (one arg); the render
manager at g_sys+0x9b has slot +0x114 (six args, returns a dword whose low word is used)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _hooks(c):
    e = c.emu

    def h480ff0(em, r):
        em.calllog.append(('480ff0', 0, em.reg('ecx'), ()))
        em.ret()

    def h45c510(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(argbytes=0)

    def h4690b0(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    e.hook(0x480ff0, h480ff0)
    e.hook(0x45c510, h45c510)
    e.hook(0x4690b0, h4690b0)


def _flag(c):
    _hooks(c)
    o = _rnd(c, 0x100)
    return [o, c.rng.choice([0, 1, 2, 4, 5, 6, c.rng.getrandbits(32)])]


def _load(c):
    e = c.emu
    _hooks(c)
    o8 = _rnd(c, 0x100)
    e.w32(o8, e.logging_vtable('o8', 0x708 // 4, impl={0x704: _const(0), 0x128: _const(0)},
                               argwords={0x704: 1, 0x128: 1}))
    self_o = _rnd(c, 0x100)
    e.w32(self_o + 8, o8)
    ctl = _rnd(c, 0x100)
    word = c.rng.getrandbits(32)
    e.w32(ctl, e.logging_vtable('rendermgr', 0x118 // 4, impl={0x114: _const(word)}, argwords={0x114: 6}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [self_o]


S(0x481180, 'GUESS FUN_481180 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_flag,
  note='area 73 batch 1; flag helper: 0x480ff0, then 0x45c510 or 0x4690b0(this, 0x64b)')
S(0x5eaf80, 'GUESS FUN_5eaf80 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load,
  note='area 73 batch 1; o8 slots +0x704, +0x128; render manager slot +0x114 with six args')
