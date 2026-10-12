"""specs_s4621.py - area 73 batch 21 (gap band, GUESS names). Objects have logging vtables (slots +0x33c, +0x308, +0x314, +0x2ec);
the flag at +0x70 is 0x20 about half the time. FUN_4fa370's argument is 0x104 about half the time."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _obj(c, slots, argw):
    e = c.emu
    o = _rnd(c, 0x200)
    e.w32(o, e.logging_vtable('g46', 0x340 // 4, impl={k: _const(0) for k in slots}, argwords=argw))
    e.w32(o + 0x70, 0x20 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return o


def _3args(c):
    o = _obj(c, [0x33c], {0x33c: 1})
    return [o, c.rng.getrandbits(8), c.rng.getrandbits(8), c.rng.getrandbits(8)]


def _1arg(c):
    o = _obj(c, [0x308], {0x308: 0})
    a = 0x104 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [o, a]


def _unused(c):
    o = _obj(c, [0x314, 0x2ec], {0x314: 0, 0x2ec: 1})
    return [o, c.rng.getrandbits(32)]


S(0x4f3240, 'GUESS FUN_4f3240 (unknown) thiscall', 'thiscall', None, ret=None, gen=_3args,
  note='area 73 batch 21; packed ((a1<<8|a2)<<8|a3) to slot +0x33c')
S(0x4fa370, 'GUESS FUN_4fa370 (unknown) thiscall', 'thiscall', None, ret='al', gen=_1arg,
  note='area 73 batch 21; arg == 0x104 -> slot +0x308 and true')
S(0x4fa2f0, 'GUESS FUN_4fa2f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_unused,
  note='area 73 batch 21; when +0x70 != 0x20: slot +0x314 then +0x2ec(8)')
