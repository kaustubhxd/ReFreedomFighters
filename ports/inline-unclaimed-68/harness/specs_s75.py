"""specs_s75.py - unclaimed-68 batch 75 (slice 7). Names GUESS (FUN_addr). CRT sized delete 0x634273 is hooked and logged (cdecl)."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj
from pe_emu import F


def _f(c):
    return struct.unpack('<f', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0]


def _setup_del(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete634273', em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))


def _g4cd3f0(c):
    o = zero_obj(c, 0x40)
    p = zero_obj(c, 0x20)
    c.emu.w32(o + 4, p)
    return [o, c.rng.getrandbits(32)]


def _g527530(c):
    o = zero_obj(c, 0x100)
    # the sub-object lives at this+0x28: its first dword is the vtable (the exe calls [vtable] with ecx = this+0x28)
    vt = c.emu.logging_vtable('ZSub527530', 0x80, impl={}, argwords={0: 3})
    c.emu.w32(o + 0x28, vt)
    return [o, F(_f(c)), F(_f(c)), F(_f(c))]


def _g45fa30(c):
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('Self45fa30', 0x200, impl={0x168: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                              argwords={0x168: 1, 0x124: 4})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4cd3f0, 'FUN_4cd3f0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g4cd3f0, setup=_setup_del,
  note='unclaimed-68 batch 75: vt = 0x695b40; delete([this+4], 4); if flags&1 delete(this, 0x14)')
S(0x527530, 'FUN_527530 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g527530,
  note='unclaimed-68 batch 75: [this+0x28] slot 0 (a, b, c floats)')
