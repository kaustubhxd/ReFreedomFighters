"""specs_s908.py - unclaimed-01 claim 7 (docs/20-unclaimed-01.md): ZActor::GetAnimOffset (0x478b00). The vtable is a
logging fake with slot +0x21c returning a per-case value (zero 30% of the time) and logging its argument; the global at
0x70039c points to an object whose +0x9b pointer targets a record with the subtracted dword at +0x44."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _getanim(c):
    v = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    o = _rnd(c, 0x100)
    vt = c.emu.logging_vtable('ZActor', 0x88, impl={0x21c: (lambda e, args, v=v: (v, None))}, argwords={0x21c: 1})
    c.emu.w32(o, vt)
    g = _rnd(c, 0x100)
    m = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, m)
    c.emu.w32(0x70039c, g)
    return [o, _rnd(c, 16)]


S(0x478b00, 'ZActor::GetAnimOffset (unknown) thiscall', 'thiscall', None, ret='eax', gen=_getanim,
  note='unclaimed-01 claim 7; slot +0x21c logged; subtracts dword +0x44 of the global object chain')
