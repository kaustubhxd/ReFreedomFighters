"""specs_s2703.py - unclaimed-27 claim 3 (docs/20-unclaimed-27.md): ZMoveOnSpline::StopSound (0x514560). The global at
0x70039c is a fresh 0x800-byte object with a random dword at +0x40 and a pointer at +0x9b to G9 (fresh). G9's slot +0x60
(one argument) returns P or 0 (stub, NOT verified). The player object (this) is 0x800 random bytes with +0x1ed pointing to
a fresh object whose slot +0x40 (one argument) is a stub that counts calls (NOT verified). P is a fresh 0x800-byte object
with random floats at +0x88. Both sides write the same fields of P, which the harness compares."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _ss(c):
    cnt = c.emu.alloc(0x10, 4)
    # object at this+0x1ed: vtable slot +0x40 (thiscall, one argument): inc [cnt]; ret 4
    ovt = c.emu.alloc(0x800, 4)
    c.emu.w32(ovt + 0x40, _stub(c, b'\xff\x05' + cnt.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    obj = _rnd(c, 0x800)
    c.emu.w32(obj, ovt)
    # the player: +0x1ed points to obj
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x1ed, obj)
    # P: the object returned by G9's slot +0x60
    p = _rnd(c, 0x800)
    # G9: slot +0x60 (thiscall, one argument, ret 4) returns P, or 0
    p_ret = p if c.rng.random() < 0.75 else 0
    g9vt = c.emu.alloc(0x800, 4)
    c.emu.w32(g9vt + 0x60, _stub(c, b'\xb8' + p_ret.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    g9 = _rnd(c, 0x800)
    c.emu.w32(g9, g9vt)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, g9)
    c.emu.w32(g + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, g)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x514560, 'ZMoveOnSpline::StopSound (unknown) thiscall', 'thiscall', None, ret=None, gen=_ss,
  note='unclaimed-27 claim 3; G9 slot +0x60 and the this+0x1ed slot +0x40 are stubs')
