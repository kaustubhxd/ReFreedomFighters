"""specs_s934.py - unclaimed-80 group (docs/20-unclaimed-80.md): ZSTDOBJ::CheckBoxInside (0x43df80) and ZSTDOBJ::CheckPointInside
(0x43dfb0). The global at 0x70039c holds the object at +0x1aa3, whose +0x18 is the object O; O's slots +0x20 (four arguments) and
+0x1c (three) are logging fakes returning per-case values. The this object's +8 record holds a value at +0x6c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _setup(c):
    rv = c.rng.getrandbits(32)
    O = _rnd(c, 0x40)
    c.emu.w32(O, _fake(c, 'ZSTDOBJ_O', 0x90, {0x20: (4, lambda e, a, v=rv: (v, None)),
                                             0x1c: (3, lambda e, a, v=rv: (v ^ 1, None))}))
    T = _rnd(c, 0x40)
    c.emu.w32(T + 0x18, O)
    g = _rnd(c, 0x1ab0)
    c.emu.w32(g + 0x1aa3, T)
    c.emu.w32(0x70039c, g)
    S = _rnd(c, 0x80)
    self_o = _rnd(c, 0x20)
    c.emu.w32(self_o + 8, S)
    return self_o


def _box(c):
    self_o = _setup(c)
    return [self_o, _rnd(c, 12), _rnd(c, 12), _rnd(c, 12)]


def _point(c):
    self_o = _setup(c)
    return [self_o, _rnd(c, 12), c.rng.getrandbits(32)]


S(0x43df80, 'ZSTDOBJ::CheckBoxInside (unknown) thiscall', 'thiscall', None, ret='eax', gen=_box,
  note='unclaimed-80 group; slot +0x20 with four arguments (value at +0x6c first)')
S(0x43dfb0, 'ZSTDOBJ::CheckPointInside (unknown) thiscall', 'thiscall', None, ret='eax', gen=_point,
  note='unclaimed-80 group; slot +0x1c with three arguments (value at +0x6c first; float as bits)')
