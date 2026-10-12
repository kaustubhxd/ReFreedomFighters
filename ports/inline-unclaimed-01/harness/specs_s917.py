"""specs_s917.py - unclaimed-01 claim 16 (docs/20-unclaimed-01.md): CHitpointControl::Init (0x584580). The global list
at 0x7003b8 has a count at +0xb61 (0..10) and a write pointer at +0x4a4 with the end at +0x4a8 set one slot past it (never
full, so the exe's full-list call 0x4301c0 is not reached). The render sub-object's slot +0x4c returns a per-case value
(logged with its one argument); the target object's slot +0xbc is a logging fake (one argument)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    L = _rnd(c, 0x1000)
    c.emu.w32(L + 0xb61, c.rng.randint(0, 10))
    slot = _rnd(c, 0x40)
    c.emu.w32(L + 0x4a4, slot)              # write pointer (inside L)
    c.emu.w32(L + 0x4a8, slot + 4 + c.rng.randint(1, 8) * 4)   # end pointer, not equal to the write pointer
    c.emu.w32(0x7003b8, L)
    v4c = c.rng.getrandbits(32)
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, c.emu.logging_vtable('ZRenderMgr2', 0x40, impl={0x4c: (lambda e, a, v=v4c: (v, None))},
                                       argwords={0x4c: 1}))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(0x70039c, g)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, c.emu.logging_vtable('ZHitTarget', 0x30, argwords={0xbc: 1}))
    o = _rnd(c, 0x100)
    c.emu.wbytes(o + 0x63, bytes([c.rng.choice([0, 1])]))
    c.emu.wbytes(o + 0x56, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(o + 0x44, obj)
    c.emu.w32(o + 0x48, c.rng.getrandbits(32))
    return [o]


S(0x584580, 'CHitpointControl::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-01 claim 16; list append and ring write; slot +0x4c logged; slot +0xbc logged')
