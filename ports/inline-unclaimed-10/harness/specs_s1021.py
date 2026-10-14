"""specs_s1021.py - unclaimed-10, batch 17: CMAINCAMERACONTROL::Load2 (0x4fcfd0). Thiscall, no arguments, ret 0.
Stubs: the engine (global 0x70039c, +0x9b) holds obj1 (slot +0x58, one argument: returns the address of r1, a stub object with
slot +0x128 (two arguments)) and obj2 (slot +0x4c, two arguments: returns a fixed value chosen in gen). The tail target 0x4fdac0
is hooked to log. The word at this+0x80 and the dword at this+0x44 / +0x78 are random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load2(c):
    e = c.emu
    r2 = c.rng.getrandbits(32)
    r1 = _rnd(c, 0x200)
    vt_r1 = e.logging_vtable('camr1', 80, argwords={0x128: 2})
    e.w32(r1, vt_r1)
    vt_cam = e.logging_vtable('cam', 32,
                              impl={0x58: lambda em, a: (r1, None), 0x4c: lambda em, a: (r2, None)},
                              argwords={0x58: 1, 0x4c: 2})
    cam = _rnd(c, 0x40)
    e.w32(cam, vt_cam)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, cam)
    e.w32(0x70039c, eng)
    e.hook(0x4fdac0, lambda em, rr: (em.calllog.append(('tail_4fdac0', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    return [_rnd(c, 0x800)]


S(0x4fcfd0, 'CMAINCAMERACONTROL::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-10 batch 17; obj1/obj2/r1 slots stubbed; tail 0x4fdac0 hooked (logged)')
