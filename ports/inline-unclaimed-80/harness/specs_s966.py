"""specs_s966.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4324d0 and 0x4253c0 (see src/batch966.cpp).
0x4324d0: the embedded object at self+0xac has a logging vtable (slot +0x84, one argument) returning r (zero 30%); r points to an object whose
+4 field points to a buffer with a per-case dword. The global object (0x70039c) has a logging vtable (slot +0x5c, two arguments; it writes a per-case
value through the second, the out-pointer, and returns 0). 0x4253c0: the object has a logging vtable (slot +0x4c, three arguments; the third is an
out-pointer; it writes a per-case value there and returns a per-case eax)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_thiscall(c):
    self_o = _rnd(c, 0x100)
    if c.rng.random() < 0.3:
        r_val = 0
    else:
        buf = _rnd(c, 0x20)
        c.emu.w32(buf, c.rng.getrandbits(32))
        r_val = _rnd(c, 0x20)
        c.emu.w32(r_val + 4, buf)
    sub_vt = c.emu.logging_vtable('ZGroupSub84', 0x22, impl={0x84: (lambda e, a, v=r_val: (v, None))}, argwords={0x84: 1})
    c.emu.w32(self_o + 0xac, sub_vt)
    out5c = c.rng.getrandbits(32)

    def impl5c(e, a, v=out5c):
        e.w32(a[1], v)
        return (0, None)

    g = _rnd(c, 0x40)
    c.emu.w32(g, c.emu.logging_vtable('ZGlobal5c', 0x18, impl={0x5c: impl5c}, argwords={0x5c: 2}))
    c.emu.w32(0x70039c, g)
    return [self_o, c.rng.getrandbits(32)]


def _gen_cdecl(c):
    out4c = c.rng.getrandbits(32)
    ret4c = c.rng.getrandbits(32)

    def impl4c(e, a, v=out4c, r=ret4c):
        e.w32(a[2], v)
        return (r, None)

    obj = _rnd(c, 0x40)
    c.emu.w32(obj, c.emu.logging_vtable('ZGroupObj4c', 0x14, impl={0x4c: impl4c}, argwords={0x4c: 3}))
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4324d0, 'embedded-object call then global call (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_thiscall,
  note='unclaimed-80 gap band; sub-object at self+0xac, slot +0x84; global slot +0x5c with out-pointer')
S(0x4253c0, 'cdecl forward with out-pointer (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen_cdecl,
  note='unclaimed-80 gap band; slot +0x4c with three arguments (third is the address of the fourth parameter)')
