"""specs_s73.py - unclaimed-68 batch 73 (slice 7). Names GUESS (FUN_addr). The CRT sized delete 0x634273 is hooked and logged (cdecl)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _o(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _setup_del(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete634273', em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))


def _g445c70(c):
    eng = zero_obj(c, 0x2000)
    obj = logged_obj(c, 'ZObj445c70', 0x200, impl={0x2c: lambda e, a: (None, None)}, argwords={0x2c: 0})
    c.emu.w32(eng + 0x190f, obj if c.rng.random() < 0.8 else 0)
    set_global(c, 0x70039c, eng)
    o = _o(c)
    c.emu.wbytes(o + 0x48, bytes([c.rng.getrandbits(8)]))
    return [o]


def _g656c30(c):
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('Obj656c30', 0x200,
                              impl={0xc: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32)),
                                    0x9c: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                              argwords={0xc: 1, 0x9c: 2})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g6042f0(c):
    o = _o(c)
    c.emu.w32(o + 8, c.rng.getrandbits(32))
    return [o]


S(0x445c70, 'FUN_445c70 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g445c70,
  note='unclaimed-68 batch 73: if this+0x48 bit 0x20: [G+0x190f] slot +0x2c; clear bit')
S(0x656c30, 'FUN_656c30 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g656c30,
  note='unclaimed-68 batch 73: slot +0xc(a) then slot +0x9c(r, b)')
S(0x6042f0, 'FUN_6042f0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g6042f0, setup=_setup_del,
  note='unclaimed-68 batch 73: vt = 0x6b9b6c; cdecl delete([this+8], 0x320) hooked')
